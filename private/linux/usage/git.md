#配置git的个人配置文件#
===
基于项目的配置在 .git/config 文件中
如配置user 与 email
[core]
	edior = emacs
	user = xxx
	email = xx@xx.com

#配置github过程#
===
1、准备git环境
==
2、准备ssh环境
==
3、生成ssh rsa密钥对
==
ssh-keygen -t rsa -C "密钥名称"

eg: 
cd ～/.ssh
ssh-keygen -t rsa -C "heysion@github.com"

生成密钥对的时候其他使用回车默认
生成的pub密钥在 ~/.ssh/id_rsa.pub
4、再github里面添加生成的ssh密钥
==
将上步操作中的 pub密钥 添加到github中
将pub文件中的内容复制到 github中
5、测试密钥文件
==
采用 ssh git@github.com 命令来判断
若失败可以使用
ssh -v git@github.com 命令来跟踪错误原因
#git用ssh push的config文件#
===
[core]
	repositoryformatversion = 0
	filemode = true
	bare = false
	logallrefupdates = true
	editor = emacs
[user]
	name = heysion
	email = heysions@gmail.com
[remote "origin"]
	url = git@github.com:heysion/1ghl.git
	fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
	remote = origin
	merge = refs/heads/master
