编动态链接库：
    g++ -fPIC -shared main.cpp -o libNativeTest.so
运行lua脚本：
    lua main.lua // require 'libNativeTest'时，会加载libNativeTest.so，且lua会在动态链接库中寻找luaopen_libNativeTest函数，找到后加载动态链接库并执行luaopen_libNativeTest函数；luaopen_libNativeTest函数在lua表中注册功能函数并返回该表；
    