#gui test 
import sys
import tkMessageBox 
from Tkinter import *

def die(event):
    tkMessageBox.showinfo("msg","this quit")
    sys.exit(0)

root = Tk()
button = Button(root)
button["text"] = "test"
button.bind("<Button-1>",die)
button.pack()
root.mainloop()

