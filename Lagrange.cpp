//
// Created by dubro on 14.09.2021.
//
#include <iostream>
#include "Lagrange.h"
#include <algorithm>
#include <cmath>
using namespace std;
double Lagrange::L(double t, int k) const {
    double result = 1;
    for(int i = 0;i < x.size();i++){
        if(i == k) continue;
        result *= (t - x[i]);
        result /= (x[k] - x[i]);
    }
    return result;
}

Lagrange::Lagrange(const std::vector<double> &x, const std::vector<double> &y){
    this->x = x;
    this->y = y;
}
double Lagrange::interpolate(double t) const {
    double result = 0;
    if (!(x[0] <= t && x.back() >= t)) {
        cout << "nilzya extrapolirovatbb" << endl;
        return 0;
    }
    int m = std::upper_bound(x.begin(),x.end(),t) - x.begin();
    if(std::abs(t-x[m]) < 1e-15 && m < x.size()- 1)
        return y[m];
    if(std::abs(t-x[m-1]) < 1e-15 && m > 0)
        return y[m-1];
    for(int i =0;i < x.size();i++){
        result += y[i]*L(t,i);
    }
    return result;
}


