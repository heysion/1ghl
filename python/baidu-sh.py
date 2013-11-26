from baidupcs import *
import webbrowser
import hashlib
# 根据自己创建的应用，设置相应的app_key与pcs_dir
app_key = 'app_key'
pcs_dir = 'pcs_dir'
pcs = PCS(app_key)
# webbrowser.open(pcs.access_token_url)   # limit grant授权
pcs.authorize('here is access toekn')
# 获取云盘使用情况
info = pcs.quota.info()
print info
print 'quota info: %sM/%sM' % (info.used / 1024 / 1024, info.quota / 1024 / 1024)
# 创建目录
dir_name = 'test'
ret = pcs.file.mkdir(path = '/apps/%s/%s' % (pcs_dir, dir_name))
print 'file.mkdir:', ret
base_dir = '/apps/%s/%s/' % (pcs_dir, dir_name)
# 上传文件
path = 'd:\\test.jpg'
file_data = open(path, 'rb').read()
ret = pcs.file.upload(file = file_data, path = '/apps/%s/%s/test.jpg' % (pcs_dir, dir_name))
print 'file.upload:', ret
# 移动文件(改名)
frm = base_dir + 'test.jpg'
to = base_dir + 'test_to.jpg'
ret = pcs.file.move(_from = frm, to = to)
print ret
