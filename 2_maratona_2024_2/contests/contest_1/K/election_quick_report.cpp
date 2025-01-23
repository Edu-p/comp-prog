#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> candi(n, 0);

    for (int i=0; i<n; ++i){
        candi[i] = 0;
    }
    
    int m;
    cin >> m;
    vector<int> votes(m);
    tuple<int, int> info_winner = {0, 0};

    /*
        (n_of_winner, how_many_votes_winner)
    */ 

    for (int i=0; i<m; ++i){
        int vote;
        cin >> vote;
        candi[vote-1] += 1;

        if (i==0) {
            get<0>(info_winner) = vote;
            get<1>(info_winner) = candi[vote-1]; 
        }
        else {
            // if candi[vote-1] > get<1>
            if ((candi[vote-1] > get<1>(info_winner)) || (candi[vote-1] == get<1>(info_winner)  && vote < get<0>(info_winner))){
                get<0>(info_winner) = vote;
                get<1>(info_winner) = candi[vote-1];
            }
        }
        cout << get<0>(info_winner) << "\n";
    }
}