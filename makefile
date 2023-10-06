Program: Derle Calistir
Derle:
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/DogruKuyruk.o -c ./src/DogruKuyruk.cpp
	g++ -I ./include/ -o ./lib/Nokta.o -c ./src/Nokta.cpp
	g++ -I ./include/ -o ./bin/uyg ./lib/DogruKuyruk.o ./lib/AVL.o ./lib/Nokta.o ./src/main.cpp
Calistir:
	./bin/uyg.exe

