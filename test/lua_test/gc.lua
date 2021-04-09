local meta =
{
	__gc = function(self)
 		print("destroying self: " .. self.name)
 	end
}
local t = setmetatable({ name = "outer" }, meta)
do
 local t = { name = "inner" }
 setmetatable(t, meta)
end
print("program exit")