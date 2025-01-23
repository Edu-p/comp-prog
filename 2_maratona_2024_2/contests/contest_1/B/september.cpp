#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    // ler a entrada
    vector<string> vec_of_str;

    for (int i=0; i<12; ++i){
        string da_vez;
        cin >> da_vez;
        vec_of_str.push_back(da_vez);
    }

    // compute count_same
    int count_same = 0;
    for (int i=0; i<12; ++i){
        if (i+1 == vec_of_str[i].length()){
            count_same++;
        }
    }

    cout << count_same;

    return 0;
}