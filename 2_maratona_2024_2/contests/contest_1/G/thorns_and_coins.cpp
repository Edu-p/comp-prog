#include <iostream>
#include <vector>

using namespace std;

int how_many_coins(vector<char>& ref_a_vec){
    int qtd_coins = 0;
    
    // somar todos os coins
    for (char carac : ref_a_vec){
        if (carac == '@') {
            qtd_coins++;
        }
    }

    // encontrar o ** e pegar o indice do segundo *
    int index_sec = -1;
    for (int i = 0; i<ref_a_vec.size(); ++i){
        if (ref_a_vec[i] == '*' && ref_a_vec[i+1] == '*') {
            index_sec = i+1;
            break;
        }
    }

    // ver quantos coins estao depois dessa posicao do segundo "*"
    int qtd_coins_to_remove = 0;
    for (int i=index_sec; i<ref_a_vec.size(); ++i){
        if (ref_a_vec[i] == '@'){
            qtd_coins_to_remove++;
        }
    }

    // subtrair essa quantidade de coins do somatorio total das coins 
    int to_return = qtd_coins - qtd_coins_to_remove;


    return to_return;
}   

int main(){
    // leitura da entrada
    int qtd_tests;
    cin >> qtd_tests;
    
    for (int i=0; i<qtd_tests; ++i){
        int n;
        cin >> n;

        vector<char> vec_a(n);

        for (int i=0; i<n; ++i){
            cin >> vec_a[i];
        }

        cout << how_many_coins(vec_a) << endl;

    }

}


