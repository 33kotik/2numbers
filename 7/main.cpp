#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <exception>
#include <locale.h>
#include <clocale>
#include <cstdlib>

using namespace std;

//v14
double solutoin(double x) {
    return exp(2 * x);
}

double p(double x) {
    return -(2 * x + 1) / x;
}

double q(double x) {
    return 3 / x;
}

double f(double x) {
    return exp(2 * x) / x;
}
//double q(double x){
//    return 3/x;
//}

double a = 0.1;
double b = 1.1;
vector<double> errors;
vector<double> split_count;
vector<double> step_size;

void finite_difference_metod(int n, double delta = 0) {
    vector<double> X;
    vector<double> F;
    vector<double> A;
    vector<double> B;
    vector<double> C;
//        int n=5;
    vector<double> y(n + 1);
    double h = (b - a) / n;
//    cerr<<h<<endl;
//        cerr << h<<endl;
    //    double dy_a=(F[1]-F[0])/h;
    //    double dy_b=(F[n]-F[n-1])/h;
    for (int i = 0; i <= n; i++) {
        X.push_back(a + h * i);
//        F.push_back(f(a + i * h));
    }
    F.push_back(solutoin(a) + delta);
    A.push_back(0);
    B.push_back(1);
    C.push_back(0);
    // есть ли решение в точке а?
//    F[0] += -solutoin(a) * (1 / (h * h) - p(X[0]) / (2 * h));
    for (int i = 1; i < n; i++) {
        F.push_back(f(a + i * h));
        A.push_back(1 / (h * h) - p(X[i]) / (2 * h));
        B.push_back(-2 / (h * h) + q(X[i]));
        C.push_back(1 / (h * h) + p(X[i]) / (2 * h));
    }
    F.push_back(solutoin(b) + delta);
    A.push_back(0);
    B.push_back(1);
    C.push_back(0);
//    F[1] += -solutoin(a) * A[1];
//    F[n-1] += -solutoin(b) * C[n-1];

    //    for (int i = 0; i < n ; i++) {
    //        cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<endl;
    //    }
    for (int i = 1; i < n; i++) {
        double kof = A[i] / B[i - 1];
        A[i] -= B[i - 1] * kof;
        B[i] -= C[i - 1] * kof;
        F[i] -= F[i - 1] * kof;
    }
    //    for (int i = 0; i < n ; i++) {
    //        cout<<A[i]<<" "<<B[i]<<" "<<C[i]<<endl;
    //    }

//    y[n] = F[n] / B[n];
    y[n] = solutoin(X[n]) + delta;
//    y[0] = solutoin(X[0]);


    for (int i = n; i >= 0; i--) {
        y[i] = (F[i] - C[i] * y[i + 1]) / B[i];
    }
//    {

//        //        freopen("output.txt", "w+", stdout);
    cout << X.size() << endl;
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < y.size(); i++) {
        cout << y[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << abs(solutoin(X[i])-y[i] )<< " ";
    }
    cout << endl;
//
//    }
    double error = 0;
    for (int i = 0; i <= n; i++) {
        error = max(error, abs(y[i] - solutoin(X[i])));
    }
    errors.push_back(error);
    split_count.push_back(delta);
    step_size.push_back(h);


}

int main() {

    freopen("output.txt", "w+", stdout);
    cerr << solutoin(a) << " " << solutoin(b) << endl;
//    for (double delta = 0.1;  delta > 1e-18;  delta =  delta / 10) {
//        finite_difference_metod(100,delta);
//    }
//    for (int i =2;i<1e7;i=i*2)
//        finite_difference_metod(i);
    finite_difference_metod(3);
    finite_difference_metod(5);

//    freopen("output.txt", "w+", stdout);
//    cout << errors.size() << endl;
//
//    cout << endl;
//    for (auto i :step_size) {
//        cout << i << " ";
//    }
//
//    cout << endl;
//    for (int i = 0; i < errors.size(); i++) {
//        cout << errors[i] << " ";
//    }
//    cout<<endl;
//    for (auto i :step_size) {
//        cout << i*i << " ";
//    }
//    cout << endl;

    return 0;
}
