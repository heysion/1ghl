#!/bin/bash
#input 
set -xv
debug=1
USAGE='usage: sh $1 $2 ;'\
'$1: is value of [1,2] create file or directory '\
'$2: is number '
echo $USAGE
echo $0 
echo $1 
echo $2
echo $#

if [ $# -eq 2 ]
