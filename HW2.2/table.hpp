#ifndef TABLE
#define TABLE

#include <iostream>
#include <cstdlib>
#include <vector>

typedef struct {
double successful , unsuccessful[2] ;
} Perform ;

using namespace std ;

template <class DATA>
class Table {

private :
	int currentSize;
	int tableSize;
	int sProbes;
	int pbCount;
	vector<bool> passbit;
	vector<bool> full;
	vector<DATA> bucket;
public :
	explicit Table ( unsigned size = 5 ) ;
	void empty ( ) ;
	bool insert ( DATA & data ) ;
	bool insertD ( DATA & data ) ;
	bool fetch ( DATA & data ) const ;
	bool getData ( unsigned i , DATA & data , bool & passbit ) const ;
	Perform perform ( ) const ;
} ;

#include "table.cpp"

#endif
