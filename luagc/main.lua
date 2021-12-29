#!/usr/local/bin/lua

local modTest = require('mode')

local function testGC()
    local o = {say = 'hi local'}   -- 局部变量会在函数结束后，被标记为垃圾
    setmetatable(o, { __gc = function (self) print(self.say) end })
    -- o = nil
end

local function testGC2()
    obj = {say = 'hi global'}  -- 全局变量obj
    setmetatable(obj, { __gc = function (self) print(self.say) end} )
    obj = nil -- 全局变量手动标记为垃圾
end

local function testGC3()
    local list = nil
    local mt = { __gc = function (self) print(self[1]) end }
    for i = 1, 3 do
        list = setmetatable({i, link = list}, mt)
    end
end

-- 没有手动赋nil的全局变量，会在lua环境（本lua文件）结束时，被标记为垃圾，最后被回收

testGC()
testGC2()
testGC3()
collectgarbage()  -- 手动回收垃圾

modTest:buy()
modTest:say()
gSay('gSay')

-- while true do
    
-- end