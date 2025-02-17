#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_input;
    cin >> num_input;

    int counter = 0;

    for (int h=1; h*h<= num_input; h++){
        for (int w=h; w * h <= num_input; w++){
            counter++;
        }     
    }

    cout << counter << '\n';

}