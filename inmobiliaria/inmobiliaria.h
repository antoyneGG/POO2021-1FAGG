#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "propiedad.h"

class Inmobiliaria{
    private:
        vector<Propiedad> listaPropiedades;
    public:
        Inmobiliaria();
        void crearPropiedad(Propiedad&);
        int buscarPropiedad(int);
        void modificarPropiedad(int);
        void eliminarPropiedad(int);
        void listarPropiedades();
        void listarPropiedadesPrecio(float, int);
        void listarPropiedadesBarrio(string);
        void listarPropiedadesTipoPago(int);
        void ordenarMenorMayorPropiedades();
};

#endif