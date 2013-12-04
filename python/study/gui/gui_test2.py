import sys
import Tkinter
#from Tkconstants import *
tk = Tkinter.Tk()
frame = Tkinter.Frame(tk, relief="raised", borderwidth=2)
frame.pack(fill="both",expand=1)
label = Tkinter.Label(frame, text="Hello, World")
label.pack(fill="x", expand=1)
button = Tkinter.Button(frame,text="Exit",command=tk.destroy)
button.pack(side="bottom")
tk.mainloop()
