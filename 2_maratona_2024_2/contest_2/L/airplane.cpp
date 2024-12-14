#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> cost_fl(3);

    for (int i=0; i<cost_fl.size(); ++i){
        int cost; cin >> cost;
        cost_fl[i] = cost;
    }

    sort(begin(cost_fl), end(cost_fl));

    int sum = 0;
    sum = cost_fl[0] + cost_fl[1];

    cout << sum;

}