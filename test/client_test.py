import socket
import os
import threading
# host = input('请输入测试服务IP地址: ')
# port = int(input('请输入测试服务端口号: '))
host = '192.168.29.174'
port = 9999
s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_TCP, socket.TCP_KEEPIDLE, 10)
s.connect((host, port))

while True:
	sendstr = input("请输入要发送字符串: ")	
	if len(sendstr)>0:
		s.sendall(sendstr.encode(encoding='utf-8'))
		data = s.recv(1024)
		if not data :
			print('网络断开')
			break
		else:
			print('Received', repr(data))