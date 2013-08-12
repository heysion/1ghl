#!/bin/bash
BIN=mpc_daemon dust_connect
OBJ=mpc_daemon.o dust_connect.o
SRC=mpc_daemon.c dust_connect.c
CC=gcc
all:$(BIN)
	chmod +x $(BIN)
#$(OBJ):$(SRC)
#$(BIN):(OBJ)
mpc_daemon:mpc_daemon.c
	gcc mpc_daemon.c -o mpc_daemon
dust_connect:dust_connect.c
	gcc dust_connect.c -o dust_connect

clean:
	-rm *.o
	-rm mpc_daemon dust_connect

