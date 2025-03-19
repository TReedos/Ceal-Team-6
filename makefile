CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
#LDFLAGS = -lstdc++

.PHONY: clean test

all: wordle test

wordle: engine.o
	@echo "Building wordle"
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o wordle engine.o

engine.o: wordleGameEngine.cpp
	@echo "Compiling wordleGameEngine.cpp to engine.o"
	$(CXX) $(CXXFLAGS) -c wordleGameEngine.cpp -o engine.o

test: test.o
	@echo "Building test"
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o test test.o

test.o: wordleGameEngineTest.cpp
	@echo "Compiling wordleGameEngineTest.cpp to test.o"
	$(CXX) $(CXXFLAGS) -c wordleGameEngineTest.cpp -o test.o

run:
	./wordle

clean:
	rm -f *.o wordle test