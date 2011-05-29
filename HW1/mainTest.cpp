#include <fstream>						// #include <stdio.h>
#include <iostream>						// #include <stdio.h>
#include <string>						// #include <string.h>    <cstring>
#include <cstdlib>						// #include <stdlib.h>

using namespace std ;

#include "testSort.hpp"						// #include "testSort.h"

int
main ( int argc , char * * argv ) 
{
	string iname , iiname ; 				// char iname [100] ;	char iiname [100] ;    
	ifstream iidata , idata ;				// FILE * iidata , * idata ;
	
	if ( argc > 2 ) {
		iname = argv[1] ; 				// strcpy ( iname , argv[1] ) ;
		iiname = argv[2] ; 				// strcpy ( iiname , argv[2] ) ;
	} else {
		cerr << argv[0] << 												
			" requires two input files" << endl ; 	// fprintf ( stderr , "%s requires two input files\n" , argv[0] ) ;
		exit ( 0 ) ;
	}

	idata.open ( iname.data() , ios::in ) ;			//  idata = fopen (  iname , "r" ) ;
	iidata.open ( iiname.data() , ios::in ) ;   		// iidata = fopen ( iiname , "r" ) ;
	if ( ! idata.is_open() ) 				// if ( feof (  idata ) ) 
		cerr << "can't open " << iname << endl ; 	// 		fprintf ( stderr , "can't open %s\n" ,  iname ) ;
	if ( ! iidata.is_open() ) 				// if ( feof ( iidata ) ) 
		cerr << "can't open " << iiname << endl ;	//		fprintf ( stderr , "can't open %s\n" , iiname ) ;
	if ( ! idata.is_open() || ! iidata.is_open())		// if ( idata == NULL || iidata == NULL ) 
		exit ( 0 ) ; 

	cout << iname <<" " << iiname << endl ;			// printf ( "%s %s\n" , iname , iiname ) ;

	if ( testSort ( idata, iidata ) == true ) 
		cout << "order is consistent" << endl ;		// printf ( "order is consistent\n" ) ;

}
