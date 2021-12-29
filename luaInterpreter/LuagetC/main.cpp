#include <stdio.h>
extern "C" {
    #include "lua.hpp"
    #include "lauxlib.h"
    #include "lualib.h"
}

static int helloWorld(lua_State *L) {
    lua_pushstring(L, "hello world");
    return 1;
}

static const struct luaL_Reg libF[] = {
    {"helloWorld", helloWorld},
    {NULL, NULL},
};

extern "C" {
    int luaopen_libNativeTest(lua_State *L) {
        printf("load dynamic library start\n");
        lua_createtable(L, 0, sizeof(libF)/sizeof(luaL_Reg));
        luaL_setfuncs(L, libF, 0);
        // lua_setfield(L, -1, "NativeTest"); // 如何用 ？？
        // luaL_newlib(L, libF); // 单个调用good
        // luaL_register(L, "NativeTest", libF); // NativeTest 为模块名 // 废弃
        printf("load dynamic library end\n");
        return 1;
    }
}