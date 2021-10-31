/*  SIMPLE ROBOT
*   
*   Program creates a robot named "R3D3" and allows
*   the user to control it manually or set it to 
*   autopilot while it delivers a personal message.
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>                           // used for string functions
#include <vector>                           // used for vector functions
#include <unistd.h>                         // used for sleep() function
#include <boost/algorithm/string.hpp>       // used for boost::to_upper/lower
using namespace std ;

//============================================================================]
//===============================================================[ PROTOTYPES ]
//============================================================================]

void clear()
{
    cout << "\033[2J\033[1;1H" ;
}


class ROBOT
{
    public:
                ROBOT() ;
                void manualPilot() ;
                void outputGreeting() ;
                void deliverMessage( int X, int Y ) ;
    
    private:
                int batteryLevel ;      string name, greeting ;
                
                vector<int> homePosition, currentPosition ;
                
                void checkStatus() ;
                void checkBattery() ;
                void checkPosition() ;
                void rechargeBattery() ;
                void autoPilot( int X, int Y ) ;
                void setPosition( int X, int Y ) ;
} ;


ROBOT::ROBOT()
{
    name = "R3D3" ;
    batteryLevel = 100 ;
    homePosition = {0,0} ;
    currentPosition = {0,0} ;
    greeting = "\t\t\tR3D3:\t\"HELLO, MY NAME IS " + name + "...\"" ;
}


void ROBOT::checkStatus()
{
    checkBattery() ;
    checkPosition() ;
}


void ROBOT::checkBattery()
{
    cout << "CURRENT BATTERY LEVEL:\t" << batteryLevel << endl << endl ;
}


void ROBOT::rechargeBattery()
{
    if ( batteryLevel == 100 )
    {
        clear() ;
        
        cout << "\t\t\tR3D3:\t\"NO NEED TO CHARGE RIGHT NOW...\"\n" << endl ; 
        
        checkStatus() ;      sleep(3) ;      clear() ;
    }

    else
    {
        clear() ;
        
        cout << "\t\t\t\tR3D3:\t\"RECHARGING BATTERY...\"\n" << endl ;    sleep(2) ;
        
        unsigned int milliseconds ;
        
        while ( batteryLevel != 100 )
        {
            clear() ;       cout << "\t\t\t\t\tCURRENT BATTERY LEVEL: " ;
            
            batteryLevel++ ;    cout << batteryLevel << "  " << endl ;
            
            usleep(milliseconds) ;      clear() ;
        }
        
        cout << "\t\t\t\tR3D3:\t\"BATTERY FULLY CHARGED...\"\n" << endl ;
        
        checkStatus() ;      sleep(2) ;      clear() ;
    }
}


void ROBOT::checkPosition()
{
    cout << "CURRENT POSITION:\tX-Coordinate: " << currentPosition.at(0) 
         << "\t\tY-Coordinate: " << currentPosition.at(1) << endl ;
}


void ROBOT::setPosition(  int X, int Y )
{
    currentPosition.at(0) = X ;
    currentPosition.at(1) = Y ;
}


void ROBOT::manualPilot()
{
    string MOVE = "" ;
    
    cout << "\t\t\tR3D3:\t\"COMMENCING MANUAL-PILOT...\"" << endl ;
    
    sleep(2) ;      clear() ;
    
    while ( MOVE != "done" )
    {
        cout << "\t\t\t\tTYPE A DIRECTION, DONE, OR RECHARGE\n\t\t(FORWARD, BACKWARD, " 
                "RIGHT, LEFT, DONE, RECHARGE): " ;
        cout << endl << endl ;
        
        cin >> MOVE ;       boost::to_lower(MOVE) ;     cout << endl ;
        
        
        while ( (MOVE != "done") && (MOVE != "recharge") && ((MOVE != "forward")
                                 && (MOVE != "backward") && (MOVE != "right") 
                                 && (MOVE != "left")) )
        {
            cout << "\t\tR3D3:\t\"I'M SORRY, BUT THAT ENTRY IS NOT VALID...\"" << endl ;
            
            sleep(2) ;      clear() ;
            
            cout << "\t\t\t\tTYPE A DIRECTION, DONE, OR RECHARGE\n\t\t"
                    "(FORWARD, BACKWARD, RIGHT, LEFT, DONE, RECHARGE): " ;
            
            cout << endl << endl ;
            
            cin >> MOVE ;       boost::to_lower(MOVE) ;     cout << endl ;
        }
        
        clear() ;
        
        if (MOVE == "recharge") { cout << endl ; rechargeBattery() ;   continue ; }
        
        if ( (MOVE != "done") && (batteryLevel == 0) )
        {
            cout << "\t\t\tR3D3:\t\"MUST RECHARGE BEFORE MOVING...\"\n" << endl ;
            
            checkStatus() ;  sleep(2) ;  cin.ignore() ; clear() ;
            
            continue ; 
        }
        
        
        else if ( MOVE == "forward" )
        {
            (currentPosition.at(1))++ ;         (batteryLevel -= 5) ;
            
            setPosition(currentPosition.at(0), currentPosition.at(1)) ;
        }
        
        else if ( MOVE == "backward" )
        {
            (currentPosition.at(1))-- ;         (batteryLevel -= 5) ;
            
            setPosition(currentPosition.at(0), currentPosition.at(1)) ;
        }
        
        else if ( MOVE == "right" )
        {
            (currentPosition.at(0))++ ;         (batteryLevel -= 5) ;
            
            setPosition(currentPosition.at(0), currentPosition.at(1)) ;
        }
        
        else if ( MOVE == "left" )
        {
            (currentPosition.at(0))-- ;         (batteryLevel -= 5) ;
            
            setPosition(currentPosition.at(0), currentPosition.at(1)) ;
        }
        
        if ( batteryLevel < 0 )     { batteryLevel = 0 ; }
        
        if ( MOVE != "done" )
        {
            string status ;
            
            ( batteryLevel <= 20 ) ? ( status = 
                                        "\t\t\t\t\tR3D3:\t\"BATTERY LEVEL LOW...\"\n" )
                                   : ( status = "\t\t\t\t\t\tR3D3:\t\"MOVING...\"\n" ) ;
                            
            cout << status << endl ;
        }
        
        if ( MOVE == "done" )
        {
            cout << "\t\t\t\t\tR3D3:\t\"GOODBYE...\"\n" << endl ;
        }
        
        checkStatus() ;         sleep(2) ;      cin.ignore() ;      clear() ;
    }
}


void ROBOT::outputGreeting()
{
    clear() ;       cout << greeting << endl ;      sleep(3) ;      clear() ;
}


void ROBOT::autoPilot( int X, int Y )
{
    if ( batteryLevel == 0 )    { cout << endl ;    clear() ;   rechargeBattery() ; }
    
    string status ;
    
    ( batteryLevel <= 20 ) ? ( status = "\t\t\t\t\tR3D3:\t\"BATTERY LEVEL LOW...\"\n" )
                           : ( status = "\t\t\t\t\t\tR3D3:\t\"MOVING...\"\n" ) ;
                          
    cout << status << endl ;        checkStatus() ;      clear() ;
    
    if ( (currentPosition.at(0) != X) )
    {
        ( currentPosition.at(0) < X )   ?   ( (currentPosition.at(0))++ )
                                        :   ( (currentPosition.at(0))-- ) ;
        
        (batteryLevel -= 5) ;
    }
    
    if ( (currentPosition.at(1) != Y) )
    {
        ( currentPosition.at(1) < Y )   ?   ( (currentPosition.at(1))++ )
                                        :   ( (currentPosition.at(1))-- ) ;
        
        (batteryLevel -= 5) ;
    }
    
    if ( batteryLevel < 0 )             { batteryLevel = 0 ; }
    
    ( batteryLevel <= 20 ) ? ( status = "\t\t\t\t\tR3D3:\t\"BATTERY LEVEL LOW...\"\n" )
                           : ( status = "\t\t\t\t\t\tR3D3:\t\"MOVING...\"\n" ) ;
                          
    cout << status << endl ;        checkStatus() ;      clear() ;
}


void ROBOT::deliverMessage( int X, int Y )
{
    cout << "\t\t\t\tR3D3:\t\"COMMENCING AUTOPILOT...\"" << endl ;
    
    sleep(2) ;      clear() ;
    
    cout << "\t\t\tR3D3:\t\"TYPE A MESSAGE TO DELIVER...\"\n\n" ;
    
    string MESSAGE ;     getline(cin, MESSAGE) ;     clear() ;
    
    while ( (currentPosition.at(0) != X) || (currentPosition.at(1) != Y) )
    {
        autoPilot( X, Y ) ;     sleep(1);       clear() ;
    }
    
    cout << endl ;   clear() ;      boost::to_upper(MESSAGE) ;
    
    cout << "\tR3D3:\t\"MESSAGE: '"+MESSAGE+"' DELIVERED SUCCESSFULLY...\"" << endl ;
    
    sleep(3) ;      clear() ;
    
    cout << "\t\t\t\t\tR3D3:\t\"GOODBYE...\"\n" << endl ;
    
    sleep(2) ;      clear() ;
}


//============================================================================]
//=====================================================================[ MAIN ]
//============================================================================]

int main()
{
    ROBOT myRobot ;
    
    myRobot.outputGreeting() ;
    
    myRobot.manualPilot() ;
    
    myRobot.deliverMessage( -15, -15 ) ;
    myRobot.deliverMessage( 0, 0 ) ;
    
    myRobot.manualPilot() ;
    
    return 0 ;
}

//============================================================================]
//===================================================[ USER-DEFINED FUNCTIONS ]
//============================================================================]
