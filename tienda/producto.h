#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto{
    private:
        std::string marca;
        std::string tipoProducto;
        int codigoProducto;
        int existencia;
        float valorProducto;
        int porcIVA;
    public:
        Producto();
        Producto(std::string, std::string, int, int, float, int);
        void mostrarProducto();
        int getCodigoProducto();
        void setExistencia(int);
        int getExistencia();
        int getValor();
        int getPorcIva();
        void resExist(int);
};

#endif