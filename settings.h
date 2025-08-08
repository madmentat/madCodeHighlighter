#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    void setCurrentTheme(bool dark);
    void setAutosave(bool enabled);          // <-- добавить

private slots:
    void on_themeBox_currentTextChanged(const QString &text);
    void on_cancelBtn_clicked();
    void on_applyBtn_clicked();
    void on_settingsBox_toggled(bool on);    // <-- заменить checkStateChanged на toggled

private:
    Ui::Settings *ui;
    bool isDarkTheme;    // потом флаги

signals:
    void saveSettingsSignal();
    void themeBoxSignal(bool dark);
    void autosaveChanged(bool enabled);      // <-- добавить

};

#endif // SETTINGS_H
