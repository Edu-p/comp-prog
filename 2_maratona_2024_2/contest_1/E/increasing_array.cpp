#include <iostream>
#include <vector>

using namespace std;

void modify_print_array(vector<long long >& to_modify){
    long long  count_to_print = 0;

    if (to_modify.size()!=0){
        for (long long  i=1; i<to_modify.size(); ++i){
            if (to_modify[i-1]>to_modify[i]){
                count_to_print += (to_modify[i-1] - to_modify[i]);
                to_modify[i] = to_modify[i-1];
            }
        }
        // printando o valor final
        cout << count_to_print;
    }   
    else{
        // printando o valor final
        cout << count_to_print;
    }
}

int main(){
    long long  n;
    cin >> n;

    vector<long long > main_vec;

    for (long long  i = 0;i<n;++i){
        long long  num_to_add;
        cin >> num_to_add;
        main_vec.push_back(num_to_add);
    }

    modify_print_array(main_vec);

    return 0;
}
