#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ler entrada
    int n; cin >> n;

    vector<string> main_vec;

    for (int i=0; i<n; ++i){
        string da_vez; cin >> da_vez;
        main_vec.push_back(da_vez);
    }

    // encontrar o tamanho da maior string 
    int tam_max = INT_MIN;

    for (auto str_da_vez : main_vec){
        tam_max = max(static_cast<int>(str_da_vez.size()), tam_max);
    }

    for (auto str_da_vez : main_vec){
        if (str_da_vez.size() < tam_max){
            for (int i=(tam_max-str_da_vez.size()); i<tam_max; ++i){
                str_da_vez.append("*");
            }
        }
    }

    for (auto str_da_vez : main_vec){
        cout << str_da_vez << '\n';
    }

    // // da ultima string para a primeira  
    // for (int j=0; j<tam_max; ++j){
    //     for (int i=(main_vec.size() - 1); i>=0; --i){
    //         cout << main_vec[i][j];
    //     }
    //     cout << '\n';
    // }
    

}
