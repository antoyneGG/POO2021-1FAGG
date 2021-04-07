#include "propiedad.h"

Propiedad::Propiedad(){}

Propiedad::Propiedad(int codigo, float area, int numeroAlcobas, int numeroParqueaderos, int numeroBanios, float precio, string barrio, tipoPago tipo_pago, tipoPropiedad tipo_propiedad, string descripcion){
    this->codigo = codigo;
    this->area = area;
    this->numeroAlcobas = numeroAlcobas;
    this->numeroParqueaderos = numeroParqueaderos;
    this->numeroBanios = numeroBanios;
    this->precio = precio;
    this->barrio = barrio;
    this->tipo_pago = tipo_pago;
    this->tipo_propiedad = tipo_propiedad;
    this->descripcion = descripcion;
}

void Propiedad::mostrarPropiedad(){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Codigo: " << this->codigo << endl;
    cout << "Area: " << this->area << endl;
    cout << "Precio: " << this->precio << endl;
    cout << "Numero de alcobas: " << this->numeroAlcobas << endl;
    cout << "Numero de parqueaderos: " << this->numeroParqueaderos << endl;
    cout << "Numero de banios: " << this->numeroBanios << endl;
    cout << "Barrio: " << this->barrio << endl;
    cout << "Tipo de pago: DESPUES LO PONGO" << endl;
    cout << "Tipo de propiedad: DESPUES LO PONGO" << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int Propiedad::getCodigo(){
    return this->codigo;
}

string Propiedad::getBarrio(){
    return this->barrio;
}

float Propiedad::getPrecio(){
    return this->precio;
}

tipoPago Propiedad::getTipoPago(){
    return this->tipo_pago;
}

void Propiedad::setArea(float area){
    this->area = area;
}

void Propiedad::setNumAlcob(int num){
    this->numeroAlcobas = num;
}

void Propiedad::setNumPark(int num){
    this->numeroParqueaderos = num;
}

void Propiedad::setNumBan(int num){
    this->numeroBanios = num;
}

void Propiedad::setPrecio(float num){
    this->precio = num;
}

void Propiedad::setTipoPago(int num){
    num == 1 ? this->tipo_pago = arrendamiento : this->tipo_pago = venta;
}

void Propiedad::setTipoProp(int num){
    switch( num ){
        case 1:
            this->tipo_propiedad = apartamento;
            break;
        case 2:
            this->tipo_propiedad = apartaestudio;
            break;
        case 3:
            this->tipo_propiedad = casa;
            break;
        case 4:
            this->tipo_propiedad = lote;
            break;
        case 5:
            this->tipo_propiedad = casa_con_renta;
            break;
        case 6:
            this->tipo_propiedad = finca;
            break;
    }
}

void Propiedad::setDescrip(string descripcion){
    this->descripcion = descripcion;
}