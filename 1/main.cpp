#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
vector<double> x(10);
vector<double> y(10);
int n = 2;
int a = 1;
int b = 11;

double f(double p) {
    return (p - sin(p) - 0.25);
}

double lagran(double p) {
    double sum = 0;
    for (int k = 0; k <= n; k++) {
        double ans = 1;
        for (int i = 0; i <= n; i++) {
            if (i != k)
                ans = ans * (p - x[i]) / (x[k] - x[i]);
//            cerr<<ans<<endl;
        }
        sum += ans * y[k];
//        cerr<<ans<<endl;
    }
    return sum;
}

int main() {
    freopen("output.txt", "w+", stdout);

//    отрезок [1,6]
    int q[3] = {2, 4, 8};
    vector<double> errors;
    vector<long long> nn;
    x[0] = a;
    y[0] = (f(a));


//    for (double i = a; i < b; i += 0.01) {
//        cout << f(i) << " ";
//    }
    cout << endl << endl;
    for (int j = 2; j <= 100; j++) {
        n = j;
        double h = (b - a) / double(n);
//        cerr<<h<<endl;
        for (int i = 1; i <= n; i++) {
            x[i] = (x[i - 1] + h);
            y[i] = (f(x[i]));

        }
//        for (int i = 0; i <= n; i++) {
//            cerr<<x[i]<<" "<<y[i]<<endl;
////        }
//        cout << endl;
//        for (double i = a; i < b; i += 0.01) {
//            cout << lagran(i) << " ";
//        }
//        cout << endl;//"la"<<endl;
        //<<"f"<<endl;
        double sum = 0;
        for (double i = a; i < b; i += 0.01) {
            sum += abs(f(i) - lagran(i));
        }
        errors.push_back(sum);
        nn.push_back(j);
        //        cout << sum<< endl;//<<"delta"<<endl;
//        cerr << n + 1 << endl;
    }
    int t = 0;
//    for (double i = a; i < b; i += 0.01) {
//        cout << i << " ";
//        t++;
//    }
    cerr << t << endl;
    for (auto j : errors) {
        cout << j << " ";
        t++;
    }
    cerr << t << endl;
    cout << endl;
    for (auto j : nn) {
        cout<<setprecision(10) << j << " ";
    }
    cerr << t << endl;
    cout << endl;



    return 0;
}
