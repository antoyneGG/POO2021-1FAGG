#include <iostream>

class person{
    public:
        int age;
        char genre[10];
        float height;
};

int main(){
    person user;
    std::cout << "Ingrese su edad: ";
    std::cin >> user.age;
    std::cout << "Ingrese su sexo: ";
    std::cin >> user.genre;
    std::cout << "Ingrese su altura en metros: ";
    std::cin >> user.height;
    std::cout << "-------------\nEdad: " << user.age << "\nSexo: " << user.genre << "\nAltura: " << user.height << "\n-------------\n";
    return 0;
}