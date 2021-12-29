local function testMetatable()
    local o = {}
    setmetatable(o, { __name = 'test metatable' })
    print(tostring(o))  --> test metatable: 0x20af680
end

testMetatable()