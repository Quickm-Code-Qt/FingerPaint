# FingerPaint
Finger painting application in Qt/C++ demonstrating touch screen events.

This is an enhanced version of an example project.  The example project comes with QtCreator.  This application enhances the example project in the following ways:
  1.  Added a submenu in Options menu to choose a specific color rather than rotating within supported color.
  2.  A Command design pattern to manage QAction for Color submenu, where all color menu items utilize a single QAction/Command.
  3.  A Data Model class to manage all color related information.
  4.  A Singleton design pattern class is the base class of Data Model class since multiple classes access the color data.
