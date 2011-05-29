
#include <iostream>
#include <string>
#include "table.hpp"

using namespace std ;

class Data {
	public : 
	explicit Data ( ) { data = 0 ; }
	Data ( unsigned d , const char * n ) { data = d ; name = n ; }
	operator unsigned ( ) { return data ; } 
	void print ( ostream & out ) const { out << data << "    " << name << " " ; }
	unsigned data ;
	string name ;
} ;

ostream & operator << ( ostream & out , const Data & rhs ) 
{
	rhs.print(out) ;
	return out ;
}

void  main_print ( Table<Data> & t, ostream & out , unsigned & tabSize )
{
        unsigned i , val , step ;
	Data bucket ;
	bool pb;
	bool flag;
        int loc;

        for ( i = 0 ; i < tabSize ; i ++ ) {
		out.width(2) ;  out.flags( ios::right ) ;
		out << i ;  
		flag = t.getData( i, bucket, pb );
		if ( flag ){
			out << ": " << ((pb)?"t":"f") << "  " ;
                        out << bucket << "  | " ;
			val = unsigned(bucket);
			loc = val % tabSize;
                        step = val % (tabSize-2) + 1 ;
                        while ( loc != i ) {
                                out << loc << ", " ;
                                loc -= step ;
                                if ( loc < 0 ) loc += tabSize ;
                        }
                        out << i ;
                } else out << ": f" ;
                out << endl ;
        }
}



int
main ( )
{
	int i ;
	unsigned size = 5 ;
	Data d [] = { Data ( 20 , "cow" ) , Data(12,"pig") , Data(16,"dog") , Data (18,"ape" ) , Data(22,"yak") } ;
	Perform ppp ;
	
	Table<Data> test(size) ;

	cout << endl << "Double hashing:         notes page 40" << endl << endl ;

	for ( i = 0 ; i < size ; i++ )
		test.insertD ( d[i] ) ;

	// cout << test << endl ;
	
	main_print( test, cout , size );

	ppp = test.perform() ;
	cout << "ssl " << ppp.successful << "     usl via passbits " << ppp.unsuccessful[0] << 
									"     usl calculated " << ppp.unsuccessful[1] << endl ;

	test.empty( ) ;
	
	cout << endl << "Brent hashing:" << endl << endl ;
	for ( i = 0 ; i < size ; i++ ) 
		test.insert(d[i]) ; 
	
	//	cout << test << endl ;
	
	main_print( test, cout , size );

	ppp = test.perform( ) ;
	cout << "ssl " << ppp.successful << "     usl via passbits " << ppp.unsuccessful[0] << 
									"     usl calculated " << ppp.unsuccessful[1] << endl ;
}
