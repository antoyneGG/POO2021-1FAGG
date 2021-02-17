#include <iostream>
const float iva = 0.19;

int ivaCalculation(int price){
    return price * iva;
}

int main(){
    float price;
    std::cout << "Ingrese el precio del producto: ";
    std::cin >> price;
    std::cout << "El precio del producto con el IVA aplicado es: " << price + ivaCalculation(price) << "\n";
    return 0;
}