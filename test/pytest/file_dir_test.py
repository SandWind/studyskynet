import sys
# from os import path
import os

file_dirs = os.path.dirname( os.path.abspath(__file__))
up_file_dirs =  os.path.dirname(file_dirs)
print(file_dirs)
print(up_file_dirs)
sys.path.append(up_file_dirs)
l = os.path.join('..')
print(l)
lib_path = os.path.abspath(os.path.join('../lib'))
sys.path.append(lib_path)
print(lib_path)