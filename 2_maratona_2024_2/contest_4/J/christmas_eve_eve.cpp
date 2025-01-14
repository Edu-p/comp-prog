#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<long long> main_vec(n);

    for (int i=0; i<n; ++i){
        int da_v; cin >> da_v;
        main_vec[i] = da_v;
    }

    sort(begin(main_vec), end(main_vec));

    main_vec[n-1] = main_vec[n-1]/2;

    long long sum = 0;
    
    for(int i=0; i<n; ++i){
        sum += main_vec[i];
    } 

    cout << sum;
}

