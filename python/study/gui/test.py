import sys
from PySide.QtCore import *
from PySide.QtGui import *
from testgui import Ui_Dialog
from PySide import QtCore, QtGui

def accept2():
	print 'hell'
def reject2():
	print 'hell2'
def clicked1():
	print 'hell3'
def clicked2():
	print 'hell4'


class MainWindow(QMainWindow, Ui_Dialog):  
        def __init__(self, parent=None):  
            super(MainWindow, self).__init__(parent)  
            self.setupUi(self)  
#            self.buttonBox.connect(self.accepted)
	    QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("accepted()"), accept2)
	    QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("rejected()"), reject2)
	    QtCore.QObject.connect(self.checkBox, QtCore.SIGNAL("clicked()"), clicked1)
	    QtCore.QObject.connect(self.btn_OK, QtCore.SIGNAL("clicked()"), clicked2)
#	    self.center()
if __name__ == '__main__':  
    app = QApplication(sys.argv)  
    mainWnd = MainWindow()  
    mainWnd.show()  
#    width_len = QApplication.desktop().width()
    width_len = (QApplication.desktop().width() - mainWnd.width() ) / 2
    height_len = (QApplication.desktop().height() - mainWnd.height() ) / 2
    print width_len , height_len
    mainWnd.move(width_len,height_len)
    app.exec_()  

