#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int frosh_number = 1;

    // depois ajeitar leitura da entrada, não tô sabendo ainda acessar 
    cin >> frosh_number;

    map<set<int>, int> mapa_main;

    for (int i=0; i<frosh_number; ++i){
        set<int> set_of_course;
        for (int j=0; j<5; ++j){
            int course_number; cin >> course_number;
            set_of_course.insert(course_number);
        }
        mapa_main[set_of_course]+=1;
    }

    for (auto [key, value] : mapa_main){
        for (auto val_set : key){
            cout << val_set << " ";
        }
        cout << value;
    }



}