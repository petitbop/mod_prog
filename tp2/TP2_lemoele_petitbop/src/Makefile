# Source Makefile

EXEC 	=	test
SRC 	=	$(wildcard *.cpp)
OBJ 	=	$(SRC:%.cpp=%.o)
HEAD 	=	$(wildcard *.h)

CXX 		=	g++
CXXFLAGS 	=	-Wall -Wextra -g 

# Generating all executable files
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(CXXFLAGS) $^

$(SRCFILE)/%.o: ($SRCFILE)/%.cpp ($SRCFILE)/%.h
	$(CXX) -o $@ $(CXXFLAGS) -c $< 

# Executing all executable files
check: 
	./$(EXEC)

# Cleaning all built files
clean:
	rm -f *.o
	rm -f $(EXEC)

