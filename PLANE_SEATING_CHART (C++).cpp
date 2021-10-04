/*  CSCI - 1370: PLANE SEATING CHART
*   
*   This program prints out the seating chart for a plane.
*   The program takes a user's input for number of rows and a number of
*   seats (e.g. 17 rows, 5 seats per row) and prints out the seating 
*   chart such as:
*                       1A 1B 1C 1D 1E
*                       2A 2B 2C 2D 2E
*                       3A 3B 3C 3D 3E
*                       ...
*                       17A 17B 17C 17D 17E
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <unistd.h>         // allows the use of sleep() function
using namespace std ;

//============================================================[ USER-DEFINED FUNCTIONS ]

// outputs seating chart with provided information
void makeSeatingChart( int xSeatingRows, int xSeatingColumns )
{
    char seatR = 'A' ;
    
    for ( int row = 1; row <= xSeatingRows; row++ )
    {
        char seatC = 'A' ;
        
        cout << setw(10) ;
        
        for ( int clm = 1; clm <= xSeatingColumns; clm++ )
        {
            cout << row << "-" << seatC << " " ;
            
            seatC++ ;
        }
        
        cout << endl ;
        
        seatR++ ;
    }
}


// returns End Of Program user response
int responseEOP( int xChoice )
{
    cout << "\t\tWould You Like For Me To Generate Another?\n"
            "\n"
            "                         1.  Yes\n"
            "                         2.  No\n"
            "\n"
            "                        Your Response: " ;
    
    cin >> xChoice ;
    
    while ( xChoice < 1 || xChoice > 2 )
    {
        cout << "\n========================[ INVALID ]"
                    "=========================\n\n" ;
        
        cout << "\t\tWould You Like For Me To Generate Another?\n"
                "\n"
                "                         1.  Yes\n"
                "                         2.  No\n"
                "\n"
                "                        Your Response: " ;
        
        cin >> xChoice ;
    }
    
    switch( xChoice )
    {
        case 1:
        {
            cout << "\n=========================[ GOT IT ]"
                    "=========================\n" ;
            
            sleep(1) ;
            
            cout << "\n========================[ RESTARTING ]"
                    "======================\n\n" ;
            
            sleep(2) ;
            
            break ;
        }
        
        case 2:
        {
            cout << "\n=========================[ GOT IT ]"
                    "=========================\n" ;
            
            sleep(1) ;
            
            cout << "\n======================[ SHUTTING DOWN ]"
                    "=====================\n" ;
            
            sleep(3) ;
            
            break ;
        }
    }
    
    return xChoice ;
}

//==============================================================================[ MAIN ]

int main()
{
    int seatingRows ;                   // number of user-identified plane rows
    int seatingColumns ;                // number of user-identified plane columns
    
    int choice ;                        // user-input variable
    
    bool active = true ;                // program killswitch [ sentinal = false ]
    
    
    cout << "\n========================[ WELCOME ]"
            "=========================\n\n" ;
    
    sleep(1) ;
    
    
    while ( active )                    // following code is repeated until EOP
    {
        cout << " This Program Helps Print Out Your Plane's Seating-Chart\n"
                " So You Don't Have To: \"So What Do You Get Paid For Again?\"\n\n\n" ;
        
        cout << "\t\t  *MUST BE EQUAL TO OR GREATER THAN 5*\n\n" ;
        cout << "\tPlease Enter The Number of Rows On Your Plane: " ;
        
        cin >> seatingRows ;
        cout << endl ;
        
        while ( seatingRows < 5 )
        {
            cout << "========================[ INVALID ]"
                    "=========================\n\n" ;
            cout << "\t\t  *MUST BE EQUAL TO OR GREATER THAN 5*\n\n" ;
            cout << "\tPlease Enter The Number of Rows On Your Plane: " ;
            
            cin >> seatingRows ;
            cout << endl ;
        }
        
        cout << "=======================[ THANK YOU ]"
                "========================\n\n" ;
        
        cout << "\t\t\t *MUST BE A NUMBER FROM 5 TO 26*\n\n" ;
        cout << "\t\tPlease Enter The Number of Seats Per Row: " ;
        
        cin >> seatingColumns ;
        cout << endl ;
        
        while ( seatingColumns < 5 || seatingColumns > 26 )
        {
            cout << "========================[ INVALID ]"
                    "=========================\n\n" ;
            
            cout << "\t\t\t *MUST BE A NUMBER FROM 5 TO 26*\n\n" ;
            cout << "\t\tPlease Enter The Number of Seats Per Row: " ;
            
            cin >> seatingColumns ;
            cout << endl ;
        }
        
        cout << "=======================[ EXCELLENT ]"
                "========================\n\n" ;
        
        cout << "\t Now Give Me A Few Seconds While I Wrap Things Up..." ;
        cout << endl ;
        
        sleep(3) ;
        
        cout << "\n==========================[ DONE ]"
                "==========================\n\n" ;
        
        sleep(1) ;
        
        makeSeatingChart( seatingRows, seatingColumns ) ;
        
        cout << "\n============================="
                "===============================\n\n" ;
        
        choice = responseEOP( choice ) ;
        
        switch ( choice )
        {
            case 1:
            {
                active = true ;
                
                break ;
            }
            
            case 2:
            {
                active = false ;
                
                break ;
            }
            
        }
        
    }
    
    
    cout << "\n========================[ GOOD-BYE ]"
            "========================\n\n" ;
    
    return 0 ;                           // indicates successful termination
}