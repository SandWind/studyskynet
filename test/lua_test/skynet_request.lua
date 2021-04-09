local reqs = skynet.request { slave, "lua", "ping", 100 , "PING" }
for req, resp in reqs:select(10) do
	info("%s", resp[1])
end

info("Timeout : %s", reqs.timeout)