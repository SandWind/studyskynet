local pack =string.pack
local unpack = string.unpack
local t = {'=============12321323','2323','311===','===4'}
local k1 = {}
print(table.unpack(t))

local function funcpp(a)
    return a, a + 1, a + 2,a+3
end

local ret =  {funcpp(4)}
print(#ret)
print(#{funcpp(4)})


require"dump"
function strsplit(str, delim)
  if type(delim) ~= "string" or string.len(delim) <= 0 then
    return
  end 
  local start = 1
  local t = {}
  while true do
  local pos = string.find (str, delim, start, true) -- plain find
    if not pos then
     break
    end
    table.insert (t, string.sub (str, start, pos - 1))
    start = pos + string.len (delim)
  end
  table.insert (t, string.sub (str, start))
  return t
end

local nodecfg = "192.168.29.147:3002"

local t= strsplit(nodecfg,":")
print(#t)
dump(t)

-- local host, port = string.match(nodecfg, "([^:]+):(.*)$")

local host, port = string.match(nodecfg, ":(.*)$")
print(host,port)

print(string.find(nodecfg,'([^:]+)'))
print(string.find(nodecfg,':(.*)$'))

local teststr1 = "123?2132?13.0213?21.301321?3213"
print("teststr1 len： ",string.len(teststr1))
--print(string.find(teststr1,'%a.%a.%a'))
--[^?]除?号外的字符
print(string.match(teststr1, "([^?]+)%?([^?]+)%?([^?]+)%?([^?]+)%?"))

local tab = {"a", "c", "d", "b"}

local t1 = table.concat( tab, ", ", 1, #tab )

dump(tab)
print("t1 of type ",type(t1))
dump(t1)

local content = '{"LoginInfo":{"Name":"cxn8801","Pwd":"123abc"}}'
local data = string.char(math.floor(string.len(content)/128)) .. string.char(string.len(content)%128) .. content
print(data)

local pack_str = "12345621323"
local packedstr = pack(">s",pack_str)
print(type(packedstr),string.len(packedstr),packedstr)
local upack_str = unpack(">s1",packedstr)
print(type(upack_str),upack_str)
print(type(pack_str),pack_str)
if pack_str == upack_str then
   print("解包成功")
end

local teststr2 = '1111disconnect'
print(#teststr2)

local btyestr = string.sub(teststr2,5,-1)
print(btyestr)
