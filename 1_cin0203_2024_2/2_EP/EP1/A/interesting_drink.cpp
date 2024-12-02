#include <bits/stdc++.h>

using namespace std;

void how_many_greater_with_binary_search(long long num, vector<long long>& vec_to_make_bs){
    long long index_of_start = 0;
    long long index_of_end = vec_to_make_bs.size() - 1;
    long long answer = -1;

    while(index_of_end >= index_of_start){
        long long mid = (index_of_start+index_of_end) / 2;

        // ir para direita se o num procurado por maior que o do index do meio, caso contrario ir para esquerda 
        if (num >= vec_to_make_bs[mid]){
            index_of_start = mid+1;
        }
        else{
            answer = mid;
            index_of_end = mid - 1;
        }
    }
    if (answer == -1){
        cout << vec_to_make_bs.size() << "\n";
    }
    else{
        cout << answer << "\n";
    }
    
    
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

    // for (auto price : prices){
    //     cout << price << " ";
    // }

    for (long long p=0; p<j; ++p){
        long long value_to_eval; cin>>value_to_eval; 
        how_many_greater_with_binary_search(value_to_eval, prices);
    }

}
