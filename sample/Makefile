SRCDIR		= ./
LIBDIR		= ../library
INCDIR		= ../include

CC	= g++
CFLAGS	= -O2 -Wall -I$(INCDIR)
LDFLAGS	= -L$(LIBDIR) -lautomaze
AR	= ar
ARFLAGS	= cru
MAKE	= make

TARGETS = main


all: $(TARGETS)

$(TARGETS): $(LIBDIR)/libautomaze.a $(TARGETS:%=%.cpp)
	$(CC) -o $@ $@.cpp $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OUTDIR)/*.o
	rm -f $(TARGETS)

