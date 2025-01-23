#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    long long t_zeros = 0;

    for (long long num_to_divide=5; num_to_divide<=n; num_to_divide*=5){
        t_zeros += (n/num_to_divide);
    }
    
    cout << t_zeros << '\n';
}