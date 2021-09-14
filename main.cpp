#include <iostream>
#include "Lagrange.h"
int main() {
    std::vector<double> x = {-1,0,1,2,3,4};
    std::vector<double> y = {1,0,1,4,9,16};
    Lagrange ans(x,y);
    std::cout << ans.interpolate(1.5) << std::endl;
    return 0;
}
