
/* = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
 *
 *	createMaze.hpp			Winter 2011
 *
 *
 * = = = = = = = = = = = = = = = = = = = = = = = = = = = = = */


#ifndef CREATEMAZE
#define CREATEMAZE


#include <list>
#include "PriorityQueue.hpp"
#include "Wall.hpp"

list<Wall> &
createMaze ( int r , int c , PriorityQueue<Wall> & pq ) ;

#include "createMaze.cpp"

#endif
