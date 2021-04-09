import socket
import os
from ctypes import create_string_buffer
from struct import *
# host = input('请输入测试服务IP地址: ')
# port = int(input('请输入测试服务端口号: '))
host = '192.168.29.174'
port = 10002
s=socket.socket(socket.AF_INET,  socket.SOCK_STREAM)
s.setsockopt(socket.SOL_TCP, socket.TCP_KEEPIDLE, 10)
s.connect((host, port))
# sendbuffer = create_string_buffer(10000)
while True:
	sendstr = input("请输入要发送字符串: ")	
	if len(sendstr)>0:
		print(len(sendstr))
		sendbuffer = pack(">H%ds" % (len(sendstr),), len(sendstr), sendstr.encode(encoding='utf-8'))
		print("发送数据长度%d"%(len(sendbuffer)))
		try:
			s.sendall(sendbuffer)
		except Exception as e:
			raise
			print(e)
		data=s.recv(1024)
		print('Received', repr(data))
			
		