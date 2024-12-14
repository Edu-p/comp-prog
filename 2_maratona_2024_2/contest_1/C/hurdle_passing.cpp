#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec_in_format(string& str){
    vector<int> to_format;
    int count_tam = 0;
    for (int i=1; i<str.length(); ++i){
        if (str[i] == '|'){
            to_format.push_back(count_tam);
            count_tam=0;
        }
        else{
            count_tam++;
        }
    }

    for (int i=0; i<to_format.size(); ++i){
        if (i!=(to_format.size()-1)){
            cout << to_format[i] << " ";
        }
        else{
            cout << to_format[i];
        }
    }
}

int main(){
    // ler a entrada
    string main_str;
    cin >> main_str;

    print_vec_in_format(main_str);
    
}