#include <bits/stdc++.h>

using namespace std;

long long compute_nearly_full(vector<long long>& vec_ref){
    long long counter_0 = 0;
    long long counter_1 = 0;

    for (long long i = 0; i<vec_ref.size(); ++i){
        if (vec_ref[i] == 0){
            counter_0 += 1;
        }
        if (vec_ref[i] == 1){
            counter_1 += 1;
        } 
    }

    if (counter_1>0){
        return counter_1 * (1LL << counter_0);
    }
    else{
        return 0; 
    }
    
}

int main() {
    long long num_tests; cin >> num_tests;
    for (long long i = 0; i<num_tests; ++i){

        long long tam_vec; cin >> tam_vec;
        vector<long long> main_vec_da_vez(tam_vec);

        for (long long it_vec = 0; it_vec < tam_vec; ++it_vec){
            long long da_vez; cin >> da_vez;
            main_vec_da_vez[it_vec] = da_vez;
        }

        cout << compute_nearly_full(main_vec_da_vez) << '\n';
    }
}