#include<fstream>
using std::ifstream;
#include<iostream>
using std::ostream;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
#include<vector>
using std::vector;
#include<algorithm>
using std::sort;

#include "proj10_knapsack.h"
/*  Julia Heisler
    Project 10 Part 2
    11/29/17
    CSE 232     */

// useless swap function included in header
void Knapsack::swap(Knapsack& k){
    
    std::swap(k.capacity_,capacity_);
    std::swap(k.weight_limit_,weight_limit_);
    std::swap(k.size_,size_);
    std::swap(k.data_, data_);
}
//constructor for wlimit 
Knapsack::Knapsack(size_t wlimit){
    weight_limit_ = wlimit;
    size_ = 0;
    capacity_ = 10;
    data_ = new Package[capacity_];
}
//constructor for wlimit and cap
Knapsack::Knapsack(size_t wlimit, size_t cap){
    weight_limit_ = wlimit;
    capacity_ = cap;
    size_ = 0;
   data_ = new Package[capacity_];
}
//copy constructor 
Knapsack::Knapsack(const Knapsack&k){
    //initializers
    weight_limit_ = k.weight_limit_;
    capacity_ = k.capacity_;
    size_ = k.size_;
    //allocates memory for data_
    data_ = new Package[capacity_];
    std::copy(k.data_, k.data_+capacity_, data_);
  }
  //operator constructor
 Knapsack& Knapsack::operator=(Knapsack k){
    swap(k);
    return *this;
  }
  //destructor - deletes data_ (returns to memory)
  Knapsack::~Knapsack(){
      delete [] data_;
  }
  
  //getters
  
  long Knapsack::capacity() const {
      return capacity_;
  }
  
  long Knapsack::size() const {
      return size_;
  }
  long Knapsack::weight_limit() const {
      return weight_limit_;
  }
  
  // if the knapsack is empty, returns true
   bool Knapsack::empty() const {
       if (size_ == 0){
           return true;
       }else 
           return false;
   }
//function sums up all weights   
long Knapsack::weight() const {
     long sum = 0;
     //if size is 0, sum returned is 0
     if (size_ == 0)
        return sum;
     //sums up weights
     for( unsigned int i = 0; i < size_; i++ ){
        sum += data_[i].weight_;
     }
     return sum;
 }
 //function sums up  all priorities
 long Knapsack::priority() const {
     long sum = 0;
     //if size is 0, sum returned is
     if (size_ == 0)
        return sum;
    //sums up weights    
     for( unsigned int i = 0; i < size_; i++ ){
        sum += data_[i].priority_;
     }
     return sum;
     
 }
 //add function - adds a package to the knapsack
 bool Knapsack::add(const Package&p){
     //if package exceeds weight limit, return false
     if((weight()+p.weight_)>weight_limit()){
        return false;
    }
    else{
        //if adding the package would exceed the capacity
        if(size_ == capacity_){
            // creates new array of package to make for more data (double capacity)
            Package * new_array = new Package[capacity_*2];
            //copies contents to new array
            std::copy(data_, data_+capacity_, new_array);
            //swaps data and new array
            std::swap(new_array, data_);
            // deletes new array (returns allocated memory)
            delete [] new_array;
            //increment capacity
            capacity_ *= 2;
            // add p to data at that index
            data_[size_]=p;
            // increment size
            size_+=1;
        // if package does not exceed capacity
        }else{
            //add p to data at that index
            data_[size_] = p;
            // increment size
            size_+=1;
        
        }
    }
    return true;
 }
 //printing for knapsack
ostream& operator<<(ostream& out, Knapsack &k){
    ostringstream oss;
    for (unsigned int i = 0; i < k.size_; i++){
        oss << k.data_[i]<<", ";
    }  
    // convert oss to string
    string s = oss.str();
    // pops off last comma
    string w = s.substr(0, s.size()-2);
    out << w;
    return out;
}
// function adds elements from text file to knapsack 
void solve_KS(string fstring, Knapsack& k){
    //opens file - if file does not exist, throws runtime error
    ifstream inFile(fstring);
    
    if(!inFile.is_open()){
        throw std::runtime_error("Error: File Does Not Exist!");
    }
    //if file exists
    else{
        //initializers
        string line;
        vector<Package> sack;
        // while loop for lines in txt file
        while (getline(inFile, line)){
            //index of white space
           long index = line.find(" ");
           //creates longs from string in txt file
           long w = stol(line.substr(0,index));
           long p = stol(line.substr(index+1));
           //creates package from w and p longs
           Package box = Package(w,p);
           //adds package to sack vector
           sack.push_back(box);
       }
       //sorts vector using package compare
       sort(sack.begin(),sack.end(),package_compare);
       //loop adding package to knapsack if weight limit is not exceeded
       for(auto i : sack){
            if((k.weight()+i.weight_)>k.weight_limit())
                break;
            else
                k.add(i);
       }
    }
}