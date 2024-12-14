#include <bits/stdc++.h>

using namespace std;

bool is_valid(vector<long long>& ref_main_vec, int k, long long mid, long long l, long long r){
    long long qtd_ks = 1;
    long long parc_sum = 0;
    for (long long i=0; i<ref_main_vec.size(); ++i){
        if ((parc_sum+ref_main_vec[i])<=mid){
            parc_sum+=ref_main_vec[i];
        }
        else{
            qtd_ks+=1;
            parc_sum = ref_main_vec[i];
        }
    }

    return k>=qtd_ks;
}

long long bs_with_is_valid(vector<long long>& ref_main_vec, int k){
    // achar maior numero 
    vector<long long> find_min(ref_main_vec.size());
    for (long long i=0; i<ref_main_vec.size(); ++i){
        find_min[i] = ref_main_vec[i];
    }
    sort(find_min.begin(), find_min.end());

    long long large_value = find_min[find_min.size()-1];

    // fazer soma de todos os numeros
    long long sum=0;
    for (long long i=0; i<ref_main_vec.size(); ++i){
        sum+=ref_main_vec[i];
    }

    // fazer binary search
    long long r = sum;
    long long l = large_value;

    while (r>l){
        long long mid = (l+r)/2;
        if (is_valid(ref_main_vec, k, mid, l, r)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }

    return r;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long k; cin >> k;

    vector<long long> main_vec(n); 

    for (int i=0; i<n; ++i){
        long long num; cin >> num;
        main_vec[i] = num;
    }

    cout << bs_with_is_valid(main_vec, k) << "\n";

}