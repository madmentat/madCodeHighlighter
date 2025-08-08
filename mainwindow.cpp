#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmlhighlighter.h"
#include "about.h"
#include "settings.h"
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QApplication>
#include <QAction>


#ifdef Q_OS_WIN
#include <QWindow>
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isDarkTheme(false)
{
    qDebug() << "Создание UI...";
    ui->setupUi(this);
    m_about = new About(this);
    m_settings = new Settings(this);

    qDebug() << "UI готово.";

    qDebug() << "Заполнение начального текста...";
    ui->codeInput->setPlainText("int main() {\n    return 0;\n}");

    qDebug() << "Создание репозитория подсветки...";
    repo = new KSyntaxHighlighting::Repository();
    if (!repo) {
        qDebug() << "Ошибка: Не удалось создать KSyntaxHighlighting::Repository!";
    }

    qDebug() << "Получение определения и темы...";
    definition = repo->definitionForName("C++");
    theme = repo->theme("Breeze Light");

    if (!definition.isValid()) qDebug() << "⚠️  Definition for C++ is invalid!";
    if (!theme.isValid()) qDebug() << "⚠️  Theme is invalid!";

    qDebug() << "Создание highlighter...";
    highlighter = new KSyntaxHighlighting::SyntaxHighlighter(ui->codeViewer->document());
    if (!highlighter) {
        qDebug() << "Ошибка: Не удалось создать SyntaxHighlighter!";
    } else {
        highlighter->setDefinition(definition);
        highlighter->setTheme(theme);
    }

    qDebug() << "Заполнение comboBox'ов...";
    for (const auto &t : repo->themes()) {
        ui->comboBoxTheme->addItem(t.name());
    }

    ui->comboBoxFontScale->addItems({"10", "12", "14", "16", "18", "20"});
    ui->comboBoxFontScale->setCurrentText("14");

    ui->comboBoxLineSpacing->addItems({"1.0", "1.2", "1.4", "1.6", "1.8", "2.0"});
    ui->comboBoxLineSpacing->setCurrentText("1.4");

    for (const auto &def : repo->definitions()) {
        if (!def.name().isEmpty() && def.isValid()) {
            ui->comboBoxLanguage->addItem(def.name());
        }
    }
    ui->comboBoxLanguage->setCurrentText("C++");

    /*
    // Add toggle theme action to menu
    QAction *toggleThemeAction = new QAction("Переключить тему", this);
    */
    //ui->themeBar->addAction(toggleThemeAction); // Assumes menuBar exists in UI
    //Settings *settings = new Settings(this);
    connect(ui->codeInput, &QTextEdit::textChanged, this, &MainWindow::onCodeChanged);
    connect(ui->comboBoxFontScale, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxFontScale_currentTextChanged);
    connect(ui->comboBoxLineSpacing, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxLineSpacing_currentTextChanged);
    connect(ui->comboBoxTheme, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxTheme_currentTextChanged);
    connect(ui->comboBoxLanguage, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxLanguage_currentTextChanged);
    connect(ui->saveSettingsButton, &QPushButton::clicked, this, &MainWindow::on_saveSettingsButton_clicked);
    connect(ui->AboutCHL, &QAction::triggered, this, &MainWindow::on_AboutCHL_triggered);
    connect(ui->themeBar, &QAction::triggered, this, &MainWindow::on_themeBar_toggled);
    //connect(ui->themeBar, &QAction::triggered, this, &MainWindow::on_themeBar_toggled);
    // Соединяем сигнал из Settings со слотом MainWindow
    connect(m_settings, &Settings::saveSettingsSignal, this, &MainWindow::saveSettings);
    connect(m_settings, &Settings::themeBoxSignal, this, &MainWindow::setDarkTheme);
    connect(m_settings, &Settings::autosaveChanged,this, &MainWindow::setAutosaveEnabled);
    //connect(m_settings, &Settings::themeBoxSignal,this, &MainWindow::toggleTheme);


    loadSettings();
    applyTheme();


    (void)winId();            // гарантирует создание HWND
    updateTitleBarTheme();    // теперь hwnd точно не null

    qDebug() << "Вызов onCodeChanged()...";
    onCodeChanged();

    qDebug() << "MainWindow конструктор завершён.";
}

MainWindow::~MainWindow()
{
    delete highlighter;
    delete m_about;
    delete m_settings;
    delete repo;
    delete ui;
}

void MainWindow::onCodeChanged()
{
    qDebug() << "onCodeChanged вызван";
    const QString code = ui->codeInput->toPlainText();
    QSignalBlocker blocker(ui->codeViewer); // Block signals to prevent recursion
    ui->codeViewer->setPlainText(code);

    HtmlHighlighter htmlExporter;
    htmlExporter.setDefinition(definition);
    htmlExporter.setTheme(theme);

    int fontSize = ui->comboBoxFontScale->currentText().toInt();
    double lineSpacing = ui->comboBoxLineSpacing->currentText().toDouble();

    QString html = htmlExporter.highlightToHtml(code, fontSize, lineSpacing);
    QSignalBlocker htmlBlocker(ui->HTMLout);
    ui->HTMLout->setPlainText(html);

    QFile file("output.html");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(html.toUtf8());
        file.close();
        qDebug() << "HTML saved to output.html";
    }
}

