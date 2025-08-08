/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *settings;
    QAction *AboutCHL;
    QAction *saveSettings;
    QAction *themeBar;
    QWidget *centralwidget;
    QTextEdit *codeInput;
    QTextEdit *codeViewer;
    QTextEdit *HTMLout;
    QComboBox *comboBoxFontScale;
    QComboBox *comboBoxTheme;
    QComboBox *comboBoxLineSpacing;
    QPushButton *saveSettingsButton;
    QComboBox *comboBoxLanguage;
    QPushButton *aboutButton;
    QPushButton *settingsButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *copyButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1542, 966);
        settings = new QAction(MainWindow);
        settings->setObjectName("settings");
        AboutCHL = new QAction(MainWindow);
        AboutCHL->setObjectName("AboutCHL");
        saveSettings = new QAction(MainWindow);
        saveSettings->setObjectName("saveSettings");
        themeBar = new QAction(MainWindow);
        themeBar->setObjectName("themeBar");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        codeInput = new QTextEdit(centralwidget);
        codeInput->setObjectName("codeInput");
        codeInput->setGeometry(QRect(10, 40, 500, 800));
        codeViewer = new QTextEdit(centralwidget);
        codeViewer->setObjectName("codeViewer");
        codeViewer->setGeometry(QRect(520, 40, 500, 800));
        HTMLout = new QTextEdit(centralwidget);
        HTMLout->setObjectName("HTMLout");
        HTMLout->setGeometry(QRect(1030, 40, 500, 800));
        comboBoxFontScale = new QComboBox(centralwidget);
        comboBoxFontScale->setObjectName("comboBoxFontScale");
        comboBoxFontScale->setGeometry(QRect(10, 850, 221, 24));
        comboBoxTheme = new QComboBox(centralwidget);
        comboBoxTheme->setObjectName("comboBoxTheme");
        comboBoxTheme->setGeometry(QRect(250, 850, 221, 24));
        comboBoxLineSpacing = new QComboBox(centralwidget);
        comboBoxLineSpacing->setObjectName("comboBoxLineSpacing");
        comboBoxLineSpacing->setGeometry(QRect(490, 850, 221, 24));
        saveSettingsButton = new QPushButton(centralwidget);
        saveSettingsButton->setObjectName("saveSettingsButton");
        saveSettingsButton->setGeometry(QRect(10, 880, 701, 24));
        comboBoxLanguage = new QComboBox(centralwidget);
        comboBoxLanguage->setObjectName("comboBoxLanguage");
        comboBoxLanguage->setGeometry(QRect(720, 850, 221, 24));
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(720, 880, 100, 24));
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(830, 880, 701, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 201, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(520, 10, 301, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1030, 10, 371, 21));
        copyButton = new QPushButton(centralwidget);
        copyButton->setObjectName("copyButton");
        copyButton->setGeometry(QRect(959, 850, 571, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1542, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(saveSettings);
        menu_2->addAction(settings);
        menu_2->addAction(themeBar);
        menu_3->addAction(AboutCHL);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "madCodeHighlighter v1.0", nullptr));
        settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        AboutCHL->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        saveSettings->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        themeBar->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        saveSettingsButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\265 \320\262\320\262\320\276\320\264\320\260 \320\262\320\260\321\210\320\265\320\263\320\276 \320\272\320\276\320\264\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\262\320\260\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\276\320\272\321\200\320\260\321\210\320\265\320\275\320\275\320\276\320\263\320\276 \320\272\320\276\320\264\320\260\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "HTML \321\210\320\260\320\261\320\273\320\276\320\275 \320\277\320\276\320\264\320\272\321\200\320\260\321\210\320\265\320\275\320\275\320\276\320\263\320\276 \320\272\320\276\320\264\320\260 \320\264\320\273\321\217 \320\262\321\201\321\202\320\260\320\262\320\262\320\272\320\270 \320\275\320\260 \321\201\320\260\320\271\321\202:", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 HTML \321\210\320\260\320\261\320\273\320\276\320\275 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
