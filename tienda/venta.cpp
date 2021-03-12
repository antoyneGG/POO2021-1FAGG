#include "venta.h"
#include "detalleVenta.h"
#include <list>

Venta::Venta(){}

Venta::Venta(Cliente cliente, int fecha, int id){
    this->cliente = cliente;
    this->fecha = fecha;
    this->valorTotal = 0;
    this->IVATotal = 0;
    this->id = id;
}

void Venta::agregarDetalle(Producto producto, float valor, int IVA, int cantP){
    DetalleVenta detalleVenta(producto, valor, IVA, cantP);
    this->listaDetallesVenta.push_back(detalleVenta);
}

void Venta::setValorTotal(int valorTotal){
    this->valorTotal = valorTotal;
}

void Venta::setIVATotal(int IVATotal){
    this->IVATotal = IVATotal;
}