Main: Main.o Circulo.o Triangulo.o Rectangulo.o
	g++ -o Main Main.o Circulo.o Triangulo.o Rectangulo.o
Main.o: main.cpp circulo.h triangulo.h rectangulo.h
	g++ -c main.cpp
Circulo.o: circulo.cpp circulo.h
	g++ -c circulo.cpp
Triangulo.o: triangulo.cpp triangulo.h
	g++ -c triangulo.cpp
Rectangulo.o: rectangulo.cpp rectangulo.h
	g++ -c rectangulo.cpp
clean:
	rm -f Main Main.o Circulo.o Triangulo.o Rectangulo.o