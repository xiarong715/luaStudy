#!/usr/local/bin/lua

local function testWeakRef() 
    local mt = { __mode = 'k'}
    local a = {}
    setmetatable(a, mt)
    
    local key = {} -- strong reference
    a[key] = 1  -- weak reference， 用表的键引用表
    key = {} -- 重新引用一个新表，key原来引用的表只剩下一个弱引用
    a[key] = 2
    
    collectgarbage()  -- 垃圾回收，回收没有引用或只有弱引用的对象
    
    for k, v in pairs(a) do
        print(v)  --> 2
    end
end

local function testWeakRef2()
    local mt = { __mode = 'v'}
    local a = {}
    setmetatable(a, mt)
    local value = {}
    a.one = value  -- 弱引用value引用的对象
    value = {}     -- value重新引用一对象，之前引用的对象只剩下弱引用
    a.two = value  -- value目前引用的的对象，有一个强引用和一个弱引用

    collectgarbage()
    for k, v in pairs(a) do
        print(k)  --> two
    end
end

local function testWeakRef3()
    local mt = { __mode = 'kv' }
    local a = {}
    setmetatable(a, mt)
    local key = {}
    local value = {}
    a[key] = 1 -- 键弱引用
    key = {}
    a[key] = 2
    a.one = value -- 值弱引用
    value = {}
    a.two = value

    collectgarbage()

    for k, v in pairs(a) do
        print(tostring(k) .. ' > ' .. tostring(v))
    end
end

testWeakRef()
print('-----------------------------')
testWeakRef2()
print('-----------------------------')
testWeakRef3()
print('-----------------------------')