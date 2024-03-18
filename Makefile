#Makefile
all: add-nbo

add-nbo:
	gcc -o add-nbo add-nbo.cpp

clean:
	rm -f add-nbo
	rm -f *.o