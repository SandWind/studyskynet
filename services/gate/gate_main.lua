local skynet = require"skynet"

skynet.start(function( ... )
	skynet.error("gate service start")
	local gateserver = skynet.newservice("mygate")
	skynet.call(gateserver,"lua","open",{
		port = 10002,
		maxclient = 220,
		nodelay = true,
	})
	skynet.error("gate launch on 10002")
end)