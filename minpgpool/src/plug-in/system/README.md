#file list
makefile   #编译文件
md5.c
md5.h
test_md5_hash.c #测试样例文件
README.md  #帮助文件


==========
该库目前仅仅支持Gun/Linux/Unix 系列的编译
若是winxp/win7/win8 系列请自己包含进去，或者自己重新打包
代码是从bPostgreSQL中的库文件copy出来的，经过自己的测试，重新提取打包出来的
目前这个库的代码是在 PG 的 8.5RS 里面用的

MD5 返回的是一个 32位的消息hash因此需要一个char 类型的返回buf
  query_md5 =(char *)malloc(33);
函数调用
  md5_hash(argv[1],query_len,query_md5);
argv1 需要加密的数据
argv2 加密数据长度
argv3 密文

MD5.c 里面其他函数不常用，有兴趣的自己看一下吧，注释是用英文写的，基本上都能看
懂，不能看懂的，Google翻译一下就行了

自己的文件编译已测试样例文件为例
make后同时生成静态库和动态库
libminmd5.a 静态库
libminmd5.so 动态库

1、静态库的用法
gcc -o test test_md5_hash.c -L. -lminmd5 -I. 
-L  #库文件的路径，
-l  #库名字，通常情况下就是 去掉后缀和前缀lib的名字
-I  #头文件的路径
PS：动态库和静态库文件同名的建议不要放在一起，不然 ld的时候有可能找错文件

2、动态库的用法
gcc -o test test_md5_hash.c -g -L. -lminmd5 -I.
编译完后，建议将so 文件copy 到/usr/lib 
然后执行 ldconfig
或者写死一点
gcc -o test test_md5_hash.c -g -L. -lminmd5 -I. -Wl,-rpath,.
-Wl，-rpath,.  #告诉ld 从本地找库（W后面是L小写的），rpath里面接的是库文件存在
的路径，正常应用建议用第一种方案，第二种方案在写小测试程序的时候，可以考虑。

至于选静态库还是动态库，就看具体应用场景了，静态库的坏处是把库代码编译进去了，
若是程序按字节收费还是可以的，（PS，吐槽那个写了一个10w，10G的程序中国神童）




