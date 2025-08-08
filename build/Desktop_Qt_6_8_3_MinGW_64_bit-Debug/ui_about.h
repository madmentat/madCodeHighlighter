/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QTextEdit *textEdit;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(401, 730);
        pushButton = new QPushButton(About);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 680, 380, 30));
        graphicsView = new QGraphicsView(About);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 380, 391));
        textEdit = new QTextEdit(About);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 410, 380, 261));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265 madCodeHighlighter", nullptr));
        pushButton->setText(QCoreApplication::translate("About", "Ok", nullptr));
        textEdit->setHtml(QCoreApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">madCodeHighlighter v1.0</span> \342\200\224 \321\215\321\202\320\276 \320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \321\203\321\202\320\270\320\273\320\270\321\202\320\260 \320\264\320\273\321\217 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\272\320\270 \320\272\320\276\320\264\320\260, \320"
                        "\276\321\201\320\275\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\275\320\260 \321\204\321\200\320\265\320\271\320\274\320\262\320\276\321\200\320\272\320\265 Qt \320\270 KDE \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\265 KF6 KSyntaxHighlighting, \320\272\320\276\321\202\320\276\321\200\320\260\321\217 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\216\321\202\321\201\321\217 \320\262 QtCreator.</p>\n"
"<p align=\"justify\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\321\213 \320\262\321\201\321\217\320\272\320\270\320\265 \321\204\320\270\321\210\320\265\321\207\320\272\320\270 \320\264\320\273\321\217 \321\203\320\264\320\276\320\261\321\201\321\202\320\262\320\260: \321\215\320\272\321\201\320\277\320\276\321\200\321\202 \320\262 HTML, \320\262\321\213\320\261\320\276\321\200 \321\217\320\267"
                        "\321\213\320\272\320\260 \320\277\320\276\320\264\321\201\320\262\320\265\321\202\320\272\320\270, \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\320\260\320\267\320\274\320\265\321\200\320\260 \321\210\321\200\320\270\321\204\321\202\320\260 \320\270 \320\274\320\265\320\266\321\201\321\202\321\200\320\276\321\207\320\275\320\276\320\263\320\276 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\260, \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272 \320\274\320\265\320\266\320\264\321\203 \321\201\320\265\321\201\321\201\320\270\321\217\320\274\320\270, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\272\320\276\320\264\320\260 \320\270 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\321\217 HTML-\321\210\320\260\320\261\320\273\320\276\320\275\320\260 \320\264\320\273\321\217"
                        " \320\262\321\201\321\202\320\260\320\262\320\272\320\270 \320\275\320\260 \320\272\320\260\320\272\320\276\320\271-\320\275\320\270\320\261\321\203\320\264\321\214 \321\201\320\260\320\271\321\202, \321\202\320\270\320\277\320\260 Joomla3.5. \320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201 \321\201 \321\202\321\203\320\273\321\202\320\270\320\277\320\260\320\274\320\270 \342\200\224 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276 \320\264\320\273\321\217 \321\202\320\265\321\205, \320\272\321\202\320\276 \320\277\320\276\321\201\320\273\320\265 2 \320\275\320\276\321\207\320\270 \320\267\320\260\320\261\321\213\320\273, \320\267\320\260\321\207\320\265\320\274 \320\262\320\276\320\276\320\261\321\211\320\265 \321\201\321\216\320\264\320\260 \320\267\320\260\321\210\321\221\320\273.</p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\321\201\320\265 \320"
                        "\277\320\276\320\264\321\200\320\276\320\261\320\275\320\276\321\201\321\202\320\270, \320\270\321\201\321\205\320\276\320\264\320\275\320\270\320\272\320\270 \320\270 \320\264\321\200\321\203\320\263\320\270\320\265 \320\277\320\276\320\273\320\265\320\267\320\275\320\276\321\201\321\202\320\270 \320\275\320\260:<br /><a href=\"https://madmentat.ru\"><span style=\" font-weight:700; text-decoration: underline; color:#27bf73;\">https://madmentat.ru</span></a><span style=\" font-size:10pt;\">  </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
