#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

double a = -0.7;
double b = 2.2;


double f(double p) {
//    cout<<pow(p, 5)<<" "<<- 3.5 * pow(p, 3)<<" "<<2.5 * p * p<<" "<<- 7 * p <<" - 6.4 = ";
    return (pow(p, 5) - 3.5 * pow(p, 3) + 2.5 * p * p - 7 * p - 6.4);
}

double integral() {
    double step = 1e-6;
    double ans = 0;

//    for (double i=a;i<=b;i+=step ){
//        ans+=f(i)*step;
//    }
    ans = (pow(b, 6) / 6 - 3.5 * pow(b, 4) / 4 + 2.5 * b * b * b / 3 - 7 * b * b / 2 - 6.4 * b) -
          (pow(a, 6) / 6 - 3.5 * pow(a, 4) / 4 + 2.5 * a * a * a / 3 - 7 * a * a / 2 - 6.4 * a);
    return ans;
}

double my_integral(int nodes) {
    double step = (b - a) / nodes;
    double ans = 0;

    for (double i = a; i < b; i += step) {
        ans += f(step / 2 + i) * step;
//        cout << "    " << f(step / 2 + i) * step << endl;
    }

    return ans;

}

int main() {
//    freopen("output.txt", "w+", stdout);
    double true_ans = integral();
    int max_nodes = 1e10;
    vector<double> integrals;
//    int n=4;
//    double h=(b-a)/n;
//    cerr<<"h = "<<h<<endl;
//    double res=f(a+h/2+3*h);
//    cout<<res<<endl<<res*h;
    for (long long i = 2e18; i < 2e22; i = i * 2) {
        integrals.push_back(my_integral(i));
        cout << i << " " << my_integral(i) << endl;
    }
    for (int i=1;i<integrals.size();i++){
        cout<<abs(integrals[i] - integrals[i - 1]) / (2 * 2 - 1)<<endl;
    }
    cout<<true_ans;
 /*   vector<double> accuracy;
    vector<double> rung_accuracy;
    for (double eps = 1e-1; eps > 1e-15; eps = eps / 10.0) {
        int k = 0;
        for (int i = 1; i < integrals.size(); i++) {
            double rung_presicion = abs(integrals[i] - integrals[i - 1]) / (2 * 2 - 1);
            if (i > 1) {
//                cout<< rung_presicion<<"    "<<integrals[i]<<"   "<<integrals[i-1]<<"  "<<i<<endl;
//                cerr<<rung_presicion<<" "<<integrals;
                if (rung_presicion <= eps) {
                    cout << i << " ";
                    accuracy.push_back(abs(integrals[i] - integral()));
                    rung_accuracy.push_back(eps);
                    cout << " eps " << eps << " iter: " << i << " " << "integtal: " << integrals[i]
                         << " total presicion: " << integrals[i] - integral() << " rung_presicion " << rung_presicion
                         << endl;
                    break;
                }
            }
//            cerr<<setprecision(12)<<rung_presicion<<endl;
        }
    }
    cout << endl;
    for (int i = 0; i < accuracy.size(); i++) {
        cout << setprecision(15) << accuracy[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < rung_accuracy.size(); i++) {
        cout << setprecision(15) << rung_accuracy[i] << " ";
    }

    cerr << integrals.size();*/
    return 0;
}
