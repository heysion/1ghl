#**************************************************
#Description: md5 libfile makefile
#Version:     v0.01
#Copyleft:    
#**************************************************
#SHELL=/bin/sh
SRC    = md5.c 
OBJECT = md5.o 
CC = gcc
AR = ar rc
LIB_OBJECT_A = libminmd5.a
LIB_OBJECT = libminmd5
BIN_OBJECT    = md5
LD_FLAGS = -shared -fpic -o
LIB_SO = libminmd5.so

$(LIB_OBJECT):
	$(CC) $(SRC) $(LD_FLAGS) $(LIB_SO)

.PHONY:clean
#all:$(LIB_OBJECT_A) $(LIB_OBJECT_SO) 
#$(LIB_OBJECT_A):$(OBJECT)
#	$(AR) $(LIB_OBJECT_A) $(OBJECT)
#$(OBJECT):
	$(CC) -c $(SRC)
clean:
	-rm -f $(BIN_OBJECT) $(OBJECT) $(LIB_OBJECT_A) $(LIB_OBJECT_SO) 




