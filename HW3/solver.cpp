#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include "mazeSolver.hpp"

using namespace std ;


int r , c , goal ; 		// r rows and c columns		goal is the exit room  

extern
list<unsigned> solution ; // temporary solution goes here -- before it is written to fout file.

vector<list<unsigned> > demo ;   	  // 	demolished walls representation
	

int
main ( unsigned argc , char ** argv )
{
	string name ; 
	char buffer[100] ;
	int goalc , rr , cc , entry , i ; 

	int r , c , goal ; 		// r rows and c columns	goal is the exit room
	fstream fout ;
	FILE * fptr ;

	if ( argc != 2 ) {
		cerr << argv[0] << " <name of maze>" << endl ; 
		exit ( 1 ) ;
	} else {
		fptr = fopen ( argv[1] , "r" ) ;
		if ( fptr == NULL ) {
			cerr << "trouble opening " << argv[1] << endl ; 
			exit ( 1 ) ;
		}
	}
	
	name = argv[1] ;
	name = name + ".solved" ;
	fout.open ( name.data() , fstream::out ) ;
	if ( ! fout.is_open() ) {
		cerr << "trouble opening " << name << endl ;
		exit ( 1 ) ;
	}
	
	fscanf ( fptr , "%[^\n]%*c" , buffer ) ; 
	sscanf ( buffer , "%*s %d rows x %d columns" , &r , &c ) ;
	fscanf ( fptr , "%[^\n]%*c" , buffer ) ; 
	sscanf ( buffer , "start\t%d" , &entry ) ;
	fscanf ( fptr , "%[^\n]%*c" , buffer ) ; 
	sscanf ( buffer , "end\t%d\t%d" , &goalc, &goal ) ;

  	demo.resize( r*c ) ; 

	for ( ; !feof(fptr) ; ) { 										// read the data 
		fscanf ( fptr , "%d %d%*[^\n]%*c" , &rr , &cc ) ;
		demo[rr].push_front ( cc ) ;
		demo[cc].push_front ( rr ) ; 
	}

	fclose ( fptr ) ; 
	
	// create path through the maze using depth first search.

	solution = mazeSolve ( entry , goal , r , c ) ;		// puts rooms into the solution, entry to goal.
	list<unsigned> :: iterator itr ;

	fout << "start " << entry ;					// writes solution to fout stream.
	for ( itr = solution.begin() ; itr != solution.end() ; itr++ ) 
		fout << " " << *itr ;
	fout << " end" << endl ;
	cerr << name << " created" << endl ;
}
