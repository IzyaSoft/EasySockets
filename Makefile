# Easy Sockets Makefile Shared Library v 1.0
# ********************************1. VARIABLES SECTION*********************************
# 1 C/C++ Compiler
CXX = g++
# 2. Compiler And Linker Keys (man gcc)
CXXFLAGS = -Wall -g -O2
C99_LANG = -std=c99
CPP_03_LANG = -std=c++03
# todo: Add other cpp and c standards
SHARED_LIB_LINK = -shared
SHARED_LIB_FLAG = -fPIC
STATIC_LIB_LINK = -static
STATIC_LIB_ARCH = ar rcs
# 3. Linking libraries
LIBPATH = -L. -L..
# -L/lib64/
LIBS = 
# -lc -lrt
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
C_SRC_FILES := $(foreach sdir, $(SRCFILESDIRS), $(wildcard $(sdir)/*.c))
CPP_SRC_FILES = $(foreach sdir, $(SRCFILESDIRS), $(wildcard $(sdir)/*.cpp))
# 7. OBJECTS FILE NAME
C_OBJFILES = $(C_SRC_FILES:.c=.o)
CPP_OBJFILES = $(CPP_SRC_FILES:.cpp=.o) $(C_OBJFILES)
# $(SRCFILES:.cpp=.o)
# 8. TARGETS OR RESULTING OBJ-FILE
LIB_VERSION := 1.0
C_SHARED_LIB = libEasySocketsC.so.$(LIB_VERSION)
CPP_SHARED_LIB = libEasySocketsCpp.so.$(LIB_VERSION)
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

$(C_SHARED_LIB):$(C_OBJFILES)
	$(CXX) $(CXXFLAGS) $(C99_LANG) $(SHARED_LIB_LINK) $(INCLUDES) $(LIBPATH) $(LIBS) -o $(C_SHARED_LIB) $(C_OBJFILES)
# $(LIBPATH) $(LIBS)
	
$(CPP_SHARED_LIB):$(CPP_OBJFILES)
	$(CXX) $(CXXFLAGS) $(CPP_03_LANG) $(SHARED_LIB_LINK) $(INCLUDES) $(LIBPATH) $(LIBS) -o $(CPP_SHARED_LIB) $(CPP_OBJFILES)
# $(LIBPATH) $(LIBS)

# These are the suffix replacement rules
%.o : %.c
	$(CXX) $(CXXFLAGS) $(SHARED_LIB_FLAG) $(C99_LANG) $(INCLUDES) -c $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPP_03_LANG) $(INCLUDES) -c $< -o $@

clean:
	@ -rm -f *.o

#remove intermediate obj files
finish:
	@ -rm $(CPP_OBJFILES)

depend: $(C_SRC_FILES)
	makedepend $(INCLUDES) $^

# make depend needs this line
# ****************************END OF BUILDING TARGETS SECTION**************************
