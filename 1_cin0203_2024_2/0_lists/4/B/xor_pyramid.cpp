#include <bits/stdc++.h>

using namespace std;

int main() {
    int tam; cin >> tam;
    vector<int> main_vec(tam); 

    for (int i = 0; i<tam; ++i){
        int num_vez; cin >> num_vez;
        main_vec[i] = num_vez;
    }

    int xor_cumul = 0;
    for (int i=0; i < tam; ++i){
        if(((tam-1)&i)==i) {  
            xor_cumul ^= main_vec[i];
        }
    }

    cout << xor_cumul << '\n';
}