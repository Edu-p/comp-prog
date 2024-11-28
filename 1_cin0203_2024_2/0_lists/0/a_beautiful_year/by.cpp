#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_beauty_year(int input){
    vector<int> vec_gt = {0,0,0,0,0,0,0,0,0,0};

    int num_interativo = input;

    for (int i=0; i<=3; i++) {
        int mod_do_num_interativo = num_interativo % 10;
        vec_gt[mod_do_num_interativo] += 1;
        num_interativo /= 10;
    } 

    for (int num : vec_gt){
        if (num>1){
            return false;
        }
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int input;
    cin >> input;

    int num_of_int = input;
    num_of_int++;

    while (!is_beauty_year(num_of_int)){
        num_of_int++;
    }

    cout << num_of_int;

    return 0;
}

