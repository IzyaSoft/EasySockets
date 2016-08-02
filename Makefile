# Easy Sockets Makefile Different type of targets Libraries v 1.0
# ********************************0. INCLUDE SECTION***********************************
include Makefile.defs
# *****************************END OF INCLUDE SECTION**********************************
# ********************************1. TARGETS SECTION***********************************
.PHONY: clean

c99-shared:
	@ -make -f Makefile.impl c99-shared LANG_OPTION=${C99_LANG} LIB_LINK_OPTION=${SHARED_LIB_LINK} LIB_COMPILE_OPTION=${SHARED_LIB_COMPILE}

cpp03-shared:
	@ -make -f Makefile.impl cpp03-shared LANG_OPTION=${CPP_03_LANG} LIB_LINK_OPTION=${SHARED_LIB_LINK} LIB_COMPILE_OPTION=${SHARED_LIB_COMPILE}

c99-static:
	@ -make -f Makefile.impl c99-static LANG_OPTION=${C99_LANG} LIB_LINK_OPTION=${STATIC_LIB_LINK} LIB_COMPILE_OPTION=${STATIC_LIB_COMPILE}

cpp03-static:
	@ -make -f Makefile.impl cpp03-static LANG_OPTION=${CPP_03_LANG} LIB_LINK_OPTION=${STATIC_LIB_LINK} LIB_COMPILE_OPTION=${STATIC_LIB_COMPILE}

clean:
	@ -make -f Makefile.impl clean

# ****************************END OF BUILDING TARGETS SECTION**************************
