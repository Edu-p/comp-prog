/*
Funções e Recursão:
Implemente uma função recursiva para calcular o fatorial de um número inteiro positivo fornecido pelo usuário.
*/

#include <iostream>

int fat(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*fat(n-1);
    }
}

int main(){
    int num;
    std::cout << "Digite um numero inteiro positivo: ";
    std::cin >> num;
    std::cout << fat(num);
}