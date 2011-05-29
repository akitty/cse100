#include <iostream>
#include <cstdio>
#include <cmath>
#include "table.hpp"
#include "MyData.hpp" 

MyData myData[]  = { MyData(92014,"bev tuxin") , MyData(92093,"herb jones") , MyData(16428,"diane lake") , 
		MyData(12345, "willie yuu"), MyData(23455,"darrell cruz") , MyData(34567,"jehan roma") , 
		MyData(16428,"patti bliss"), MyData(56789,"alex kronkov") , MyData(92014,"beth smith") ,
		MyData(78901,"alan knox") , MyData(89012, "khanh tran") , MyData(90123,"ray bass") , 
		MyData(23471,"steve finny") , MyData(23423, "lee park") , MyData(711711,"phil bose") } ;

using namespace std ;


void  main_print ( Table<MyData> & t, ostream & out, unsigned tableSize )
{
        unsigned i , val , step ;
        MyData bucket ;
        bool pb;
        bool flag;
        int loc;

        for ( i = 0 ; i < tableSize ; i ++ ) {
		out.width(2) ; out.flags ( ios::right ) ;
		out << i ;
                flag = t.getData( i, bucket, pb );
                if ( flag ){
                	out << ": " << ((pb)?"t":"f") << "  " ;
                        out << bucket    << "  | " ;
                        // val = unsigned(bucket[i]) ;
                        val = unsigned(bucket);
                        loc = val % tableSize;
                        step = val % (tableSize-2) + 1 ;
                        while ( loc != i ) {
                                out << loc << ", " ;
                                loc -= step ;
                                if ( loc < 0 ) loc += tableSize ;
                        }
                        out << i ;
                } else out << ": f" ;
                out << endl ;
        }
}




int 
main ( void ) 
{
	Table<MyData> table(13);     
	int i , j ;
	Perform ppp ;
	

	cout << endl << "Double hashing:" << endl << endl ;
	for ( j = 0 ; j < 10 ; j++ ) 
		table.insertD ( myData[j] ) ;

// 	cout << table << endl ;
	
        main_print( table, cout, 13 ); cout << endl;

	ppp = table.perform() ;

	cout << "average ssl " << ppp.successful ;
	cout << "    expected ssl " <<  -13.0/10 * log ( 1 - 10.0/13 ) << endl ;
	cout << "average usl via passbits " << ppp.unsuccessful[1] ;
	cout << "    average usl calculated " << ppp.unsuccessful[0] ;
	cout << "    expected usl " <<  1.0/((1-10.0/13)*(1-log(1-10.0/13))) << endl ;

	table.empty( ) ;


	cout << endl << "Brent hashing:" << endl << endl ;

	for ( j = 0 ; j < 10 ;  j++ ) 
		table.insert ( myData[j] ) ;

//	cout << table << endl ;

	main_print( table, cout, 13 ); cout << endl;
	

	ppp = table.perform() ;

	cout << "average ssl " << ppp.successful << endl ;
	cout << "average usl via passbits " << ppp.unsuccessful[1] ;
	cout << "    average usl calculated " << ppp.unsuccessful[0] << endl ;
}
