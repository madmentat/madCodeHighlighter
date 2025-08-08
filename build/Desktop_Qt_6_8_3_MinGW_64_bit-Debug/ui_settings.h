/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *languageBox;
    QLabel *label;
    QCheckBox *settingsBox;
    QComboBox *themeBox;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *applyBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(400, 160);
        Settings->setMinimumSize(QSize(400, 160));
        Settings->setMaximumSize(QSize(400, 1000));
        gridLayoutWidget_2 = new QWidget(Settings);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 381, 92));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        languageBox = new QComboBox(gridLayoutWidget_2);
        languageBox->addItem(QString());
        languageBox->addItem(QString());
        languageBox->setObjectName("languageBox");
        languageBox->setBaseSize(QSize(50, 30));

        gridLayout_2->addWidget(languageBox, 5, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");
        label->setBaseSize(QSize(100, 30));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        settingsBox = new QCheckBox(gridLayoutWidget_2);
        settingsBox->setObjectName("settingsBox");

        gridLayout_2->addWidget(settingsBox, 2, 0, 1, 1);

        themeBox = new QComboBox(gridLayoutWidget_2);
        themeBox->addItem(QString());
        themeBox->addItem(QString());
        themeBox->setObjectName("themeBox");
        themeBox->setBaseSize(QSize(50, 30));

        gridLayout_2->addWidget(themeBox, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        gridLayoutWidget = new QWidget(Settings);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 100, 381, 51));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        applyBtn = new QPushButton(gridLayoutWidget);
        applyBtn->setObjectName("applyBtn");

        gridLayout_3->addWidget(applyBtn, 0, 2, 1, 1);

        cancelBtn = new QPushButton(gridLayoutWidget);
        cancelBtn->setObjectName("cancelBtn");

        gridLayout_3->addWidget(cancelBtn, 0, 1, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "madHighlighter settings", nullptr));
        languageBox->setItemText(0, QCoreApplication::translate("Settings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        languageBox->setItemText(1, QCoreApplication::translate("Settings", "English", nullptr));

        label->setText(QCoreApplication::translate("Settings", "\320\257\320\267\321\213\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        settingsBox->setText(QCoreApplication::translate("Settings", "\320\220\320\262\321\202\320\276\321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", nullptr));
        themeBox->setItemText(0, QCoreApplication::translate("Settings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217", nullptr));
        themeBox->setItemText(1, QCoreApplication::translate("Settings", "\320\242\320\265\320\274\320\275\320\260\321\217", nullptr));

        label_2->setText(QCoreApplication::translate("Settings", "\320\242\320\265\320\274\320\260 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260:", nullptr));
        applyBtn->setText(QCoreApplication::translate("Settings", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        cancelBtn->setText(QCoreApplication::translate("Settings", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
