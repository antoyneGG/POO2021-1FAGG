#include <iostream>
#include <string>
#include "producto.h"

Producto::Producto(){}

Producto::Producto(std::string marca, std::string tipoProducto, int codigoProducto, int existencia, float valorProducto, int porcIva){
    this->marca = marca;
    this->tipoProducto = tipoProducto;
    this->codigoProducto = codigoProducto;
    this->existencia = existencia;
    this->valorProducto = valorProducto;
    this->porcIVA = porcIva;
}

void Producto::mostrarProducto(){
    std::cout << "------------------------------\n";
    std::cout << "Marca: " << this->marca << std::endl;
    std::cout << "Tipo de producto: " << this->tipoProducto << std::endl;
    std::cout << "Codigo del producto: " << this->codigoProducto << std::endl;
    std::cout << "Existencia: " << this->existencia << std::endl;
    std::cout << "Valor del producto: " << this->valorProducto << std::endl;
    std::cout << "------------------------------\n";
}

int Producto::getCodigoProducto(){
    return this->codigoProducto;
}

void Producto::setExistencia(int exist){
    this->existencia = exist;
}

int Producto::getExistencia(){
    return this->existencia;
}

int Producto::getValor(){
    return this->valorProducto;
}

int Producto::getPorcIva(){
    return this->porcIVA;
}

void Producto::resExist(int n){
    this->existencia = this->existencia - n;
}