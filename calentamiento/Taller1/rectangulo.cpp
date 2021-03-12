#include <iostream>
#include "rectangulo.h"

Rectangulo::Rectangulo(){}

Rectangulo::Rectangulo(float largo, float ancho){
    this->largo = largo;
    this->ancho = ancho;
}

float Rectangulo::calcularArea(){
    return largo * ancho;
}

float Rectangulo::calcularPerimetro(){
    return (ancho * 2) + (largo * 2);
}

void Rectangulo::setLargo(float largo){
    this->largo = largo;
}

void Rectangulo::setAncho(float ancho){
    this->ancho = ancho;
}
