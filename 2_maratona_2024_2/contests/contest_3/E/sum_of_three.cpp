#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    long long x; cin >> x;

    vector<long long> vec_entrada;

    for (long long i=0; i<n; ++i){
        long long value; cin >> value;
        vec_entrada.push_back(value);
    }

    // fluxo principal
    long long qtd_prints = 0;
    bool already_printed = false;

    for (long long prim=0; prim<n; ++prim){
        if (already_printed == true){
            break;
        }

        if (vec_entrada[prim] <= x){
            for (long long sec=prim+1; sec<n; ++sec){
                if ((vec_entrada[prim] + vec_entrada[sec]) <= x){
                    for (long long tr=sec+1; tr<n; ++tr){
                        // cout << (prim) << " " << (sec) << " " << (tr) << '\n'; 
                        if ((((vec_entrada[prim]) + (vec_entrada[sec]) + (vec_entrada[tr])) == x) & (already_printed == false)) {
                            cout << (prim+1) << " " << (sec+1) << " " << (tr+1) << '\n';
                            already_printed = true;
                            qtd_prints++;
                        }
                    }
                } 
            }
        }        
    }


    if (qtd_prints==0){
        cout << "IMPOSSIBLE" << '\n';
    }
}