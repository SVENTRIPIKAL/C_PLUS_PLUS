/*  CSCI - 1370: USER-DEFINED FUNCTIONS & LOOPS
*   
*   Program takes in positive integers and outputs the max number,
*   as well as, the total average--Negative integers end the input loop.
*   Challenge: Must create user-defined functions to return intended numbers.
*   
*                        [ EXAMPLE ]
*   INPUT:        15, 20, 0, 3, -1 ]
*   OUTPUT:    Max= 20, Mean= 9.50 ]
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>          // used for decimal rounding: fixed << set precision(2)

using namespace std ;

//============================================================[ USER-DEFINED FUNCTIONS ]

// RETURNS MAX INTEGER OF 2 INTEGER VALUES
int getMAX( int xUserInput, int xMax )
{
    if ( xUserInput > xMax )
    {
        xMax = xUserInput ;
    }
    
    return xMax ;
}

// RETURNS MEAN DECIMAL OF 2 VALUES (DECIMAL, INTEGER)
double getMEAN( double xTotal, int xCount)
{
    double result ;
    
    if ( xCount != 0 )
    {
        result = xTotal / xCount ;
    }
    
    else
    {
        result = 0 ;
    }
    
    return result ;
}

//==============================================================================[ MAIN ]

int main()
{
    int userInput ;                             // holds user input
    int max = 0   ;                             // holds max integer value
    
    double mean ;                               // holds mean value
    int count = 0 ;                             // holds number of positive integers
    double total = 0 ;                          // holds sum of positive integers
    
    
    cin >> userInput ;
    
    while( userInput >= 0 )          // executes while input is a positive integer
    {
        count++ ;                               // increase count by 1
        
        total += userInput ;                    // update total by adding to input
        
        max = getMAX( userInput, max ) ;        // update MAX integer, if necessary
        
        cin >> userInput ;                      // receive next input
    }
    
    
    mean = getMEAN( total, count ) ;        // get mean by dividing total by count
    
    cout << "MAX: " << max << endl ;
    cout << "MEAN: " << fixed << setprecision(2) << mean << endl ;
    
    
    return 0 ;                              // indicates successful termination
}
