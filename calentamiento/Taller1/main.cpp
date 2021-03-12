#include <iostream>
#include <cmath>
#include "circulo.h"
#include "triangulo.h"
#include "rectangulo.h"
using std::cout;
using std::cin;
using std::endl;

int main(){
    const int CAP = 10;
    float radio, largo, ancho, lados;
    int selec, recIn = 0, cirIn = 0, triIn = 0;
    Circulo listaCirculos[CAP];
    Rectangulo listaRectangulos[CAP];
    Triangulo listaTriangulos[CAP];
    do{
        cout << "Seleccione una opcion:\n1. Circulo\n2. Rectangulo\n3. Triangulo\n4. Salir\n";
        cin >> selec;
        switch( selec ){
            case 1:{
                if(cirIn < 10){
                    cout << "Ingrese el radio del circulo: ";
                    cin >> radio;
                    Circulo circuloTemp(radio);
                    listaCirculos[cirIn++] = circuloTemp;
                    cout << "Su area es " << circuloTemp.calcularArea() << endl;
                    cout << "Su perimetro es " << circuloTemp.calcularPerimetro() << endl;
                } else{
                    cout << "La lista se encuentra llena." << endl;
                }
                break;
            }
            case 2:{
                if(recIn < 10){
                    cout << "Ingrese el largo del rectangulo: ";
                    cin >> largo;
                    cout << "Ingrese el ancho del rectangulo: ";
                    cin >> ancho;
                    Rectangulo rectanguloTemp(largo, ancho);
                    listaRectangulos[recIn++] = rectanguloTemp;
                    cout << "Su area es " << rectanguloTemp.calcularArea() << endl;
                    cout << "Su perimetro es " << rectanguloTemp.calcularPerimetro() << endl;
                } else{
                    cout << "La lista se encuentra llena." << endl;
                }
                break;
            }
            case 3:{
                if(triIn < 10){
                    cout << "Seleccione el tipo de triangulo:\n1. Equilatero\n2. Isosceles\n3. Escaleno\n";
                    cin >> lados;
                    Triangulo trianguloTemp(lados);
                    listaTriangulos[triIn++] = trianguloTemp;
                    cout << "Su area es " << trianguloTemp.calcularArea() << endl;
                    cout << "Su perimetro es " << trianguloTemp.calcularPerimetro() << endl;
                } else{
                    cout << "La lista se encuentra llena." << endl;
                }
                break;
            }
            case 4:{
                cout << "Adieu\n";
                break;
            }
            default:{
                cout << "Opcion invalida, seleccione una correcta\n";
            }
        }
    } while(selec != 4);
    return 0;
}