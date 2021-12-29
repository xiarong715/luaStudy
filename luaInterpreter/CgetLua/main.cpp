// 一个简章的独立解释器
#include <stdio.h>
#include <string.h>
extern "C" {
    #include "lua.hpp"
    #include "lauxlib.h"
    #include "lualib.h"
}

int main(void) {
    char buf[256];
    int error;
    lua_State *L = luaL_newstate(); /* 打开lua */
    luaL_openlibs(L); /* 打开标准库 */ 
    
    // 手动输入lua代码，并执行
    // while(fgets(buf, sizeof(buf), stdin) != NULL) {  // 获取 lua str
    //     // load lua str and call lua str
    //     error = luaL_loadstring(L, buf) || lua_pcall(L, 0, 0, 0);
    //     if (error) {
    //         fprintf(stderr, "%s\n", lua_tostring(L, -1));
    //         lua_pop(L, 1); // 从栈中弹出错误信息
    //     }
    // }

    // 加载lua文件并执行
    error = luaL_loadfile(L, "test.lua") || lua_pcall(L, 0, 0, 0);
    if (error) {
        fprintf(stderr, "%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
    
    lua_close(L);
    return 0;
}