#include <bits/stdc++.h>

using namespace std;

bool is_under_deadline(long long n, long long d) {
    long long previous_num = -1;
    for (long long int j = 1; j < d; ++j) {
        if (j==1){
            previous_num = j + ceil(static_cast<float>(d) / (j + 1));
            if (n >= j + ceil(static_cast<float>(d) / (j + 1))) {
                return 1;
            }
        }
        else{
            if (j + ceil(static_cast<float>(d) / (j + 1)) > previous_num){
                return 0;
            }
            previous_num = j + ceil(static_cast<float>(d) / (j + 1));
            if (n >= j + ceil(static_cast<float>(d) / (j + 1))) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t; cin >> t;

    for (int i=0; i<t; ++i){
        long long n; cin >> n;
        long long d; cin >> d;

        if (n>=d){
            cout << "YES" << '\n';
        }   
        else{
            bool ret = is_under_deadline(n, d);
            if (ret){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    } 
}