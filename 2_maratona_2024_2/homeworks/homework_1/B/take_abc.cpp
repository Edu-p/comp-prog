#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    stack<char> st;

    for (char c : s){
        st.push(c);

        if (st.size() >= 3){
            char c3 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            char c1 = st.top(); st.pop();

            if (c1!='A' || c2!='B' || c3!='C'){
                st.push(c1);
                st.push(c2);
                st.push(c3);
            }
        }
    }

    string to_print;
    while (!st.empty()){
        to_print.push_back(st.top());
        st.pop();
    }
    reverse(to_print.begin(), to_print.end());

    cout << to_print << '\n';

}
