CXX = g++
CXXFLAGS = -Wall -g

# Target
project6: main.o Decision.o Student.o Group.o Weather.o World.o StudentVector.o
	$(CXX) $(CXXFLAGS) -o project6 main.o Decision.o Student.o Group.o Weather.o World.o StudentVector.o

# Object files
main.o: main.cpp World.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Decision.o: Decision.cpp Decision.hpp
	$(CXX) $(CXXFLAGS) -c Decision.cpp

Student.o: Student.cpp Student.hpp Decision.hpp
	$(CXX) $(CXXFLAGS) -c Student.cpp

StudentVector.o: StudentVector.cpp StudentVector.hpp Student.hpp
	$(CXX) $(CXXFLAGS) -c StudentVector.cpp

Group.o: Group.cpp Group.hpp StudentVector.hpp
	$(CXX) $(CXXFLAGS) -c Group.cpp

Weather.o: Weather.cpp Weather.hpp
	$(CXX) $(CXXFLAGS) -c Weather.cpp

World.o: World.cpp World.hpp Group.hpp Weather.hpp
	$(CXX) $(CXXFLAGS) -c World.cpp

clean:
	rm -f *.o project6
