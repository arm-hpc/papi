KERNINC = /usr/src/linux-2.4/include
PERFCTR ?= ./perfctr-2.4.x
PERFCTR_LIB_PATH = $(PERFCTR)/usr.lib

#
# GNU G77 section
#
F77   = g77
FFLAGS        = -Dlinux
FOPTFLAGS= $(OPTFLAGS)
FTOPTFLAGS= $(TOPTFLAGS)
# #
# #  Portland Group PGF77 section
# #
# F77       = pgf77
# FFLAGS    = -Dlinux
# FOPTFLAGS = -O3 -tp p6
# FTOPTFLAGS= $(FOPTFLAGS)
# #
# #  Intel Corp. Fortran compiler
# #
# F77      = ifc
# FFLAGS   = -Dlinux
# LDFLAGS  = -lPEPCF90 -lIEPCF90 -lF90 -lintrins # Intel portability library (getarg_)
# FOPTFLAGS= -O3 -tpp6
# FTOPTFLAGS= $(FOPTFLAGS)

#
# DO NOT TOUCH BELOW HERE UNLESS YOU KNOW WHAT YOU ARE DOING
#

LIBRARY = libpapi.a
SHLIB   = libpapi.so
SUBSTR  = perfctr-$(CPU)
MSUBSTR = linux-perfctr-$(CPU)
MEMSUBSTR= linux
DESCR   = "Linux with PerfCtr 2.4.5 patch"
LIBS    = static shared
TARGETS = serial multiplex_and_pthreads

CC_R    = $(CC) -pthread
CFLAGS  = -I$(PERFCTR)/usr.lib -I$(PERFCTR)/linux/include -I$(KERNINC) -I.
#-DDEBUG -DMPX_DEBUG -DMPX_DEBUG_TIMER
MISCSRCS= linux.c $(CPU)_events.c
MISCOBJS= $(PERFCTR)/usr.lib/libperfctr.o linux.o $(CPU)_events.o
MISCHDRS= perfctr-$(CPU).h
SHLIBDEPS = -L$(PERFCTR_LIB_PATH) -lperfctr

include Makefile.inc

linux.o: linux.c
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c linux.c -o $@

$(CPU)_events.o: $(CPU)_events.c
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c $(CPU)_events.c -o $@

$(PERFCTR)/usr.lib/libperfctr.o:
	$(MAKE) -C $(PERFCTR)/usr.lib

native_clean:
	$(MAKE) -C $(PERFCTR) clean

native_install:
	-cp -p $(PERFCTR)/usr.lib/libperfctr.so $(DESTDIR)/lib
	-cp -p $(PERFCTR)/usr.lib/event_codes.h $(DESTDIR)/include
	-cp -p $(PERFCTR)/usr.lib/libperfctr.h  $(DESTDIR)/include