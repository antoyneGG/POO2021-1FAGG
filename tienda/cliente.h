#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using std::string;

class Cliente{
    private:
        string nombre;
        string email;
        int id;
        float cantLitrosTomados;
        int telefono;
    public:
        Cliente();
        Cliente(string, string, int, float, int);
        void mostrarCliente();
        int getId();
};

#endif