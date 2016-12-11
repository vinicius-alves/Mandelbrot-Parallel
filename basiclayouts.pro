QT += widgets

HEADERS     = dialog.h \
    window.h \
    renderarea.h
SOURCES     = dialog.cpp \
              main.cpp \
    window.cpp \
    renderarea.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/andrei/basiclayouts
INSTALLS += target
