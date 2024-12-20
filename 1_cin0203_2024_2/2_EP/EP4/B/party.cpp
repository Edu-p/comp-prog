#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> main_vec;
    for (int i=0; i<n; ++i){
        int da_vez; cin >> da_vez;
        main_vec.push_back(da_vez);
    }

    int min_num_groups = 0;

    for (int i=1; i<=n; ++i){
        int qtd_til_minus_1 = 0;
        int pointer_boss = i;
        while (pointer_boss != -1){
            pointer_boss = main_vec[pointer_boss - 1];
            qtd_til_minus_1++;
        }
        min_num_groups = max(min_num_groups, qtd_til_minus_1);
    }

    cout << min_num_groups << '\n';

}