local filelog = require "filelog"
local print = print
local tconcat = table.concat
local tinsert = table.insert
local srep = string.rep
local type = type
local pairs = pairs
local tostring = tostring
local next = next
local json = require "cjson"

local index = {}
local mt_defaultvalue = {__index = function (t)
	return t.__
end}

local mt_monitor = {
	__index = function (t, k)
		filelog.sys_obj("tabletool", "monitor", "*access to element "..tostring(k))
		return t[index][k]
	end,

	__newindex = function (t, k, v)
		filelog.sys_obj("tabletool", "monitor", "*update to element "..tostring(k).." to "..tostring(v))
		t[index][k] = v
	end
}


local TableTool = {}

--设置默认值表
function TableTool.set_default(t, defaultvalue)
	t__ = defaultvalue
	setmetatable(t, mt_defaultvalue)
end

--监控表的访问情况
function TableTool.track(t)
	local proxy = {}
	proxy[index] = t
	setmetatable(proxy, mt_monitor)
	return proxy
end

--创建只读表
function TableTool.create_readonlytable(t)
	local proxy = {}
	local mt = {
		__index = t,
		__newindex = function (t, k, v)
			error("attempt to update a read-only table", 2)
		end
	}

	setmetatable(proxy, mt)
	return proxy
end

--判断一张表是否为空 
function TableTool.is_emptytable(t)
	if t == nil or type(t) ~= "table" then
		return false
	end
    return (_G.next( t ) == nil or TableTool.getn(t) == 0)
end

--取得hashtable的元素个数
function TableTool.getn(t)
	local count = 0
	for _, _ in pairs(t) do
		count = count + 1
	end
	return count
end

