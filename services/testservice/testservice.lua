local skynet =require'skynet'
local os = require "os"
local cluster=require'skynet.cluster'
-- require "skynet.manager"
require"dump"

skynet.start(function( ... )

	 print("==========调用getSum")

	 -- local result = cluster.call('myservice','myservice','lua','getSum',10,20,30)
	 local myservice2 = cluster.query("myservice", "myservice")
	 print(isHave)
	 if isHave then
	 	
	 end
	 local myservice = cluster.proxy("myservice","myservice")
	 -- print(pcall(skynet.call, proxy,"getSum", 10,20,30))
	 local result = skynet.call(myservice,"lua","getSum", 10,20,30)
	 print("==========已获取getSum结果")
	 dump(result)
	 print("==========调用getMult")
	 local result = skynet.call(myservice,'lua','getMult',{parm=10,parm2=10,parm3=10})
	 print("==========已获取getMult结果")
	 dump(result)


	 
	 skynet.exit()
end)