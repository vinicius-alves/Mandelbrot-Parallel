QT += widgets

HEADERS     = window.h \
    renderarea.h
SOURCES     = main.cpp \
    window.cpp \
    renderarea.cpp \
    teste.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/home/andrei/mandelbrotset
INSTALLS += target
