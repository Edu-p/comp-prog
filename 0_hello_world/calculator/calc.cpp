/*
Calculadora Simples:

Crie um programa que peça ao usuário dois números e uma operação aritmética (+, -, *, /).
Use estruturas condicionais (if, switch) para executar a operação correspondente e exibir o resultado.
*/

#include <iostream>

int main(){
    double num1, num2;
    char operacao;

    // ask to user
    std::cout << "digite o primeiro numero: ";
    std::cin >> num1;

    std::cout << "digite o segundo numero: ";
    std::cin >> num2;

    std::cout << "digite a operacao: ";
    std::cin >> operacao;

    double resultado;
    bool valid_op = true;

    switch (operacao){
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2!=0){
                resultado = num1 / num2;
            }
            else {
                std::cout << "DIV POR 0";
                valid_op = false;
            }
            break;
        
        default:
            std::cout << "Entrada invalida" << std::endl;
            valid_op = false;
            return 1;

    }

    if (valid_op){
        std::cout << "Resultado: " << resultado << std::endl;
    }

    return 0;

}
