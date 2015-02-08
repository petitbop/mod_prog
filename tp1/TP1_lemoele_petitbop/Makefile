# General Makefile

SRCFILE	= ./src
DOCFILE = ./doc

EXEC 	=	$(SRCFILE)/test
SRC 	=	$(wildcard $(SRCFILE)/*.cpp)
OBJ 	=	$(SRC:$(SRCFILE)/%.cpp=$(SRCFILE)/%.o)
HEAD 	=	$(wildcard $(SRCFILE)/*.h)

CXX 	=	g++
CFLAGS 	=	-Wall -Wextra -g 

# Generating all executable files
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(CFLAGS) $^

$(SRCFILE)/%.o: ($SRCFILE)/%.cpp ($SRCFILE)/%.h
	$(CXX) -o $@ $(CFLAGS) -c $< 

# Executing all executable files
check: 
	$(EXEC)

# Building of the doxygen documentation.
doc:
	doxygen docs/doxyfilerc
	echo "To open the documentation, type : "
	echo "		firefox html/index.html "
	echo "in your terminal." 

# Cleaning all built files
clean:
	rm -f $(SRCFILE)/*.o
	rm -f $(EXEC)
	rm -rf $(DOCFILE)/html
