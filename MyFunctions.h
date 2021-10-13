//================================[ MY FUNCTIONS ]=============================\\

//===================================================================[ ADDITION ]
// RETURNS SUM OF TWO NUMBERS
double add( double x, double y )
{
    return ( x + y ) ;
}

//=============================================================[ MULTIPLICATION ]
// RETURNS PRODUCT OF TWO NUMBERS
double multiply( double x, double y )
{
    return ( x * y ) ;
}

//===================================================================[ BIGGEST ]
// RETURNS BIGGEST VALUE OF THREE NUMBERS
double biggest( double x, double y, double z )
{
    vector<double> list = { x, y, z } ;
    
    double biggest ;    int LIST = list.size() ;
    
    for ( unsigned int i = 0; i < LIST; i++ )
    {
        if ( i == 0 ) { biggest = list[i] ; }
        
        if ( biggest < list[i] ) { biggest = list[i] ; }
    }
    
    return biggest ;
}

//==================================================================[ SMALLEST ]
// RETURNS SMALLEST VALUE OF THREE NUMBERS
double smallest( double x, double y, double z )
{
    vector<double> list = { x, y, z } ;
    
    double smallest ;   int LIST = list.size() ;
    
    for ( unsigned int i = 0; i < LIST; i++ )
    {
        if ( i == 0 ) { smallest = list[i] ; }
        
        if ( smallest > list[i] ) { smallest = list[i] ; }
    }
    
    return smallest ;
}

//======================================================================[ EVEN ]
// RETURNS TRUE IF NUMBER IS EVEN
bool isEven( int number )
{
    bool condition ;
    
    ( number % 2 == 0 ) ? ( condition = true ) : ( condition = false ) ;
    
    return condition ;
}

//=======================================================================[ ODD ]
// RETURNS TRUE IF NUMBER IS ODD
bool isOdd( int number )
{
    bool condition ;
    
    ( number % 2 != 0 ) ? ( condition = true ) : ( condition = false ) ;
    
    return condition ;
}

//===============================================================[ SUM IN RANGE ]
// RETURNS SUM OF ENTIRE RANGE BETWEEN TWO NUMBERS
int sum( int x, int y )
{
    int sum = 0 ;
    
    for ( unsigned int i = x; i <= y; i++ )
    {
        sum += i ;
    }
    
    return sum ;
}

//=============================================================[ POWER FUNCTION ]
// RETURNS TOTAL OF A NUMBER RAISED TO A CERTAIN POWER
int power( int x, int y )
{
    int powered = x ;
    
    for ( unsigned int i = 1; i < y; i++ )
    {
        powered *= x ;
    }
    
    return powered ;
}

//=============================================================[ RANDOM NUMBERS ]
// RETURNS RANDOM NUMBER WITHIN RANGE OF TWO NUMBERS
int randomNumber( int x, int y )
{
    // get range of numbers         // to be added to START to reach END
    int START = abs( x - y ) ;      int END = x ;
    
    int number = rand() % START + END ;         // generate random number
    
    return number ;
}

//===========================================================[ PRIME IDENTIFIER ]
// RETURNS TRUE IF NUMBER IS PRIME
bool isPrime( int number )
{
    bool condition ;    vector<int> factors = {} ;
    
    for ( unsigned int i = number; i >= 1; i--)
    {
        if ( number % i == 0 )      { factors.push_back(i) ; }
    }
    
    int FACTORS = factors.size() ;
    
    ( FACTORS == 2 ) ? ( condition = true ) : ( condition = false ) ;
    
    return condition ;
}

//============================================================[ PRIMES IN RANGE ]
// OUTPUTS ALL PRIME NUMBERS IN RANGE; EXCLUDING USER-INPUT
void listPrimes( int number )
{
    vector<int> primes = {} ;
    
    for ( unsigned int p = 0; p < number; p++ )
    {
        if ( isPrime(p) )  { primes.push_back(p) ; }
    }
    
    int PRIMES = primes.size() ;
    
    for ( unsigned int i = 0; i < PRIMES; i++ )
    {
        ( i <= (PRIMES-2) ) ? ( cout << primes[i] << ", " ) :
                              ( cout << primes[i] ) ;
    }
    
    cout << endl ;
}