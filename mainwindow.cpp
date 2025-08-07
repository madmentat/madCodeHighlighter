#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmlhighlighter.h"
#include "about.h"
#include "settings.h"
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isDarkTheme(true) // Default to light theme
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

    qDebug() << "Получение определения и темы...";
    definition = repo->definitionForName("C++");
    theme = repo->theme("Breeze Light");

    if (!definition.isValid()) qDebug() << "⚠️  Definition is invalid!";
    if (!theme.isValid()) qDebug() << "⚠️  Theme is invalid!";

    qDebug() << "Создание highlighter...";
    highlighter = new KSyntaxHighlighting::SyntaxHighlighter(ui->codeViewer->document());
    highlighter->setDefinition(definition);
    highlighter->setTheme(theme);

    qDebug() << "Заполнение comboBox'ов...";
    for (const auto &t : repo->themes()) {
        ui->comboBoxTheme->addItem(t.name());
    }

    ui->comboBoxFontScale->addItems({"10", "12", "14", "16", "18", "20"});
    ui->comboBoxFontScale->setCurrentText("14");

    ui->comboBoxLineSpacing->addItems({"1.0", "1.2", "1.4", "1.6", "1.8", "2.0"});
    ui->comboBoxLineSpacing->setCurrentText("1.4");

    for (const auto &def : repo->definitions()) {
        if (!def.name().isEmpty())
            ui->comboBoxLanguage->addItem(def.name());
    }
    ui->comboBoxLanguage->setCurrentText("C++");

    connect(ui->codeInput, &QTextEdit::textChanged, this, &MainWindow::onCodeChanged);
    connect(ui->comboBoxFontScale, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxFontScale_currentTextChanged);
    connect(ui->comboBoxLineSpacing, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxLineSpacing_currentTextChanged);
    connect(ui->comboBoxTheme, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxTheme_currentTextChanged);
    connect(ui->comboBoxLanguage, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBoxLanguage_currentTextChanged);
    connect(ui->saveSettingsButton, &QPushButton::clicked, this, &MainWindow::on_saveSettingsButton_clicked);
    connect(ui->AboutCHL, &QAction::triggered, this, &MainWindow::on_AboutCHL_triggered);

    loadSettings();
    applyTheme(); // Apply theme after loading settings

    qDebug() << "Вызов onCodeChanged()...";
    onCodeChanged();

    // Temporary: Toggle theme to test functionality (remove later)
    toggleTheme();

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
    const QString code = ui->codeInput->toPlainText();
    ui->codeViewer->setPlainText(code);

    HtmlHighlighter htmlExporter;
    htmlExporter.setDefinition(definition);
    htmlExporter.setTheme(theme);

    int fontSize = ui->comboBoxFontScale->currentText().toInt();
    double lineSpacing = ui->comboBoxLineSpacing->currentText().toDouble();

    QString html = htmlExporter.highlightToHtml(code, fontSize, lineSpacing);
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
    QFont font = ui->HTMLout->font();
    font.setPointSize(arg1.toInt());
    ui->HTMLout->setFont(font);
    onCodeChanged();
}

void MainWindow::on_comboBoxLineSpacing_currentTextChanged(const QString &arg1)
{
    ui->HTMLout->setStyleSheet(QString("QTextEdit { line-height: %1; }").arg(arg1));
    onCodeChanged();
}

void MainWindow::on_comboBoxTheme_currentTextChanged(const QString &arg1)
{
    theme = repo->theme(arg1);
    if (!theme.isValid()) {
        qDebug() << "Invalid theme selected!";
        return;
    }
    highlighter->setTheme(theme);
    onCodeChanged();
}

void MainWindow::on_comboBoxLanguage_currentTextChanged(const QString &arg1)
{
    definition = repo->definitionForName(arg1);
    if (!definition.isValid()) {
        qDebug() << "Invalid language definition!";
        return;
    }
    highlighter->setDefinition(definition);
    onCodeChanged();
}

void MainWindow::on_saveSettingsButton_clicked()
{
    saveSettings();
}

void MainWindow::saveSettings()
{
    QSettings settings("madmentat", "SyntaxHighlighter");

    settings.setValue("fontSize", ui->comboBoxFontScale->currentText());
    settings.setValue("lineSpacing", ui->comboBoxLineSpacing->currentText());
    settings.setValue("theme", ui->comboBoxTheme->currentText());
    settings.setValue("language", ui->comboBoxLanguage->currentText());
    settings.setValue("isDarkTheme", isDarkTheme); // Save theme preference

    qDebug() << "Настройки сохранены.";
}

void MainWindow::loadSettings()
{
    QSettings settings("madmentat", "SyntaxHighlighter");

    ui->comboBoxFontScale->setCurrentText(settings.value("fontSize", "14").toString());
    ui->comboBoxLineSpacing->setCurrentText(settings.value("lineSpacing", "1.4").toString());
    ui->comboBoxTheme->setCurrentText(settings.value("theme", "Breeze Light").toString());
    ui->comboBoxLanguage->setCurrentText(settings.value("language", "C++").toString());
    isDarkTheme = settings.value("isDarkTheme", false).toBool(); // Load theme preference
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

void MainWindow::toggleTheme()
{
    isDarkTheme = !isDarkTheme; // Toggle theme
    applyTheme(); // Apply new theme
    saveSettings(); // Save new theme preference
}

void MainWindow::applyTheme()
{
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
}
