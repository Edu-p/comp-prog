#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long find_mininum(long long n, vector<int>& a_vec_ref, vector<int>& b_vec_ref){
    // achar o minimo de cada um (algoritmo de busca melhor para achar esse valor)
    long long min_a = INT_MAX;
    long long min_b = INT_MAX;

    for (long long num_a : a_vec_ref){
        if (num_a < min_a){
            min_a = num_a;
        }
    }

    for (long long num_b : b_vec_ref){
        if (num_b < min_b){
            min_b = num_b;
        }
    }

    // diminuir o minimo de cada um de cada elemento 
    for (long long i=0; i<a_vec_ref.size(); ++i){
        a_vec_ref[i] -= min_a;
    }

    for (long long i=0; i<b_vec_ref.size(); ++i){
        b_vec_ref[i] -= min_b;
    }

    // criar um novo vetor c que vai ser o máximo em cada um dos indices compartilhados
    vector<int> vec_c(n);

    for (long long i=0; i<n; ++i){
        if (a_vec_ref[i] > b_vec_ref[i]){
            vec_c[i] = a_vec_ref[i];
        }
        else {
            vec_c[i] = b_vec_ref[i];
        }   
    }

    // somar todos os elementos do vetor c(da para usar fenwick)
    long long soma = 0;

    for (long long num : vec_c){
        soma += num;
    }

    // retornar essa soma
    return soma;
}

int main(){
    long long qtd_tests;
    cin >> qtd_tests;

    for (long long i=0; i<qtd_tests; ++i){
        long long n;
        cin >> n;

        vector<int> vec_a(n), vec_b(n);

        // capturando entrada
        for (long long i=0; i<n; i++){
            cin >> vec_a[i];
        } 

        for (long long i=0; i<n; i++){
            cin >> vec_b[i];
        }

        long long minimum = find_mininum(n, vec_a, vec_b);
        cout << minimum << endl;
    }
    
    return 0;
}