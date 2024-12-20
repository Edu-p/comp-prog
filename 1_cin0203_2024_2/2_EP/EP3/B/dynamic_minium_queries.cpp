#include <bits/stdc++.h>

using namespace std;

vector<long long> buildSegTree(vector<long long>& ref_main_vec){
    long long tam_main_vec = ref_main_vec.size();
    vector<long long> vec_seg_tree(4*tam_main_vec);

    for (long long i=0; i< tam_main_vec; ++i){
        vec_seg_tree[tam_main_vec+i] = ref_main_vec[i];
    }

    for (long long i=tam_main_vec-1; i>0; --i){
        vec_seg_tree[i] = min(vec_seg_tree[2*i], vec_seg_tree[2*i + 1]);
    }

    return vec_seg_tree;
}

void update(vector<long long>& ref_seg_tree, long long index, long long value, long long tam_main_vec){
    index += tam_main_vec;

    ref_seg_tree[index] = value;

    for (index /=2; index > 0; index/=2){
        ref_seg_tree[index] = min(ref_seg_tree[2*index], ref_seg_tree[2*index + 1]);
    }


}

long long range_min_query(vector<long long>& ref_seg_tree, long long left, long long right, long long tam_main_vec){
    left+= tam_main_vec;
    right+= tam_main_vec;

    long long min_val = LLONG_MAX;

    while(left <= right){
        if (left % 2 == 1){
            min_val = min(min_val, (long long)ref_seg_tree[left]);
            left++;
        }
        if (right % 2 == 0){
            min_val = min(min_val, (long long)ref_seg_tree[right]);
            right--;
        }

        left /= 2;
        right /= 2;
    }
    return min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long tam_array; cin >> tam_array;
    long long qtd_queries; cin >> qtd_queries;
    
    vector<long long> main_vec;

    for (long long i=0; i<tam_array; ++i){
        long long num; cin >> num;
        main_vec.push_back(num);
    } 

    vector<long long> seg_tree = buildSegTree(main_vec);

    for (long long i=0; i<qtd_queries; ++i){
        long long type_of_query; cin >> type_of_query;

        if (type_of_query == 1){
            // update 
            long long k; cin >> k;
            long long u; cin >> u;

            main_vec[k-1] = u; // update original

            update(seg_tree, k-1, u, tam_array); // update bit
        }
        else if (type_of_query == 2){
            // rsq[a,b]
            long long a; cin >> a;
            long long b; cin >> b;
            cout << range_min_query(seg_tree, a-1, b-1, tam_array) << '\n';
        }


    }
    return 0;
}