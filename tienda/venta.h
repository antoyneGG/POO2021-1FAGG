#ifndef VENTA_H
#define VENTA_H
#include "cliente.h"
#include "detalleVenta.h"
#include <list>

class Venta{
    private:
        Cliente cliente;
        int fecha;
        float valorTotal;
        std::list<DetalleVenta> listaDetallesVenta;
        int IVATotal;
        int id;
    public:
        Venta();
        Venta(Cliente, int, int);
        void agregarDetalle(Producto, float, int, int);
        void setValorTotal(int);
        void setIVATotal(int);
};

#endif