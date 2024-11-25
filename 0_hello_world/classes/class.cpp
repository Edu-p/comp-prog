/*
Estruturas e Classes Simples:
Defina uma estrutura (struct) ou classe chamada Pessoa com atributos como nome, idade e altura.
Crie uma função que receba um objeto Pessoa e exiba seus dados formatados.
*/

#include <iostream>
#include <string>

class Pessoa{
    public:
        std::string nome;
        int idade;
        float altura;
};

void mostrar_dados(Pessoa p){
    std::cout << "Nome: " << p.nome << std::endl;
    std::cout << "Idade: " << p.idade << std::endl;
    std::cout << "Altura: " << p.altura << std::endl;
}

int main(){
    Pessoa p1;
    p1.nome = "Roberto";
    p1.idade = 26;
    p1.altura = 1.86;

    mostrar_dados(p1);
}
