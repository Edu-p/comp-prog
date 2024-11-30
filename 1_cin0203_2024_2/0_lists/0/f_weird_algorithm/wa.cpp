#include <iostream>
#include <vector>

using namespace std;

void compute_sequence(long long n){

    long long n_of_int = n;

    cout << n_of_int << " ";

    while (n_of_int!=1){
        if (n_of_int % 2 == 0){
            n_of_int /= 2;
            if (n_of_int!=1){
                cout << n_of_int << " ";
            }
            else{
                cout << n_of_int;
            }
            
        }
        else{
            n_of_int = (n_of_int * 3) + 1;
            cout << n_of_int << " ";
        }
    }
}

int main(){
    long long n;
    cin >> n;

    compute_sequence(n);

    return 0;
}
