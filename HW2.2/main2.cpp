#include <iostream>
#include <cmath>
#include "table.hpp"
#include <iomanip>

#define Number 8
#define TableSize 11
Perform pp ;

unsigned x[Number] = { 1234 , 2345 , 2342 , 6781 , 234 , 9982 , 235 , 3589 } ;

using namespace std ;

void  main_print ( Table<unsigned> & t, ostream & out, unsigned tableSize )
{
        unsigned i , val , step ;
        unsigned bucket;
        bool pb;
        bool flag;
        int loc;

        for ( i = 0 ; i < tableSize ; i ++ ) {
		out.width(2) ; out.flags ( ios::right ) ;
		out << i ;
                flag = t.getData( i, bucket, pb );
                if ( flag ){
                	out << ": " << ((pb)?"t":"f") << "  " ;
                        out << setw(7) << bucket  << "  | " ;
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
	Table<unsigned> myTable(TableSize) ;
	unsigned a = 6781 , b = 7766 , c = 98 ;

	for ( int j = 0 ; j < Number ;  j++ ) {
			myTable.insert ( x[j] ) ;
	}

	// cout << endl << myTable << endl ;
	cout << endl;
	main_print( myTable, cout, TableSize );
	cout << endl;

	if ( myTable.fetch(a) ) 
		cout << "record 6781 is present" << endl ;
	if ( ! myTable.fetch(b) ) 
		cout << "record 7766 is not present" << endl ;
	if ( ! myTable.fetch(c) ) 
		cout << "record 98 is not present" << endl ;
	if ( ! myTable.insert ( a ) )
		cout << "duplicate record attempted: 6781" << endl ;

	pp = myTable.perform() ;
	cout << "ssl is " << pp.successful << "    usl via passbits " << pp.unsuccessful[0] <<
				"     usl calculated " << pp.unsuccessful[1] << endl ;

	myTable.empty() ;

	// cout << endl << myTable << endl ;
        cout << endl;
        main_print( myTable, cout, TableSize );
        cout << endl;

}
