QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport

HEADERS       = mainwindow.h \
                color_constants.h \
                colorcommand.h \
                colordatamodel.h \
                scribblearea.h \
                singletonbase.h
SOURCES       = main.cpp \
                colorcommand.cpp \
                colordatamodel.cpp \
                mainwindow.cpp \
                scribblearea.cpp \
                singletonbase.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/touch/fingerpaint
INSTALLS += target
