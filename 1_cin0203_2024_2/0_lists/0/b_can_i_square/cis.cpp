#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string is_square(vector<long long>& a_vec_ref){
    // soma dos elementos do vetor
    long long sum = 0;
    for (int num : a_vec_ref){
        sum += num;
    }

    // calcula parte inteira da raiz
    long long sqrt_int = static_cast<long long>(sqrt(sum));

    // multiplica o numero por ele mesmo e vê se bate
    if ((sqrt_int*sqrt_int)!=sum){
        return "NO";
    }
    else{
        return "YES";
    }

}

int main(){
    // tratamento da entrada e chamando metodo
    long long qtd_tests;
    cin >> qtd_tests;

    for (int i=0; i<qtd_tests; ++i){
        long long n;
        cin >> n;

        vector<long long> vec_a(n);

        for (int i=0; i<n; ++i){
            cin >> vec_a[i];
        }

        cout << is_square(vec_a) << endl;

    }

}