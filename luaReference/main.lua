local nativetest = require("libNativeTest")

local cbMusic = {
    onOver = function ()
        print('lua cbMusic onOver')
    end
}

local music

local function main()
    if (not coroutine.isyieldable(coroutine.running())) then return coroutine.wrap(main)() end
    music = nativetest.create(cbMusic)
    music:play()
    music:stop()
    coroutine.yield()
end

main()
