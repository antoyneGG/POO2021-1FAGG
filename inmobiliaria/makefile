all: compilar
compilar: inmobiliaria propiedad  main
		g++ -o starInmobiliaria inmobiliaria.o propiedad.o main.o
inmobiliaria: inmobiliaria.cpp inmobiliaria.h
		g++ -c inmobiliaria.cpp
propiedad: propiedad.cpp propiedad.h
		g++ -c propiedad.cpp
main: main.cpp inmobiliaria.h 
	  g++ -c main.cpp
