alias
===
别名
格式
alias ll= 'ls -l'

常用命令
===
ls -F 
#目录
ls -l
ls -a
#列所有目录
cat -n hosts
#带行号
cat -b hosts
#空行不标行号
wc hosts
#第一个数字，行数 wc -l
#第二个数字，字数(单词） wc -w
#第二个数字，字符数 wc -m,-c
cp 命令 最后一个参数为目标地址
cd -
#返回上次路径
mkdir -p
#创建上一层
cp -r files files2
#拷贝目录
ln -s 原路径 快捷路径
ln -s dev/github/1ghl d.git.1ghl


#ls 权限问题#
===
ls -l
drwxr-xr-x 6 ndk  users 4096 8月  24 00:00 2013

#第一个字符表示对象属性 d为目录，c为字符设备，-为文件
#后3个字符表示 文件ower的权限 wxr 
#中间3位表示对象所属组的权限 wxr 缺的用-
#最后3位表示对象公共属性
chmod 改变对象权限
chown 改变所有者
chgrp 改变所属组

jobs 
#看后台进程

