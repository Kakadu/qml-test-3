# Add more folders to ship with the application, here
folder_01.source = ..
folder_01.target = .
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH = ..

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    MainModel.cpp \
    MiniModel.cpp \
    dataitem.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
# include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
# qtcAddDeployment()

QT += qml quick

HEADERS += \
    MainModel.h \
    MiniModel.h \
    dataitem.h

CXX_OPTIONS= -std=c++11

OTHER_FILES += \
    ScrollBar.qml \
    View.qml
