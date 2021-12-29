#include "music.h"

#include "luaRef.h"

std::thread::id mainThreadID = std::this_thread::get_id();

class TestWrapper : public Music::Callback {
    int idCbRef;
    std::shared_ptr<Music> music;
    static lua_State *lua;
    static int userdataTableRef;
   public:
    const static char * const LuaMetaName;
    static int create(lua_State *L) {
        std::cout << "TestWrapper::create" << std::endl;
        lua = L;
        auto w = std::make_shared<TestWrapper>();
        w->music = std::make_shared<Music>();
        w->music->setCallback(w);
        // get and bind meta table
        w->idCbRef = luaPushRef(L, w, 1);
        return 1;
    }
    static int play(lua_State *L) {
        auto w = (TestWrapper *)lua_touserdata(L, 1);
        w->music->play();
        return 0;
    }
    static int stop(lua_State *L) {
        auto w = (TestWrapper *)lua_touserdata(L, 1);
        w->music->stop();
        return 0;
    }
    void onOver() {
        std::cout << "onOver" << std::endl;
        assert(mainThreadID == std::this_thread::get_id());
        std::cout << "c++ onOver" << std::endl;
        luaPushCbAndTable(lua, idCbRef, "onOver");
        lua_call(lua, 0, 0);
    }
    TestWrapper() : idCbRef(LUA_REFNIL) {}
    ~TestWrapper() { std::cout << "TestWrapper::~TestWrapper()" << std::endl; }
};
const char * const TestWrapper::LuaMetaName = "music";
lua_State * TestWrapper::lua = NULL;

static const luaL_Reg lib_nativetest_F[] = {
    {"create", TestWrapper::create},
    {nullptr, nullptr},
};

static const luaL_Reg lib_nativetest_M[] = {
    {"play", TestWrapper::play},
    {"stop", TestWrapper::stop},
    {nullptr, nullptr},
};

extern "C" {
int luaopen_libNativeTest(lua_State *L) {
    std::cout << "luaopen_libNativeTest" << std::endl;
    // register table in registry
    if (!luaL_newmetatable(L, TestWrapper::LuaMetaName)) std::cout << "new metatable error" << std::endl;
    luaL_setfuncs(L, lib_nativetest_M, 0);
    lua_setfield(L, -1, "__index");
    luaL_newlib(L, lib_nativetest_F);
    return 1;
}
}