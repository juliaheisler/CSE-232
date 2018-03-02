#include<string>
using std::string;

#include <iostream>
using std::fixed;

#include <sstream>

#include<iomanip>
using std::setprecision;

#include<cmath>
using std::pow;

#include "proj08_twod.h"

/*  Project 08 - Part 1
    Julia Heisler
    11/4/17 */

//TwoD constructor- has x and y values
TwoD::TwoD(double xval, double yval){
    x = xval;
    y = yval;
}

//format for printing TwoD
string TwoD::to_string(){
    
    std::ostringstream os;
    os << fixed;
    os << setprecision(2);
    os << "(" << x <<", " << y << ")";
    return os.str();
}

//TwoD subtraction method
TwoD TwoD::diff(TwoD k){
    auto m = x - k.x; 
    auto n = y - k.y;
    return TwoD(m,n);
}

//TwoD multiplication by a scalar method
TwoD TwoD::mult(double a){
    auto m = x * a;
    auto n = y * a;
    return TwoD(m,n);
}

//TwoD dot product method
double TwoD::dot_product(TwoD k){
    auto m = x * k.x; 
    auto n = y * k.y;
    double result = m+n;
    return result;  
}

//TwoD magnitude squared method
double TwoD::magnitude_squared(){
    //uses pow included from cmath
    return (pow(x,2)+pow(y,2));
}