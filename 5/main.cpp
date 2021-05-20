#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <GL/glut.h>
//#include "GLh"
using namespace std;
double const a = M_PI / 2;
double const b = M_PI * 2;
//double const b = a+0.2;
double h;
vector<double> X;
vector<double> Y;

vector<double> accuracy;
vector<double> step_size;
vector<double> hp;
vector<double> delta;
vector<double> xerror;

//double const
//точное решение в точке p
double solution(double p) {
    return p * sin(p);
}

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

int main() {
//    cout<<a<<" "<<a<<endl;
////    RungeKutta4(2);
//    X.clear();
//    Y.clear();
//    freopen("output.txt", "w+", stdout);

//    for (double d = 0.1; d >= 1e-15; d = d / 10) {
//            cerr<<erorr<<" "<<eps<<endl;

//        int n=64;
    for (int n = 10; n < 1e8; n = n * 10) {


        RungeKutta4(n);
//            cerr << n << " " << erorr << endl;
        double erorr = 0;
        double xerorr = 0;
        for (int i = 0; i < Y.size(); i++)

            if (erorr == min(erorr, abs(solution(X[i]) - Y[i]))) {
                erorr = max(erorr, abs(solution(X[i]) - Y[i]));
                xerorr = X[i];
            }

        X.clear();
        Y.clear();
        accuracy.push_back(erorr);
//        delta.push_back(d);
        xerror.push_back(xerorr);
        step_size.push_back((b - a) / n);
//        hp.push_back(pow(((b - a) / n),4));
//        cerr <<(b - a) / n << "  " << erorr << "   " << n << endl;
    }

//
    matlab_output();
/*for (int j = 1; j <= 1e1; j = j * 2) {
    RungeKutta4(j);

    cout << X.size() << endl << "X     ";
    for (int i = 0; i < X.size(); i++)
        cout << setprecision(4) << X[i] << "   ";
    cout << endl << "Y     ";
    for (int i = 0; i < Y.size(); i++)
        cout << setprecision(4) << Y[i] << "   ";
    cout << endl << "true  ";
    for (int i = 0; i < Y.size(); i++)
        cout << setprecision(4) << solution(X[i]) << "   ";
    cout << endl << "delta ";
    cout << endl;
    X.clear();
    Y.clear();
    cerr << X.size() << endl;


}*/
//    cout << endl;
//    for (int i = 0; i < Y.size(); i++)
//        cout << solution(X[i]) << "   ";
//    cout << endl;

}
