local skynet = require"skynet"
local gateserver = require "snax.gateserver"
local netpack = require"skynet.netpack"
local socketdriver = require "skynet.socketdriver"
require "skynet.manager"
local proto = require "protoc"
local pb = require"pb"
-- local lfs = require"lfs"
local  handler = {}
local CMD = {}
require"dump"

local proto_path_result =skynet.getenv("protopath").."result.proto"
local proto_path_mobile =skynet.getenv("protopath").."moblie.proto"

prbf = proto.new()

prbf:loadfile(proto_path_mobile)
function handler.connect( fd,ipaddr )
	skynet.error("ipaddr: "..ipaddr,type(fd),"fd: "..fd,"connect")
	gateserver.openclient(fd)

end

function handler.disconnet(fd)
	skynet.error("fd: "..fd.." disconnet")
	gateserver.closeclient(fd)
end

function handler.message( fd,msg,sz)
	skynet.error("rev message fom fd: "..fd)
	local cmdstr = netpack.tostring(msg,sz)
	-- cmdstr = string.gsub(cmdstr, "\r", "")
	-- cmdstr = string.gsub(cmdstr, "\n", "")
	-- dump(cmdstr)
	-- skynet.error("message",cmdstr)
	cmdstr = string.sub(cmdstr,3,-1)
	-- print(cmdstr)
	-- local mobile =  pb.decode("mycell.moblie.moblie",cmdstr)
	-- dump(moblie)
	prbf:loadfile(proto_path_result)
	local ret = {
		status = 1,
		desc = '已收到数据包'
	}
	ret = pb.encode("Result",ret)
	-- local ret = "ok"
	socketdriver.send(fd,ret)
	--socket.write(fd,"OK")
	-- skynet.call("gated111","lua","kick",fd)
	-- print(type(skynet.self()),skynet.self())

	if cmdstr == 'disconnect' then
	   skynet.error("断开服务器")
	   gateserver.closeclient(fd)
	end
end

function handler.open(source, conf)
	skynet.error("open by====== ",skynet.address(source),type(source),source)
	skynet.error("listen on========", conf.port)
	skynet.error("client max======", conf.maxclient)
	skynet.error("nodelay=========", conf.nodelay)
end

function CMD.kick(source,fd)
	gateserver.closeclient(fd)
end

function handler.command( cmd,source,...)
	local  f =assert(CMD[cmd])
	return pcall(f,source,...) 
end


skynet.register("gated111")
print("服务注册名字")
gateserver.start(handler)
