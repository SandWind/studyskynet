local skynet =require'skynet'

skynet.start(function( ... )
	 local param ={}
	 print(type(SERVICE_NAME))
	 if type(SERVICE_NAME) then
	  	print('SERVICE_NAME: '..SERVICE_NAME)
	 end
	  
	 param.s1 = '学习传入参数'
	 param.s2 = 2021
	 param.mywork = 'new world'
	 local myservice = newservice("myservice",param)
	 local watchdog = skynet.call(watchdog,'lua',start)
	 skynet.exit()
end)