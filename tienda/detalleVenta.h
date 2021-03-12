#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include "cliente.h"
#include "producto.h"

class DetalleVenta{
    private:
        Producto producto;
        float valor;
        int IVA;
        int cantidadProducto;
    public:
        DetalleVenta();
        DetalleVenta(Producto, float, int, int);
};

#endif