CXX=g++

CFLAGS=-g -c 

BASEDIR=.

INC=-I$(BASEDIR)

OBJDIR=$(BASEDIR)

BINDIR=$(BASEDIR)

SRCDIR=$(BASEDIR)

LIBS=


HELPER_OBJS=$(OBJDIR)/helper.o \
		$(OBJDIR)/main.o\
		$(OBJDIR)/RMS.o \
		$(OBJDIR)/EDF.o

all : edf_sim

edf_sim : $(HELPER_OBJS) 
	$(CXX) -g -o $(BINDIR)/$@ $(HELPER_OBJS) $(INC) $(LIBS)

$(OBJDIR)/main.o : $(SRCDIR)/main.cpp
	$(CXX) $(CFLAGS) $(INC)  $^

$(OBJDIR)/helper.o : $(SRCDIR)/helper.cpp
	$(CXX) $(CFLAGS) $(INC)  $^

$(OBJDIR)/EDF.o : $(SRCDIR)/EDF.cpp
	$(CXX) $(CFLAGS) $(INC)  $^

$(OBJDIR)/RMS.o : $(SRCDIR)/RMS.cpp
	$(CXX) $(CFLAGS) $(INC)  $^ 

clean : 
	rm $(OBJDIR)/*.o
	rm edf_sim
