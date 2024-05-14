CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./lcs -I./scs -I./trie

# Define the executable file
EXEC = lcs_scs

# Define source files
SOURCES = main.cpp lcs/lcs.cpp scs/scs.cpp trie/trie.cpp

# Define object files based on the source files
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean
