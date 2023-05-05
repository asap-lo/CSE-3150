CC = g++
DEPENDENCIES = ECTextViewImp.cpp ECProject.cpp TestDriver.cpp

all: clean  editor	run

editor:
	$(CC) $(DEPENDENCIES) -o editor

clean:
	rm -f editor

run:
	./editor test.txt