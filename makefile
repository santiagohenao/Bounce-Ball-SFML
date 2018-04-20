all : ball
	./ball

ball : main.o
	g++ main.o -o ball -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o ball
