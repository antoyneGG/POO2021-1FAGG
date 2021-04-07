#include "../Controller/FigurasController.h"

// Inicializacion constante estatica para elemento compartido
const int FigurasController::MAX_ITEMS = 10;

void FigurasController::agregarRectagulo(const float largo, const float ancho)
{
    if (listaRectangulo.size() < MAX_ITEMS)
    {
        cout << "Agrego rectangulo" << endl;
        listaRectangulo.push_back(Rectangulo(largo, ancho));
    }
    else
    {
        //FIXME agregar manejo de excepcion
        std::cout << "\nSe sobrepasa el limite\n"
                  << std::endl;
    }
}

list<Rectangulo> &FigurasController::getListaRectangulo()
{
    // Creo la  referencia
    list<Rectangulo> &lista = listaRectangulo;
    return lista;
}

Rectangulo &FigurasController::encontrarMayorAncho(){
    list <Rectangulo> :: iterator I = listaRectangulo.begin();
    Rectangulo *rectanguloMayor = &(*I), *rectangulo;
    for(I = listaRectangulo.begin(); I != listaRectangulo.end(); I++){
        rectangulo = &(*I);
        if(rectangulo->getAncho() > rectanguloMayor->getAncho()){
            rectanguloMayor = &(*I);
        }
    }
    return *rectanguloMayor;
}

Rectangulo &FigurasController::encontrarRectangulo( int n ){
    list <Rectangulo> :: iterator I = listaRectangulo.begin();
    advance(I, n);
    Rectangulo *rectangulo = &(*I);
    return *rectangulo;
}

//CIRCULO

void FigurasController::agregarCirculo(const float radio){
    if (listaCirculo.size() < MAX_ITEMS){
        cout << "Agrego circulo" << endl;
        listaCirculo.push_back(Circulo(radio));
    } else{
        std::cout << "\nSe sobrepasa el limite\n" << std::endl;
    }
}

list<Circulo> &FigurasController::getListaCirculo(){
    list<Circulo> &lista = listaCirculo;
    return lista;
}

Circulo &FigurasController::encontrarCirculo( int n ){
    list <Circulo> :: iterator I = listaCirculo.begin();
    advance(I, n);
    Circulo *circulo = &(*I);
    return *circulo;
}

//TRIANGULO

void FigurasController::agregarTriangulo(const float base, const float altura){
    if (listaTriangulo.size() < MAX_ITEMS){
        cout << "Agrego triangulo" << endl;
        listaTriangulo.push_back(Triangulo(base, altura));
    } else{
        std::cout << "\nSe sobrepasa el limite\n" << std::endl;
    }
}

list<Triangulo> &FigurasController::getListaTriangulo(){
    list<Triangulo> &lista = listaTriangulo;
    return lista;
}

Triangulo &FigurasController::encontrarTriangulo( int n ){
    list <Triangulo> :: iterator I = listaTriangulo.begin();
    advance(I, n);
    Triangulo *triangulo = &(*I);
    return *triangulo;
}