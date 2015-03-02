TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    lex.yy.c \
    parser.tab.c \
    classes/analizerbranch.cpp \
    classes/coordinate.cpp \
    classes/data.cpp \
    classes/debug.cpp \
    classes/formula.cpp \
    classes/generatortest.cpp \
    classes/parseddata.cpp \
    classes/parser.cpp \
    classes/parsingtree.cpp \
    classes/receiver.cpp \
    classes/refutationtree.cpp \
    classes/refutationtreeparser.cpp \
    classes/treeaux.cpp \
    classes/weakestprecondition.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    last.pro.user

HEADERS += \
    data.h \
    classes/analizerbranch.h \
    classes/coordinate.h \
    classes/data.h \
    classes/debug.h \
    classes/formula.h \
    classes/generatortest.h \
    classes/parseddata.h \
    classes/parser.h \
    classes/parsingtree.h \
    classes/receiver.h \
    classes/refutationtree.h \
    classes/refutationtreeparser.h \
    classes/treeaux.h \
    classes/weakestprecondition.h