void MainWindow::on_comboBoxFontScale_currentTextChanged(const QString &arg1)
{
    qDebug() << "Font scale changed to:" << arg1;
    QFont font = ui->HTMLout->font();
    font.setPointSize(arg1.toInt());
    QSignalBlocker blocker(ui->HTMLout);
    ui->HTMLout->setFont(font);
    onCodeChanged();
    maybeSave();                 // <-- добавь
}

void MainWindow::on_comboBoxLineSpacing_currentTextChanged(const QString &arg1)
{
    qDebug() << "Line spacing changed to:" << arg1;
    QSignalBlocker blocker(ui->HTMLout);
    ui->HTMLout->setStyleSheet(QString("QTextEdit { line-height: %1; }").arg(arg1));
    onCodeChanged();
    maybeSave();                 // <-- добавь
}

void MainWindow::on_comboBoxTheme_currentTextChanged(const QString &arg1)
{
    qDebug() << "Theme changed to:" << arg1;
    theme = repo->theme(arg1);
    if (!theme.isValid()) {
        qDebug() << "Invalid theme selected!";
        return;
    }
    if (highlighter) {
        highlighter->setTheme(theme);
    }
    onCodeChanged();
    maybeSave();                 // <-- добавь
}

void MainWindow::on_comboBoxLanguage_currentTextChanged(const QString &arg1)
{
    qDebug() << "Language changed to:" << arg1;
    definition = repo->definitionForName(arg1);
    if (!definition.isValid()) {
        qDebug() << "Invalid language definition for:" << arg1;
        definition = repo->definitionForName("C++");
        if (!definition.isValid()) {
            qDebug() << "Fallback to C++ failed!";
        }
        QSignalBlocker blocker(ui->comboBoxLanguage);
        ui->comboBoxLanguage->setCurrentText("C++");
        return;
    }
    if (highlighter) {
        highlighter->setDefinition(definition);
    }
    onCodeChanged();
    maybeSave();                 // <-- добавь
}

void MainWindow::saveSettings()
{
    qDebug() << "Жопа!" << GetLastError();

    QSettings cfg("madmentat", "SyntaxHighlighter");
    cfg.setValue("fontSize", ui->comboBoxFontScale->currentText());
    cfg.setValue("lineSpacing", ui->comboBoxLineSpacing->currentText());
    cfg.setValue("theme", ui->comboBoxTheme->currentText());
    cfg.setValue("language", ui->comboBoxLanguage->currentText());
    cfg.setValue("isDarkTheme", isDarkTheme);
    cfg.setValue("autoSave", m_autoSave); // <-- добавь
    qDebug() << "Настройки сохранены.";
}

void MainWindow::loadSettings()
{
    qDebug() << "Загрузка настроек...";

    QSettings cfg("madmentat", "SyntaxHighlighter"); // <-- СНАЧАЛА cfg
    m_autoSave = cfg.value("autoSave", false).toBool(); // <-- читаем флаг отсюда

    QSignalBlocker fontBlocker(ui->comboBoxFontScale);
    ui->comboBoxFontScale->setCurrentText(cfg.value("fontSize", "14").toString());

    QSignalBlocker spacingBlocker(ui->comboBoxLineSpacing);
    ui->comboBoxLineSpacing->setCurrentText(cfg.value("lineSpacing", "1.4").toString());

    QSignalBlocker themeBlocker(ui->comboBoxTheme);
    ui->comboBoxTheme->setCurrentText(cfg.value("theme", "Breeze Light").toString());

    QString language = cfg.value("language", "C++").toString();
    QSignalBlocker langBlocker(ui->comboBoxLanguage);
    if (repo->definitionForName(language).isValid()) {
        ui->comboBoxLanguage->setCurrentText(language);
    } else {
        qDebug() << "Saved language" << language << "is invalid, falling back to C++";
        ui->comboBoxLanguage->setCurrentText("C++");
    }

    isDarkTheme = cfg.value("isDarkTheme", false).toBool();
}


void MainWindow::about()
{
    if (!m_about)
        m_about = new About(this);

    m_about->show();
    m_about->raise();
    m_about->activateWindow();
}

void MainWindow::settings()
{
    if (!m_settings)
        m_settings = new Settings(this);

    m_settings->setCurrentTheme(isDarkTheme);
    m_settings->setAutosave(m_autoSave);     // <-- ВАЖНО
    m_settings->show();
    m_settings->raise();
    m_settings->activateWindow();
}

