#include <bits/stdc++.h>

using namespace std;

long long size_of_longest_good_array(long long l, long long r){
    if (l==r){
        return 1;
    }

    long long counter = 0;
    long long parc_sum = l;

    long long first_after = 1;
    long long second_after = 2;

    while ((parc_sum+first_after+second_after)<=r){
        counter++;
        parc_sum += first_after;
        first_after++;
        second_after++;
    }

    return counter + 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //leitura da entrada
    long long n; cin >> n;

    for (long long p=0; p<n; ++p){
        long long l; cin>>l;
        long long r; cin>>r;

        cout << size_of_longest_good_array(l, r) << "\n";
    }

}
