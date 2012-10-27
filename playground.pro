TEMPLATE = app
CONFIG += console

include (sources.pri)

OTHER_FILES += \
    REFERENCES.txt \
    NOTES.txt

# boost
INCLUDEPATH += /opt/local/include
QMAKE_LIBDIR += /opt/local/lib
LIBS += -lboost_thread-mt -lboost_system-mt
