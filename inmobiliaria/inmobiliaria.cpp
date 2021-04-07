#include "inmobiliaria.h"

Inmobiliaria::Inmobiliaria(){}

void Inmobiliaria::crearPropiedad(Propiedad& propiedad){
    this->listaPropiedades.push_back(propiedad);
}

void Inmobiliaria::listarPropiedades(){
    for(int i = 0; i < this->listaPropiedades.size(); i++){
        listaPropiedades[i].mostrarPropiedad();
    }
}

int Inmobiliaria::buscarPropiedad(int codigo){
    for(int i = 0; i < this->listaPropiedades.size(); i++){
        if(this->listaPropiedades[i].getCodigo() == codigo){
            return i;
        }
    }
    cout << "No se encontro dicha propiedad" << endl;
    return 0;
}

void Inmobiliaria::modificarPropiedad(int pos){
    int selec, cambioInt;
    float cambioFloat;
    string cambioString;
    cout << "Que desea modificar de la propiedad?\n1. Area\n2. Numero de alcobas\n3. Numero de parqueaderos\n4. Numero de banios\n5. Precio\n6. Tipo de pago\n7. Tipo de propiedad\n8. Descripcion" << endl;
    cin >> selec;
    switch( selec ){
        case 1:
            cout << "Ingrese el nuevo area: ";
            cin >> cambioFloat;
            this->listaPropiedades[pos].setArea(cambioFloat);
            break;
        case 2:
            cout << "Ingrese el nuevo numero de alcobas: ";
            cin >> cambioInt;
            this->listaPropiedades[pos].setNumAlcob(cambioInt);
            break;
        case 3:
            cout << "Ingrese el nuevo numero de parqueaderos: ";
            cin >> cambioInt;
            this->listaPropiedades[pos].setNumPark(cambioInt);
            break;
        case 4:
            cout << "Ingrese el nuevo numero de banios: ";
            cin >> cambioInt;
            this->listaPropiedades[pos].setNumBan(cambioInt);
            break;
        case 5:
            cout << "Digite el nuevo precio: ";
            cin >> cambioFloat;
            this->listaPropiedades[pos].setPrecio(cambioFloat);
            break;
        case 6:
            cout << "Seleccione el nuevo tipo de pago de la propiedad:\n1. Arrendamiento\n2. Venta" << endl;
            cin >> cambioInt;
            this->listaPropiedades[pos].setTipoPago(cambioInt);
            break;
        case 7:
            cout << "Seleccione el nuevo tipo de la propiedad:\n1. Apartamento\n2. Apartaestudio\n3. Casa\n4. Lote\n5. Casa con renta\n6. finca" << endl;
            cin >> cambioInt;
            this->listaPropiedades[pos].setTipoProp(cambioInt);
            break;
        case 8:
            cout << "Ingrese la nueva descripcion: ";
            cin.ignore(100, '\n');
            getline(cin, cambioString);
            this->listaPropiedades[pos].setDescrip(cambioString);
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
    }
}

void Inmobiliaria::eliminarPropiedad(int pos){
    this->listaPropiedades.erase(this->listaPropiedades.begin() + pos);
}

void Inmobiliaria::listarPropiedadesPrecio(float precio, int op){
    if( op == 1){
        for(int i = 0; i < this->listaPropiedades.size(); i++){
            if(this->listaPropiedades[i].getPrecio() > precio){
                this->listaPropiedades[i].mostrarPropiedad();
            }
        }
    } else{
        for(int i = 0; i < this->listaPropiedades.size(); i++){
            if(this->listaPropiedades[i].getPrecio() < precio){
                this->listaPropiedades[i].mostrarPropiedad();
            }
        }
    }
}

void Inmobiliaria::listarPropiedadesBarrio(string barrio){
    for(int i = 0; i < this->listaPropiedades.size(); i++){
        if(this->listaPropiedades[i].getBarrio() == barrio){
            this->listaPropiedades[i].mostrarPropiedad();
        }
    }
}

void Inmobiliaria::listarPropiedadesTipoPago(int op){
    if( op == 1){
        for(int i = 0; i < this->listaPropiedades.size(); i++){
            if(this->listaPropiedades[i].getTipoPago() == arrendamiento){
                this->listaPropiedades[i].mostrarPropiedad();
            }
        }
    } else{
        for(int i = 0; i < this->listaPropiedades.size(); i++){
            if(this->listaPropiedades[i].getTipoPago() == venta){
                this->listaPropiedades[i].mostrarPropiedad();
            }
        }
    }
}

void Inmobiliaria::ordenarMenorMayorPropiedades(){
    Propiedad temp;
    for( int i = 0; i < this->listaPropiedades.size() - 1; i++ ){
        for( int j = 0; j < this->listaPropiedades.size() - 1; j++ ){
            if( this->listaPropiedades[ j ].getPrecio() > this->listaPropiedades[ j + 1 ].getPrecio() ){
            temp = this->listaPropiedades[ j ];
            this->listaPropiedades[ j ] = this->listaPropiedades[ j + 1 ];
            this->listaPropiedades[ j + 1 ] = temp;
            }
        }
    }
}