TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    STL/container/encapsulation.cpp \
    verbose.cpp \
    Patterns/uncopyable_example.cpp \
    common.cpp \
    Exceptions/exceptionsafe_destructor.cpp \
    STL/smartpointers/sharedpointer_customdeleter.cpp \
    Patterns/pimplexample.cpp \
    Patterns/pimpltemplateexample.cpp \
    Patterns/strategy.cpp



HEADERS += \
    verbose.h \
    common.h \
    Patterns/uncopyable.h \
    Patterns/unthreadsafesingleton.h \
    Exceptions/exceptionsafe_destructor.h \
    Patterns/pimplexample.h \
    Patterns/pimpltemplateexample.h \
    Patterns/strategy.h

OTHER_FILES += \
    REFERENCES.txt

INCLUDEPATH += /opt/local/include
