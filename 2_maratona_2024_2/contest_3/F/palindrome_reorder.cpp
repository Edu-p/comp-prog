#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // le a palavra
    string palavra_to_analy;
    cin >> palavra_to_analy;

    // faz um map para armazenar a quantidade de cada letra
    map <char, int> mapa_letras;

    for (auto letra : palavra_to_analy){
        mapa_letras[letra] += 1;
    }

    // for (auto [key, value]: mapa_letras){
    //     cout << key << " - " << value << '\n';
    // }

    // checa se tiver mais de 1 com numeros impares 
        // se tiver printa NO SOLUTION
    
    int count_imp = 0;

    for (auto [key, value]: mapa_letras){
        if ((value%2)==1){
            count_imp++;
        }
    }

    if (count_imp > 1){
        cout << "NO SOLUTION";
    }
    else{
        // se nao printar o NO SOLUTION faz a palavra palindromo
        // pegar a quantidade de letras total
        int qtd_letras_total = 0;
        for (auto [key, value]: mapa_letras){
            qtd_letras_total+=value;
        }

        // pegar a quantidade de vezes da letra impar
        string string_final;
        int qtd_letras_imp = 0;
        char letra_imp;

        for (auto [key, value]: mapa_letras){
            if ((value%2)==1){
                qtd_letras_imp = value;
                letra_imp = key;
            }
        }

        for (int i=0; i<qtd_letras_total; ++i){
            string_final.push_back('*');
        }

        // colocar a letra impar no centro
        int pos_mid = qtd_letras_total/2;
        string_final[pos_mid] = letra_imp;
    
        // rodar por (qtd_letras_imp-1)/2 vezes a atribuição na string final do char imp
        for (int i=0; i <= ((qtd_letras_imp-1)/2); ++i){
            string_final[pos_mid+i] = letra_imp;
            string_final[pos_mid-i] = letra_imp;
        } 

        // atribuir as pares
        // int qtd_vezes_rodar_pares = (qtd_letras_total - qtd_letras_imp)/2;
        int counter_to_qtd = 0;

        for (auto [key, value]: mapa_letras){
            if ((value%2)==0){
                for (int i=0; i < (value/2); ++i){
                    string_final[counter_to_qtd] = key;
                    string_final[(qtd_letras_total - counter_to_qtd)-1] = key;
                    counter_to_qtd++;
                }
            }
        }

        cout << string_final;
    }

    
}