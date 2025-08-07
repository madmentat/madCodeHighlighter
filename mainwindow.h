#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <KSyntaxHighlighting/SyntaxHighlighter>
#include <KSyntaxHighlighting/Repository>
#include <KSyntaxHighlighting/Definition>
#include <KSyntaxHighlighting/Theme>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class About;
class Settings;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCodeChanged();
    void on_comboBoxFontScale_currentTextChanged(const QString &arg1);
    void on_comboBoxTheme_currentTextChanged(const QString &arg1);
    void on_comboBoxLineSpacing_currentTextChanged(const QString &arg1);
    void on_saveSettingsButton_clicked();
    void on_comboBoxLanguage_currentTextChanged(const QString &arg1);
    void on_AboutCHL_triggered();
    void on_aboutButton_clicked();
    void on_settingsButton_clicked();
    void on_settings_triggered();
    void on_copyButton_clicked();
    void toggleTheme(); // New slot to toggle theme

private:
    Ui::MainWindow *ui;
    KSyntaxHighlighting::Repository *repo;
    KSyntaxHighlighting::SyntaxHighlighter *highlighter;
    KSyntaxHighlighting::Definition definition;
    KSyntaxHighlighting::Theme theme;
    About* m_about;
    Settings* m_settings;
    bool isDarkTheme; // Boolean to track theme state

    void saveSettings();
    void loadSettings();
    void about();
    void settings();
    void applyTheme(); // Apply theme based on isDarkTheme
};

#endif // MAINWINDOW_H
