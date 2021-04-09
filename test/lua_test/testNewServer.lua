local server = require'serverobj'
require'dump'
-- print(type(server))
for k,v in pairs(server) do
	if type(v) == 'string' or type(v) == 'number' then
		print(k,v)
	else
		if type(v) == 'table' then
			print(k)
			for l,t in pairs(v) do
				print(l,t)
			end
		end
	end
end

local daodata = server:new({
	redisdb_service = {1,2,3,4,4},
	mysqldb_service = {2,2,3,4,3},
})

-- print('daodata type:',type(daodata))

for k,v in pairs(daodata) do
	if type(v) == 'string' or type(v) == 'number' then
		print(k,v)
	else
		if type(v) == 'table' then
			print(k)
			for l,t in pairs(v) do
				print(l,t)
			end
		end
	end
end

local data = {1,2,3,4,5,6,7,8,9,10}
data[#data] = nil
local r=table.remove(data,#data)
print(r)
data[#data] = nil
local r=table.remove(data,#data)
print(r)

dump(daodata,'daodata')
local str = "disconnect"
if str == "disconnect" then
   print(str)
end