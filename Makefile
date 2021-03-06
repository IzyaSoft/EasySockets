# Easy Sockets Makefile Different type of targets Libraries v 1.0
# ********************************0. INCLUDE SECTION***********************************
include Makefile.defs
# *****************************END OF INCLUDE SECTION**********************************
# 0. COMMON OPTIONS
VERSION := 1.0
BUILD_DIRECTORY=./Debug/bin
# ********************************2. TARGETS SECTION***********************************
.PHONY: clean

c99-shared:
	@ -make -f Makefile.impl c99-shared LANG_OPTION=${C99_LANG} LIB_LINK_OPTION=${SHARED_LIB_LINK} LIB_COMPILE_OPTION=${SHARED_LIB_COMPILE} LIB_VERSION_OPTION=${VERSION} LIB_BUILD_DIRECTORY=${BUILD_DIRECTORY}

cpp03-shared:
	@ -make -f Makefile.impl cpp03-shared LANG_OPTION=${CPP_03_LANG} LIB_LINK_OPTION=${SHARED_LIB_LINK} LIB_COMPILE_OPTION=${SHARED_LIB_COMPILE} LIB_VERSION_OPTION=${VERSION} LIB_BUILD_DIRECTORY=${BUILD_DIRECTORY}

c99-static:
	@ -make -f Makefile.impl c99-static LANG_OPTION=${C99_LANG} LIB_LINK_OPTION=${STATIC_LIB_LINK} LIB_COMPILE_OPTION=${STATIC_LIB_COMPILE} LIB_VERSION_OPTION=${VERSION} LIB_BUILD_DIRECTORY=${BUILD_DIRECTORY}

cpp03-static:
	@ -make -f Makefile.impl cpp03-static LANG_OPTION=${CPP_03_LANG} LIB_LINK_OPTION=${STATIC_LIB_LINK} LIB_COMPILE_OPTION=${STATIC_LIB_COMPILE} LIB_VERSION_OPTION=${VERSION} LIB_BUILD_DIRECTORY=${BUILD_DIRECTORY}

clean:
	@ -make -f Makefile.impl clean LIB_VERSION_OPTION=${VERSION} LIB_BUILD_DIRECTORY=${BUILD_DIRECTORY}

# ****************************END OF BUILDING TARGETS SECTION**************************
