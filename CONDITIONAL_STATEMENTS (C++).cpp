// CSCI - 1370: CONDITIONAL STATEMENTS
// Program works as a phone bill payment kiosk; asking
// user for monthly phone usage and returning total charges
// according to their specific data plan.

#include <iostream>
#include <iomanip>
using namespace std ;

//============================================================[ USER-DEFINED FUNCTIONS ]

// rechecks user-entry and returns to main menu or continues
int continueMain_Prompt( int xChoice, int xReprompt )
{
    switch ( xReprompt )            // recheck input
    {
        case 1:                     // if entry was valid
        {
            xChoice = 0 ;           // reassign choice, break loop, & continue
            
            break ;
        }
        
        case 2:                     // if entry was mistaken
        {
            xChoice = 5 ;           // reassign choice, break loop, & break to main
            
            cout << "\n============================="
                    "===============================\n\n" ;
            
            cout << "\t\t\t No Problem, Returning To Main Menu...\n" ;
            
            break ;
        }
        
        default:                    // all else, loop until input is 1 or 2
        {
            cout << "\n============================="
                    "===============================\n\n" ;
            
            cout << "\t\t\tSorry, Only 1 & 2 Are Valid Entries...\n" ;
        }
    }
    
    return xChoice ;
}


// follows 1 of three scenarios with different data to compute & returns final input
int dataPlan_Scenario( double xMonthly_charge, int xMonthly_hours,
                       int xAdditional_charge, double xHours_used,
                       double xHours_over, double xTotal_cost,
                       int xReprompt, int xScenario )
{
    if ( xScenario == 1 || xScenario == 2 )     // BASIC or GOLD scenario
    {
        cout << "\n============================="
                "===============================\n\n" ;
        
        cout << "\t\t\t\t\t\t  Super!\n"
                "\t\t  So How Many Hours Did You Use This Month?\n"
                "\n"
                "\t\t              Your Input: " ;
        
        cin >> xHours_used ;                    // receive user-input
        
        while ( !( xHours_used >= 0 ) )         // loop if input is less than 0
        {
            cout << "\n============================="
                    "===============================\n\n" ;
            
            cout << "\t  Please Enter A Number Greater Than Or Equal To 0..." << endl ;
            cout << "\n"
                    "\t\t              Your Input: " ;
            
            cin >> xHours_used ;                // re-receive user-input
        }
        
        if ( xHours_used > xMonthly_hours )     // if hours are over the monthly limit
        {
            xHours_over = xHours_used - xMonthly_hours ; // get total & additional cost
            
            xTotal_cost = xMonthly_charge + ( xHours_over * xAdditional_charge ) ;
        }
        
        else if ( xHours_used <= xMonthly_hours )       // if hours within monthly limit
        {
            xTotal_cost = xMonthly_charge ;             // only charge monthly rate
        }
        
        cout << "\n============================="
                "===============================\n\n" ;
        
        cout << "\t\t\t Your Bill For The Month Is $" << fixed << setprecision(2)
                << xTotal_cost << "\n" << endl ;        // output total cost
        
    }
    
    else if ( xScenario == 3 )                          // PLATINUM scenario
    {
        xTotal_cost = xMonthly_charge ;                 // total is monthly rate
        
        cout << "\n============================="
                "===============================\n\n" ;
        
        cout << "\t\t\t Since You Have Unlimited Access Hours,\n" ;
        cout << "\t\t\t\t Your Bill Each Month Is $" << fixed << setprecision(2)
                << xTotal_cost << "\n" << endl ;       // output total cost
    }
    
    cout << "=============================="
            "==============================\n\n" ;
    
    cout << "\t\t\tWould You Like To Return To Main Menu\n"
            "\t\t\t\t  Or Exit Terminal? (1, 2):\n"
            "\n"
            "                      1.  Main Menu\n"
            "                      2.  Exit Terminal\n"
            "\n"
            "                      Your Input: " ;
    
    cin >> xReprompt ;                                 // receive user input
    
    while ( xReprompt < 1 || xReprompt > 2 )           // if not 1 or 2, force loop
    {
        cout << "\n============================="
                "===============================\n\n" ;
        
        cout << "\t\t\tSorry, Only 1 & 2 Are Valid Entries..." << endl ;
        
        cout << "\n============================="
                "===============================\n\n" ;
        
        cout << "\t\t\tWould You Like To Return To Main Menu\n"
                "\t\t\t\t  Or Exit Terminal? (1, 2):\n"
                "\n"
                "                      1.  Main Menu\n"
                "                      2.  Exit Terminal\n"
                "\n"
                "                      Your Input: " ;
        
        cin >> xReprompt ;                             // re-receive user-input
    }
    
    return xReprompt ;
}


