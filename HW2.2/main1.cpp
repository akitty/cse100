
#include <iostream>
#include <ctime>
#include "table.hpp"

using namespace std ;

int
main ( unsigned argc , char * * argv )
{
	int i , j , k ;
	unsigned size , samples = 2000 ;
	double successful , unsuccessful0 , unsuccessful1 ;

	if ( argc == 2 ) 
		size = atoi ( argv[1] ) ;
	else {
		cerr << argv[0] << " requires one <size> parameter" << endl ;
		exit(1) ;
	}

	Table<unsigned> test(size) ;
	
	unsigned ddd ;
	Perform ppp ;

	// srandom(time(0)) ;			this will provide differing results
	srandom(1234) ;					
	
	printf ( "%0.6f %10.6f %10.6f %10.6f   Brent hashing with one passbit\n" , 0.0 , 1.0 , 1.0 , 1.0 ) ;
	for ( j = 1 ; j <= size ; j++ ) {			// j is alpha*size
		successful = unsuccessful0 = unsuccessful1 = 0 ;
		for ( k = 0 ; k < samples ; k++ ) {
			test.empty() ;
			for ( i = 0 ; i < j ; i++ ) {
				ddd = random () ;		// random will differ on various systems
				test.insert(ddd) ; 
			}
			ppp = test.perform( ) ;
			successful += ppp.successful ;
			unsuccessful0 += ppp.unsuccessful[0] ;
			unsuccessful1 += ppp.unsuccessful[1] ;
		}
		double alpha ;
		alpha = (double)j/size ;
		printf ( "%0.6f %10.6f %10.6f %10.6f   Brent hashing with one passbit\n" , alpha , successful/samples , unsuccessful0/samples , 
							unsuccessful1/samples ) ;
		fflush ( stdout ) ;
	}
}
