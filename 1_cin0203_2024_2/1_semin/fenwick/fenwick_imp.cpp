/*
Functions related to BIT 
*/

#include <iostream>
#include <vector>

using namespace std;

int sum_bit(int i, const vector<int>& BIT){
    /*
        retorna a soma do intervalo [0,n]
    */
    int ret = 0;

    // pegando o lssb -> i-= (i & -i)
    for (;i>0; i-= (i & -i)){
        ret += BIT[i];
    }

    return ret;
}

void update(int i, int v, vector<int>& BIT){
    /*
        atualiza o vetor BIT com o valor v no indice i do vetor original
    */
   int tam_bit = BIT.size();
   for(; i<tam_bit; i+= (i & -i)){
        BIT[i]+=v; 
   }
}

int main(){
    vector<int> BIT(11, 0);
    // initialize fenwick vector
    BIT[0] = 0;
    
    update(1, 1, BIT);
    update(2, 2, BIT);
    update(3, 3, BIT);
    update(4, 4, BIT);
    update(5, 5, BIT);

    int ub; cin>>ub;

    int soma = sum_bit(ub, BIT);
    cout << soma << endl;

    return 0;

}