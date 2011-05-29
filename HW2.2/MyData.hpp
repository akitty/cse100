
#include <iostream>
#include <string>
#include <cmath>

using namespace std ;

class MyData {
 
	public :
		MyData ( ) { zip = 0 ; } 
	
		MyData ( int z , const char * n )
		{ zip = z ;  name = n ; } 

		MyData ( string & n ) { name = n ; }

		void 
		print ( ostream & out ) const 
		{ 
			out << "name: " << name << string ( 25-name.length() , ' ' ) << 
						 "  zip: " << zip << string ( 6-(int)floor(log10(zip)) , ' ' ) ; 
		}
		
		operator unsigned ( ) const ;
	
		string & readName ( ) { return name ; }

		int & readZip ( ) { return zip ; }

	private :
	  int zip ;
	  string name ;

} ;


ostream & operator << ( ostream & out , const MyData & rhs ) 
{
	rhs.print(out) ;
	return out ;
}

MyData :: operator unsigned ( ) const
{
	enum {crcBits = 32, crcPoly = 0x04c11db7} ;
	enum { crcHiBit=1<<(crcBits-1), crcMask = 0xffffffff } ; 
	enum { tblBits=8, tblSize=1<<tblBits } ;
	static unsigned long table[tblSize] = {0,0} ;
	enum {byteSize=8,shiftAmt=crcBits-byteSize} ;
	unsigned long crcPoly_d = crcPoly , h = 0 ;
	int j , diff , d ;
	unsigned char c ;

	if ( table[0] == table[1] ) 	// build table on first call
		for ( d=0; d<tblBits; ++d ) {
			diff = 1<<d ;
			for ( j = 0 ; j<diff ; ++j )
				table[j+diff] =table[j]^crcPoly_d ;
			crcPoly_d = (crcPoly_d<<1)&crcMask ;
			if ( crcPoly_d & crcHiBit ) crcPoly_d ^= crcPoly ;
		}
	for ( j = 0 ; c = this->name[j++] ; ) 
		h = table[(h>>shiftAmt)^c]^((h<<byteSize)&crcMask) ;
	return h ;
}
