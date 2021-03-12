#include <iostream>
#include <string>
#include "cliente.h"

Cliente::Cliente(){}

Cliente::Cliente(string nombre, string email, int id, float cantLitros, int telefono){
    this->nombre = nombre;
    this->email = email;
    this->id = id;
    this->cantLitrosTomados = cantLitros;
    this->telefono = telefono;
}

void Cliente::mostrarCliente(){
    std::cout << "El cliente es " << this->nombre << std::endl;
}

int Cliente::getId(){
    return this->id;
}