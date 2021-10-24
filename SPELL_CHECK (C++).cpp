/*  SPELL-CHECK
*   
*   Program reads from 'largeDictionary.txt' file
*   and checks if a user's input is spelled correctly,
*   provides a few spelling suggestions, and updates the
*   dictionary to include any word the user adds.
*   
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>                           // used for string functions
#include <vector>                           // used for vector functions
#include <fstream>                          // used for i/o fstream
#include <unistd.h>                         // used for sleep() function
#include <boost/algorithm/string.hpp>       // used for boost::to_upper/lower
using namespace std ;

//============================================================================]
//===============================================================[ PROTOTYPES ]
//============================================================================]

void checkSPELLING( string xWord, vector<string> xDictionary, bool& xSearching ) ;

void spellingSUGGESTIONS( string xWord, vector<string> xDictionary ) ;

void updatePROMPT( bool& xUpdating ) ;

void updateDICTIONARY( string xWord, vector<string>& xDictionary,
                       bool& xUpdating, bool& xUpdated ) ;

void finalizeUPDATES( vector<string> xDictionary ) ;

//============================================================================]
//=====================================================================[ MAIN ]
//============================================================================]

int main()
{
    // declare variables            // declare in-file stream
    bool searching = true ;         ifstream READ ;
    bool updating = false ;          
    bool updated = false ;          string word ;
    
    // declare empty vector         // open text document
    vector<string> DICTIONARY ;     READ.open("largeDictionary.txt") ;
    
    
    // check if document can read properly or return error
    if ( !READ.is_open() )  { cout << "READ UNSUCCESSFUL" << endl ; return 1 ; }
    
    // read document and append words to dictionary vector
    while ( !READ.eof() )
    {
        READ >> word ;              DICTIONARY.push_back(word) ;
    }
    
    
    cout << "WELCOME TO SPELL-CHECK!\n\n" ;
    
    // loop until check-spelling ends
    while ( searching )
    {
        checkSPELLING( word, DICTIONARY, searching ) ;
    }
    
    
    // prompt to update dictionary
    updatePROMPT( updating ) ;
    
    // loop until update dictionary ends
    while ( updating )
    {
        updateDICTIONARY( word, DICTIONARY, updating, updated ) ;
    }
    
    
    // finalize any updates to dictionary
    if ( updated )
    {
        finalizeUPDATES( DICTIONARY ) ;
    }
    
    
    cout << "THANK YOU FOR USING SPELL-CHECK!\n\n" ;       sleep(2) ;
    cout << "GOOD-BYE!" << endl << endl ;
    
    
    return 0 ;
}

//============================================================================]
//===================================================[ USER-DEFINED FUNCTIONS ]
//============================================================================]

// function checks if words are spelled correctly
// and outputs suggestions if word is misspelled
void checkSPELLING( string xWord, vector<string> xDictionary, bool& xSearching )
{
    cout << "Enter A Word To Check Its Spelling: " ;
    
    cin >> xWord ;          boost::to_lower( xWord ) ;
    
    
    // loops to find word in dictionary
    for ( unsigned int i = 0; i < xDictionary.size(); i++ )
    {
        // outputs suggestions if word is not found
        if ( (i == xDictionary.size() - 1) && (xWord != xDictionary.at(i)) )
        {
            i = 0 ;
            
            boost::to_upper( xWord ) ;
            
            cout << "*" << xWord << " IS NOT A WORD!\n" << endl ;
            
            spellingSUGGESTIONS(xWord, xDictionary) ;
            
            sleep(4) ;
            
            cout << "Enter A Word To Check Its Spelling: " ;    cin >> xWord ;
            
            boost::to_lower( xWord ) ;
        }
        
        // skips dictionary word if searched word is not identical
        if ( xWord != xDictionary.at(i) )           { continue ; }
        
        // breaks from loop once word is found in dictionary
        else if ( xWord == xDictionary.at(i) )         { break ; }
    }
    
    
    boost::to_upper( xWord ) ;
    
    cout << "*" << xWord << " IS SPELLED CORRECTLY*\n\n" << endl ;
    
    
    // prompt to check another word's spelling
    cout << "Check Another Word? (Yes/No) " ;
    
    cin >> xWord ;          boost::to_lower( xWord ) ;
    
    
    while ( xWord != "yes" && xWord != "no" )
    {
        cout << "*INVALID*\n\n" << endl ;
        cout << "Check Another Word? (Yes/No) " ;
        
        cin >> xWord ;      boost::to_lower( xWord ) ;
    }
    
    ( xWord == "yes" ) ? ( xSearching = true ) : ( xSearching = false ) ;
    
    cout << endl << endl ;
}



// function outputs suggestions for misspelled words
void spellingSUGGESTIONS( string xWord, vector<string> xDictionary )
{
    vector<string> suggestions ;        boost::to_lower( xWord ) ;
    
    // loop through dictionary to find similar words
    for ( unsigned int i = 0; i < xDictionary.size(); i++ )
    {
        // lower word-casing to increase precision
        boost::to_lower( xDictionary.at(i) ) ;
        
        // delete last char from word index
        if ( i == 0 )                       { xWord.pop_back() ; }
        
        // break once suggestion list holds 5 words
        if ( suggestions.size() == 5 )                 { break ; }
        
        // or break before suggestion list repeats a word
        else if ( find(suggestions.begin(), suggestions.end(), xDictionary.at(i) ) 
                    != suggestions.end() )             { break ; }
        
        // once end of dictionary is reached, delete last 
        // char from current word index, and continue looping
        if ( (xDictionary.at(i).find(xWord) == string::npos) &&
             (i == xDictionary.size() - 1) )
        {
            i = 0 ;     xWord.pop_back() ;
        }
        
        // if dictionary word does not contain searched word, skip index
        if (xDictionary.at(i).find(xWord) == string::npos)      { continue ; }
        
        // if dictionary word contains searched word, add to suggestion list
        else if (xDictionary.at(i).find(xWord) != string::npos)
        { 
            suggestions.push_back(xDictionary.at(i)) ;
        }
    }
    
    cout << "DID YOU MEAN TO TYPE ONE OF THESE?\n\n" ;
    
    // output collected suggestions from list
    for ( string SUGGESTIONS: suggestions )
    {
        cout << "* " << SUGGESTIONS << endl ;
    }
    
    cout << endl << endl ;
}



// function prompts user to update dictionary
void updatePROMPT( bool& xUpdating )
{
    cout << "Would You Like To Update The Dictionary? (Yes/No) " ;
    
    string choice ;     cin >> choice ;     boost::to_lower( choice ) ;
    
    while ( choice != "yes" && choice != "no" )
    {
        cout << "*INVALID*\n\n" << endl ;
        cout << "Would You Like To Update The Dictionary? (Yes/No) " ;
        
        cin >> choice ;             boost::to_lower( choice ) ;
    }
    
    ( choice == "yes" ) ? ( xUpdating = true ) : ( xUpdating = false ) ;
    
    cout << endl << endl ;
}



// function takes in a new word, updates the dictionary
// alphabetically, & indicates where the word is stored
void updateDICTIONARY( string xWord, vector<string>& xDictionary,
                       bool& xUpdating, bool& xUpdated )
{
    while ( xUpdating )
    {
        cout << "Enter A Word To Add To The Dictionary: " ;      cin >> xWord ;
        
        boost::to_lower( xWord ) ;      bool DONE = false ;
        
        // loops to check if word already exists
        for ( unsigned int i = 0; i < xDictionary.size(); i++ )
        {
            // if word does not exist
            if ( (i == xDictionary.size()-1) && (xWord != xDictionary.at(i)) )
            {
                // loop to find alphabetical order
                for ( unsigned int I = 0; I < xDictionary.size(); I++ )
                {
                    // once found; insert word and output position
                    if ( (xWord < xDictionary.at(I)) )
                    {
                        xDictionary.insert( xDictionary.begin() + I, xWord ) ;
                        
                        cout << endl ;
                        
                        xWord[0] = toupper(xWord[0]) ;
                        xDictionary.at(I-1)[0] = toupper(xDictionary.at(I-1)[0]) ;
                        xDictionary.at(I+1)[0] = toupper(xDictionary.at(I+1)[0]) ;
                        
                        cout << "* " << xWord << " Has Been Added To The Dictionary\n"
                                                 "  Between " << xDictionary.at(I-1) 
                                                << " And "  << xDictionary.at(I+1)
                                                << " *" << endl << endl << endl ;
                        
                        boost::to_lower( xWord ) ;
                        boost::to_lower( xDictionary.at(I-1) ) ;
                        boost::to_lower( xDictionary.at(I+1) ) ;
                        
                        sleep(3) ;
                        
                        // change updated condition
                        xUpdated = true ;
                        
                        // change condition to exit outer loop
                        DONE = true ;
                        
                        break ;
                    }
                }
            }
            
            if ( DONE )                                         { break ; }
            
            if ( xWord != xDictionary.at(i) )                  { continue ; }
            
            else if ( xWord == xDictionary.at(i) )
            {
                cout << "*THAT WORD ALREADY EXISTS*\n\n" << endl ;  break ;
            }
        }
        
        updatePROMPT( xUpdating ) ;
    }
}



void finalizeUPDATES( vector<string> xDictionary )
{
    // declare out-file stream
    ofstream WRITE ;
    
    // overwrite txt file to include updated dictionary
    WRITE.open( "largeDictionary.txt" ) ;
    
    cout << "*FINALIZING UPDATES...PLEASE WAIT*" << endl << endl ; 
    
    // overwrite txt file
    for ( string UPDATE: xDictionary )
    {
        WRITE << UPDATE << endl ;        
    }
    
    cout << "*UPDATES COMPLETE*" << endl << endl ;
    
    sleep(1) ;
    
    cout << "\"Go Forth Ye and Wield Thy New Diction...\"\n"
            "                                 -Unknown\n\n\n" ;
    
    sleep(4) ;
}