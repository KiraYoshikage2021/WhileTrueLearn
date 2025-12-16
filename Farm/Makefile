CXX = g++
CXXFLAGS = -Wall -g

# Object files (compiled from .cpp)
OBJS = main.o Game.o Gui.o Item.o Animal.o Grass.o Rabbit.o Predator.o Wolf.o Tiger.o

# Target
farm: $(OBJS)
	$(CXX) $(CXXFLAGS) -o farm $(OBJS)

# Compile rules (Updated dependencies to .hpp and sources to .cpp)
main.o: main.cpp Game.hpp Gui.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: Game.cpp Game.hpp Rabbit.hpp Wolf.hpp Tiger.hpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Gui.o: Gui.cpp Gui.hpp Game.hpp
	$(CXX) $(CXXFLAGS) -c Gui.cpp

Item.o: Item.cpp Item.hpp
	$(CXX) $(CXXFLAGS) -c Item.cpp

Animal.o: Animal.cpp Animal.hpp Item.hpp
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Grass.o: Grass.cpp Grass.hpp Item.hpp
	$(CXX) $(CXXFLAGS) -c Grass.cpp

Rabbit.o: Rabbit.cpp Rabbit.hpp Animal.hpp
	$(CXX) $(CXXFLAGS) -c Rabbit.cpp

Predator.o: Predator.cpp Predator.hpp Animal.hpp
	$(CXX) $(CXXFLAGS) -c Predator.cpp

Wolf.o: Wolf.cpp Wolf.hpp Predator.hpp
	$(CXX) $(CXXFLAGS) -c Wolf.cpp

Tiger.o: Tiger.cpp Tiger.hpp Predator.hpp
	$(CXX) $(CXXFLAGS) -c Tiger.cpp

clean:
	rm -f *.o farm
