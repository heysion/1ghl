import os 
filename = os.environ.get('HOME')
if filename and os.path.isfile(filename):
    execfile(filename)
