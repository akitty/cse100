#include <ctime>
#include <string>
#include <list>
#include <vector>

using namespace std ;

vector<bool> marks ;

extern				// created in solver.cpp
vector<list<unsigned> > demo ;

bool done = false ;

void depthFirst ( unsigned , unsigned ) ;

list<unsigned> &
mazeSolve ( unsigned entry , unsigned goal , unsigned r , unsigned c ) 
{
		
	// your work here....
	
}
	
void
depthFirst ( unsigned site , unsigned goal )
{
	unsigned room ;
	marks [ site ] = true ; 	// site is to be first visited now!
	list<unsigned> :: iterator itr ;
	for( itr = demo[site].begin() ; itr != demo[site].end() ; itr++ ) {
		room = *itr ;
		if ( room == goal ) {
			solution.push_front ( room ) ;
			done = true ;
			return ; 
		} 
		if ( marks[room] == false ) { 
			depthFirst ( room , goal ) ;
			if ( done == true ) {
				solution.push_front ( room ) ;
				return ;
			}
		}
	}
}
