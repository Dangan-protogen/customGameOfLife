game:main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -o game 

main.o:
	g++ -c main.cpp

clear: 
	rm game *.o