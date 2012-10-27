TEMPLATE = app
CONFIG += console


QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
QMAKE_CXXFLAGS += -D__STDC_FORMAT_MACROS -U__STRICT_ANSI__ -DCPLUSPLUS11
QMAKE_LFLAGS += -std=c++11 -stdlib=libc++

include (sources.pri)
include (sources_cpp11.pri)

OTHER_FILES += \
    REFERENCES.txt \
    NOTES.txt

# boost
INCLUDEPATH += /opt/local/include
QMAKE_LIBDIR += /opt/local/lib
LIBS += -lboost_thread-mt -lboost_system-mt
