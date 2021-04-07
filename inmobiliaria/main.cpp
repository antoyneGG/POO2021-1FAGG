#include "inmobiliaria.h"

void recogerDatosPropiedad(int& codigo, Inmobiliaria& inmobiliaria){
    int selec, numAlcobas, numParks, numBanios;
    float area, precio;
    tipoPago tipo_pago;
    tipoPropiedad tipo_propiedad;
    string desc, barrio;
    bool continuar = true;
    cout << "Digite el area de la propiedad: ";
    cin >> area;
    cout << "Digite el numero de alcobas: ";
    cin >> numAlcobas;
    cout << "Digite el numero de parqueaderos: ";
    cin >> numParks;
    cout << "Digite el numero de banios: ";
    cin >> numBanios;
    cout << "Digite el precio de la propiedad: ";
    cin >> precio;
    cout << "Ingrese el nombre del barrio en el que se encuentra ubicada: ";
    cin.ignore(100, '\n');
    getline(cin, barrio);
    try{
        do{
            cout << "Seleccione el tipo de pago de la propiedad:\n1. Arrendamiento\n2. Venta" << endl;
            cin >> selec;
            if(selec == 1){
                tipo_pago = arrendamiento;
            } else if(selec == 2){
                tipo_pago = venta;
            } else{
                throw;
            }
            continuar = false;
        } while( continuar );
        continuar = true;
        do{
            cout << "Seleccione el tipo de la propiedad:\n1. Apartamento\n2. Apartaestudio\n3. Casa\n4. Lote\n5. Casa con renta\n6. finca" << endl;
            cin >> selec;
            switch( selec ){
                case 1:
                    tipo_propiedad = apartamento;
                    break;
                case 2:
                    tipo_propiedad = apartaestudio;
                    break;
                case 3:
                    tipo_propiedad = casa;
                    break;
                case 4:
                    tipo_propiedad = lote;
                    break;
                case 5:
                    tipo_propiedad = casa_con_renta;
                    break;
                case 6:
                    tipo_propiedad = finca;
                    break;
                default:
                    throw;
            }
            continuar = false;
        } while( continuar );
    } catch(...){
        cout << "Ingrese una opcion valida" << endl;
    }
    cout << "Ingrese la descripcion de la propiedad: " << endl;
    cin.ignore(100, '\n');
    getline(cin, desc);
    Propiedad propiedad(codigo, area, numAlcobas, numParks, numBanios, precio, barrio, tipo_pago, tipo_propiedad, desc);
    inmobiliaria.crearPropiedad(propiedad);
    codigo++;
}

int pedirCodigo(){
    int codigo;
    cout << "Digite el codigo de la propiedad: ";
    cin >> codigo;
    return codigo;
}

float pedirPrecio(){
    float precio;
    cout << "Digite el precio: ";
    cin >> precio;
    return precio;
}

string pedirBarrio(){
    string barrio;
    cout << "Ingrese el nombre del barrio que desea buscar: ";
    cin.ignore(100, '\n');
    getline(cin, barrio);
    return barrio;
}

void menu(int& selec){
    cout << "BIENVENIDO A STARINMOBILIARIA\nSeleccione que desea hacer: \n1. Crear propiedad\n2. Modificar propiedad\n3. Eliminar propiedad\n4. Listar propiedades\n5. Consultar propiedad segun precio minimo o maximo\n6. Consultar propiedad segun barrio\n7. Consultar propiedad segun tipo de pago\n8. Ordenar propiedades de menor a mayor precio\n0. Salir" << endl;
    cin >> selec;
}

int main(){
    int num, iterador, selec, codigo = 101;
    Inmobiliaria starInmobiliaria;
    do{
        menu(selec);
        switch( selec ){
            case 1:
                recogerDatosPropiedad(codigo, starInmobiliaria);
                break;
            case 2:
                iterador = starInmobiliaria.buscarPropiedad(pedirCodigo());
                starInmobiliaria.modificarPropiedad(iterador);
                break;
            case 3:
                iterador = starInmobiliaria.buscarPropiedad(pedirCodigo());
                starInmobiliaria.eliminarPropiedad(iterador);
                break;
            case 4:
                starInmobiliaria.listarPropiedades();
                break;
            case 5:
                cout << "Desea listar por precio minimo o maximo?\n1. Minimo\n2. Maximo" << endl;
                cin >> selec;
                if( selec == 1 ){
                    starInmobiliaria.listarPropiedadesPrecio(pedirPrecio(), 1);
                } else if( selec == 2 ){
                    starInmobiliaria.listarPropiedadesPrecio(pedirPrecio(), 2);
                } else{
                    cout << "Opcion no valida." << endl;
                }
                break;
            case 6:
                starInmobiliaria.listarPropiedadesBarrio(pedirBarrio());
                break;
            case 7:
                cout << "Seleccione el tipo de pago que desea consultar:\n1. Arrendamiento\n2. Venta" << endl;
                cin >> selec;
                if( selec == 1 ){
                    starInmobiliaria.listarPropiedadesTipoPago(1);
                } else if( selec == 2 ){
                    starInmobiliaria.listarPropiedadesTipoPago(2);
                } else{
                    cout << "Opcion no valida." << endl;
                }
                break;
            case 8:
                starInmobiliaria.ordenarMenorMayorPropiedades();
                cout << "El ordenamiento se realizo con exito!" << endl;
                break;
            case 0:
                cout << "Muchas gracias por hacer uso de este servicio" << endl;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    } while(selec != 0);

}