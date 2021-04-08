local skynet = require"skynet"
local  fd = ...
skynet.start(function( ... )
	
	skynet.call("gated111","lua","kick",fd)
end)