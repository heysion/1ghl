#!/bin/bash
count=`ps -ef | grep shadowsocks  | grep -v grep | wc -l`
pid=`ps -ef | grep shadowsocks  | grep -v grep | awk '{print $2}'`
if [ $count -eq 1 ] && [ $# != 1 ]
then
printf "the pid %d is runing ...\n" $pid 
elif [ $# != 1 ]
then
printf "the starting...\n"
./shadowsocks-bin -c="config.json" >> run.log 2>&1 &
elif [ $# = 1  ] && ( [ $1 = "stop" ] || [ $1 = "STOP" ] )
then 
if [ $count -eq 0 ]
then 
printf "nothing is runing ...\n"
else
printf "killed the %d \n" $pid
kill -9 ${pid}
fi
fi

