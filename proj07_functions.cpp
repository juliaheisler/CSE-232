#include <iostream>
using std::ostream;using std::cout; using std::cin; using std::endl;
using std::fixed;
#include <sstream>
using std::istringstream;
#include<string>
using std::string;
using std::stod;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;
#include<iomanip>
using std::setprecision;
#include<cmath>
using std::sqrt; using std::pow;

/*  CSE 232 Project 7
    Julia Heisler
    10/30/17        */

/* Creates vector of strings, splits on delim (if not given splits on ' ') */
vector<string> split(const string &s, char delim){
    istringstream iss(s);
    string word;
    vector<string> split_vect = {};
    //loop pushes back each word onto vector
    while(getline(iss, word, delim)){
        split_vect.push_back(word);
    }
    //returns vector of strings
    return split_vect;
}
/* reads data from an already open file, saves contents to a map */
void read_data(map<vector<double>, string> &m, unsigned
int feature_count, ifstream &inf){
    string val;
    vector<double> p;
    string class_strv;
    
    //reads each line of file 
    while(getline(inf, val)){

        //creates vector of everything in line
        vector<string> v = split(val, ',');
        
        //creates new vector of only doubles (converts string vector to doubles)
        for(unsigned int i = 0; i<feature_count;i++){
           double dec = stod(v[i]);
           p.push_back(dec);
        }

        //saves the class at the end of v to a string
        string class_strv = v.back();
        //inserts key (vector of doubles) and value (string) to map
        m.insert({p, class_strv});
        // clears vector p for every line
        p.clear();

    }

}
/* coverts pair to string - with doubles set to precision 3 */
string pair_to_string(const pair<vector<double>, string> &p){
  std::ostringstream os;
  os << fixed;
  os << setprecision(3);
  // loops through vector
  for (size_t i = 0; i < p.first.size(); i++){
   os << p.first[i];
   os << ' ';
  }
  os << p.second;
  // returns string
  return os.str();
}
// prints map using previous function for each pair
void print_map(const map<vector<double>, string> &m, ostream &out){
    //for each pair in m
    for (auto i : m){
        out << pair_to_string(i);
        out << endl;
    }
    
}
/* Calculates Euclidean distance between 2 vectors */
double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){
        double first;
        double sum;
        double sum_sqrt;
        // sums together squared differences
     for (unsigned int i = 0; i < feature_count; i++){
         first = pow((v1[i]-v2[i]),2);
         sum += first;
     }
     //takes square root of overall sum
     sum_sqrt = sqrt(sum);
     //returns distance
     return sum_sqrt;
    
}

map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k){
    map<double, vector<double>> distance_map;
    map<vector<double>, string> r_map;
    for (auto i : m){
    double key = distance(test, i.first, k);
    if (key != 0){
        distance_map.insert({key, i.first}); 
    }
    }
    int n = 0;
    for(auto i : distance_map){
            r_map.insert({i.second, m.at(i.second)});
            n++;
            if(n == k)
                break;
        
    }
   return r_map; 
        
}