#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <GL/glut.h>
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
//vector<double> delta;
vector<double> xerror;



double f(double x, double y) {
    return (y + x * x * cos(x)) / x;
}

void matlab_output() {
    freopen("output.txt", "w+", stdout);
    cout << step_size.size() << endl;
    for (int i = 0; i < step_size.size(); i++)
        cout << step_size[i] << " ";
    cout << endl;
//    for (int i = 0; i < delta.size(); i++)
//        cout << delta[i] << " ";
//    cout << endl;
//    for (int i = 0; i < accuracy.size(); i++)
//        cout << accuracy[i] << " ";
//    cout << endl;
    for (int i = 0; i < xerror.size(); i++)
        cout << xerror[i] << " ";
    cout << endl;

    /*
     cout << X.size() << endl;
     for (int i = 0; i < X.size(); i++)
         cout << setprecision(4) << X[i] << "   ";
     cout << endl;
     for (int i = 0; i < Y.size(); i++)
         cout << setprecision(4) << Y[i] << "  ";
     cout << endl;
     for (int i = 0; i < Y.size(); i++)
         cout << setprecision(4) << solution(X[i]) << "   ";
     cout << endl;
     int k = 0;
     for (int i = 0; i < Y.size(); i++) {
         if (abs(solution(X[i]) - Y[i]) > abs(solution(X[k]) - Y[k]))
             k = i;
         cout << setprecision(4) << solution(X[i]) - Y[i] << "  ";
     }*/
//    fclose("outp")
}

void RungeKutta4(int n, double delta = 0) {
    h = (b - a) / n;
    vector<double> X;
    vector<double> Y;
//    cerr << h << endl;
//    X.push_back(a);
    for (int i = 0; i <= n; i++) {
        X.push_back(a + i * h);
    }
    Y.push_back(a + delta);
    double k1, k2, k3, k4;
    for (int i = 0; i < n; i++) {
        k1 = f(X[i], Y[i]);
        k2 = f(X[i] + h / 2, Y[i] + k1 * h / 2);
        k3 = f(X[i] + h / 2, Y[i] + k2 * h / 2);
        k4 = f(X[i] + h, Y[i] + k3 * h);
        Y.push_back(Y[i] + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6);
//        cout<<setprecision(10)<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<(Y[i] + (k1 + 2 * k2 + 2 * k3 + k4) * h / 6)<<endl;
    }

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
    {
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
            cout << abs(solutoin(X[i]) - y[i]) << " ";
        }
        cout << endl;
    }
    double error = 0;
    for (int i = 0; i <= n; i++) {
        error = max(error, abs(y[i] - solutoin(X[i])));
    }
    errors.push_back(error);
    split_count.push_back(delta);
    step_size.push_back(h);


}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
