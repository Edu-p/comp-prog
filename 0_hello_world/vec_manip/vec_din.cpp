/*
Crie um vetor de inteiros com 10 elementos.
Preencha o vetor com valores inseridos pelo usuário.
Calcule e exiba a soma, a média, o maior e o menor valor do vetor.
*/
// array -> fixo 
// vector -> dinamico (MUDA COMPLEXIDADE DE TEMPO DAS OPERACOES QUE ENVOLVEM BUSCA POR EX)


#include <iostream>
#include <climits>
#include <vector>

int main(){
    std::vector<int> vec;

    // só o sizeof retorna o umero de bytes
    size_t tam_vec = 10;

    
    for (size_t i=0; i<tam_vec; ++i){
        int value;
        std::cout << "Digite o valor: ";
        std::cin >> value;
        vec.push_back(value);
    }
    
    int sum = 0;
    for (int num:vec){
        sum += num;
    }

    float mean = static_cast<float>(sum) / tam_vec;

    int maior = INT_MIN;
    int menor = INT_MAX;

    for (int num:vec){
        if (num>maior){
            maior=num;
        }
        if (num<menor){
            menor=num;
        }
    }
    
    std::cout << "soma " << sum << std::endl;
    std::cout << "media " << mean << std::endl;
    std::cout << "maior " << maior << std::endl;
    std::cout << "menor " << menor << std::endl;
    
    return 0;
}


