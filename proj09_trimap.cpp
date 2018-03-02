#include<algorithm>
using std::upper_bound; using std::sort;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;
#include<sstream>
using std::ostringstream;
#include "proj09_trimap.h"

/*  Julia Heisler
    11/21/17
    Project 9
    CSE 232     */

//initializers

TriMap::TriMap(initializer_list<Element> n){
    vec_ =  n; 
    
}

TriMap::TriMap(const Element&e){
    vec_.push_back(e);
    
}
// output operator for printing of element
ostream& operator<<(ostream& out, const Element& e){
    out << e.key_ 
    <<':'
    << e.value_
    << ':'
    << e.index_;
    return out;
}

// size class method
size_t TriMap::size(){
    return vec_.size();
}

//inserts element into TriMap if key does not already exist
bool TriMap::insert(string key,string value){
    
    bool ans = true;
    for(auto e : vec_){
        if (e.key_ == key)
            ans = false;
        else
            continue;
    }
    //if key is not in TriMap
    if (ans == true){
        // initializing new element with new inputed key
        Element g(key, value, 0);
        size_t num = 0;
        for(auto e : vec_){
            //updates index_ of new element
            if (e.index_ >= num) {
                num = e.index_;
                num += 1;
            }
        }
        g.index_ = num;
        vec_.push_back(g);
        //sorts TriMap by keys
        sort(vec_.begin(), vec_.end(),
        [ ] (Element one, Element two)
        {return one.key_ < two.key_;});
        
    return ans;
    }

    return ans;
}

// TriMap class method - removes element from TriMap if key exists
bool TriMap::remove(string key){
    bool ans;
    for (auto i : vec_){
            // if key in element is inputed key
            if (i.key_ == key){
                //ans is true
                ans = true;
                break;
            }
            else{
                ans = false;
                continue;
            }
        }
    
    if (ans == true) {
        unsigned int num = 0;
        unsigned int length = vec_.size();
        //loop removing element 
        for (unsigned int w = 0; w < length; w++){
            if(vec_[w].key_ == key){
                num = vec_[w].index_;
                vec_.erase(vec_.begin()+w, vec_.begin()+w+1);
            }
            // subtracts 1 from each index_ after element removed
            if (vec_[w].index_ >= num) {
                vec_[w].index_ -= 1;
            }
            
        }
    }
    
    return ans;
    
}

Element* TriMap::find_key(const string&key){
    // iterating loop
    for (auto it = vec_.begin(); it != vec_.end();it++){
        // if key is found, return it (address)
        if (it->key_ == key){
            return &(*it); 
        }
        else{
            continue;
        }
    }
    //if after looping through entire TriMap and it is not found return nullptr.
    return nullptr;
}

Element* TriMap::find_value(const string&value){
    // iterating loop
    for (auto it = vec_.begin(); it != vec_.end();it++){
        // if value is found, return it (address)
        if (it->value_ == value){
            return &(*it); 
        }
        else{
            continue;
        }
    }
    //if after looping through entire TriMap and it is not found return nullptr.
    return nullptr;
}

Element* TriMap::find_index(size_t index){
    //iterating loop
    for (auto it = vec_.begin(); it != vec_.end();it++){
        // if index is found, return it (address)
        if (it->index_ == index){
            return &(*it); 
        }
        else{
            continue;
        }
    }
    //if after looping through entire TriMap and it is not found return nullptr.
    return nullptr;
}
// printing for TriMap
ostream& operator<<(ostream& out, const TriMap& m){
    ostringstream oss;
    for ( auto i : m.vec_){
        oss << i
        <<", ";
    }  
    // convert oss to string
    string s = oss.str();
    // pops off last comma
    string w = s.substr(0, s.size()-2);
    out << w;
    return out;
}
