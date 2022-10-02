output: main.o functions.o classes.o
	g++ main.o functions.o classes.o -o output
main.o: main.cpp functions.o classes.o
	g++ -c main.cpp
classes.o: classes.h classes.cpp
	g++ -c classes.cpp
functions.o: functions.h functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o output