TEMPLATE      = app
QT           += script
#CONFIG       += uitools        # :-1: warning: CONFIG+=uitools is deprecated. Use QT+=uitools instead.
HEADERS       = htmlsyntaxhighlighter.h \
                htmlwindow.h
SOURCES       = htmlsyntaxhighlighter.cpp \
                htmlwindow.cpp \
                main.cpp
QT += widgets script uitools
