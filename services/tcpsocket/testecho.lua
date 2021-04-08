local skynet =require'skynet'
local os = require "os"
local cluster=require'skynet.cluster'
-- require "skynet.manager"
require"dump"

skynet.start(function( ... )
	local echo = skynet.newservice("socketecho","start") 
	 skynet.exit()
end)