void MainWindow::on_AboutCHL_triggered()
{
    about();
}

void MainWindow::on_aboutButton_clicked()
{
    about();
}

void MainWindow::on_settingsButton_clicked()
{
    settings();
}

void MainWindow::on_settings_triggered()
{
    settings();
}

void MainWindow::on_copyButton_clicked()
{
    // Placeholder for copy functionality
}

void MainWindow::on_saveSettingsButton_clicked()
{
    saveSettings();
}

void MainWindow::toggleTheme()
{
    qDebug() << "Переключение темы...";
    isDarkTheme = !isDarkTheme;
    applyTheme();
    saveSettings();
}

void MainWindow::applyTheme()
{
    qDebug() << "Применение темы:" << (isDarkTheme ? "Темная" : "Светлая");
    QString lightTheme = R"(
        QWidget {
            background-color: #ffffff;
            color: #000000;
        }
        QTextEdit {
            background-color: #f5f5f5;
            color: #000000;
            border: 1px solid #d3d3d3;
        }
        QPushButton {
            background-color: #e0e0e0;
            color: #000000;
            border: 1px solid #a0a0a0;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #d0d0d0;
        }
        QComboBox {
            background-color: #f5f5f5;
            color: #000000;
            border: 1px solid #d3d3d3;
        }
    )";

    QString darkTheme = R"(
        QWidget {
            background-color: #2b2b2b;
            color: #ffffff;
        }
        QTextEdit {
            background-color: #1e1e1e;
            color: #ffffff;
            border: 1px solid #555555;
        }
        QPushButton {
            background-color: #555555;
            color: #ffffff;
            border: 1px solid #777777;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: #666666;
        }
        QComboBox {
            background-color: #1e1e1e;
            color: #ffffff;
            border: 1px solid #555555;
        }
    )";

    qApp->setStyleSheet(isDarkTheme ? darkTheme : lightTheme);
    ui->themeBar->setText(isDarkTheme ? "Светлая тема" : "Темная тема");
    updateTitleBarTheme();
}

void MainWindow::updateTitleBarTheme()
{
#ifdef Q_OS_WIN
    qDebug() << "Обновление темы заголовка окна...";
    if (!windowHandle()) {
        qDebug() << "Ошибка: windowHandle недоступен!";
        return;
    }
    HWND hwnd = reinterpret_cast<HWND>(windowHandle()->winId());
    if (!hwnd) {
        qDebug() << "Ошибка: Неверный HWND!";
        return;
    }

    // Попробуем DWMWA_CAPTION_COLOR (Windows 11 и поздние Windows 10)
    constexpr DWORD DWMWA_CAPTION_COLOR = 35;
    COLORREF captionColor = isDarkTheme ? RGB(30, 30, 30) : RGB(240, 240, 240);
    HRESULT result = DwmSetWindowAttribute(hwnd, DWMWA_CAPTION_COLOR, &captionColor, sizeof(captionColor));

    if (FAILED(result)) {
        qDebug() << "Failed to set caption color, error:" << result << ", trying fallback...";
        // Fallback: DWMWA_USE_IMMERSIVE_DARK_MODE (Windows 10 2004+)
        constexpr DWORD DWMWA_USE_IMMERSIVE_DARK_MODE = 20;
        BOOL darkMode = isDarkTheme ? TRUE : FALSE;
        result = DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode, sizeof(darkMode));
        if (FAILED(result)) {
            qDebug() << "Failed to set title bar theme, error:" << result;
        } else {
            qDebug() << "Title bar theme set to" << (darkMode ? "dark" : "light") << "via DWMWA_USE_IMMERSIVE_DARK_MODE";
        }
    } else {
        qDebug() << "Title bar color set to" << (isDarkTheme ? "dark" : "light") << "via DWMWA_CAPTION_COLOR";
    }

    // Перерисовка окна
    BOOL setPosResult = SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
    if (!setPosResult) {
        qDebug() << "SetWindowPos failed, error:" << GetLastError();
    }
#else
    qDebug() << "Title bar theme switching is only supported on Windows.";
#endif
}

void MainWindow::on_themeBar_toggled(bool)
{
    toggleTheme();
}

void MainWindow::setDarkTheme(bool dark)
{
    if (isDarkTheme == dark)
        return; // уже установлено

    isDarkTheme = dark;
    applyTheme();
    saveSettings();
}

void MainWindow::setAutosaveEnabled(bool en)
{
    if (m_autoSave == en) return;
    m_autoSave = en;
    // можно сразу сохранить сам флаг
    saveSettings();
}

void MainWindow::maybeSave()
{
    if (m_autoSave)
        saveSettings();
}


void MainWindow::on_saveSettings_triggered()
{
    saveSettings();
    qDebug() << "Хуй!" << GetLastError();

}

