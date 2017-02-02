CXXFLAGS      = -Wall --pedantic 

DEST	      = .

EXTHDRS	      =

HDRS	      = Board.hpp \
		BoardSize.hpp \
		Cell.hpp \
		Config.hpp \
		Group.hpp

INSTALL	      = cp

LD	      = $(CXX)

LDFLAGS	      =

LIBS	      =

MAKEFILE      = Makefile

OBJS	      = Board.o \
		BoardSize.o \
		Cell.o \
		main.o

PRINT	      = pr

PROGRAM       = ysudoku 

SHELL	      = /bin/sh

SRCS	      = Board.cpp \
		BoardSize.cpp \
		Cell.cpp \
		main.cpp

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
Board.o: BoardSize.hpp Board.hpp Group.hpp Cell.hpp
BoardSize.o: BoardSize.hpp
Cell.o: Cell.hpp BoardSize.hpp
main.o: BoardSize.hpp Board.hpp Group.hpp Cell.hpp
