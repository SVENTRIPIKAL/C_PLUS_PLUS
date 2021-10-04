// CSCI - 1370: CALCULATING THE AREA OF A TRIANGLE
// Program asks for lengths of three sides for a
// triangle and returns the area, as well as
// its type: Equilateral, Right, or Isosceles.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std ;


//============================================================[ USER-DEFINED FUNCTIONS ]

// calculates and returns semiperimeter of triangle
double calculate_semiPerimeter( double xSide_a, double xSide_b,
                                    double xSide_c )
{
    double x_semiPerimeter ;
    
    x_semiPerimeter = ( xSide_a + xSide_b + xSide_c ) / 2 ;
    
    return x_semiPerimeter ;
    
}   // end function


// calculates and returns area of triangle
double calculate_area( double xSide_a, double xSide_b,
                        double xSide_c, double x_semiPerimeter )
{
    double x_area ;
    
    x_area = sqrt( x_semiPerimeter * ( x_semiPerimeter - xSide_a ) *
                                     ( x_semiPerimeter - xSide_b ) *
                                     ( x_semiPerimeter - xSide_c ) ) ;
    
    return x_area ;
    
}   // end function


// displays results to screen with Triangle type
void display_result(double xSide_a, double xSide_b,
                        double xSide_c, double x_area )
{
    cout << "\n         The Area of a Triangle with side lengths of\n " ;
    cout << "\t\t         " << std::fixed << std::setprecision(1) << xSide_a << ", " ;
    cout << std::fixed << std::setprecision(1) << xSide_b << ", and " ;
    cout << std::fixed << std::setprecision(1) << xSide_c << " is " ;
    cout << std::fixed << std::setprecision(1) << x_area ;
    cout << "\n\n" ;
    
    
    double shortest_1 ;         // temp: contains one of shortest side length
    double shortest_2 ;         // temp: contains one of shortest side length
    double longest ;            // temp: contains longest side length
    
    // checks and reassigns side values where A is longest side
    if ( (xSide_a > xSide_b) && (xSide_a > xSide_c) )
    {
        shortest_1 = xSide_b ;
        shortest_2 = xSide_c ;
        longest = xSide_a ;
    }
    // checks and reassigns side values where B is longest side
    else if ( (xSide_b > xSide_a) && (xSide_b > xSide_c) )
    {
        shortest_1 = xSide_a ;
        shortest_2 = xSide_c ;
        longest = xSide_b ;
    }
    // checks and reassigns side values where C is longest side
    else if ( (xSide_c > xSide_a) && (xSide_c > xSide_b) )
    {
        shortest_1 = xSide_a ;
        shortest_2 = xSide_b ;
        longest = xSide_c ;
    }
    
    
    // checks if all triangle lengths are equal
    if ( (xSide_a == xSide_b) && (xSide_b == xSide_c) )
    {
        cout << "\t\t     and it is an Equilateral Triangle!\n\n" ;
    }
    // checks if at least two triangle lengths are equal
    else if ( (xSide_a == xSide_b) || (xSide_b == xSide_c)
                                        || (xSide_c == xSide_a) )
    {
        cout << "\t\t      and it is an Isosceles Triangle!\n\n" ;
    }
    // checks if (A^2) + (B^2) = (C^2)
    else if ( pow( shortest_1, 2 ) + pow( shortest_2, 2 ) ==
                                            pow( longest, 2 ) )
    {
        cout << "\t             and it is a Right Triangle!\n\n" ;
    }
    // default action if all else fail
    else
    {
        cout << "\t\t      and it is neither an Equilateral,\n"
                "\t\t        Isosceles, or Right Triangle!\n\n" ;
    }
    
}   // end function


//==============================================================================[ MAIN ]

int main()
{
    double side_a, side_b, side_c ;         // contain triangle side lengths
    double semiPerimeter ;                  // contains triangle semiperimeter
    double area ;                           // contains area of triangle
    
    
    cout << "\n========================[ WELCOME ]==========="
                "=============\n\n" ;
    
    // prompt user
    cout << "\t        To calculate the Area of a Triangle,\n"
            "\t         please enter three side lengths:\n\t\t\t\t\t\t   " ;
    
    // receive user input
    cin >> side_a >> side_b >> side_c ;
    
    
    // calculate semiperimeter
    semiPerimeter = calculate_semiPerimeter( side_a, side_b, side_c ) ;
    
    // calculate area
    area = calculate_area( side_a, side_b, side_c, semiPerimeter ) ;
    
    // display results to screen
    display_result( side_a, side_b, side_c, area ) ;
    
    
    cout << "=============================================="
                "=============\n\n" ;
    
    
    return 0 ; // indicates successful termination
    
}   // end main
