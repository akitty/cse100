#ifndef PQUEUE
#define PQUEUE

#include <vector> 
#include <iostream>

using namespace std ;

template <class DATA>
class PriorityQueue ;

template <class DATA>				// Weiss presents a different approach for these nodes.
class NodeBQ {
	private :
		friend class PriorityQueue<DATA> ;
		DATA element ;
		double priority ;
		NodeBQ * left , * right ;
		
	public :
		NodeBQ( DATA & d , double prio ) : element(d) , priority(prio) , left(NULL) , right(NULL) {}
		NodeBQ() { } 
		NodeBQ( NodeBQ & node ) ;
		~NodeBQ ( ) {} ;
} ;
 
	
template <class DATA>
class PriorityQueue {

	private :
		unsigned count;
		vector< NodeBQ<DATA>* > roots;
		void merge(vector<NodeBQ<DATA> *> &  a, vector<NodeBQ<DATA> *> & b,int max);
		NodeBQ<DATA> * join(NodeBQ<DATA> * p , NodeBQ<DATA> * q );
		void printNode(NodeBQ<DATA>*)const ;
	public: 
		PriorityQueue ( ) : count(0) { roots.resize(1);} ;   	// see figure 2 of assignment.
		bool fetchPQ ( DATA & data ) ;
		bool insertPQ ( DATA & data , double priority ) ;
		bool getDataPQ ( unsigned index , DATA & data ) ;
		void printPQ ( ostream & out ) const ; 

} ;

template <class DATA>
ostream & operator << ( ostream & out , const PriorityQueue<DATA> & pq ) 
{
	pq.printPQ(out) ; 
	return out ;
}


//#include "PriorityQueue.cpp"

#endif
