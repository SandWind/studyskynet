
Window = {}
Window.prototype = {x = 0 ,y = 0 ,width = 100 ,height = 100,}
Window.mt = {}
function Window.new(o)
	setmetatable(o ,Window.mt)
	return o
end
Window.mt.__index = function (t ,key)
	return 1000
end
Window.mt.__newindex = function (table ,key ,value)
	print(key)
	-- table.key = "yes,i am"
	rawset(table,key,"yes,i am")
end
w = Window.new{x = 10 ,y = 20}
w.wangbin = "55"
print("wangbin",w.wangbin)
w.wangbin ="100"
print("wangbin",w.wangbin)
print(w.oooooooooooooo)
w.oooooooooooooo = 100
print(w.oooooooooooooo)
