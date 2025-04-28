CXX = g++
CXXFLAGS = -g -Wall

all: divideByZero stackOverFlow undefinedMemory

undefinedMemory: undefinedMemory.cpp
	$(CXX) $(CXXFLAGS) -o undefinedMemory undefinedMemory.cpp

stackOverFlow: stackOverFlow.cpp
	$(CXX) $(CXXFLAGS) -o stackOverFlow stackOverFlow.cpp

divideByZero: divideByZero.cpp
	$(CXX) $(CXXFLAGS) -o divideByZero divideByZero.cpp

clean:
	rm -f undefinedMemory stackOverFlow divideByZero core*
