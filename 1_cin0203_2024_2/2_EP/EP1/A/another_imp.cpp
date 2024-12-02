#include <bits/stdc++.h>

using namespace std;

void how_many_greater_with_binary_search(long long num, vector<long long>& vec_to_make_bs){
    long long left_index = 0;
    long long right_index = vec_to_make_bs.size() - 1;
    long long answer = -1;

    while (right_index >=left_index){ //maior igual para ir mais parar esquerda nos numeros repetidos
        // calcula meio do vetor 
        long long mid = (left_index + right_index)/2;

        // se for maior vai para direita para procurar o primeiro maior(que vai retornar o indice certo(qtd de numeros menores que o num))
        if (num >= vec_to_make_bs[mid]){
            left_index = mid + 1;
        } 
        // senao vai para esquerda, e armazena o possivel numero que vai dar a qtd de numeros maiores
        else{
            answer = mid;
            right_index = mid - 1;
        }
        
        if (answer == -1){
            answer = vec_to_make_bs.size();
        }
    }

     cout << answer << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //leitura da entrada
    long long n; cin >> n;
    
    vector<long long> prices(n);
    for (long long i=0; i<n; ++i){
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    long long j; cin >> j;

    for (long long p=0; p<j; ++p){
        long long value_to_eval; cin>>value_to_eval; 
        how_many_greater_with_binary_search(value_to_eval, prices);
    }

}
