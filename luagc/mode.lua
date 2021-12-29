local mod = { name = 'mod'}

function mod:buy()  -- local func
    print(self.name ..  ': ' .. 'buy')
end

function mod:say()  -- local func
    print(self.name ..  ': ' .. 'say')
end

function gSay(str)  -- global func
    print(str)
end

return mod