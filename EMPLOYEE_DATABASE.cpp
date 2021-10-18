/*  EMPLOYEE DATABASE
*   
*   Program reads employee data from 'employee.txt'
*   file and runs various functions to manipulate &
*   print data to the screen.
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std ;

//===============================================================[ PROTOTYPES ]

void printEmployeeINFO( int xIndex, vector<string> xNames,
                                    vector<string> xTitles ) ;

void printALL( vector<string> xNames, vector<string> xTitles,
                                      const int xEMPLOYEES ) ;

void searchForEMPLOYEE( string& xNAME, vector<string> xNames,
                        const int xEMPLOYEES ) ;

int returnEmployeeINDEX( string NAME, vector<string> xNames,
                                      const int xEMPLOYEES ) ;

double returnEmployeeAVERAGE( int xIndex, vector<int> xReview1,
                              vector<int> xReview2, vector<int> xReview3,
                              const int xREVIEWS  ) ;

void printEmployeeINFORMATION( string NAME, vector<string> xNames,
                               vector<string> xTitles, vector<int> xReview1,
                               vector<int> xReview2, vector<int> xReview3,
                               const int xEMPLOYEES, const int xREVIEWS  ) ;

int returnIndexHighestAVERAGE( vector<string> xNames, vector<int> xReview1,
                               vector<int> xReview2, vector<int> xReview3,
                               const int xEMPLOYEES, const int xREVIEWS ) ;

void updateTITLES( string NAME, vector<string> xNames, vector<string>& xTitles,
                                                       const int xEMPLOYEES ) ;

//=====================================================================[ MAIN ]

int main()
{
    const int EMPLOYEES = 8 ;   const int REVIEWS = 3 ;
    
    vector<string> names ;      vector<string> titles ;
    vector<int> review1 ;       vector<int> review2 ;
    vector<int> review3 ;       ifstream INFS ;
    
    // open txt document
    INFS.open( "employees.txt" ) ;
    
    // indicate failure to open txt document
    if ( !(INFS.is_open()) )  { cout << "*READ UNSUCCESSFUL*\n" << endl ; }
    
    else
    {
        int count = 0 ;
        
        // populate vectors
        while ( !(INFS.eof()) )
        {
            string str1, str2 ;     int num1, num2, num3 ;
            
            INFS >> str1 ;      INFS >> str2 ;
            INFS >> num1 ;      INFS >> num2 ;      INFS >> num3 ;
            
            for ( unsigned int i = 0; i < 1; i++ )
            {
                names.push_back(str1) ;     titles.push_back(str2) ;
                
                review1.push_back(num1) ;   review2.push_back(num2) ;
                review3.push_back(num3) ;
            }
            
            count++ ;
        }
        
        // receive user-input
        cout << "Enter Employee Index: " ;
        
        int INDEX ;
        cin >> INDEX ;
        
        while ( INDEX < 0 || INDEX > 7 )
        {
            cout << "\n*INDEX NOT FOUND...TRY AGAIN*" << endl ;
        
            cout << "\n\nEnter Employee Index: " ;      cin >> INDEX ;
        }
        
        
        // print single employee data
        printEmployeeINFO( INDEX, names, titles ) ;
        
        // print all employee data
        printALL( names, titles, EMPLOYEES ) ;
        
        // receive user-input
        cout << "\n\nEnter Employee Name: " ;
        
        string NAME ;       cin >> NAME ;
        
        searchForEMPLOYEE( NAME, names, EMPLOYEES ) ;
        
        
        // return employee index
        INDEX = returnEmployeeINDEX( NAME, names, EMPLOYEES ) ;
        
        // return employee average score
        double AVERAGE ;
        
        AVERAGE = returnEmployeeAVERAGE( INDEX, review1, review2, review3, REVIEWS ) ;
        
        ( AVERAGE == floor(AVERAGE) ) ? ( cout << floor(AVERAGE) << endl )
                                      : ( cout << fixed << setprecision(2)
                                                        << AVERAGE << endl ) ;
        
        
        // print employee information
        printEmployeeINFORMATION( NAME, names, titles, review1, review2, review3,
                                  EMPLOYEES, REVIEWS ) ;
        
        // return index of employee with highest average score (AYATI)
        INDEX = returnIndexHighestAVERAGE( names, review1, review2, review3,
                                           EMPLOYEES, REVIEWS ) ;
        
        cout << "\n\nIndex With The Highest Average Score: " << INDEX << endl ;
        
        
        bool unfinished = true ;
        
        // loop until finished
        while ( unfinished )
        {
            // receive user-input
            cout << "\n\nEnter Employee Name To Change Their Title: " ;
            
            cin >> NAME ;
            
            searchForEMPLOYEE( NAME, names, EMPLOYEES ) ;
            
            // update employee titles by Name
            updateTITLES( NAME, names, titles, EMPLOYEES ) ;
            
            cout << "\nWould You Like To Change Another? (yes/no) " ;
            
            string response ;   cin >> response ;
            
            while ( (response != "yes") && (response != "no") )
            {
                cout << "\n*INVALID RESPONSE...TRY AGAIN*" << endl ;
                
                cout << "\nWould You Like To Change Another? (yes/no) " ;
                
                cin >> response ;
            }
            
            ( response == "yes" ) ? ( unfinished = true ) : ( unfinished = false ) ;
        }
        
        // print all employee data
        printALL( names, titles, EMPLOYEES ) ;
    }
    
    return 0 ;
}

//===================================================[ USER-DEFINED FUNCTIONS ]

// print single employee information
void printEmployeeINFO( int xIndex, vector<string> xNames,
                                    vector<string> xTitles )
{
    switch( xIndex )
    {
        case 0: 
        case 1: 
        case 2: 
        case 3: 
        case 4: 
        case 5: 
        case 6: 
        case 7:
        {
            cout << "\n" << xNames.at(xIndex) << "(" 
                 << xTitles.at(xIndex) << ")" << endl ; break ;
        }
    }
}


// print all data of employees
void printALL( vector<string> xNames, vector<string> xTitles,
                                      const int xEMPLOYEES )
{
    cout << "\n\n*PRINTING ALL EMPLOYEE DATA*" << endl ;
    
    for ( unsigned int index = 0; index < xEMPLOYEES; index++ )
    {
        printEmployeeINFO( index, xNames, xTitles ) ;
    }
}


// search for employee name
void searchForEMPLOYEE( string& xNAME, vector<string> xNames,
                        const int xEMPLOYEES )
{
    for ( unsigned int i = 0; i < xEMPLOYEES; i++ )
    {
        if ( (i == 7) && (xNAME != xNames.at(i)) )
        {
            i = 0 ;
            cout << "\n*NAME NOT FOUND...TRY AGAIN*" << endl << endl ; 
            
            cout << "\nEnter Employee Name To Change Their Title: " ;   cin >> xNAME ;
        }
        
        if ( xNAME != xNames.at(i) )  { continue ; }
        
        else                            { break ; }
    }
}


// returns employee index
int returnEmployeeINDEX( string NAME, vector<string> xNames,
                                      const int xEMPLOYEES )
{
    for ( unsigned int i = 0; i < xEMPLOYEES; i++ )
    {
        if ( NAME != xNames.at(i) )         { continue ; }
        
        else if ( NAME == xNames.at(i) )    { return i ; }
    }
    
    return 0 ;
}


// returns employee average score
double returnEmployeeAVERAGE( int xIndex, vector<int> xReview1,
                              vector<int> xReview2, vector<int> xReview3,
                              const int xREVIEWS )
{
    double average ;        double sum ;
    
    switch( xIndex )
    {
        case 0: 
        case 1: 
        case 2: 
        case 3: 
        case 4: 
        case 5: 
        case 6: 
        case 7:
        {
            sum = ( xReview1.at(xIndex)   +
                    xReview2.at(xIndex)   +
                    xReview3.at(xIndex) ) ;
            
            average = sum / xREVIEWS ;
                         
            break ;
        }
    }
    
    return average ;
}


// prints employee information
void printEmployeeINFORMATION( string NAME, vector<string> xNames,
                               vector<string> xTitles, vector<int> xReview1,
                               vector<int> xReview2, vector<int> xReview3,
                               const int xEMPLOYEES, const int xREVIEWS )
{
    double average ;        int index ;
    
    index = returnEmployeeINDEX( NAME, xNames, xEMPLOYEES ) ;
    
    average = returnEmployeeAVERAGE( index, xReview1, xReview2,
                                     xReview3, xREVIEWS ) ;
    
    ( average == floor(average) ) ? ( cout << "\n" << xNames.at(index) << "(" <<
                                        xTitles.at(index) << ")\n" <<
                                        "Average Review Score: " << 
                                        floor(average) << endl )
                                    
                                  : ( cout << "\n" << xNames.at(index) << "(" <<
                                        xTitles.at(index) << ")\n" <<
                                        "Average Review Score: " << fixed <<
                                        setprecision(2) << average << endl ) ;
}


// returns highest average score of all employees
int returnIndexHighestAVERAGE( vector<string> xNames, vector<int> xReview1,
                               vector<int> xReview2, vector<int> xReview3,
                               const int xEMPLOYEES, const int xREVIEWS )
{
    vector<double> AVERAGES ;       vector<string> NAMES ;
    
    int average ;               int highest ;           string strHIGHEST ;
    
    for ( unsigned int index = 0; index < xEMPLOYEES; index++ )
    {
        average = returnEmployeeAVERAGE( index, xReview1, xReview2,
                                         xReview3, xREVIEWS ) ;
        
        AVERAGES.push_back( average ) ;     NAMES.push_back( xNames.at(index) ) ;   
    }
    
    for ( unsigned int i = 0; i < xEMPLOYEES; i++ )
    {
        if ( i == 0 )
        {
            highest = AVERAGES.at(i) ;
            strHIGHEST = NAMES.at(i) ;
        }
        
        else if ( AVERAGES.at(i) > highest )
        {
            highest = AVERAGES.at(i) ;
            strHIGHEST = NAMES.at(i) ;
        }
    }
    
    int index = returnEmployeeINDEX( strHIGHEST, xNames, xEMPLOYEES ) ;
    
    return index ;
}


// updates employee titles
void updateTITLES( string NAME, vector<string> xNames, vector<string>& xTitles,
                                                       const int xEMPLOYEES )
{
    for ( unsigned int i = 0; i < xEMPLOYEES; i++ )
    {
        if ( NAME != xNames.at(i) )         { continue ; }
        
        else if ( NAME == xNames.at(i) )
        {
            string newTITLE ;
            
            cout << "\nEnter A New Title For " << NAME << ": " ;
            
            cin >> newTITLE ;       xTitles.at(i) = newTITLE ;
        }
    }
}
