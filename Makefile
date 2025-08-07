EXEC = fryer

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic

$(EXEC): src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o fryer

run: $(EXEC)
	./$(EXEC)
