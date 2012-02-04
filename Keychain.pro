# Add more folders to ship with the application, here
folder_01.source = qml/Keychain
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian {
    ICON = Keychain.svg
#    TARGET.CAPABILITY += NetworkServices
     TARGET.UID3 = 0x20041E88
    my_deployment.pkg_prerules += vendorinfo

    DEPLOYMENT += my_deployment
    DEPLOYMENT.display_name= Chabhi
    vendorinfo += "%{\"Ravi Vagadia\"}" ":\"Ravi Vagadia\""
}

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
CONFIG += qt-components

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    keyssortfilterproxymodel.cpp


# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    resource/r.qrc

VERSION = 0.8.0

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/manifest.aegis \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog

HEADERS += \
    QmlClipboardAdapter.h \
    keyssortfilterproxymodel.h
