//
// Created by dubro on 14.09.2021.
//

#ifndef LAGRANG_LAGRANGE_H
#define LAGRANG_LAGRANGE_H
#include <vector>

class Lagrange {
private:
    std::vector<double> x;
    std::vector<double> y;
    double L(double t, int k)const;
public:
    Lagrange(const std::vector<double>& x,const std::vector<double>& y);
    double interpolate(double t)const;
};



#endif //LAGRANG_LAGRANGE_H
