
/* * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *	Disjoint Subsets union-find 	winter 2011
 *
 *      Walt Burkhard
 *
 * * * * * * * * * * * * * * * * * * * * * * * * */ 

#ifndef UNIVERSE 
#define UNIVERSE 

#include <vector>

using namespace std;

class DisjointSubsets { 

	public :
		DisjointSubsets ( unsigned numberElements = 6 ) ;
		unsigned findDS ( unsigned ) ;
		bool unionDS ( unsigned , unsigned ) ;

	private :

		int numberOfElements;
		vector <int> parent;
		vector <int> rank;

} ;

#include "DisjointSubsets.cpp"

#endif
