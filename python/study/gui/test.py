import sys
from PySide.QtCore import *
from PySide.QtGui import *
from testgui import Ui_Dialog
from PySide import QtCore, QtGui

def accept2():
	print 'hell'
def reject2():
	print 'hell2'


class MainWindow(QMainWindow, Ui_Dialog):  
        def __init__(self, parent=None):  
            super(MainWindow, self).__init__(parent)  
            self.setupUi(self)  
#            self.buttonBox.connect(self.accepted)
	    QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("accepted()"), accept2)
	    QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("rejected()"), reject2)

if __name__ == '__main__':  
    app = QApplication(sys.argv)  
    mainWnd = MainWindow()  
    mainWnd.show()  
    app.exec_()  

