#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
//#include <GL/glut.h>
//#include "GLh"
using namespace std;

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

double dy(double x) {
    return 2 * exp(2 * x);
}
//double q(double x){
//    return 3/x;
//}

double a = 0.1;
double b = 1.1;
vector<double> errors;
vector<double> split_count;
vector<double> step_size;
double h;


vector<double> accuracy;
//vector<double> step_size;
vector<double> hp;
vector<double> delta;
vector<double> runge_error;
vector<double> finite_error;
vector<double> x_runge_error;
vector<double> x_finite_error;
//vector<double> ;




double f(double x, double y, double z) {
    return z;
}

double g(double x, double y, double z) {
    return (2 * x + 1) * z / x - 3 * y / x + exp(2 * x) / x;
}

//void matlab_output() {
//    freopen("output.txt", "w+", stdout);
//    cout << step_size.size() << endl;
//    for (int i = 0; i < step_size.size(); i++)
//        cout << step_size[i] << " ";
//    cout << endl;
//
//}

void RungeKutta4(int n, double delta = 0) {
    h = (b - a) / n;
    vector<double> X;
    vector<double> Y;
    vector<double> Z;
//    cerr << h << endl;
//    X.push_back(a);
    for (int i = 0; i <= n; i++) {
        X.push_back(a + i * h);
    }
    Y.push_back(solutoin(a) + delta);
    Z.push_back(dy(a));
    double k1, k2, k3, k4;
    double l1, l2, l3, l4;
    for (int i = 0; i < n; i++) {
        k1 = h * f(X[i], Y[i], Z[i]);
        l1 = h * g(X[i], Y[i], Z[i]);
        k2 = h * f(X[i] + h / 2, Y[i] + k1 / 2, Z[i] + l1 / 2);
        l2 = h * g(X[i] + h / 2, Y[i] + k1 / 2, Z[i] + l1 / 2);
        k3 = h * f(X[i] + h / 2, Y[i] + k2 / 2, Z[i] + l2 / 2);
        l3 = h * g(X[i] + h / 2, Y[i] + k2 / 2, Z[i] + l2 / 2);
        k4 = h * f(X[i] + h, Y[i] + k3, Z[i] + l3);
        l4 = h * g(X[i] + h, Y[i] + k3, Z[i] + l3);
        Y.push_back(Y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6);
        Z.push_back(Z[i] + (l1 + 2 * l2 + 2 * l3 + l4) / 6);
//        cout<<setprecision(10)<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<(Y[i] + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6)<<endl;

    }
//    for (int i = 0; i < Y.size(); i++) {
//    cout << Y.size() << endl;
    double error = 0;
    double x_error = 0;

    for (int i = 0; i < Y.size(); i++) {
        error = max(error, abs(Y[i] - solutoin(X[i])));
        if (error==abs(Y[i] - solutoin(X[i]))){
            x_error=X[i];
        }
    }
    runge_error.push_back(error);
    x_runge_error.push_back(x_error);
//    for (int i = 0; i < Y.size(); i++) {
//        cout << Y[i] << " ";
//    }
}

void finite_difference_metod(int n, double delta = 0) {
    vector<double> X;
    vector<double> F;
    vector<double> A;
    vector<double> B;
    vector<double> C;
    vector<double> y(n + 1);
    double h = (b - a) / n;
//    cerr<<h<<endl;
    for (int i = 0; i <= n; i++) {
        X.push_back(a + h * i);
//        F.push_back(f(a + i * h));
    }
    F.push_back(solutoin(a) + delta);
    A.push_back(0);
    B.push_back(1);
    C.push_back(0);
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
    for (int i = 1; i < n; i++) {
        double kof = A[i] / B[i - 1];
        A[i] -= B[i - 1] * kof;
        B[i] -= C[i - 1] * kof;
        F[i] -= F[i - 1] * kof;
    }
    y[n] = solutoin(X[n]) + delta;
    for (int i = n; i >= 0; i--) {
        y[i] = (F[i] - C[i] * y[i + 1]) / B[i];
    }
//    {
////        //        freopen("output.txt", "w+", stdout);
//        cout << X.size() << endl;
//        for (int i = 0; i < X.size(); i++) {
//            cout << X[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i < y.size(); i++) {
//            cout << y[i] << " ";
//        }
//        cout << endl;
//        for (int i = 0; i <= n; i++) {
//            cout << abs(solutoin(X[i]) - y[i]) << " ";
//        }
//        cout << endl;
//    }
    double error = 0;
    double x_error =a;
    for (int i = 0; i <= n; i++) {
        error = max(error, abs(y[i] - solutoin(X[i])));
        if (error==abs(y[i] - solutoin(X[i]))){
            x_error=X[i];
        }
    }
    finite_error.push_back(error);
    x_finite_error.push_back(x_error);
//    split_count.push_back(delta);
    step_size.push_back(h);


}

int main() {
    freopen("output.txt", "w+", stdout);
//    for (double d = 0.1; d > 1e-10; d = d / 10) {
    for (int n=2;n<1e6;n=n*2){
//        double n = 100;
        finite_difference_metod(n);
        RungeKutta4(n);
//        delta.push_back(d);
    }
    cout << finite_error.size() << endl;
    for (int i = 0; i < finite_error.size(); i++) {
//        cout << finite_error[i] << " ";
        cout << x_finite_error[i] << " ";
        //        cout<<abs(finite_error[i]-finite_error[i-1])/(4-1)<<" ";
    }
    cout << endl;
    for (int i = 0; i < runge_error.size(); i++) {
//        cout << runge_error[i] << " ";
        cout << x_runge_error[i] << " ";
        //        cout<<abs(runge_error[i]-runge_error[i-1])/(16-1)<<" ";
    }
    cout << endl;
//    for (int i = 0; i < delta.size(); i++) {
//        cout << delta[i] << " ";
//    }

    for (int i = 0; i < step_size.size(); i++) {
        cout << step_size[i] << " ";
    }

    return 0;
}
