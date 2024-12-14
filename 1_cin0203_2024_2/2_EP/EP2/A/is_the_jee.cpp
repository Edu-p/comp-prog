#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double pi = acos(-1);


double f_x(double x, double b, double c){
    return (x * x + b * x + c) / sin(x);
}

double find_min_value(double b, double c){
    double left_index = eps;
    double right_index = pi/2 - eps;
    double answer = f_x(left_index, b, c);

    while (right_index - left_index > eps){
        double mid1 = left_index + (right_index - left_index)/3; 
        double mid2 = right_index - (right_index - left_index)/3;

        double f_mid_1 = f_x(mid1, b, c);
        double f_mid_2 = f_x(mid2, b, c);

        if (f_mid_1 < f_mid_2){
            right_index = mid2;
        }
        else{
            left_index= mid1;
        }

    }
    return f_x((left_index + right_index) / 2, b, c);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests; cin >> n_tests;
    for (int it=0; it<n_tests; ++it){
        double b; cin >> b;
        double c; cin >> c;

        double result = find_min_value(b, c);

        cout << fixed << setprecision(6) << result << '\n'; 
    }

}