local ServerBase = {
	gate_service = 'gate_service',
	service_manager = {},
	netpack = 'netpack',
	socket = 'socket',
	tcpmng = 'tcpmng',
	eventmng = 'eventmng',
	last_heart_time = 0,
	client_fd = 'client_fd',
	isoffline = true,
	marquee_index = 0,
	protocol_key = '11200029298282727',

	isenteringtableormatch = false, --是否正在进入桌子或是比赛
	enteringtableormatchtime = 0, 
}



function ServerBase:new(obj)
    obj = obj or {}
    setmetatable(obj, self)
    self.__index = self
    self.__newindex = self
    return obj
end


return ServerBase