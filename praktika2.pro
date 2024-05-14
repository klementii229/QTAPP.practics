QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    initial.cpp \
    regestration.cpp \
    adminpanel.cpp \
    userpanel.cpp

HEADERS += \
    initial.h \
    main.h \
    regestration.h \
    adminpanel.h \
    userpanel.h

FORMS += \
    initial.ui \
    regestration.ui \
    adminpanel.ui \
    userpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc

DISTFILES += \
    res/1671025999_grizly-club-p-zavod-png-5.png \
    res/apps_icon_151630.png \
    res/vecteezy_3d-bill-payment-with-credit-card-and-financial-security-for_11993276 (1).png
