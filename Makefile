SOURCES := $(wildcard *.cpp) $(wildcard *.hpp)
OBJECTS := $(wildcard *.cpp)

main: $(SOURCES)
	g++ -W -Wall -std=c++11 -o bin/config-test $(OBJECTS)
