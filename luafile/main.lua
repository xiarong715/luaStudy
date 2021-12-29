local function test()
    local file = io.open('readme', 'rb')
    if nil == file then
        print('open failed')
    end
    local v = file:read('a')
    print(v)
end

test()