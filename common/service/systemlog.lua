local skynet = require "skynet"
local tabletool = require "tabletool"
local timetool = require "timetool"
local base = require "base"
require "skynet.manager"
local CMD = {}


local filemap = {}
local function get_file_name(dirname, filename)
     ----- 日志分日期存储------
    local path = skynet.getenv("logpath")
    if path == nil then
    	path = "."
    end
    if dirname == nil then
 		dirname = "."
 	end

    local current_time = os.date("%Y_%m_%d", timetool.get_time())
    local log_path = path.."/"..current_time.."/"..dirname
    local current_file_name = log_path.."/"..filename
    if not base.is_file_exist(log_path) then
        os.execute("mkdir -p "..log_path)
    end
    return current_file_name
end

local function clear_log(file)


    local fileinfo = filemap[file]
    if not fileinfo then 
        fileinfo = {}
        fileinfo.filehandle = io.open(file, "w")
        filemap[file] = fileinfo
    else
        local filehandle = fileinfo.filehandle
        filehandle:close()
        fileinfo.filehandle = io.open(file, "w")
    end

	local f = fileinfo.filehandle
	if f ~= nil then
		f:write("")
		f:close()
	end
    filemap[file] = nil 
end

local function write_log(file, ...)

    local fileinfo = filemap[file]
    if not fileinfo then 
        fileinfo = {}
        fileinfo.filehandle = io.open(file, "a+")
        filemap[file] = fileinfo
    end
    fileinfo.writetime = timetool.get_time()
    local f = fileinfo.filehandle
    if f ~= nil then
        fileinfo.hasdata = true
        f:write("-------------["..os.date("%Y-%m-%d %X", timetool.get_time()).."]--------------\n")
        local arg = table.pack(...)
        if arg ~= nil then
            for key, value in pairs(arg) do
                if key ~= "n" then
                    if type(value) ~= "table" then
                        f:write(tostring(value).."\n")                
                    else
                        local str = tabletool.tostring(value)
                        f:write(str.."\n")                
                    end
                end 
            end
        end
        --f:close()
    end	
end

local function write_protomsg_log(file, msgname, ...)
    local fileinfo = filemap[file]
    if not fileinfo then 
        fileinfo = {}
        fileinfo.filehandle = io.open(file, "a+")
        filemap[file] = fileinfo
    end
    fileinfo.writetime = timetool.get_time()
    local f = fileinfo.filehandle
    if f ~= nil then
        fileinfo.hasdata = true
        f:write("["..os.date("%Y-%m-%d %X", timetool.get_time()).."] msgname: "..msgname.."\n")
        local arg = table.pack(...)
        if arg ~= nil then
            for key, value in pairs(arg) do
                if key ~= "n" then
                    if type(value) ~= "table" then
                        f:write(tostring(value).."\n")                
                    else
                        local str = tabletool.tostring(value)
                        f:write(str.."\n")                
                    end
                end 
            end
        end
        --f:close()
    end     
end

local function load_config()
end

function CMD.error(...)
   local file = get_file_name(".", "error.log")
   write_log(file, ...)
end

function CMD.info(...)
    local file = get_file_name(".", "info.log")
    write_log(file, ...)
end

function CMD.warning(...)
    local file = get_file_name(".", "warning.log")
    write_log(file, ...)
end

function CMD.protomsg(msgname, ...)
    local file = get_file_name(".", "protomsg.log")
    local param = {...}
    if #param >=2 and param[2] == "clientmsg" then
        return 
    end
    write_protomsg_log(file, msgname, ...)
end

function CMD.obj(objname, objid, ...)
	if objname == nil then
		objname = "."
	end
	if objid == nil then
		objid = "unknow"
	end
    local file = get_file_name(objname, objid..".log")
    write_log(file, ...)
end

function CMD.reload(...)
    load_config()
end

function CMD.exit(...)
    skynet.exit()
end

function CMD.start( ... )
    load_config()
end

skynet.dispatch("lua", function(_, address,  cmd, ...)
	    local f = CMD[cmd]
		if f ~= nil then
            f(...)
        end
end)
skynet.start(function()
    CMD.start()
    skynet.register ".systemlog"
end)


skynet.fork(function ()
    while true do
        skynet.sleep(300)
        local nowtime = timetool.get_time()
        for filename,fileinfo in pairs(filemap) do
            local filehandle = fileinfo.filehandle
            if fileinfo.hasdata then
                fileinfo.hasdata = false
                filehandle:flush()
            elseif fileinfo.writetime + 3600 < nowtime then
                filehandle:close()
                filemap[filename] = nil
            end
        end
    end
end)