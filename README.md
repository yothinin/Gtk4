# Gtk4
Example for learning C with Gtk4.

install:

apt install libgtk-4-1 libgtk-4-dev gtk-4-examples

Compile:

gcc  -g -Wall -Wunused -c "%f"  -DG_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED  -DGDK_PIXBUF_DISABLE_DEPRECATED  -DGTK_DISABLE_DEPRECATED `pkg-config --libs --cflags gtk4` 
