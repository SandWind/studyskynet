# -*- coding: UTF-8 -*-
import socket
import os
import sys
lib_path = os.path.abspath(os.path.join('../pblib'))
sys.path.append(lib_path)
import pblib.moblie_pb2 as moblie_create
import pblib.apps_pb2 as appcreate
from ctypes import create_string_buffer
from struct import *
# host = input('请输入测试服务IP地址: ')
# port = int(input('请输入测试服务端口号: '))
host = '192.168.29.174'
port = 10002
s=socket.socket(socket.AF_INET,  socket.SOCK_STREAM)
s.setsockopt(socket.SOL_TCP, socket.TCP_KEEPIDLE, 10)
s.connect((host, port))

moblie = moblie_create.moblie()
moblie.name  = "myphone"
moblie.model = moblie_create.Brand.vivo
moblie.systemName = "systemNo1"
print(moblie)
applist = moblie.apps

for x in range(1,10):
	app = appcreate.App()
	app.name = "世界传奇"+ str(x)
	app.sysdep = "andriod"+str(x)
	app.version = 5100+x
	app.descr = "ver10.01"+str(x)
	applist.extend([app])
# app = appcreate.App()
# app.name = "世界传奇"
# app.sysdep = "andriod"
# app.version = 5100
# app.descr = "ver10.01"
# moblie.apps.extend([app])
	
sendbuffer=moblie.SerializeToString()
print(len(sendbuffer))
while True:
	no = int(input("请输入发送次数: "))
	
	for x in range(1,no):
		print(moblie)
		sendbuffer = pack(">H%dp" % (len(sendbuffer),), len(sendbuffer), sendbuffer)
		# print(sendbuffer)
		# sendbuffer = pack(">H%dp" % (len(sendbuffer),), len(sendbuffer), sendbuffer.encode(encoding="utf-8"))
		print(sendbuffer)
		try:
			s.sendall(sendbuffer)
		except Exception as e:
			raise
			print(e)
		data=s.recv(1024)
		print('Received', repr(data))
		


			
		