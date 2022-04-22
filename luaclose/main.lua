
-- 当testclose退出后，会释放close<close>变量，且是一个to-be-closed的变量，那么在close<close>变量超出其作用域时，系统会调用close<close>变量的__close元方法
-- 被标记为to-be-close变量的前提：
-- 1.这个变量是table类型
-- 2.这个变量具有（设定了）__close元方法

local function testclose()
    local close<close> = setmetatable({}, {
        __close = function ()
            print('__close')
        end
    })
end

testclose()