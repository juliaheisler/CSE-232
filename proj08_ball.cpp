#include<string>
using std::string;

#include <sstream>

#include<iomanip>
using std::setprecision;

#include <iostream>
using std::fixed;

#include<cmath>
using std::pow;using std::sqrt;

#include "proj08_ball.h"
#include "proj08_twod.h"

/*  Project 08 - Part 2
    Julia Heisler
    11/4/17 */

//Ball constructor - also uses type TwoD created in twod.h
Ball::Ball(double m, TwoD pos, TwoD speed, double r){
    mass = m;
    coords = pos;
    velocity = speed;
    radius = r;
    
}
//format for printing ball
string Ball::to_string(){
    std::ostringstream os;
    os << fixed;
    os << setprecision(2);
    os << mass <<", "<<"("<<coords.x<<", " <<coords.y
    <<"), (" <<velocity.x<<", " <<velocity.y<<"), "<<radius;
    return os.str();
}

//method determining if ball is in contact with another ball
bool Ball::contact_ball(Ball h){
    //distance formula between balls
    auto new_pos = sqrt(pow(h.coords.x-coords.x,2)-pow(h.coords.y-coords.y,2));
    //if distance is less than the sum of the two ball's radii, balls contact
    if (new_pos<(radius+h.radius)){
        return true;
    }
    else
        return false;
}
//method for determining if a ball is in contact with a wall (in rectangle)
bool Ball::contact_wall(long xdim, long ydim){
    // if sum of ball's x coordinate position and radius greater that the rectangles x dimention OR the difference between the ball's x coordinate position and radius is less than 0, ball contacts wall. //
  if(coords.x+radius > xdim or (coords.x - radius) < 0)
    return true;
    // if sum of ball's y coordinate position and radius greater that the rectangles y dimention OR the difference between the ball's y coordinate position and radius is less than 0, ball contacts wall. //
  if(coords.y+radius > xdim or (coords.y - radius) < 0)
    return true;
    else
        return false;
}

//method for updating ball's velocity when two balls contact
TwoD Ball::update_velocity_ball(Ball h){
    //first fraction in equation followinf order of ops
    double step1 = (h.mass*2)/(mass+h.mass);
    
    //second fraction in equation following order of ops
    TwoD v_diff = (velocity.diff(h.velocity));
    TwoD c_diff = (coords.diff(h.coords));
    double step2 = (v_diff.dot_product(c_diff))/(c_diff.magnitude_squared());
    
    //multiplication of terms that are doubles
    double step3 = step1*step2;
    
    //multiplication of vector by scalar
    TwoD step4 = c_diff.mult(step3);
    
    //final step of subtracting combined terms above
    TwoD result = velocity.diff(step4);
    
    return result;
    
}
//method updating velocity when ball contacts wall
 TwoD Ball::update_velocity_wall(long xdim, long ydim){
     auto xval = velocity.x;
     auto yval = velocity.y;
     //if sum of ball's x coordinate position and raidus is greater than rectangles x dimension OR the difference of the ball's x coordinate position and radius is greater than 0, the velocity's xval changes signs. //
    if(coords.x+radius > xdim or (coords.x - radius) < 0){
        xval*=-1;  
    } 
    //if sum of ball's y coordinate position and raidus is greater than rectangles y dimension OR the difference of the ball's y coordinate position and radius is greater than 0, the velocity's yval changes signs. //
    if(coords.y+radius > xdim or (coords.y - radius) < 0){
        yval*=-1;  
    } 
    return TwoD(xval,yval);
     
 }