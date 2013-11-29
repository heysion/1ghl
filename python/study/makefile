#python c api

CC = gcc

LIB_SO = -shared -fpic -o
LIBNAME1 = libtest
LIBSRC1 = testlib.c
${LIBNAME1}:
	${CC} ${LIBSRC1} ${LIB_SO} ${LIBNAME1}.so

.clean:
	rm -f *.so 
