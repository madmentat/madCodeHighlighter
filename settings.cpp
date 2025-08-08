#include "settings.h"
#include "ui_settings.h"
#include <QDebug>


Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_cancelBtn_clicked()
{
       this->close();
}


void Settings::on_applyBtn_clicked()
{
   emit saveSettingsSignal();
   this->close();
}


void Settings::on_themeBox_currentTextChanged(const QString &text)
{
    const QString t = text.trimmed().toLower();
    const bool dark = (t == QStringLiteral("темная"));
    emit themeBoxSignal(dark);
    qDebug() << "Выбрана тема:" << (dark ? "Темная" : "Светлая");
}


void Settings::setCurrentTheme(bool dark)
{
    // Чтобы программная установка не вызывала currentTextChanged и твой emit
    QSignalBlocker blocker(ui->themeBox);
    ui->themeBox->setCurrentText(dark ? QStringLiteral("Темная") : QStringLiteral("Светлая"));
}

void Settings::setAutosave(bool enabled)
{
    QSignalBlocker blocker(ui->settingsBox);   // <-- ВАЖНО: блокируем, чтобы не стрельнул сигнал
    ui->settingsBox->setChecked(enabled);
}

void Settings::on_settingsBox_toggled(bool on)
{
    emit autosaveChanged(on);
}
