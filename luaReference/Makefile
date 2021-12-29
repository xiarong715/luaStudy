CCFLAG = -std=c++11 -shared -fPIC -Wall
libNativeTest.so: nativeTest.o music.o
	g++ -o libNativeTest.so nativeTest.o music.o $(CCFLAG)
nativeTest.o: NativeTest.cpp
	g++ -o nativeTest.o -c NativeTest.cpp $(CCFLAG)
music.o: music.cpp
	g++ -o music.o -c music.cpp $(CCFLAG)
clean:
	rm -rf nativeTest.o music.o libNativeTest.so