CXXFLAGS = -fPIC -shared
libNativeTest.so: main.o
	g++ -o libNativeTest.so $(CXXFLAGS) main.o
main.o: main.cpp
	g++ -o main.o $(CXXFLAGS) -c main.cpp
clean:
	rm -rf main.o libNativeTest.so

	
# g++ -fPIC -shared main.cpp -o libNativeTest.so