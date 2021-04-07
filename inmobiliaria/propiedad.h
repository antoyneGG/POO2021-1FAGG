#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

enum tipoPago{
    arrendamiento, venta
};

enum tipoPropiedad{
    apartamento, apartaestudio, casa, lote, casa_con_renta, finca
};

class Propiedad{
    private:
        int codigo;
        float area;
        int numeroAlcobas;
        int numeroParqueaderos;
        int numeroBanios;
        float precio;
        string barrio;
        tipoPago tipo_pago;
        tipoPropiedad tipo_propiedad;
        string descripcion;
    public:
        Propiedad();
        Propiedad(int, float, int, int, int, float, string, tipoPago, tipoPropiedad, string);
        void mostrarPropiedad();
        int getCodigo();
        string getBarrio();
        float getPrecio();
        tipoPago getTipoPago();
        void setArea(float);
        void setNumAlcob(int);
        void setNumPark(int);
        void setNumBan(int);
        void setPrecio(float);
        void setTipoPago(int);
        void setTipoProp(int);
        void setDescrip(string);
};

#endif