CXXFLAGS = -ldl -llua
main: main.o
	g++ -o main main.o $(CXXFLAGS)
main.o: main.cpp
	g++ -o main.o -c main.cpp $(CXXFLAGS)
clean:
	rm -rf main.o main

# g++ main.cpp -o main -ldl -llua