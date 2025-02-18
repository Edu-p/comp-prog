#include <bits/stdc++.h>

using namespace std;

long long sumDiv(long long n){
    long long sum = 0;
    for (long long i=1; i*i <= n; ++i){
        if((n%i) == 0){
            sum += i;
            if(i != (n/i)){
                sum += (n/i);
            } 
        }
    }
    return sum;
}

int main() {
    int num_da_vez;
    int counter = 1;
    while (true){
        cin >> num_da_vez;
        if (num_da_vez == 0){
            break;
        }
        if (num_da_vez == 1){
            cout<<"Case "<<counter<<": 1\n";
            counter += 1;
            continue;
        }

        int resp = -1;
        for (long long n=2; n<=num_da_vez; ++n){
            if(sumDiv(n) == num_da_vez){
                resp = n;
            }
        }
        
        cout<<"Case "<<counter<<": "<< resp << "\n";
        counter += 1;
        

    }
}