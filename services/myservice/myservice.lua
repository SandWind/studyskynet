local skynet =require'skynet'
require 'dump'
local param1,param2,param3,param4,param5,param6 = ...
local CMD = {}
if type(param1) == 'string' then
   print("==========",param1)
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
end



skynet.start(function( ... )
	skynet.dispatch("lua", function(session, source, cmd, ...)
        local f = assert(CMD[cmd], cmd .. "not found")
        skynet.retpack(f(...))
    end)	 
end)