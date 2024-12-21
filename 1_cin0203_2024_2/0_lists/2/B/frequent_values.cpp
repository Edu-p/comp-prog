#include <bits/stdc++.h>
using namespace std;

vector<long long> buildSegTree(vector<long long> &v) {
    long long n = v.size();

    vector<long long> seg(4*n, LONG_LONG_MIN);
    for (long long i = 0; i < n; i++){
        seg[n+i] = v[i];
    } 

    for (long long i = n-1; i > 0; i--){
        seg[i] = max(seg[2*i], seg[2*i+1]);
    } 
    return seg;
}

long long range_max_query(vector<long long> &seg, long long l, long long r, long long n) {
    l += n; 
    r += n; 
    long long ans = LONG_LONG_MIN;

    while (l <= r) {
        if (l % 2 == 1){
            ans = max(ans, seg[l++]);
        } 
        if ((r % 2) == 0){
            ans = max(ans, seg[r--]);
        } 
        l /= 2; 
        r /= 2;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        long long n; cin >> n;
        long long q; cin >> q;
        if (n==0){
            break;
        }

        vector<long long> a(n);

        for (long long i=0; i<n; i++){
            cin >> a[i];
        } 


        vector<long long> block_st, block_end, freq;
        vector<long long> block_idx(n);
        
        long long counter_groups = 0;
        block_st.push_back(0);
        block_idx[0] = 0;

        for (long long i=1; i<n; i++) {

            if (a[i]!=a[i-1]) {
                block_end.push_back(i-1);
                block_st.push_back(i);
                counter_groups++;
            }


            block_idx[i] = counter_groups;
        }

        block_end.push_back(n-1);


        for (long long i=0; i<block_st.size(); i++)
            freq.push_back(block_end[i]-block_st[i]+1);

        vector<long long> seg;
        if (!freq.empty()){
            seg = buildSegTree(freq);
        }
-
        for (long long i=0; i<q; i++){
            long long l; cin >> l;
            long long r; cin >> r; 
            l -= 1;
            r -= 1;


            long long bl = block_idx[l], br = block_idx[r];

            if (bl == br) {
                cout << r-l+1 << "\n";
                continue;
            }
            long long left_ans = block_end[bl]-l+1;
            long long right_ans = r - block_st[br] + 1;
            long long mid_ans = 0;
            if (bl+1<=br-1){
                mid_ans = range_max_query(seg,bl+1,br-1,freq.size());
            } 

            cout << max({left_ans,right_ans,mid_ans}) << "\n";
        }
    }
}
