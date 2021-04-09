local str = '258'

local ascii_str = string.pack('<H', str)
--H占2个字节 并且以小端存储，故存储的格式应该是下面的样子
-- 00000010 00000001
local str2 = string.unpack('>H',ascii_str)
print(str2)
--string.byte() 将一个ASCII字符还原回常用字符

local byte1 = ascii_str:byte(1)
--数据的低位，  输出 byte1 = 	2

local byte2 = ascii_str:byte(2)
--数据的高位 输出 byte2 = 	1

print('byte1 = ',byte1)
print('byte2 = ',byte2)

--所以，需要将 258 还原，只需要高位乘上 256 即可，即

local real_value = byte1 + byte2*256

print(real_value)
--输出 258
