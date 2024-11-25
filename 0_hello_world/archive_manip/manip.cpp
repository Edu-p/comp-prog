/*
Manipulação de Arquivos:
Escreva um programa que leia um arquivo de texto e conte o número de palavras, linhas e caracteres.
Exiba essas informações na tela.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
    std::ifstream arch("some_words.txt");

    int num_linhas = 0, num_palavras = 0, num_caracteres = 0;

    std::string linha;

    while (std::getline(arch, linha)){
        num_linhas++;
        num_caracteres += linha.size();

        std::istringstream iss(linha);
        std::string palavra;

        while(iss >> palavra){
            num_palavras++;
        }

        num_caracteres++;

    }
    
    std::cout << num_palavras << std::endl;
    std::cout << num_linhas << std::endl;
    std::cout << num_caracteres << std::endl;

    arch.close();

    return 0;
}