--将table转换为string
function TableTool.tostring(table)
	local cache = {  [table] = "." }
	local function _dump(t,space,name)
		local temp = {}
		for k,v in pairs(t) do
			local key = tostring(k)
			if cache[v] then
				tinsert(temp,"+" .. key .. " {" .. cache[v].."}")
			elseif type(v) == "table" then
				local new_key = name .. "." .. key
				cache[v] = new_key
				tinsert(temp,"+" .. key .. _dump(v,space .. (next(t,k) and "|" or " " ).. srep(" ",#key),new_key))
			else
				tinsert(temp,"+" .. key .. " [" .. tostring(v).."]")
			end
		end
		return tconcat(temp,"\n"..space)
	end
	return _dump(table, "","")
end

--深度copy table object
function TableTool.deepcopy(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end  -- if
        local new_table = {}
        lookup_table[object] = new_table
        for index, value in pairs(object) do
            new_table[_copy(index)] = _copy(value)
        end  -- for
        return new_table
        --return setmetatable(new_table, _copy( getmetatable(object) ))
    end  -- function _copy
    return _copy(object)
end  -- function deepcopy

--打印table
function TableTool.print_r(root)
	local cache = {  [root] = "." }
	local function _dump(t,space,name)
		local temp = {}
		for k,v in pairs(t) do
			local key = tostring(k)
			if cache[v] then
				tinsert(temp,"+" .. key .. " {" .. cache[v].."}")
			elseif type(v) == "table" then
				local new_key = name .. "." .. key
				cache[v] = new_key
				tinsert(temp,"+" .. key .. _dump(v,space .. (next(t,k) and "|" or " " ).. srep(" ",#key),new_key))
			else
				tinsert(temp,"+" .. key .. " [" .. tostring(v).."]")
			end
		end
		return tconcat(temp,"\n"..space)
	end
	print(_dump(root, "",""))
end

--删除数组table中指定的元素值
 function TableTool.remove_item(list, item, removeall)
	 local rmcount = 0
	 for i = 1, #list do
		 if list[i - rmcount] == item then
			 table.remove(list, i - rmcount)
			 if removeall then
			 	rmcount = rmcount + 1
			 else
			 	break
			 end
		 end
	 end
 end

local function writetablecontent( file, obj, index, flag )
	-- body
	local szType = type(obj)
    filelog.sys_error("----szType----", szType)
    if szType == "number" then
        file:write(obj)
    elseif szType == "string" then
        file:write(string.format("%q", obj))
    elseif szType == "table" then
        --把table的内容格式化写入文件
        index = index + 1
        local spaces = ""
        for i=1,index do
        	spaces = spaces .. " "
        end
        if flag == false then
        	file:write(spaces .. "{\n")
        else
        	file:write("{\n")
        end
        for i, v in pairs(obj) do
            if type(i) ~= "number" then
            	file:write(spaces .. " ")
            	file:write(i)
            	file:write("=")
            	writetablecontent(file, v, index, true)
            else
            	writetablecontent(file, v, index, false)
            end
            if type(v) ~= "table" then
            	file:write(", \n")
            end
        end
        if index > 1 then
        	file:write(spaces .. "},\n")
        else
        	file:write(spaces .. "}\n")
        end
    else
      	filelog.sys_error("can't serialize a "..szType)
    end
    if index > 1 then
    	index = index - 1
    end
end



function TableTool.savetablecontent(filename, obj)
	if filename == nil or obj == nil then return end
	local file = io.open(filename, "w+")
    if not file then return end
    local index = 0
    local flag = false
    file:write("return \n")
    writetablecontent(file, obj, index, flag)

    file:close()
end


--序列化table用于传参
function TableTool.serialize(t)
	return json.encode(t)
end


--将table序列化之后的子串反序列化为table
function TableTool.deserialize(...)
	return json.decode(...)
end

--打乱数组类型的table
function TableTool.random_table( t )
    if type(t)~="table" then
        return
    end
    local l=#t
    local tab={}
    local index=1
    while #t~=0 do
        local n=math.random(0,#t)
        if t[n]~=nil then
            tab[index]=t[n]
            table.remove(t,n)
            index=index+1
        end
    end
    return tab
end

--slot图标打印
function TableTool.sloticontostring(iconlisttable)
	if not iconlisttable then
		return nil
	end

	local cache = ""
	for k,iconlist in ipairs(iconlisttable) do
		local tmpstr = "("
		for i ,v in ipairs(iconlist) do
			tmpstr = tmpstr .. tostring(v) .. (next(iconlist,i) and "|" or "" )
		end
		tmpstr = tmpstr .. ")"
		cache = cache .. tmpstr
	end
	return cache
end

--cards是数字
function TableTool.cardstostring(cards)
	if not cards then
		return nil
	end

	local tmpstr = ""
	for i ,v in ipairs(cards) do
		tmpstr = tmpstr .. tostring(v) .. (next(cards,i) and "|" or "" )
	end
	return tmpstr
end

--红黑的牌转换成字符串
function TableTool.redbcardstostring(cards)
	if not cards then
		return nil
	end

	local tmpstr = ""
	for i ,v in ipairs(cards) do
		local cardstr = (v.card_type - 1 ) * 13 + v.card_value 
		tmpstr = tmpstr .. tostring(cardstr) .. (next(cards,i) and "|" or "" )
	end
	return tmpstr
end

--糖果派对图标打印
function TableTool.fruitpartyicontostring(iconlisttable)
	if not iconlisttable then
		return nil
	end

	local allicon = ""
	local lineinfo = ""
	for k,icon in ipairs(iconlisttable) do
		local tmpstr = "("
		for i ,v in ipairs(icon.iconlist) do
			tmpstr = tmpstr .. tostring(v) .. (next(icon.iconlist,i) and "|" or "" )
		end
		tmpstr = tmpstr .. ")"
		allicon = allicon .. tmpstr

		tmpstr = ""
		if #icon.scorelineinfolist > 0 then
			tmpstr = "("
			for i ,v in ipairs(icon.scorelineinfolist) do
				local str = tostring(icon.iconlist[v.indexlist[1]]) .. "|".. #v.indexlist .. "|"..v.multiply
				tmpstr = tmpstr .. str .. (next(icon.scorelineinfolist,i) and "|" or "" )
			end
			tmpstr = tmpstr .. ")"
		end
		lineinfo = lineinfo .. tmpstr	
	end
	return allicon,lineinfo
end

function TableTool.slotmarytostring(icondesc,iconlist)
	if not icondesc or not  iconlist or not icondesc.cnt or not icondesc.icon or not icondesc.multiply or #iconlist ~= 4 then
		return nil
	end

	local tmpstr = "(" .. tostring(icondesc.icon) .. "|" .. tostring(icondesc.multiply) .. "||" .. tostring(iconlist[1]) .."|".. tostring(iconlist[2]).."|".. tostring(iconlist[3]).. "|" .. tostring(iconlist[4]) .. ")"
	return tmpstr
end

function TableTool.serialicontostring(gemlist,clearlist)
	if not gemlist then
		return nil
	end

	local allicon = ""
	local lineinfo = ""

	for k,icon in ipairs(gemlist) do
		local tmpstr = "("
		for i ,v in ipairs(icon.gemid) do
			tmpstr = tmpstr .. tostring(v) .. (next(icon.gemid,i) and "|" or "" )
		end
		tmpstr = tmpstr .. ")"
		allicon = allicon .. tmpstr
	end

	for i, clearinfo in ipairs(clearlist) do
		local tmpstr = "(" .. tostring(clearinfo.gemid) .. "|".. #clearinfo.positon .. "|"..clearinfo.score ..")"
		lineinfo = lineinfo .. tmpstr	
	end
	return allicon,lineinfo
end



return TableTool



