local skynet=require "skynet"
local socket=require "skynet.socket"

function echo( cID,addr )
	socket.start(cID)
	while true do
		local str = socket.read(cID) --阻塞读取
		if str then
	       local cmdstr = string.gsub(str, "\r\n", "")
	       print(type(cmdstr),string.len(cmdstr),cmdstr)
	       if cmdstr == 'disconnect' then
	       	  print(type(str),str)
	       	  skynet.error("断开连接")
	       	  socket.close(cID)
		      skynet.error(addr.." disconnect")
		      return
	       end
	       socket.write(cID,string.upper(str))
		else
		   socket.close(cID)
		   skynet.error(addr.." disconnect")
		   return
		end
	end
end

function accept( cID,addr)
	skynet.error(addr .. " accepted")
	skynet.fork(echo,cID,addr)
end

skynet.start(function( ... )
	-- body
	skynet.error("启动服务")
	local addr = "0.0.0.0:9999"
	
	-- local port = 9999
	local host,port = string.match(addr,'([^:]+)%:(.*)$')
	--port = tonumber(port)
	local lID = socket.listen(host,port)
	print(type(lID),lID)
	socket.start(lID,accept)
end)