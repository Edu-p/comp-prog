/*to fix*/
#include <iostream>
#include <cmath>
using namespace std;

void compute_dc(long long n){
    long long p = 1;
    long long to_mod = 1000000007; // max int 2147483647
    for (long long i=0; i<n-1; ++i){
        p = (2*p) % to_mod;
    }
    cout << p; 
}

int main() {
    long long n;

    cin >> n;

    compute_dc(n);
    return 0;
}

