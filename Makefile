# Easy Sockets Makefile Shared Library v 1.0
# ********************************1. VARIABLES SECTION*********************************
# 1 C/C++ Compiler
CXX = GCC
# 2. Compiler Keys (man gcc)
CXXFLAGS = -Wall -g
C99_LANG = -std=C99
CPP_03_LANG = -std=C++03
SHARED = -shared
# todo: Add other cpp and c standards
# 3. Linking libraries
LIBPATH = -L. -L..
LIBS = 
# -lrt -lpthread
# 4. DEFINITIONS (PREPROCESSOR DEFINE)
#DEFS=
# 5. INCLUDES PATH
INCLUDES = -I../core/
# 6. SOURCES FILES
# Directories with sources
DIRS = core
#. subpath1 subpath2 subpath2/subsubpath3
SRCFILESDIRS := $(addprefix / , $(DIRS))
# Obtaining source files list
CSRCFILES := $(foreach sdir, $(SRCFILESDIRS), $(wildcard $(sdir)/*.c))
CPPSRCFILES = $(foreach sdir, $(SRCFILESDIRS), $(wildcard $(sdir)/*.cpp))
# 7. OBJECTS FILE NAME
OBJFILES = $(CSRCFILES:.c=.o) $(CPPSRCFILES:.cpp=.o)
# $(SRCFILES:.cpp=.o)
# 8. TARGETS OR RESULTING OBJ-FILE
EXEC_TARGET = EasySockets
C_SHARED_LIB = libEasySockets.so
CPP_SHARED_LIB = libEasySockets.so
DEFAULT_TARGET = $(CPP_SHARED_LIB)
# *****************************END OF VARIABLES SECTION********************************
# ****************************2. BUILDING TARGETS SECTION******************************
# BY DEFAULT BUILDS first target (make without parameters)
# TO BUILD SPECIFIC TARGETS TYPE make "target name" (without quotation marks)
# each target MUST BE WRITTEN AS: Dependencies Tab(press tab key) Command
# MAKEFILE SPECIAL MACROSES (STARTS WITH $):
# $@ name of target 
# $? list of dependancies before that macro
# $^ list of dependancies which independent of wheather they met before or after
# $+ similar to $^ but doesn't exclude dublicates
# $< first dependancy

# PHONY TARGET ARE TARGETS WITHOUT OUTPUT FILES
.PHONY: depend clean finish

all:  clean $(DEFAULT_TARGET) finish

c99-shared: clean $(C_SHARED_LIB) finish

cpp03-shared: clean $(CPP_SHARED_LIB) finish

$(C_SHARED_LIB):$(OBJFILES)
	$(CXX) $(CXXFLAGS) $(C99_LANG) $(SHARED) $(INCLUDES) -o $(EXEC_TARGET) $(OBJFILES) $(LIBPATH) $(LIBS)
	
$(CPP_SHARED_LIB):$(OBJFILES)
	$(CXX) $(CXXFLAGS) $(CPP_03_LANG) $(SHARED) $(INCLUDES) -o $(EXEC_TARGET) $(OBJFILES) $(LIBPATH) $(LIBS)

# These are the suffix replacement rules
%.o : %.c
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ -rm *.o

#remove intermediate obj files
finish:
	@ -rm $(OBJFILES)

depend: $(SRCFILES)
	makedepend $(INCLUDES) $^

# make depend needs this line
# ****************************END OF BUILDING TARGETS SECTION**************************