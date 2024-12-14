#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void who_winner(vector<int>& ref_candi){
    int qtd_votes_bigger = 0;
    int index_votes_bigger = 0;

    for (int i=0; i<ref_candi.size(); ++i) {
        if (ref_candi[i]>qtd_votes_bigger){
            qtd_votes_bigger = ref_candi[i];
            index_votes_bigger = i;
        }
    }
    
    cout <<  index_votes_bigger+1 << endl;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> candi(n);

    for (int i=0; i<n; ++i){
        candi[i] == 0;
    }
    
    int m;
    cin >> m;
    vector<int> votes(m);

    for (int i=0; i<m; ++i){
        int vote;
        cin >> vote;
        candi[vote-1] += 1;
        who_winner(candi);
    }
}