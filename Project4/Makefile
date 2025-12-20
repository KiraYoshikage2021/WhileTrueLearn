CXX = g++
CXXFLAGS = -Wall -g


TARGET = project4


OBJS = main.o Computing.o Experiment.o


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


main.o: main.cpp Experiment.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Computing.o: Computing.cpp Computing.hpp
	$(CXX) $(CXXFLAGS) -c Computing.cpp

Experiment.o: Experiment.cpp Experiment.hpp Computing.hpp
	$(CXX) $(CXXFLAGS) -c Experiment.cpp

clean:
	rm -f *.o $(TARGET)
