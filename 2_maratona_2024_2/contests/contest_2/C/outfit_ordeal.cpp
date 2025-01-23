#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    stack<string> clothes;

    for (int i=0; i<n; ++i){
        string clothes_or_command; cin >> clothes_or_command;
        string put_str = "put";
        if (!put_str.compare(clothes_or_command)){
            cin >> clothes_or_command;
            clothes.push(clothes_or_command);
        }

        string get_str = "get";
        if((!get_str.compare(clothes_or_command)) && !(clothes.empty())){
            cout << clothes.top();
            clothes.pop();
        }

        string iditarod_str = "iditarod";
        if(!iditarod_str.compare(clothes_or_command)){
            stack<string> stack_aux;

            bool have_snowcoat = 0;

            string snowcoat_str = "snowcoat";
            // enquanto o que tiver no topo da pilha main nao for o snowcoat
            while((snowcoat_str.compare(clothes.top()) && (!(clothes.empty())))){
                stack_aux.push(clothes.top());
                clothes.pop();
            }

            if(!snowcoat_str.compare(clothes.top())){
                have_snowcoat = 1;
            }
            
            if (!have_snowcoat){
                cout << "oopsimcold :(" << '\n';
            }
            else{
                cout << "winner winner chicken dinner :)" << '\n';
            }

            while(!stack_aux.empty()){
                clothes.push(stack_aux.top());
                stack_aux.pop();
            }
        }
    }
}

 // while (!clothes.empty()){
        //     cout << clothes.top() << '\n';
        //     clothes.pop();
        // }