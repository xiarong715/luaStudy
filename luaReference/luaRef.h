#include <iostream>
#include <memory>
#include <thread>
#include <assert.h>

extern "C" {
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
}

// bind metatable to userdata
// save cb to registry
template<typename T>
int luaPushRef(lua_State *L, const std::shared_ptr<T> &w, int idCbTable) {
    std::cout << "luaPushRef" << std::endl;
    lua_pushvalue(L, idCbTable);
    auto id = luaL_ref(L, LUA_REGISTRYINDEX);
    std::shared_ptr<T> *u = static_cast<std::shared_ptr<T> *>(lua_newuserdatauv(L, sizeof(std::shared_ptr<T>), 1));
    *u = std::shared_ptr<T>(w);
    if (luaL_getmetatable(L, T::LuaMetaName) != LUA_TTABLE) {
        lua_pop(L, 1); // pop 1 elements from the stack
        throw std::runtime_error("get meta table error");
    }
    lua_setmetatable(L, -2);
    return id;
}

void luaPushCbAndTable(lua_State *L, int idCbTable, const char *funcName) {
    if (lua_rawgeti(L, LUA_REGISTRYINDEX, idCbTable) != LUA_TTABLE) { throw std::runtime_error("get cb table error");}
    // lua_pushstring(L, funcName);
    lua_getfield(L, -1, funcName);
}
// 