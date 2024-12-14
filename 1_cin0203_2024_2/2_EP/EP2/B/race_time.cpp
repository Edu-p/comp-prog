#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;


double f_x(double T, vector<int>& ref_s_of_racers, vector<int>& ref_k_of_racers){
    double max_position = 0;
    double min_position = 1000000000;

    for (int i=0; i<ref_s_of_racers.size(); ++i){
        double current_position = (ref_s_of_racers[i] * T) + ref_k_of_racers[i];
        max_position = max(max_position, current_position);
        min_position = min(min_position, current_position);
    }

    return max_position - min_position;
}

double find_min_value(int K, vector<int>& ref_s_of_racers, vector<int>& ref_k_of_racers){
    double left_index = 0;
    double right_index = K;

    while (right_index - left_index > eps){
        double mid1 = left_index + (right_index - left_index)/3; 
        double mid2 = right_index - (right_index - left_index)/3;

        double f_mid_1 = f_x(mid1, ref_s_of_racers, ref_k_of_racers);
        double f_mid_2 = f_x(mid2, ref_s_of_racers, ref_k_of_racers);

        if (f_mid_1 < f_mid_2){
            right_index = mid2;
        }
        else{
            left_index= mid1;
        }

    }
    return f_x((left_index + right_index) / 2, ref_s_of_racers, ref_k_of_racers);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    int K; cin >> K;

    vector<int> s_of_racers(N);
    vector<int> k_of_racers(N); 

    for (int it = 0; it < N; ++it) {
        cin >> s_of_racers[it] >> k_of_racers[it];;
    }

    cout << fixed << setprecision(6) << find_min_value(K, s_of_racers, k_of_racers) << '\n';

}