CXX=g++

CFLAGS=-g -c 

BASEDIR=.

INC=-I$(BASEDIR)

OBJDIR=$(BASEDIR)

BINDIR=$(BASEDIR)

SRCDIR=$(BASEDIR)

LIBS=


HELPER_OBJS=$(OBJDIR)/helper.o \
		$(OBJDIR)/EDF.o

all : edf_sim

edf_sim : $(HELPER_OBJS) 
	$(CXX) -o $(BINDIR)/$@ $(HELPER_OBJS) $(INC) $(LIBS)


$(OBJDIR)/helper.o : $(SRCDIR)/helper.cpp
	$(CXX) $(CFLAGS) $(INC)  $(SRCDIR)/helper.cpp -o $@

$(OBJDIR)/EDF.o : $(SRCDIR)/EDF.cpp
	$(CXX) $(CFLAGS) $(INC)  $(SRCDIR)/EDF.cpp -o $@

clean : 
	rm $(OBJDIR)/*.o
	rm edf_sim
