#!/usr/bin/env python
import sys
import pygtk
pygtk.require("2.0")
import gtk
import gtk.glade

if __name__ == "__main__":
    w=gtk.glade.XML("u4.glade")
    w.get_widget('window1').show()
    gtk.main()
