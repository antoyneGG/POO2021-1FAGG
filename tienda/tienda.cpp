#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include "tienda.h"
#include "producto.h"
#include "cliente.h"
#include "venta.h"
using namespace std;
int idVentas = 0;

Tienda::Tienda(){}

Tienda::Tienda(string nombre, string nombreDueno){
    this->nombre = nombre;
    this->nombreDueno = nombreDueno;
    this->capacidadClientes = 10;
    this->capacidadProd = 3;
}

void Tienda::mostrarTodosProductos(){
    list <Producto> :: iterator i;
    for(i = this->listaProductos.begin(); i != this->listaProductos.end(); ++i){
        i->mostrarProducto(); 
    }
    cout << "\n";
}

void Tienda::mostrarTodosClientes(){
    list <Cliente> :: iterator i;
    for(i = this->listaClientes.begin(); i != this->listaClientes.end(); ++i){
        i->mostrarCliente(); 
    }
    cout << "\n";
}

void Tienda::agregarProducto(){
    string marca, tipoP;
    int codigoP, existencia, valorP, porcIva;
    cout << "Ingrese la marca del producto: ";
    cin >> marca;
    cout << "Ingrese el tipo del producto: ";
    cin >> tipoP;
    cout << "Digite el codigo del producto: ";
    cin >> codigoP;
    cout << "Digite la exitencia del producto: ";
    cin >> existencia;
    cout << "Ingrese el valor del producto: ";
    cin >> valorP;
    cout << "Ingrese el porcentaje de IVA del producto: ";
    cin >> porcIva;
    Producto producto(marca, tipoP, codigoP, existencia, valorP, porcIva);
    this->listaProductos.push_back(producto);
}

void Tienda::agregarCliente(){
    string nombre, email;
    int id, telefono;
    float cantLitros;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingrese el email del cliente: ";
    cin >> email;
    cout << "Digite el ID del cliente: ";
    cin >> id;
    cout << "Digite cantidad de litros consumidos por el cliente: ";
    cin >> cantLitros;
    cout << "Ingrese el telefono del cliente: ";
    cin >> telefono;
    Cliente cliente(nombre, email, id, cantLitros, telefono);
    this->listaClientes.push_back(cliente);
}

Producto Tienda::buscarProducto(int codigoP){
    Producto producto();
    list <Producto> :: iterator i;
    for(i = this->listaProductos.begin(); i != this->listaProductos.end(); ++i){
        if(i->getCodigoProducto() == codigoP){
            return *i;
        } 
    }
    throw std::domain_error("El producto no existe\n");
}

Cliente Tienda::buscarCliente(int id){
    list <Cliente> :: iterator i;
    for(i = this->listaClientes.begin(); i != this->listaClientes.end(); ++i){
        if(i->getId() == id){
            return *i;
        }
    }
    throw std::domain_error("El cliente no existe\n");
}

void Tienda::venta(){
    int id, fecha, codigoP, cantP, porcIva, IVATotal = 0, productosVendidos, existencia;
    float valor, valorT = 0;
    idVentas++;
    Cliente cliente;
    cout << "Digite el ID del cliente al que se le realiza la venta: ";
    cin >> id;
    cout << "Digite la fecha en la que se realiza la venta: ";
    cin >> fecha;
    cliente = this->buscarCliente(id);
    Venta venta(cliente, fecha, idVentas);
    cout << "Digite la cantidad de productos que compro: ";
    cin >> productosVendidos;
    for(int i = 0; i < productosVendidos; i++){
        Producto producto;
        cout << "Ingrese el codigo del producto vendido: ";
        cin >> codigoP;
        producto = this->buscarProducto(codigoP);
        if(producto.getExistencia() == 0){
            cout << "No quedan unidades de este producto.\n";
            idVentas--;
        } else{
            cout << "Ingrese la cantidad vendida de este producto: ";
            cin >> cantP;
            if(producto.getExistencia() - cantP < 0){
                cout << "No disponemos de tantas unidades de este producto, seleccione una cantidad menor.\n";
                idVentas--;
            } else{
                valor = producto.getValor();
                valorT += valor;
                porcIva = producto.getPorcIva();
                IVATotal += porcIva;
                venta.agregarDetalle(producto, valor, porcIva, cantP);
                this->listaVentas.push_back(venta);
            }
        }
        
    }
}
