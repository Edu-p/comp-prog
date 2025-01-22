#include <iostream>
#include <string>
#include <vector>

using namespace std;

string is_beauty_towers(string f_tower, string s_tower){
    string full_string;
    full_string = f_tower + string(s_tower.rbegin(), s_tower.rend());
    
    int counter = 0;

    for (int i=0; i<full_string.size(); ++i){
        // checa se tem 3 repetidas
        char char_da_vez = full_string[i];
        if (full_string[i+1] == char_da_vez){
            counter++;
            if (counter>1){
                return "NO";
            }
        } 
    }
    
    // se nao passar em nenhum dos casos da para deixar beauty
    return "YES";
}

int main(){
    // leitura da entrada
    int qtd_tests;
    cin >> qtd_tests;
    
    for (int i=0; i<qtd_tests; ++i){
        int qtd_r;
        cin >> qtd_r;

        int qtd_l;
        cin >> qtd_l;

        string first_tower;
        cin >> first_tower;

        string second_tower;
        cin >> second_tower;

        cout << is_beauty_towers(first_tower, second_tower) << endl; 
    }

}