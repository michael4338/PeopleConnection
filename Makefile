
MODE = OPT
CFLAGS = -g -O2 -Wall

ifeq "$(MODE)" "DEBUG"
	CFLAGS = -g
endif

################################################################################
#Edit these values to change the name of the executible and the source files
EXE = test 
SRC = main.cpp DataProvider.cpp Graphic.cpp
#LIBS =
################################################################################

CXX = g++
CXXFLAGS = $(CFLAGS) $(INCLUDES)

OBJS = $(addsuffix .o, $(basename $(SRC)))

all : $(EXE)

$(EXE) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

clean :
	rm -f $(OBJS) $(EXE)

