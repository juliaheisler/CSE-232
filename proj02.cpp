#include <iostream>
using std::cout; using std::cin; using std::endl;

/*
Project 02
Julia Heisler
09/15/2017
*/

int main(){
    // user's integer input
    long input_int;
    cin >> input_int;
    
    // error check
    if (input_int < 1)
        cout << "Error" << endl;
    else{
        // divisor count for user input
        long input_increment = 1;
        long div_count = 0;
        while (input_increment <= input_int){
            long div_choice = input_int%input_increment;
            if (div_choice == 0){
                div_count += 1;
            }
            input_increment += 1;
        }
        
        // loop for count of divisors for each number 1 through user's input-1
        long increment2 = 1;
        while (increment2 < input_int){
            long increment3 = 1;
            long div2_count = 0;
            while (increment3 <= increment2){
                long div2_choice = increment2%increment3;
                if (div2_choice == 0){
                    div2_count +=1;
                }
                increment3 += 1;
            }
            // if number 1 through user's input-1 has >= number of divisors
            if (div2_count >= div_count){
                cout << "False " << input_int << " " << increment2 << " " << div2_count;
                // 'go to' : ends program (goes to line 53)
                goto jmp;
            }
            increment2 += 1;
        }
        // if condition is not met, input is highly composite
cout << "True " << input_int << " " << div_count;
            
        }
    // ends program    
    jmp: cout <<"";

    }



