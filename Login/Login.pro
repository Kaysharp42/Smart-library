QT       += core gui network printsupport  serialport  \
            multimedia multimediawidgets
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += multimedia
CONFIG += resources_big
QT += multimedia
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajouter_employe.cpp \
    connection.cpp \
    employe.cpp \
    etagere.cpp \
    gestion_des_rayons.cpp \
    main.cpp \
    login.cpp \
    notification.cpp \
    rayon.cpp \
    contacts.cpp \
    event.cpp \
reclamations.cpp \
    setting.cpp \
    gestion_des_clients.cpp \
    creer_compte.cpp \
    clients.cpp \
    carte_fidelite.cpp\
    Gestion.cpp \
    commande.cpp \
    livraison.cpp \
    paiement.cpp \
    qcustomplot.cpp \
    smtp.cpp\
gestion_rh.cpp \
    Gestion_des_employes.cpp \
    etudiant.cpp \
    note.cpp \
    popup.cpp \
    tri.cpp\
    commandef.cpp \
    fournisseur.cpp \
    gestion_fournisseur.cpp \




HEADERS += \
    ajouter_employe.h \
    connection.h \
    employe.h \
    etagere.h \
    gestion_des_rayons.h \
    login.h \
    notification.h \
    rayon.h \
    contacts.h \
    event.h\
reclamations.h \
    setting.h \
    gestion_des_clients.h \
    creer_compte.h \
    clients.h \
    carte_fidelite.h\
    commande.h \
    gestion.h \
    livraison.h \
    paiement.h \
    qcustomplot.h \
    smtp.h\
gestion_rh.h \
    Gestion_des_employes.h \
    etudiant.h \
    note.h \
    popup.h \
    tri.h\
    commandef.h \
    fournisseur.h \
    gestion_fournisseur.h



FORMS += \
    ajouter_employe.ui \
    gestion_des_rayons.ui \
    login.ui \
    setting.ui \
    gestion_des_clients.ui\
    creer_compte.ui\
    gestion.ui\
gestion_rh.ui \
        Gestion_des_employes.ui \
        tri.ui \
    gestion_fournisseur.ui




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyResources.qrc \
    Ressources.qrc \
    ressource.qrc

DISTFILES += \
    customer-login-icon-27.jpg
