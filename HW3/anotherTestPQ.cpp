#include <iostream>

using namespace std ;


#include "PriorityQueue.hpp"

int testPQ()
{
  PriorityQueue<int> pq;
  #define maxElements 1000
  int data[ maxElements ];
  int i,j,temp, bi ;
  srandom(0);

  if ( pq.fetchPQ( bi ) == true ) {
    cerr << "Error: Your fetchPQ was empty, but fetchPQ returned true!" << endl ;
    return -1;
  }

  /* first, fill up the data[] array so that data[i] == i */
  for( i = 0 ; i < maxElements ; i++) data[i] = i;

  /* second, shuffle the array */
  for( i = 0 ; i < maxElements-1 ; i++)
  {
    j = i+1+(random() % (maxElements-i-1));  /* pick a place to swap with */
    temp = data[i]; data[i] = data[j]; data[j] = temp; /* do the swap */
  }

  /* third, insert all of them into the PQueue */
  for( i = 0 ; i < maxElements ; i++)
  {
    cerr << "Inserting item #" << i << ", (priority == data == " << data[i] << ")\r" ;

    if ( pq.insertPQ( data[i] , (double)data[i] ) == false )
      cerr << endl << "Error: Cannot insert the " << i << "th element (of value " << data[i] << ")!" << endl ;
    else
      continue;

    cerr << "[Stopping.]" << endl ; return -1;
  }

  cerr << "Done inserting items 0 through "  << maxElements-1 << "                           " << endl ; 


  /* next, check that we can fetch ALL of them (and that they're in order) */
  for( i = maxElements-1 ; i >= 0 ; i-- ) /* go backwards, since we expect higher data to come first */
  {
    cerr << "Fetching item #" << i << " ... (going backwards...)\r" ;

    if ( pq.fetchPQ( bi ) == false )
      cerr << endl << "Error: Could not fetch the " << i << "th element!" << endl ;
    else if ( bi != i )
      cerr << endl << "Error: I expected item #" << i << " to have value of " << i << " they should be sorted,"
	     "but instead I got " << bi << endl ;

    else continue;

    cerr << "[Stopping.]" << endl ; return -1;
  }

  cout << "Done fetching items " << maxElements-1 << " through 0                       " << endl ; 

  return 0;
}



int main(int argc, char** argv)
{
  if ( testPQ() == 0 )
    cout << "No obvious errors in PQueue found!  Good job." << endl ;
  else
    cout << "There was some errors in your PQueue; Try to fix them and run again." << endl ;

  return 0;
}

