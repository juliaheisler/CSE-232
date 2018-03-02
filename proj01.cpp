#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

/*  
Project 01
Julia Heisler
09/07/17    
*/

int main(){
    cout << fixed << setprecision(2);
    
    // user input
    double d1, d2, d3, d4;
    cin >> d1 >> d2 >> d3 >>d4;
    
    //all formulas broken down into two parts - real and complex 
    
    // formulas for addition
    double add_real = d1 + d3;
    double add_comp = d2 + d4;
    
    //formulas for subtraction
    double sub_real = d1 - d3;
    double sub_comp = d2 - d4;
    
    // formulas for multiplication - done by foiling
    double mul_real = (d1 * d3)+(-1)*(d2*d4);
    double mul_comp = (d1*d4)+(d2*d3);
    
    // formulas for division - done by multiplying by the complex conjucate
    double div_real = ((d1 * d3)+(-1)*(d2*(-d4)))/((d3*d3)+(-1)*(d4)*(-d4));
    double div_comp = ((d1*(-d4))+(d2*d3))/((d3*d3)+(-1)*(d4)*(-d4));
    
    // display of results
    cout << add_real << " + " << add_comp << "i" << endl;
    cout << sub_real << " + " << sub_comp << "i" << endl;
    cout << mul_real << " + " << mul_comp << "i" << endl;
    cout << div_real << " + " << div_comp << "i" << endl;
}