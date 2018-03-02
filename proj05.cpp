// beaufort cipher, http://practicalcryptography.com/ciphers/classical-era/beaufort/

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include<cctype>

/*  
Project 05
Julia Heisler
10/15/17    
*/

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

// rotates string given number of rotations //
string rotate_left(int rotations, string s){
    
    // error check for negative rotations - returns inputed string //
    if (rotations < 0)
        return s;
        
    // initializes counter //   
    int w = 0;
    // substring of inputed string s //
    string sub_s = s.substr(rotations);
    // while counter is less than rotations //
    while(w < rotations){
        sub_s.push_back(s[w]);
        w++;
    }
// returns new string //
 return sub_s;
}


char beaufort_letter(char plain_letter, char key_letter){
    // error check for input that is not lowercase alphabet char //
    if (isupper(plain_letter) or isupper(key_letter) or isdigit(plain_letter) or     isdigit(key_letter)){
        return plain_letter;
    }
    //equation finding rotation number //
    int rotations = plain_letter - 'a';
    string new_alph = rotate_left(rotations, alphabet);
    // finds index of key letter in rotated alphabet //
    int index = new_alph.find(key_letter);
    char beauf_ciph = alphabet[index];
    // returns beaufort ciphered letter //
    return beauf_ciph;
}

char vigenere_letter(char plain_letter, char key_letter){
    // error check for input that is not lowercase alphabet char // 
    if (isupper(plain_letter) or isupper(key_letter) or isdigit(plain_letter) or     isdigit(key_letter)){
        return plain_letter;
    }
    //equation finding rotation number //
    int rotations = plain_letter - 'a';
    string new_alph = rotate_left(rotations, alphabet);
    // finds index of key letter in rotated alphabet //
    int index = alphabet.find(key_letter);
    char vig_ciph = new_alph[index];
    // returns beaufort ciphered letter //
    return vig_ciph;
}

string encode_beaufort(string plain_text, string key){
    // initializations //
    unsigned int i = 0;
    string ciph;
    string new_key;
    string new_string;
    
    // loop creating string without symbols/digits //
    for (char ch : plain_text){
        if(int(ch) >= 97 and int(ch) <= 122)
            new_string.push_back(ch);
        else
            continue;
            
            
    }
    // creates new key the same length as plain text //
    if (new_string.length() != key.length()){
        int difference = new_string.length()-key.length();
        new_key = key+key.substr(0,difference);
    }else
        new_key = key;
    // loop for cipher //
    while (i < new_string.length()){
        char letter = beaufort_letter(new_string[i],new_key[i]);
        ciph.push_back(letter);
        i++;
        
    }
    return ciph;
}
string encode_vigenere(string plain_text, string key){
    // initializations //
    unsigned int i = 0;
    string ciph;
    string new_key;
    string new_string;
    for (char ch : plain_text){
        // initializations //
        if(int(ch) >= 97 and int(ch) <= 122)
            new_string.push_back(ch);
        else
            continue;
            
    }
    // creates new key the same length as plain text //
    if (new_string.length() != key.length()){
        int difference = new_string.length()-key.length();
        new_key = key+key.substr(0,difference);
    }else
        new_key = key;
    // loop for cipher //
    while (i < new_string.length()){
        char letter = vigenere_letter(new_string[i],new_key[i]);
        ciph.push_back(letter);
        i++;
        
    }
    return ciph;
}

int main (){
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
    
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
