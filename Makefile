#CXXFLAGS	      = -g -O0 -DDEBUG --pedantic -std=c++11 -Wall
#CXXFLAGS      = -g -O0 -DDEBUG --pedantic -Wall -ansi
CXXFLAGS      = -std=gnu++11 -g -O0 -DDEBUG --pedantic -Wall
DEST	      = .

EXTHDRS	      =

HDRS	      = Board.hpp \
		BoardSize.hpp \
		Cell.hpp \
		Group.hpp

INSTALL	      = cp

LD	      = $(CXX)

LDFLAGS	      =

LIBS	      =

MAKEFILE      = Makefile

OBJS	      = Board.o \
		BoardSize.o \
		Main.o \
		Group.o \
		Cell.o

PRINT	      = pr

PROGRAM       = ysudoku

SHELL	      = /bin/sh

SRCS	      = Board.cpp \
		Cell.cpp \
		Group.cpp \
		BoardSize.cpp \
		Main.cpp

SYSHDRS	      =

all:		$(PROGRAM)

$(PROGRAM):     $(OBJS) $(LIBS)
		@echo "Linking $(PROGRAM) ..."
		@$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROGRAM)
		@echo "done"

clean:;		@rm -f $(OBJS) core

clobber:;	@rm -f $(OBJS) $(PROGRAM) core tags

depend:;	@mkmf -f $(MAKEFILE)

echo:;		@echo $(HDRS) $(SRCS)

index:;		@ctags -wx $(HDRS) $(SRCS)

install:	$(PROGRAM)
		@echo Installing $(PROGRAM) in $(DEST)
		@-strip $(PROGRAM)
		@if [ $(DEST) != . ]; then \
		(rm -f $(DEST)/$(PROGRAM); $(INSTALL) $(PROGRAM) $(DEST)); fi

print:;		@$(PRINT) $(HDRS) $(SRCS)

tags:           $(HDRS) $(SRCS); @ctags $(HDRS) $(SRCS)
###
Board.o: Board.hpp BoardSize.hpp Group.hpp Cell.hpp
BoardSize.o: BoardSize.hpp
Main.o: Board.hpp BoardSize.hpp Group.hpp Cell.hpp
Cell.o: Cell.hpp

