//#ifndef FIGURAS_CONTROLLER_H
// Guardas
#include "../Model/Circulo.h"
#include "../Model/Triangulo.h"
#include "../Model/Rectangulo.h"

#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;

class FigurasController
{
private:
    //constante y estático para declararla constante para todos los objetos.
    const static int MAX_ITEMS;
    list<Rectangulo> listaRectangulo;
    list<Circulo> listaCirculo;
    list<Triangulo> listaTriangulo;

public:
    //RECTANGULO
    list<Rectangulo> &getListaRectangulo();
    void agregarRectagulo(float largo, float ancho);
    Rectangulo &encontrarMayorAncho();
    Rectangulo &encontrarRectangulo(int);

    //CIRCULO
    list<Circulo> &getListaCirculo();
    void agregarCirculo(float radio);
    Circulo &encontrarCirculo(int);

    //TRIANGULO
    list<Triangulo> &getListaTriangulo();
    void agregarTriangulo(float base, float altura);
    Triangulo &encontrarTriangulo(int);
};
//#define FIGURAS_CONTROLLER_H