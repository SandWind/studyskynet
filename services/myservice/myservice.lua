local skynet =require'skynet'
require "skynet.manager"
local cluster = require'skynet.cluster'
require 'dump'

local param1,param2,param3,param4,param5,param6 = ...
local CMD = {}
if type(param1) == 'string' then
   print("==========",param1,param2,param3,param4,param5,param6)
end


local function serviceName( ... )
	
	local name = skynet.getenv("svr_name")
	dump(name)
	skynet.register(name)
end

function CMD.work( workparam )
	dump(workparam,"传入work的参数")
end

function CMD.start( startParam )
	dump(param1,"param1")
	dump(param2,"param2")
	dump(param3,"param3")
	dump(param4,"param5")
	dump(param5,"param6")
	dump(startParam,"传start的参数")
	-- local testservice = skynet.newservice("testservice")
end

function CMD.getSum( ... )
	local param1,param2,param3 = ...
	local result = {}
	result.status = 'ok'
    result.sum = param1+param2+param3
    return result
end

function CMD.getMult( ... )
	local parm = ...
	local result = {}
	result.multi = 1
	for k,v in pairs(parm) do
		result.multi = result.multi * v
	end
	result.status = 'ok'
	dump(result)
	return result
end



skynet.dispatch("lua", function(session, source, cmd, ...)
    local f = assert(CMD[cmd], cmd .. "not found")
    skynet.retpack(f(...))
end)

skynet.start(function( ... )
	  serviceName()
end)