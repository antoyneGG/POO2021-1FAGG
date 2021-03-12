#include <string>
#include <list>
#include "cliente.h"
#include "venta.h"
#include "producto.h"

class Tienda{
    private:
        std::string nombre;
        std::string nombreDueno;
        int capacidadClientes;
        int capacidadProd;
        std::list<Venta> listaVentas;
        std::list<Producto> listaProductos;
        std::list<Cliente> listaClientes;
    public:
        Tienda();
        Tienda(std::string, std::string);
        void mostrarTodosProductos();
        void mostrarTodosClientes();
        void agregarProducto();
        void agregarCliente();
        Producto buscarProducto(int);
        Cliente buscarCliente(int);
        void venta();
};