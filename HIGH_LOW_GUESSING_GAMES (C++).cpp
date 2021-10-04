/* CSCI - 1370: USER-INTERACTIVE HIGH LOW GUESSING GAMES
*  
*  Program works as a terminal for 2 different games:
*  1) HIGH LOW -- the user must guess the computer's
*  secret number; user may choose the difficulty of the game.
*  2) MIND READER -- objective of the game is reversed;
*  computer guesses your secret number.
*  
*           GAME#1 (HI-LOW): SIMPLE / COMPLEX / MY OWN
*                            -generate random #1-100
*                            -ask user to guess number
*                            -return 'high' || 'low' until correct
*                            -return score and replay option
*  
*           GAME#2 (MIND-READER):
*                            -think of a random number
*                            -input range of numbers
*                            -computer guesses until finished
*                            -COMPUTER SHOULD WIN WITHIN 10 TRIES
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std ;

//============================================================[ USER-DEFINED FUNCTIONS ]

// rechecks user-input and either returns to main menu or continues.
int continueMain_Prompt( int xUserInput, int xUserReprompt, int xGameRemarks )
{
    switch ( xUserReprompt )                // recheck input
    {
        case 1:                             // if entry was valid
        {
            xUserInput = 0 ;                // reassign, break, continue
            
            break ;
        }
        
        case 2:                             // if entry was mistaken
        {
            xUserInput = 9 ;                // reassign, break, then break to main
            
            cout << "\n=============================="
                    "================================\n\n" ;
            
            cout << "\t  HOORAYY, *SARCASM* WE'RE BACK WHERE WE STARTED...\n" ;
            
            break ;
        }
        
        default:                            // if all else, restart program
        {
            
            cout << "\n=============================="
                    "================================\n\n" ;
            
            cout << "\t\t\t SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
            
            
            xGameRemarks = (rand() % 2) + 1 ;
            
            switch ( xGameRemarks )
            {
                case 1:
                {
                    cout << "\t\t\t ODD, I SEEM TO BE REPEATING MYSELF...\n" ;
                    break ;
                }
                
                case 2:
                {
                    cout << "\t\t\t MAYBE WE SHOULD TAKE A BREAK, YEAH?...\n" ;
                    break ;
                }
            }
            
            break ;                        // return to main menu
            
        }                                  // end default case
    }
    
    return xUserInput ;
}


// enters 1 of 4 different game scenarios and returns a final user-input
bool startGame( bool xProgramActive, int xUserInput, int xUserReprompt, int xGameMode,
                    int xGameNumber, int xGameRemarks, int xUserGuesses, bool xGameRestart )
{
    
    switch ( xGameMode )
    {
        case 1:                                 // HIGH LOW
        {
            cout << "\n=============================="
                    "================================\n\n" ;
            
            cout << "\t\t\t WELCOME TO THE GAME OF \"HIGH-LOW\".\n" ;
            cout << "\t\t    PLEASE SELECT A DIFFICULTY TO BEGIN \n"
                    "\t\t\t\t\t     [1, 2, 3]:\n"
                    "\n"
                    "                        1.  SIMPLE   ( 1-100 )\n"
                    "                        2.  COMPLEX  ( 1-1000 )\n"
                    "                        3.  MY OWN    ( ?-? )\n"
                    "\n"
                    "                        YOUR INPUT: " ;
            
            
            cin >> xUserInput ;
            
            
            switch ( xUserInput )
            {
                case 1:                                 // SIMPLE
                {
                    xGameNumber = rand() % 100 + 1 ;
                    
                    while ( xUserGuesses >= 0 )
                    {
                        cout << "\n==========================[ SIMPLE ]"
                                "=========================\n\n" ;
                        
                        cout << "\t\t I AM THINKING OF A NUMBER BETWEEN 1 & 100...\n"
                                "\t\t\t\t ANY IDEAS WHAT IT MIGHT BE?\n"
                                "\n"
                                "                        YOUR GUESS: " ;
                        
                        cin >> xUserInput ;
                        
                        xUserGuesses++ ;
                        
                        if ( xUserInput == xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t !!!WINNER, WINNER!!!\n"
                                    "\t\t\t\t\t !!!CHICKEN, DINNER!!!\n" ;
                            
                            break ;
                        }
                        
                        else if ( xUserInput > xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t  !!!LOWER!!!\n" ;
                        }
                        
                        else if ( xUserInput < xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t !!!HIGHER!!!\n" ;
                        }
                        
                    }
                    
                    if ( xUserGuesses >= 12 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 0/10 SHAMEFUL (x.X')\n" ;
                    }
                    
                    else if ( xUserGuesses == 11 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 2/10 YOU LOOK A LITTLE SWEATY (x.0')\n" ;
                    }
                    
                    else if ( xUserGuesses == 10 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 4/10 MY GRANDMA GOT A BETTER SCORE (o_X')\n" ;
                    }
                    
                    else if ( xUserGuesses == 9 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << " YOUR SCORE: 6/10 I'VE SEEN FIVE-YEAR-OLDS DO BETTER (o_O')\n" ;
                    }
                    
                    else if ( xUserGuesses == 8 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 8/10 NOT TOO BAD (^_^)\n" ;
                    }
                    
                    else if ( xUserGuesses == 7 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 9/10 OKAY DON'T GET TOO EXCITED \\(^_^)>\n" ;
                    }
                    
                    else if ( xUserGuesses <= 6 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 10/10 *COUGH* CHEATER! *COUGH* \\(^o^)/\n" ;
                    }
                    
                    bool replay = true ;
                    
                    
                    while ( replay )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t  WOULD YOU LIKE TO PLAY AGAIN? [1, 2]:\n"
                                "\n"
                                "                     1.  DUH! OF COURSE!\n"
                                "                     2.  HMMM, NOT REALLY...\n"
                                "\n"
                                "                     YOUR INPUT: " ;
                        
                        cin >> xUserInput ;
                        
                        switch ( xUserInput )
                        {
                            case 1:
                            {
                                replay = !(replay) ;
                                break ;    
                            }
                            
                            case 2:
                            {
                                replay = !(replay) ;
                                xGameRestart = !(xGameRestart) ;
                                
                                break ;    
                            }
                            
                            default:                                 // DEFAULT
                            {
                                
                                cout << "\n=============================="
                                        "================================\n\n" ;
                                
                                cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                                
                                
                                xGameRemarks = (rand() % 4) + 1 ;
                                
                                switch ( xGameRemarks )
                                {
                                    case 1:
                                    {
                                        cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                                        break ;
                                    }
                                    
                                    case 2:
                                    {
                                        cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                                        break ;
                                    }
                                    
                                    case 3:
                                    {
                                        cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                                        break ;
                                    }
                                    
                                    case 4:
                                    {
                                        cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                                        break ;
                                    }
                                    
                                }
                                
                                break ;
                            }
                        }
                    }
                    
                    break ;
                }
                
                
                
                
                
                
                
                
                
                
                
                
                
                case 2:                                 // COMPLEX
                {
                    xGameNumber = rand() % 1000 + 1 ;
                    
                    while ( xUserGuesses >= 0 )
                    {
                        cout << "\n==========================[ COMPLEX ]"
                                "=========================\n\n" ;
                        
                        cout << "\t\t I AM THINKING OF A NUMBER BETWEEN 1 & 1000...\n"
                                "\t\t\t\t ANY IDEAS WHAT IT MIGHT BE?\n"
                                "\n"
                                "                        YOUR GUESS: " ;
                        
                        cin >> xUserInput ;
                        
                        xUserGuesses++ ;
                        
                        if ( xUserInput == xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t !!!WINNER, WINNER!!!\n"
                                    "\t\t\t\t\t !!!CHICKEN, DINNER!!!\n" ;
                            
                            break ;
                        }
                        
                        else if ( xUserInput > xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t  !!!LOWER!!!\n" ;
                        }
                        
                        else if ( xUserInput < xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t !!!HIGHER!!!\n" ;
                        }
                        
                    }
                    
                    if ( xUserGuesses >= 16 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 0/10 SHAMEFUL (x.X')\n" ;
                    }
                    else if ( xUserGuesses == 15 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 2/10 YOU LOOK A LITTLE SWEATY (x.0')\n" ;
                    }
                    else if ( xUserGuesses == 14 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 4/10 MY GRANDMA GOT A BETTER SCORE (o_X')\n" ;
                    }
                    else if ( xUserGuesses == 13 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << " YOUR SCORE: 6/10 I'VE SEEN FIVE-YEAR-OLDS DO BETTER (o_O')\n" ;
                    }
                    else if ( xUserGuesses == 12 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 8/10 NOT TOO BAD (^_^)\n" ;
                    }
                    else if ( xUserGuesses == 11 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 9/10 OKAY DON'T GET TOO EXCITED \\(^_^)>\n" ;
                    }
                    else if ( xUserGuesses <= 10 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 10/10 *COUGH* CHEATER! *COUGH* \\(^o^)/\n" ;
                    }
                    
                    bool replay = true ;
                    
                    
                    while ( replay )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t  WOULD YOU LIKE TO PLAY AGAIN? [1, 2]:\n"
                                "\n"
                                "                     1.  DUH! OF COURSE!\n"
                                "                     2.  HMMM, NOT REALLY...\n"
                                "\n"
                                "                     YOUR INPUT: " ;
                        
                        cin >> xUserInput ;
                        
                        switch ( xUserInput )
                        {
                            case 1:
                            {
                                replay = !(replay) ;
                                break ;    
                            }
                            
                            case 2:
                            {
                                replay = !(replay) ;
                                xGameRestart = !(xGameRestart) ;
                                
                                break ;    
                            }
                            
                            default:                                 // DEFAULT
                            {
                                
                                cout << "\n=============================="
                                        "================================\n\n" ;
                                
                                cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                                
                                
                                xGameRemarks = (rand() % 4) + 1 ;
                                
                                switch ( xGameRemarks )
                                {
                                    case 1:
                                    {
                                        cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                                        break ;
                                    }
                                    
                                    case 2:
                                    {
                                        cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                                        break ;
                                    }
                                    
                                    case 3:
                                    {
                                        cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                                        break ;
                                    }
                                    
                                    case 4:
                                    {
                                        cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                                        break ;
                                    }
                                    
                                }
                                
                                break ;
                            }
                        }
                    }
                    
                    break ;
                }
                
                
                
                
                
                
                
                
                
                
                
                
                case 3:                                 // MY OWN
                {
                    int startingRange ;
                    int endingRange ;
                    
                    cout << "\n=============================="
                            "================================\n\n" ;
                    
                    cout << "\t\t\t  PLEASE ENTER YOUR STARTING RANGE.\n\n"
                            "\t\t\t  -MUST BE A POSITIVE NUMBER!\n"
                            "\n"
                            "                     YOUR INPUT: " ;
                    
                    cin >> startingRange ;
                    
                    while ( startingRange < 0 )
                    {
                        cout << "\n==========================[ INVALID ]"
                                "=========================\n\n" ;
                        
                        cout << "\t\t\t  PLEASE ENTER YOUR STARTING RANGE.\n\n"
                                "\t\t\t  -MUST BE A POSITIVE NUMBER!\n"
                                "\n"
                                "                     YOUR INPUT: " ;
                        
                        cin >> startingRange ;
                    }
                    
                    
                    cout << "\n=============================="
                            "================================\n\n" ;
                    
                    cout << "\t\t\t  PLEASE ENTER YOUR ENDING RANGE.\n\n"
                            "\t\t\t  -MUST BE GREATER THAN STARTING NUMBER!\n"
                            "\t\t\t  -MINIMUM RANGE OF 10! (EX: 0-10)\n"
                            "\n"
                            "                     YOUR INPUT: " ;
                    
                    cin >> endingRange ;
                    
                    while ( (endingRange < startingRange) ||
                            ( ((startingRange - endingRange) * -1) < 10) )
                    {
                        cout << "\n==========================[ INVALID ]"
                                "=========================\n\n" ;
                        
                        cout << "\t\t\t  PLEASE ENTER YOUR ENDING RANGE.\n\n"
                                "\t\t\t  -MUST BE GREATER THAN STARTING NUMBER!\n"
                                "\t\t\t  -MINIMUM RANGE OF 10! (EX: 0-10)\n"
                                "\n"
                                "                     YOUR INPUT: " ;
                        
                        cin >> endingRange ;
                    }
                    
                    int range = ( ((startingRange - endingRange) * -1) + 1 ) ;
                    
                    xGameNumber = rand() % range + startingRange ;
                    
                    while ( xUserGuesses >= 0 )
                    {
                        cout << "\n==========================[ MY OWN ]"
                                "=========================\n\n" ;
                        
                        cout << "\t\t I AM THINKING OF A NUMBER BETWEEN " << startingRange
                                << " & " << endingRange << "...\n"
                                "\t\t\t\t ANY IDEAS WHAT IT MIGHT BE?\n"
                                "\n"
                                "                        YOUR GUESS: " ;
                        
                        cin >> xUserInput ;
                        
                        xUserGuesses++ ;
                        
                        if ( xUserInput == xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t !!!WINNER, WINNER!!!\n"
                                    "\t\t\t\t\t !!!CHICKEN, DINNER!!!\n" ;
                            
                            break ;
                        }
                        
                        else if ( xUserInput > xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t  !!!LOWER!!!\n" ;
                        }
                        
                        else if ( xUserInput < xGameNumber )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t\t\t\t !!!HIGHER!!!\n" ;
                        }
                        
                    }
                    
                    if ( xUserGuesses >= 16 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 0/10 SHAMEFUL (x.X')\n" ;
                    }
                    
                    else if ( xUserGuesses == 15 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 2/10 YOU LOOK A LITTLE SWEATY (x.0')\n" ;
                    }
                    
                    else if ( xUserGuesses == 14 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 4/10 MY GRANDMA GOT A BETTER SCORE (o_X')\n" ;
                    }
                    
                    else if ( xUserGuesses == 13 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << " YOUR SCORE: 6/10 I'VE SEEN FIVE-YEAR-OLDS DO BETTER (o_O')\n" ;
                    }
                    
                    else if ( xUserGuesses == 12 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t\t\t YOUR SCORE: 8/10 NOT TOO BAD (^_^)\n" ;
                    }
                    
                    else if ( xUserGuesses == 11 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 9/10 OKAY DON'T GET TOO EXCITED \\(^_^)>\n" ;
                    }
                    
                    else if ( xUserGuesses <= 10 )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                        cout << "\t YOUR SCORE: 10/10 *COUGH* CHEATER! *COUGH* \\(^o^)/\n" ;
                    }
                    
                    bool replay = true ;
                    
                    
                    while ( replay )
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t  WOULD YOU LIKE TO PLAY AGAIN? [1, 2]:\n"
                                "\n"
                                "                     1.  DUH! OF COURSE!\n"
                                "                     2.  HMMM, NOT REALLY...\n"
                                "\n"
                                "                     YOUR INPUT: " ;
                        
                        cin >> xUserInput ;
                        
                        switch ( xUserInput )
                        {
                            case 1:
                            {
                                replay = !(replay) ;
                                break ;    
                            }
                            
                            case 2:
                            {
                                replay = !(replay) ;
                                xGameRestart = !(xGameRestart) ;
                                
                                break ;    
                            }
                            
                            default:                                 // DEFAULT
                            {
                                
                                cout << "\n=============================="
                                        "================================\n\n" ;
                                
                                cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                                
                                
                                xGameRemarks = (rand() % 4) + 1 ;
                                
                                switch ( xGameRemarks )
                                {
                                    case 1:
                                    {
                                        cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                                        break ;
                                    }
                                    
                                    case 2:
                                    {
                                        cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                                        break ;
                                    }
                                    
                                    case 3:
                                    {
                                        cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                                        break ;
                                    }
                                    
                                    case 4:
                                    {
                                        cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                                        break ;
                                    }
                                    
                                }
                                
                                break ;
                            }
                        }
                    }
                    
                    break ;
                }
                
                
                
                
                
                
                
                default:                                 // DEFAULT
                {
                    
                    cout << "\n=============================="
                            "================================\n\n" ;
                    
                    cout << "\t\t\t  SORRY, ONLY NUMBERS 1-3 ARE ALLOWED;\n" ;
                    
                    
                    xGameRemarks = (rand() % 4) + 1 ;
                    
                    switch ( xGameRemarks )
                    {
                        case 1:
                        {
                            cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                            break ;
                        }
                        
                        case 2:
                        {
                            cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                            break ;
                        }
                        
                        case 3:
                        {
                            cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                            break ;
                        }
                        
                        case 4:
                        {
                            cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                            break ;
                        }
                        
                    }
                    
                    break ;
                }
            }
            
            break ;
        }
        
        
        
        
        
        
        
        
        case 2:                                 // MIND READER
        {
            int startingRange ;
            int endingRange ;
            
            cout << "\n=============================="
                    "================================\n\n" ;
            
            cout << "\t\t\t  PLEASE TELL ME THE STARTING RANGE.\n\n"
                    "\t\t\t  -MUST BE A POSITIVE NUMBER!\n"
                    "\n"
                    "                     YOUR INPUT: " ;
            
            cin >> startingRange ;
            
            while ( startingRange < 0 )
            {
                cout << "\n==========================[ INVALID ]"
                        "=========================\n\n" ;
                
                cout << "\t\t\t  PLEASE TELL ME THE STARTING RANGE.\n\n"
                        "\t\t\t  -MUST BE A POSITIVE NUMBER!\n"
                        "\n"
                        "                     YOUR INPUT: " ;
                
                cin >> startingRange ;
            }
            
            
            cout << "\n=============================="
                    "================================\n\n" ;
            
            cout << "\t\t\t  PLEASE TELL ME THE ENDING RANGE.\n\n"
                    "\t\t\t  -MUST BE GREATER THAN STARTING NUMBER!\n"
                    "\t\t\t  -MINIMUM RANGE OF 10! (EX: 0-10)\n"
                    "\n"
                    "                     YOUR INPUT: " ;
            
            cin >> endingRange ;
            
            while ( (endingRange < startingRange) ||
                    ( ((startingRange - endingRange) * -1) < 10) )
            {
                cout << "\n==========================[ INVALID ]"
                        "=========================\n\n" ;
                
                cout << "\t\t\t  PLEASE TELL ME THE ENDING RANGE.\n\n"
                        "\t\t\t  -MUST BE GREATER THAN STARTING NUMBER!\n"
                        "\t\t\t  -MINIMUM RANGE OF 10! (EX: 0-10)\n"
                        "\n"
                        "                     YOUR INPUT: " ;
                
                cin >> endingRange ;
            }
            
            
            
            int programGuess = 0 ;
            int guessCounter = 0 ;
            int response = 0 ;
            
            int highest ;
            int lowest ;
            
            bool win = false ;
            
            const int HIGHER = 1 ;
            const int LOWER = 2 ;
            
            while ( (xUserGuesses != 10) && (win == false) )
            {
                cout << "\n========================[ MIND-READER ]"
                        "=======================\n\n" ;
                    
                cout << "\t\t YOU'RE THINKING OF A NUMBER BETWEEN " << startingRange
                        << " & " << endingRange << "...\n\n" ;
                
                guessCounter++ ;
                
                xUserGuesses++ ;
                
                switch ( guessCounter )
                {
                    case 1:
                    {
                        programGuess = (startingRange + endingRange) / 2 ;
                        
                        highest = endingRange + 1 ;
                        
                        lowest = startingRange - 1 ;
                        
                        break ;
                    }
                    
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    {
                        switch ( response )
                        {
                            case HIGHER:
                            {
                                programGuess = programGuess + ( (highest - lowest) / 2 ) ;
                                
                                break ;
                            }
                            
                            case LOWER:
                            {
                                programGuess = programGuess - ( (highest - lowest) / 2 ) ;
                                
                                break ;
                            }
                        }
                        
                        break ;
                    }
                }
                
                cout << "\t\t\t\t\t IS IT " << programGuess << "? [1, 2]:\n"
                        "\n"
                        "                     1.  YES\n"
                        "                     2.  NO\n"
                        "\n"
                        "                     YOUR RESPONSE: " ;
                
                cin >> xUserInput ;
                
                while ( (xUserInput < 1) || (xUserInput > 2) )
                {
                    
                    cout << "\n=============================="
                            "================================\n\n" ;
                    
                    cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                    
                    
                    xGameRemarks = (rand() % 4) + 1 ;
                    
                    switch ( xGameRemarks )
                    {
                        case 1:
                        {
                            cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                            
                            break ;
                        }
                        
                        case 2:
                        {
                            cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                            
                            break ;
                        }
                        
                        case 3:
                        {
                            cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                            
                            break ;
                        }
                        
                        case 4:
                        {
                            cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                            
                            break ;
                        }
                        
                    }
                    
                    cout << "\n========================[ MIND-READER ]"
                            "=======================\n\n" ;
                    
                    cout << "\t\t YOU'RE THINKING OF A NUMBER BETWEEN " << startingRange
                         << " & " << endingRange << "...\n\n" ;
                    
                    cout << "\t\t\t\t\t IS IT " << programGuess << "? [1, 2]:\n"
                            "\n"
                            "                     1.  YES\n"
                            "                     2.  NO\n"
                            "\n"
                            "                     YOUR RESPONSE: " ;
                    
                    cin >> xUserInput ;
                    
                }
                
                switch( xUserInput )
                {
                    case 1:
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t\t\t !!!WINNER, WINNER!!!\n"
                                "\t\t\t\t\t !!!CHICKEN, DINNER!!!\n" ;
                        
                        win = true ;
                        
                        break ;
                    }
                    
                    case 2:
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t  IS IT HIGHER OR LOWER? [1, 2]:\n"
                                "\n"
                                "                     1.  HIGHER\n"
                                "                     2.  LOWER\n"
                                "\n"
                                "                     YOUR RESPONSE: " ;
                        
                        cin >> xUserInput ;
                        
                        while ( (xUserInput < 1) || (xUserInput > 2) )
                        {
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                            
                            
                            xGameRemarks = (rand() % 4) + 1 ;
                            
                            switch ( xGameRemarks )
                            {
                                case 1:
                                {
                                    cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                                    
                                    break ;
                                }
                                
                                case 2:
                                {
                                    cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                                    
                                    break ;
                                }
                                
                                case 3:
                                {
                                    cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                                    
                                    break ;
                                }
                                
                                case 4:
                                {
                                    cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                                    
                                    break ;
                                }
                            }
                            
                            
                            cout << "\n=============================="
                                    "================================\n\n" ;
                            
                            cout << "\t\t\t  IS IT HIGHER OR LOWER? [1, 2]:\n"
                                    "\n"
                                    "                     1.  HIGHER\n"
                                    "                     2.  LOWER\n"
                                    "\n"
                                    "                     YOUR RESPONSE: " ;
                            
                            cin >> xUserInput ;
                            
                        }
                        
                        switch ( xUserInput )
                        {
                            case 1:
                            {
                                response = HIGHER ;
                                
                                lowest = programGuess ;
                                
                                break ;
                            }
                            
                            case 2:
                            {
                                response = LOWER ;
                                
                                highest = programGuess ;
                                
                                break ;
                            }
                        }
                        
                        break ;
                    }
                }
            }
            
            
            if ( (xUserGuesses == 10) && (win == false) )
            {
                cout << "\n=============================="
                        "================================\n\n" ;
                cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                cout << "\t PROGRAM SCORE: 0/10 I'M SURE YOU CHEATED ME (x.X')\n" ;
            }
            
            else if ( (xUserGuesses <= 10) & (win == true) )
            {
                cout << "\n=============================="
                        "================================\n\n" ;
                cout << "\t\t\t\t\t\t ATTEMPTS: " << xUserGuesses << endl ;
                cout << "\t PROGRAM SCORE: 10/10 I'M JUST TOO GOOD \\(^o^)/\n" ;
            }
            
            bool replay = true ;
            
            
            while ( replay )
            {
                cout << "\n=============================="
                        "================================\n\n" ;
                
                cout << "\t\t\t  WOULD YOU LIKE TO PLAY AGAIN? [1, 2]:\n"
                        "\n"
                        "                     1.  DUH! OF COURSE!\n"
                        "                     2.  HMMM, NOT REALLY...\n"
                        "\n"
                        "                     YOUR INPUT: " ;
                
                cin >> xUserInput ;
                
                switch ( xUserInput )
                {
                    case 1:
                    {
                        replay = !(replay) ;
                        break ;    
                    }
                    
                    case 2:
                    {
                        replay = !(replay) ;
                        xGameRestart = !(xGameRestart) ;
                        
                        break ;
                    }
                    
                    default:                                 // DEFAULT
                    {
                        cout << "\n=============================="
                                "================================\n\n" ;
                        
                        cout << "\t\t\t  SORRY, ONLY NUMBERS 1-2 ARE ALLOWED;\n" ;
                        
                        
                        xGameRemarks = (rand() % 4) + 1 ;
                        
                        switch ( xGameRemarks )
                        {
                            case 1:
                            {
                                cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                                break ;
                            }
                            
                            case 2:
                            {
                                cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                                break ;
                            }
                            
                            case 3:
                            {
                                cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                                break ;
                            }
                            
                            case 4:
                            {
                                cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                                break ;
                            }
                            
                        }
                        
                        break ;
                    }
                }
            }
            
            break ;
        }
        
    }
    
    return xGameRestart ;
}

//==============================================================================[ MAIN ]

int main()
{
    bool programActive = true ;         // program killswitch [ sentinal = false ]
    bool gameRestart ;                  // game restart variable
    
    int userInput ;                     // user-input variable #1
    int userReprompt ;                  // user-input variable #2
    
    int gameMode ;                      // game version
    int gameNumber = 0 ;                // secret game number
    int gameRemarks = 0 ;               // used to randomize smart messages
    
    int userGuesses = 0 ;               // tracks player guesses
    
    
    unsigned int srand( time(0) ) ;     // generates random #'s consecutively
    
    
    while ( programActive )
    {
        cout << "\n=============================="
                "================================\n\n" ;
        
        cout << "\t\tWELCOME TO A GAME OF GUESS THE RANDOM NUMBER!\n"
                "\t\t  CHOOSE A MODE TO READ ITS RULES AND PLAY,\n"
                "\t\t\t\t\tOR EXIT THE TERMINAL\n"
                "\t\t\t\t\t\t [1, 2, 3]:\n"
                "\n"
                "                      1.  HIGH-LOW\n"
                "                      2.  MIND-READER\n"
                "                      3.  EXIT TERMINAL\n"
                "\n"
                "                        YOUR INPUT: " ;
        
        
        cin >> userInput ;
        
        
        
        
        
        
        
        switch ( userInput )
        {
            case 1:
            {
                while ( userInput == 1 )       // recheck choice validity
                {
                    cout << "\n=============================="
                            "================================\n\n" ;
                            
                    cout << "\t\t\t\t\t\t\"HIGH-LOW\":\n\n"
                            " Player Chooses A Difficulty (Simple, Complex, My Own)\n"
                            " Which Randomly Generates A Secret Number Within A Range\n"
                            " Of 1 To 100; 1,000; Or A Player's Own Range--Respectively.\n"
                            " Player Must Guess The Number Within A Set Of Turns To Win,\n"
                            " And Fewer Turns Produce Higher Scores. Hints, Such As\n"
                            " \"Higher\" Or \"Lower\", Will Be Provided To Help The Player\n"
                            " Progress After Each Guess.\n\n" ;
                    
                    cout << "\t  YOU THINK YOU'RE READY FOR A GAME OF \"HIGH-LOW\"?\n"
                            "\t\t\t\t\t\t [1, 2]:\n"
                            "\n"
                            "                     1.  DUH! OF COURSE!\n"
                            "                     2.  HMMM, NOT REALLY...\n"
                            "\n"
                            "                     YOUR INPUT: " ;
                    
                    
                    cin >> userReprompt ;       // receive user-input #2
                    
                    
                    userInput = continueMain_Prompt( userInput, userReprompt,
                                                        gameRemarks ) ;
                }
                
                
                if ( userInput == 9 )           // check for previous main menu input
                {
                    break ;                     // break to main menu
                }
                
                
                // HI-LOW GAME MODE
                gameMode = 1 ;
                gameRestart = true ;
                
                
                while ( gameRestart )
                {
                    // GAME FUNCTION HERE TAKING ALL VARIABLES
                    gameRestart = startGame( programActive, userInput, userReprompt, gameMode,
                                            gameNumber, gameRemarks, userGuesses, gameRestart ) ;
                    
                }
                
                break ;
            }
            
            
            
            
            
            
            case 2:
            {
                while ( userInput == 2 )       // recheck choice validity
                {
                    cout << "\n=============================="
                            "================================\n\n" ;
                            
                    cout << "\t\t\t\t\t\t\"MIND-READER\":\n\n"
                            " This Game Is The Opposite Of \"High-Low\". This Time, The\n"
                            " Player Must Think Of A Random Number And Guide The Program\n"
                            " While It Attempts To Guess Your Secret Number. The Program\n"
                            " Will Aim To Accomplish Its Task Within 10 Turns. Hints, Such\n"
                            " As \"Higher\" Or \"Lower\", Will Be Provided By The Player To\n"
                            " Guide The Program After Each Guess. Note: Ranges Higher Than\n"
                            " 1000 Reduce The Program's Success Rate, So Be Gentle!\n\n" ;
                    
                    cout << "  YOU THINK YOU'RE READY FOR A GAME OF \"MIND-READER\"? [1, 2]:\n"
                            "\n"
                            "                     1.  DUH! OF COURSE!\n"
                            "                     2.  HMMM, NOT REALLY...\n"
                            "\n"
                            "                     YOUR INPUT: " ;
                    
                    
                    cin >> userReprompt ;      // receive user-input #2
                    
                    
                    userInput = continueMain_Prompt( userInput, userReprompt,
                                                        gameRemarks ) ;
                }
                
                
                if ( userInput == 9 )          // check for previous main menu input
                {
                    break ;                    // break to main menu
                }
                
                // MIND-READER GAME MODE
                gameMode = 2 ;
                gameRestart = true ;
                
                
                while ( gameRestart )
                {
                    // GAME FUNCTION HERE TAKING ALL VARIABLES
                    gameRestart = startGame( programActive, userInput, userReprompt, gameMode,
                                            gameNumber, gameRemarks, userGuesses, gameRestart ) ;
                    
                }
                
                break ;
            }
            
            
            
            
            
            
            case 3:     // if EXIT TERMINAL   -   begin THIRD scenario
            {
                while ( userInput == 3 )       // recheck choice validity
                {
                    cout << "\n=============================="
                            "================================\n\n" ;
                    
                    cout << "\t  ARE YOU POSITIVELY SURE YOU WANT TO EXIT? [1, 2]:\n"
                            "\n"
                            "                     1.  DUH! OF COURSE!\n"
                            "                     2.  HMMM, NOT REALLY...\n"
                            "\n"
                            "                     YOUR INPUT: " ;
                    
                    
                    cin >> userReprompt ;      // receive user-input #2
                    
                    
                    userInput = continueMain_Prompt( userInput, userReprompt,
                                                        gameRemarks ) ;
                }
                
                if ( userInput == 9 )          // check for previous main menu input
                {
                    break ;                    // break to main menu
                }
                
                programActive = !(programActive) ;        // activate killswitch
                
                cout << "\n=============================="
                        "================================\n\n" ;
                
                cout << "\t\t\t!!!TERMINAL WILL NOW SELF-DESTRUCT!!!\n" ;
                
                break ;         // exit program
                
            }           // EXIT TERMINAL   -   end THIRD scenario
            
            
            
            
            
            
            default:            // if all else, restart program
            {
                
                cout << "\n=============================="
                        "================================\n\n" ;
                
                cout << "\t\t\t  SORRY, ONLY NUMBERS 1-3 ARE ALLOWED;\n" ;
                
                
                gameRemarks = (rand() % 4) + 1 ;
                
                switch ( gameRemarks )
                {
                    case 1:
                    {
                        cout << "\t\t\t\tCRAYONS SHOULD NOT BE CONSUMED...\n" ;
                        break ;
                    }
                    
                    case 2:
                    {
                        cout << "\t\t\t   YOUR MATH TEACHER WOULD BE PROUD...\n" ;
                        break ;
                    }
                    
                    case 3:
                    {
                        cout << "\t\t\t\t I DO HOPE YOU'RE NOT AN ADULT...\n" ;
                        break ;
                    }
                    
                    case 4:
                    {
                        cout << "\t\t\t  WHERE DID YOU ATTEND SCHOOL AGAIN?...\n" ;
                        break ;
                    }
                    
                }
                
                break ;     // return to main menu
                
            }               // end default case
            
        }                   // end main switch
        
    }                       // end main while
    
    
    cout << "\n=============================="
            "================================\n\n" ;
            
            
    cout << "\t\t\t\t\t\t\t*BOOM*\n"
            "\t\t\t  PRETEND LIKE HUMANITY JUST ENDED (T-T)\n"
            "\t\t\t\t\tAND IT'S ALL YOUR FAULT\n" ;
            
            
    cout << "\n=============================="
            "================================\n\n" ;
    
    return 0 ;             // indicates successful termination
}