// returns to main menu or exits the terminal according to user-input
int mainExit_Prompt( int xChoice )
{
    switch ( xChoice )                                // check input
    {
        case 1:                                       // return to main menu
        {
            cout << "\n============================="
                    "===============================\n\n" ;
            
            cout << "\t\t\t No Problem, Returning To Main Menu...\n" ;
            
            break ;                                 // break to main menu
        }
        
        case 2:                                     // exit terminal
        {
            
            cout << "\n============================="
                    "===============================\n\n" ;
            
            cout << "\t\t\t No Problem, Shutting Down Terminal...\n" ;
            
            break ;                                // exit program
        }
    }
    
    return xChoice ;
}

//==============================================================================[ MAIN ]

int main()
{
    double monthly_charge ;     // customer's monthly data plan cost
    int monthly_hours ;         // customer's monthly access hours limit
    int additional_charge ;     // plan's additional charge for hours over monthly limit
    
    double hours_used ;         // hours used by customer
    double hours_over ;         // hours over data plan's monthly hours limit
    double total_cost ;         // total end-of-the-month charges
    
    int choice ;                // user-input variable #1
    int reprompt ;              // user-input variable #2
    int scenario ;              // data plan scenario
    
    int active = 1 ;            // program killswitch [ sentinal = 2 || -- ]
    
    
    while ( active == 1 )       // begin program
    {
        cout << "\n=========================[ WELCOME ]"
                "========================\n\n" ;
        
        cout << "\t\t\tChoose A Cellphone Data Plan To Calculate\n" ;
        cout << "\t\t  Your Monthly Phone Bill Or Exit (1, 2, 3, 4):\n"
                "\n"
                "                      1.  Basic\n"
                "                      2.  Gold\n"
                "                      3.  Platinum\n"
                "                      4.  Exit Terminal\n"
                "\n"
                "                      Your Input: " ;
        
        cin >> choice ;                     // receive user-input #1
        
        
        switch ( choice )                   // check if choice equals 1-4
        {
            case 1:                         // if BASIC PLAN   -   begin first scenario
            {
                while ( choice == 1 )       // loop to recheck choice validity
                {
                    cout << "\n============================="
                            "===============================\n\n" ;
                    
                    cout << "\t\t\tBasic Plan? Is That Correct? (1, 2):\n"
                            "\n"
                            "                      1.  Yes\n"
                            "                      2.  No\n"
                            "\n"
                            "                      Your Input: " ;
                    
                    cin >> reprompt ;       // receive user-input #2
                    
                    choice = continueMain_Prompt( choice, reprompt ) ;
                }
                
                if ( choice == 5 )          // check for previous main menu input
                {
                    break ;                 // break to main menu
                }
                
                scenario = 1 ;              // set to basic plan scenario
                
                monthly_charge = 9.95 ;     // basic plan monthly cost
                monthly_hours = 10 ;        // basic plan monthly hours limit
                additional_charge = 2 ;     // basic plan cost-per-hour over monthly limit
                
                choice = dataPlan_Scenario( monthly_charge, monthly_hours,
                                            additional_charge, hours_used, hours_over,
                                            total_cost, reprompt, scenario ) ;
                
                active = mainExit_Prompt( choice ) ;
                
                break ;
            }                               // BASIC PLAN   -   end first scenario
            
            
            case 2:                         // if GOLD PLAN   -   begin second scenario
            {
                while ( choice == 2 )       // loop to recheck choice validity
                {
                    cout << "\n============================="
                            "===============================\n\n" ;
                    
                    cout << "\t\t\tGold Plan? Is That Correct? (1, 2):\n"
                            "\n"
                            "                      1.  Yes\n"
                            "                      2.  No\n"
                            "\n"
                            "                      Your Input: " ;
                    
                    cin >> reprompt ;       // receive user-input #2
                    
                    choice = continueMain_Prompt( choice, reprompt ) ;
                }
                
                if ( choice == 5 )          // check for previous main menu input
                {
                    break ;                 // break to main menu
                }
                
                scenario = 2 ;              // set to gold plan scenario
                
                monthly_charge = 14.95 ;    // gold plan monthly cost
                monthly_hours = 20 ;        // gold plan monthly hours limit
                additional_charge = 1 ;     // gold plan cost-per-hour over monthly limit
                
                choice = dataPlan_Scenario( monthly_charge, monthly_hours,
                                            additional_charge, hours_used, hours_over,
                                            total_cost, reprompt, scenario ) ;
                
                active = mainExit_Prompt( choice ) ;
                
                break ;
            }                               // GOLD PLAN   -   end second scenario
            
            
            case 3:                         // if PLATINUM PLAN   -   begin third scenario
            {
                while ( choice == 3 )       // loop to recheck choice validity
                {
                    cout << "\n============================="
                            "===============================\n\n" ;
                    
                    cout << "\t\t\tPlatinum Plan? Is That Correct? (1, 2):\n"
                            "\n"
                            "                      1.  Yes\n"
                            "                      2.  No\n"
                            "\n"
                            "                      Your Input: " ;
                    
                    cin >> reprompt ;       // receive user-input #2
                    
                    choice = continueMain_Prompt( choice, reprompt ) ;
                }
                
                if ( choice == 5 )          // check for previous main menu input
                {
                    break ;                 // break to main menu
                }
                
                scenario = 3 ;              // set to platinum plan scenario
                
                monthly_charge = 19.95 ;    // platinum plan monthly cost
                
                choice = dataPlan_Scenario( monthly_charge, monthly_hours,
                                            additional_charge, hours_used, hours_over,
                                            total_cost, reprompt, scenario ) ;
                
                active = mainExit_Prompt( choice ) ;
                
                break ;
            }                               // PLATINUM PLAN   -   end third scenario
            
            
            case 4:                         // if EXIT TERMINAL   -   begin fourth scenario
            {
                while ( choice == 4 )       // loop to recheck choice validity
                {
                    cout << "\n============================="
                            "===============================\n\n" ;
                    
                    cout << "\t\t\tExit Terminal? Is That Correct? (1, 2):\n"
                            "\n"
                            "                      1.  Yes\n"
                            "                      2.  No\n"
                            "\n"
                            "                      Your Input: " ;
                    
                    cin >> reprompt ;       // receive user-input #2
                    
                    choice = continueMain_Prompt( choice, reprompt ) ;
                }
                
                if ( choice == 5 )          // check for previous main menu input
                {
                    break ;                 // break to main menu
                }
                
                active-- ;                  // activate killswitch
                
                cout << "\n============================="
                        "===============================\n\n" ;
                
                cout << "\t\t\t No Problem, Shutting Down Terminal...\n" ;
                
                break ;                     // exit program
                
            }                               // EXIT TERMINAL   -   end fourth scenario
            
            
            default:                        // if all else, restart program
            {
                cout << "\n============================="
                        "===============================\n\n" ;
                
                cout << "\t\t  Sorry, Only Numbers 1-4 Are Valid Entries;\n\n"
                        "\t\t\t\t\tRestarting Terminal...\n" ;
                
                break ;                    // return to main menu
            }
        }
    }
    
    
    cout << "\n=========================[ GOOD-BYE ]"
            "=======================\n\n" ;
    
    return 0 ;                             // indicates successful termination
}