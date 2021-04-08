local skynet= require"skynet"
skynet.start(function( ... )
	local kick = skynet.newservice("kick",2)
	skynet.exit()
end)