#include <iostream>
#include "circulo.h"
#define PI 3.14

Circulo::Circulo(){}

Circulo::Circulo(float radio){
    this->radio = radio;
}

float Circulo::calcularArea(){
    return PI * (this->radio * this->radio);
}

float Circulo::calcularPerimetro(){
    return (PI * 2) * this->radio;
}

float Circulo::getRadio(){
    return this->radio;
}

void Circulo::setRadio(float radio){
    this->radio = radio;
}
