#include <bits/stdc++.h>

using namespace std;

bool is_ok_sudoku_main_matrix(vector<vector<int>>& matrix_to_verify, int n){
    for (int j=0; j<n; ++j){
        set<int> line;
        set<int> column;
        for (int k=0; k<n; ++k){
            line.insert(matrix_to_verify[j][k]);
            column.insert(matrix_to_verify[k][j]);
        }
        if ((n>line.size()) | (n>column.size())){
            return 0;
        } 
    }
    return 1;
}

bool is_ok_sudoku_sub(vector<vector<int>>& matrix_to_verify, int n){
    int n_aux = n*n;
    set<int> all_values;

    for (int j=0; j<n; ++j){
        for (int k=0; k<n; ++k){ 
            all_values.insert(matrix_to_verify[k][j]);
        }
    }

    if ((n_aux>all_values.size())){
        return 0;
    } 
    return 1;
}


int step_sqrt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int qtd_tsts; cin >> qtd_tsts;
    for (int i=0; i<qtd_tsts; ++i){
        int n; cin >> n;
        vector<vector<int>> main_matrix(n, vector<int>(n, 0));
        for (int j=0; j<n; ++j){
            for (int k=0; k<n; ++k){
                int to_read; cin >> to_read;
                main_matrix[j][k] = to_read;
            }
        }

        // verify if it ok 
        int count_ok_subs=0;

        step_sqrt = sqrt(n); 

        for (int itc=0; itc<n;itc=itc+step_sqrt){
            for (int itl=0; itl<n; itl=itl+step_sqrt){
                vector<vector<int>> aux_vec(step_sqrt, vector<int>(step_sqrt, 0));
                for (int p=0; p<step_sqrt; ++p){
                    for (int j=0; j<step_sqrt; ++j){
                        //atribuir sempre na [p+itc][j+itl]
                        aux_vec[p][j] = main_matrix[p+itc][j+itl];
                    }
                }                
                if (is_ok_sudoku_sub(aux_vec, step_sqrt)){
                    count_ok_subs++;
                }
            }
        }
        static_cast<int>(n);
        static_cast<int>(count_ok_subs);
        if ((is_ok_sudoku_main_matrix(main_matrix, n)) && (count_ok_subs==n)){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
        
    }
}
