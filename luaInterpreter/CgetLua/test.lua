local function test()
    local o = { say = 'test'}
    setmetatable(o, { __gc = function (self) print(self.say) end })
end

test()