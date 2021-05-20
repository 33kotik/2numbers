#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
vector<double> x;
vector<double> y;
vector<double> A;
vector<double> B;
vector<double> C;
vector<double> D;
double step=0.05;

int n = 4;
int a = 1;
int b = 11;

double df(double p = a) {
    return (1 - cos(p));
}

double ddf(double p = a) {
    return (sin(p));
}

double dddf(double p = a) {
    return (-cos(p));
}

double f(double p) {
    return (p - sin(p) - 0.25);
}

double splain(double p,double ff[3]) {
    return (ff[0]*p*p*p+ff[2]*p*p+ff[2]*p+ff[3]);
}

// нам даны производные в концах отрезка
// g= полином y[i]=g[i][0]*x^3+ g[i][1]*x^2+g[i][2]*x+g[i][3]
//  3*g[0]*x^2+2*g[1]*x+g[2]=df[a]
// dg= первая производная
// ddg= вторая производная
int main() {

    freopen("output.txt", "w+", stdout);
    int q[3] = {2, 4, 8};
//    for (auto j : q) {
//        n = j;

    double h = (b - a) / double(n);
//    с
    x[0]=a;
    y[0]=f(a);
//            cerr<<h<<endl;
    for (int i = 1; i <= n; i++) {
        x[i] = (x[i - 1] + h);
        y[i] = (f(x[i]));
    }

    for (int i = 1; i <= n; i++) {

    }
    double cur_x=a;
    for (int i=0; i<=n;){
        while (cur_x -a -h*i<0){
            cur_x+=step;
            cout<<splain(cur_x-x[i],g[i])<<" ";
            cerr<<cur_x<<" ";
        }
        i++;
    }
    cout<<endl;
    //    }
    for (double i=a; i<=b;i+=step){
        cout<<f(i)<<" ";
    }
    cout<<endl;
    int steps=0;
    for (double i=a; i<=b;i+=step){
        cout<<i<<" ";
        steps++;
    }
    cerr<<endl<<steps;

    cout<<endl;
    for (int i = 0; i <= n; i++) {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i <= n; i++) {
        cout<<y[i]<<" ";
    }
    cout<<endl;

    return 0;
}
