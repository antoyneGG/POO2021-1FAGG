#include "detalleVenta.h"

DetalleVenta::DetalleVenta(){}

DetalleVenta::DetalleVenta(Producto producto, float valor, int IVA, int cantP){
    this->producto = producto;
    this->valor = valor;
    this->IVA = IVA;
    this->cantidadProducto = cantP;
}

