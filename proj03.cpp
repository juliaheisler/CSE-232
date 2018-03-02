#include <iostream>
using std::cout; using std::cin; using std::endl; using std:: boolalpha;
#include <cmath>

/*
Project 03
Julia Heisler
09/25/2017
*/

long biggest_prime(long n){
    long fact;
    // loop for finding prime numbers
    for (fact=2; fact <= n; fact = fact+1){
        // if - tests each prime by division
        if (n % fact == 0) {
                n /= fact;
                fact = fact-1;
            }
    }
    // long fact (biggest prime factor) returned 
    return fact;
}

long sum_of_divisors(long n){
    // variables declared
    long div_sum = 0;
    long sq_root = sqrt(n);
    // loop for finding sum of divisors
    for(int div_1 = 1; div_1 <= sq_root; div_1++){
        if(n % div_1 == 0 and div_1*div_1 !=n){
            div_sum = div_sum + div_1 + (n/div_1);
        }
        if(n% div_1 == 0 and div_1*div_1 == n){
            div_sum = div_sum + div_1;
        }
    }
    // sum of divisors returned
    return div_sum;
}

long k_hyperperfect(long n, long k_max){
    // part one of equation
    long eq_1 = (sum_of_divisors(n)-n-1);
    long k = 1;
    // loop testing each number up until kmax
    while (k <= k_max){
        long eq_2 = 1+k*eq_1;
        if (eq_2 == n){
            // breaks out of loop to 'jmp' immediately returning that k value
            goto jmp;
        }
        k+=1;
    }
    // if number is not k-hyperperfect, 0 returned.
    k = 0;
    return k;
jmp: return k;
    
}

bool b_smooth(long n, long b){
    // 'true' 'false' instd of '1' '0'
   cout << boolalpha; 
   long big_prime = biggest_prime(n);
   // if the biggest prime number is more than the b value inputed 'false'
   if (big_prime > b){
       return false;
   }
   // otherwise 'true'
   else{
       return true;
   }
    
    
}
 
int main(){
    long n, k_max, b;
    // user input
    cin >> n >> k_max >> b;
    // printed results
    cout << biggest_prime(n) << " " << sum_of_divisors(n) << " " << k_hyperperfect(n, k_max) << " " << b_smooth(n,b) << endl;

}