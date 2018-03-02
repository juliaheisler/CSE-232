#include<iostream>
using std::ostream;

#include "proj10_package.h"
/*  Julia Heisler
    Project 10 Part 1
    11/29/17
    CSE 232     */
    
//printing for package
ostream& operator<<(ostream& out, Package& p){
    out << p.weight_ 
    <<':'
    << p.priority_;
    return out;
}
//function makes ratio of priority / weight 
bool package_compare(const Package &p1, const Package &p2){
    auto p1_ratio = p1.priority_/p1.weight_;
    auto p2_ratio = p2.priority_/p2.weight_;
    if (p1_ratio >= p2_ratio){
        return true;
    }else
        return false;
    
}