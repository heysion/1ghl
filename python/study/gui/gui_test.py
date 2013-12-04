#gui test 
import sys
from Tkinter import *

def die(event):
    sys.exit(0)

root = Tk()
button = Button(root)
button["text"] = "test"
button.bind("<Button-1>",die)
button.pack()
root.mainloop()

