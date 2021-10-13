/*  NOTHING BUT FUNCTIONS
*   
*   program imports user-defined functions from
*   'MyFunctions.h' document and tests their functionality.
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>           // used for creating arrays
#include <ctime>            // used to randomize srand()
using namespace std ;

//===================================================================[ FUNCTIONS ]

#include "MyFunctions.h"    // imports functions from 'MyFunctions.h' document

//========================================================================[ MAIN ]

int main()
{
    srand( time(0) ) ;
    
    //================================================================[ ADDITION ]
    
    cout << add(5, 2) << endl ;                             // 7    // [X]
    cout << add(-4.2, 23) << endl ;                         // 18.8 // [X]
    cout << endl ;
    
    //==========================================================[ MULTIPLICATION ]
    
    cout << multiply(5, 3) << endl ;                        // 15   // [X]
    cout << multiply(7, 10) << endl ;                       // 70   // [X]
    cout << endl ;
    
    //=================================================================[ LARGEST ]
    
    cout << biggest(10, 2.2, 7) << endl ;                   // 10   // [X]
    cout << biggest(4.9, 5, 5) << endl ;                    // 5    // [X]
    cout << biggest(8, 10, 20.3) << endl ;                  // 20.3 // [X]
    cout << endl ;
    
    //================================================================[ SMALLEST ]
    
    cout << smallest(6, 20, 3) << endl ;                    // 3    // [X]
    cout << smallest(3.14, 1.17, 8.3) << endl ;             // 1.17 // [X]
    cout << endl ;
    
    //====================================================================[ EVEN ]
    
    int n ;     cout << "Enter a number: " << endl ;    cin >> n ;
    
    if ( isEven(n) )    { cout << n << " is even." << endl ; }      // [X]
    
    //=====================================================================[ ODD ]
    
    if ( isOdd(n) )     { cout << n << " is odd." << endl ; }       // [X]
    
    cout << endl ;
    
    //============================================================[ SUM IN RANGE ]
    
    int total1 = sum(8, 20) ;       // this should be 8+9+10+...+20 = ?
    int total2 = sum(9, 35) ;
    
    cout << "The sum from 8 to 20 is " << total1 << endl ;          // [X]
    cout << "The sum from 9 to 35 is " << total2 << endl ;          // [X]
    cout << endl ;
    
    //==========================================================[ POWER FUNCTION ]
    
    // 1024
    cout << "4 raised to the 5 is " << power(4, 5) << endl ;        // [X]
    
    // 2744 
    cout << "14 raised to the 3 is " << power(14, 3) << endl ;      // [X]
    cout << endl ;
    
    //==========================================================[ RANDOM NUMBERS ]
    
    int random1 = randomNumber(19, 99) ;                            // [X]
    int random2 = randomNumber(-5, 9) ;                             // [X]
    
    cout << "Here is a random value between 19 and 99: " << random1 << endl ;
    cout << "Here is a random value between -5 and 9: " << random2 << endl ;
    cout << endl ;
    
    //========================================================[ PRIME IDENTIFIER ]
    
    cout << "Enter a number: " << endl ;        cin >> n ;          // [X]
    
    ( isPrime(n) ) ? ( cout << n << " is prime." << endl ) :
                     ( cout << n << " is not prime." << endl ) ;
    cout << endl ;
    
    //=========================================================[ PRIMES IN RANGE ]
    
    listPrimes(10) ;      // Output: 2,3,5,7                        // [X]
    listPrimes(20) ;      // Output: 2,3,5,7,11,13,17,19            // [X]
    
    //=====================================================================[ END ]
    
    return 0 ;
}