#include <iostream>
#include <fstream>
#include <string>
#define CAP 100
using namespace std;

class contact{
    public:
        string name;
        string lastName;
        int telephoneNumber;
};

contact addContact(){
    contact c1;
    std::cout << "Ingrese su nombre: ";
    cin.ignore(100, '\n');
    getline(std::cin, c1.name);
    std::cout << "Ingrese su apellido: ";
    cin.ignore(100, '\n');
    getline(std::cin, c1.lastName);
    std::cout << "Ingrese su numero telefonico: ";
    std::cin >> c1.telephoneNumber;
    return c1;
}

void create(contact * array, int n){
    std::ofstream outfile("contactos.txt");
    for(int i = 0; i < n; i++){
        outfile << "----------------\n" << "Nombre: " << array[i].name << "\nApellidos: " << array[i].lastName << "\nNumero telefonico: " << array[i].telephoneNumber << "\n";
    }
    outfile << "----------------\n";
    outfile.close();
}

void showContacts(contact * array, int n){
    for(int i = 0; i < n; i++){
        std::cout << "----------------\n" << "Nombre: " << array[i].name << "\nApellidos: " << array[i].lastName << "\nNumero telefonico: " << array[i].telephoneNumber << "\n";
    }
    std::cout << "----------------\n";
}

void menu(){
    int selec, n = 0;
    contact contactsList[CAP];
    do{
        std::cout << "Seleccione una opcion: \n1. Crear\n2. Agregar mas contactos\n3. Visualizar contactos\n4. Salir\n";
        std::cin >> selec;
        switch( selec ){
            case 1: 
                create(contactsList, n);
                break;
            case 2:
                contactsList[n] = addContact();
                n++; 
                break;
            case 3:
                showContacts(contactsList, n); 
                break;
            case 4: 
                std::cout << "Muchas gracias, tenga wuen dia\n";
                break;
            default: 
                std::cout << "Ingrese una opcion valida\n"; 
                break;
        }

    } while(selec != 4);

}

int main(){
    menu();
    return 0;
}

