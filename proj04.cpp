#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;

/*  
Project 04
Julia Heisler
10/02/17    
*/
             
// meta, strictly increase
// plain, non-strictly increase
// kata, strictly decrease
// nialp, non-strictly decrease
// non, none of the above

const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";

bool metadrome(string num, int base){
// if num is a metadrome within the base inputed, returns true - otherwise false

    //'true' 'false' instead of '1' '0'
    cout << boolalpha;
    /*creates substring of base_vals - only characters allowed to be used in
    num input */
    string base_sub = base_vals.substr(0,base);
    // initialized at 0
    int index = 0;
    int current_num = 0;
    
    //looping through 0 to length of num
    for(unsigned int i = 0; i < num.length(); i++){
        char j = num[i];
        //finds the index that the character is in (in substring)
        index = base_sub.find(j);
        
        //tests if numbers inputed have ok base 
        if (index < 0){
            goto meta_false;
        }
        
        // test for increasing in each index
        if (index > current_num){
            // current_num becomes index
            current_num = index;
            //continue through loop
            continue;
        // if not increasing
        }else{
            goto meta_false;
        }
    }
    // default condition if loop goes through finish
    return true;

//false condition for all loops (to break out of loop)
meta_false: return false;
}

bool plaindrome(string num, int base){
    // if num is a plaindrome within the base inputed, returns true - otherwise     false
    
     //'true' 'false' instead of '1' '0'
    cout << boolalpha;
    /*creates substring of base_vals - only characters allowed to be used in
    num input */
    string base_sub = base_vals.substr(0,base);
    // initialized at 0
    int index = 0;
    int current_num = 0;
    
    //looping through 0 to length of num
    for(unsigned int i = 0; i < num.length(); i++){
        char j = num[i];
        //finds the index that the character is in (in substring)
        index = base_sub.find(j);
        
        //tests if numbers inputed have ok base 
        if (index < 0){
            goto plain_false;
        }
        
        // test for increasing/sameness in each index
        if (index >= current_num){
            // current_num becomes index
            current_num = index;
            //continue through loop
            continue;
        // if not increasing
        }else{
            goto plain_false;
        }
    }
    // default condition if loop goes through finish
    return true;

//false condition for all loops (to break out of loop)
plain_false: return false;
}

bool katadrome(string num, int base){
    // if num is a katadrome within the base inputed, returns true - otherwise     false
    
     //'true' 'false' instead of '1' '0'
    cout << boolalpha;
    /*creates substring of base_vals - only characters allowed to be used in
    num input */
    string base_sub = base_vals.substr(0,base);
    // initialized at 0
    int index = 0;
    long current_num = 10000000000;
    
    //looping through 0 to length of num
    for(unsigned int i = 0; i < num.length(); i++){
        char j = num[i];
        //finds the index that the character is in (in substring)
        index = base_sub.find(j);
        
        //tests if numbers inputed have ok base 
        if (index < 0){
            goto kata_false;
        }
        
        // test for decreasing in each index
        if (index < current_num){
            // current_num becomes index
            current_num = index;
            //continue through loop
            continue;
        // if not increasing
        }else{
            goto kata_false;
        }
    }
    // default condition if loop goes through finish
    return true;

//false condition for all loops (to break out of loop)
kata_false: return false;
}

bool nialpdrome(string num, int base){
    // if num is a nialpdrome within the base inputed, returns true - otherwise     false
    
     //'true' 'false' instead of '1' '0'
    cout << boolalpha;
    /*creates substring of base_vals - only characters allowed to be used in
    num input */
    string base_sub = base_vals.substr(0,base);
    // initialized at 0
    int index = 0;
    long current_num = 10000000000;
    
    //looping through 0 to length of num
    for(unsigned int i = 0; i < num.length(); i++){
        char j = num[i];
        //finds the index that the character is in (in substring)
        index = base_sub.find(j);
        
        //tests if numbers inputed have ok base 
        if (index < 0){
            goto nialp_false;
        }
        
        // test for decreasing/sameness in each index
        if (index <= current_num){
            // current_num becomes index
            current_num = index;
            //continue through loop
            continue;
        // if not increasing
        }else{
            goto nialp_false;
        }
    }
    // default condition if loop goes through finish
    return true;

//false condition for all loops (to break out of loop)
nialp_false: return false;
}

string classify(string n, int base){
  cout << boolalpha;
  // category declared to be nondrome 
  string category = "nondrome";
  // inputs tested with each function
  bool meta = (metadrome(n,base));
  bool plain = (plaindrome(n,base));
  bool kata = (katadrome(n,base));
  bool nialp = (nialpdrome(n,base));
  
  //**series of ifs - if meets requirements for specific function (true), breaks returns that classification. **// 
  if (meta==true){
      category = "metadrome";
      goto what;
  }
  if (plain==true){
      category = "plaindrome";
      goto what;
  }
  if (kata==true){
      category = "katadrome";
      goto what;
  }
  if (nialp==true){
      category = "nialpdrome";
      goto what;
  }
 what: return category;
 
 return category;
}


int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
  