-- mytable = setmetatable({key1 = "value1"}, { __index = { key2 = "metatablevalue" } })
-- print(mytable.key1,mytable.key2)


mytable = setmetatable({key1 = "value1"}, {
  __index = function(mytable, key)
    if key == "key3" then
      return "metatablevalue"
    else
      return nil
    end
  end
})
--mytable.后跟的key参数做形参传入到 function中计算后返回结果


print(mytable.key1,mytable.key2,mytable.key3)
--__newindex 元方法用来对表更新，__index则用来对表访问 。