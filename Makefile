edf_simulator: EDF.cpp helper.o
	g++ -g -o $@ $^
helper.o : helper.cpp 
	g++ -g -c -I. $@ $^
clean:
	rm -f a.out edf_simulator *.o

