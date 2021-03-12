#include <string>
#include <iostream>
#include <list>
#include "tienda.h"
#include "producto.h"
#include "cliente.h"
#include "detalleVenta.h"
#include "licor.h"
using std::cout;
using std::cin;

int main(){
    string dueno = "Luisa Rincon", tienda = "La Farra";
    Tienda laFarra(tienda, dueno);
    int selec;
    do{
        cout << "Seleccione una opcion:\n1. Agregar producto\n2. Mostrar todos los productos\n3. Agregar cliente\n4. Mostrar todos los clientes\n5. Venta\n6. Salir\n";
        cin >> selec;
        switch( selec ){
            case 1:
                laFarra.agregarProducto();
                break;
            case 2:
                laFarra.mostrarTodosProductos();
                break;
            case 3:
                laFarra.agregarCliente();
                break;
            case 4:
                laFarra.mostrarTodosClientes();
                break;
            case 5:
                laFarra.venta();
                break;
            case 6:
                cout << "Gracias por hacer uso del servicio.\n";
                break;
            default:
                cout << "Digite una opcion valida :)\n";
        }
    } while(selec != 6);
    return 0;
}