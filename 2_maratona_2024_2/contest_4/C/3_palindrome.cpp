#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;

    long long mod = n % 2;
    long long qtd_times_full = n/2;

    bool last_a = false;
    bool last_b = true;

    for (long long i=0; i<qtd_times_full; ++i){
        if (i%2 == 0){
            cout << "aa";
            last_b = false;
            last_a = true;
        }
        else{
            cout << "bb";
            last_b = true;
            last_a = false;
        }
    }

    if ((mod == 1) & (last_b)){
        cout << "a";
    }
    if ((mod == 1) & (last_a)){
        cout << 