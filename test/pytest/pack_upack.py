from struct import *
from ctypes import *
from io import *
import sys
teststr = 'this is a test string==========='
strlen = len(teststr)
sendbuffer = create_unicode_buffer(1000)
pack_into('>bs',sendbuffer,0,strlen,teststr.encode(encoding='utf-8'))
# print(repr(sendbuffer.raw))
# print(repr(sendbuffer))
size = sys.getsizeof(teststr)

print(size)
print(strlen)
data = pack("hp",size,teststr.encode(encoding='utf-8'))
data2 = pack("s",teststr.encode(encoding='utf-8'))
print(data)
print(data2)

b = BytesIO(teststr.encode(encoding='utf-8'))
view = b.getbuffer()
print(view)

data3 = pack("I%ds" % (len(teststr),), len(teststr), teststr.encode(encoding='utf-8'))
data3 = pack(">H%ds" % (len(teststr),), len(teststr), teststr.encode(encoding='utf-8'))
print(data3)
str3 = "I%ds" % (len(teststr),)
print(str3)