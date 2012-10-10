TEMPLATE = app
CONFIG += console


QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
QMAKE_CXXFLAGS += -D__STDC_FORMAT_MACROS -U__STRICT_ANSI__
QMAKE_LFLAGS += -std=c++11 -stdlib=libc++


SOURCES += main.cpp \
    STL/container/encapsulation.cpp \
    verbose.cpp \
    Patterns/uncopyable_example.cpp \
    common.cpp \
    Exceptions/exceptionsafe_destructor.cpp \
    STL/smartpointers/sharedpointer_customdeleter.cpp \
    Patterns/pimplexample.cpp \
    Patterns/pimpltemplateexample.cpp \
    Patterns/strategy.cpp \
    Exceptions/exceptions.cpp \
    Exceptions/exception_specifications.cpp \
    Patterns/virtual_constructor.cpp \
    Patterns/limitedinstances.cpp \
    Patterns/doubledispatch_test.cpp \
    cpp11/lambda.cpp \
    cpp11/auto.cpp \
    cpp11/initialization.cpp \
    cpp11/for.cpp \
    cpp11/constexpr.cpp


HEADERS += \
    verbose.h \
    common.h \
    Patterns/uncopyable.h \
    Patterns/unthreadsafesingleton.h \
    Exceptions/exceptionsafe_destructor.h \
    Patterns/pimplexample.h \
    Patterns/pimpltemplateexample.h \
    Patterns/strategy.h \
    Patterns/limitedinstances.h \
    Patterns/lldoubledispatch.h

OTHER_FILES += \
    REFERENCES.txt \
    NOTES.txt

INCLUDEPATH += /opt/local/include
