CXX = g++

CXXFLAGS = -Wall -g

HEADERS = astronauta.hpp cemiterio.hpp voo.hpp

SOURCES = main.cpp astronauta.cpp cemiterio.cpp voo.cpp

OBJECTS = main.o astronauta.o cemiterio.o voo.o

EXECUTABLE = comandodevoo

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

astronauta.o: astronauta.cpp astronauta.hpp
	$(CXX) $(CXXFLAGS) -c astronauta.cpp

cemiterio.o: cemiterio.cpp cemiterio.hpp
	$(CXX) $(CXXFLAGS) -c cemiterio.cpp

voo.o: voo.cpp voo.hpp
	$(CXX) $(CXXFLAGS) -c voo.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: clean
