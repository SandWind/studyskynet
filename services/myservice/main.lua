local skynet =require'skynet'
local os = require "os"
local cluster = require'skynet.cluster'
require "skynet.manager"
require"dump"

skynet.start(function( ... )
	 local param ={}
	 -- print(type(SERVICE_NAME))
	 -- if type(SERVICE_NAME) =="string "then
	 --  	print('SERVICE_NAME: '..SERVICE_NAME)
	 -- end
	 dump(SERVICE_NAME,"SERVICE_NAME")
	  
	 param.s1 = '学习传入参数'
	 param.s2 = 2021
	 param.mywork = 'new world'
	 local myparam = {}
	 myparam.time = os.time()
	 myparam.title = "传入时间戳"
	 -- 传入参数不能是table,而是其他基本参数（string,number）
	 local watchdog = skynet.newservice("myservice","start",10,20,30,40,50,60,70,80)
	 -- local watchdog = skynet.uniqueservice("myservice","start",10,20,30,40,50,60,70,80)
	 local params = ",,,,,"..skynet.getenv("svr_name") 
	 dump(params,"参数")
	 dump(watchdog,"服务========")
	 skynet.call(watchdog,'lua',"start",myparam)
	 skynet.send(watchdog,'lua',"work",params)
	 cluster.register("myservice", watchdog)
	 cluster.open(2090)
	 skynet.exit()

end)