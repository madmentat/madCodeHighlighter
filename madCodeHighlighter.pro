QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    htmlhighlighter.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    about.h \
    htmlhighlighter.h \
    mainwindow.h \
    settings.h

FORMS += \
    about.ui \
    mainwindow.ui \
    settings.ui

TRANSLATIONS += \
    madCodeHighlighter_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

win32: LIBS += -ldwmapi

# Пути к KF6
INCLUDEPATH += C:/kde/kf6/include/kf6/KSyntaxHighlighting
LIBS += -LC:/kde/kf6/lib -lKF6SyntaxHighlighting

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE = icon.rc #иконка приложения для для Windows
RESOURCES += res.qrc #Все остальные ресурсы, в том числе иконка приложения для Linux
