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
    int tam_max = 0;

    for (const auto &str_da_vez : main_vec){
        tam_max = max(static_cast<int>(str_da_vez.size()), tam_max);
    }

    for (auto &str_da_vez : main_vec){
        if (str_da_vez.size() < tam_max){
            str_da_vez.append(string(tam_max - str_da_vez.size(), '*'));
        }
    }

    for(int j=0; j< tam_max; ++j){
        string result_row;
        for(int i=n - 1; i>=0; --i){
            result_row += main_vec[i][j];
        }
        while (!result_row.empty() && result_row.back() == '*'){
            result_row.pop_back();
        }
        cout << result_row << '\n';
    }
    return 0;

}
