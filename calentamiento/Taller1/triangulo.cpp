#include <iostream>
#include <cmath>
#include "triangulo.h"
using std::cout;
using std::cin;
using std::endl;

Triangulo::Triangulo(){}

Triangulo::Triangulo(int lados){
    float lado1, lado2, lado3;
    switch( lados ){
        case 1:
            cout << "Ingrese el lado nuevo: ";
            cin >> lado1;
            this->lado1 = lado1;
            this->lado2 = lado1;
            this->lado3 = lado1;
            break;
        case 2:
            cout << "Ingrese el lado que se repite: ";
            cin >> lado1;
            cout << "Ingrese el lado solitario: ";
            cin >> lado3;
            this->lado1 = lado1;
            this->lado2 = lado1;
            this->lado3 = lado3;
            break;
        case 3:
            cout << "Ingrese el lado 1: ";
            cin >> lado1;
            cout << "Ingrese el lado 2: ";
            cin >> lado2;
            cout << "Ingrese el lado 3: ";
            cin >> lado3;
            this->lado1 = lado1;
            this->lado2 = lado2;
            this->lado3 = lado3;
            break;
        default:
            break;
    }
}

float Triangulo::calcularArea(){
    float semiPerimetro = (lado1 + lado2 + lado3)/2;
    return (sqrt(semiPerimetro * (semiPerimetro - lado1) * (semiPerimetro - lado2) * (semiPerimetro - lado3)));
}

float Triangulo::calcularPerimetro(){
    return lado1 + lado2 + lado3;
}
