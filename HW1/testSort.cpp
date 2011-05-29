/*
Patrick Guan
pguan
1/16/2011

*/
#include <list>
#include <iostream>
#include <vector>
/*
takes in streams of 2 files
first file is the records to be topologically sorted
second file is the sorted list
sorts using a predeccesor count list, successors list and a mark list
*/
bool
testSort ( istream & idata , istream & iidata ) 
{
	int n;
	idata >> n;
	vector<bool> mark(n,false);//stores whether item has been outputed
	vector<unsigned int> count(n,0);//stores number of predecessors
	vector<list<unsigned int> > sucessors(n);
				//stores item's successors
		
	int x,y;
	while(idata >> x >> y) 
	{
		count[y]++; //builds # of predecessors  list
		sucessors[x].push_back(y);//builds successors list	
	}
	int b;
	while(iidata >>b) //looks at first item in sorted list
	{
		list<unsigned int>:: iterator it1;
			//iterator for the successors list
		if(count[b] != 0)//if item is not incorrecty order
		{
			list<unsigned int> predeccessors;
			  //stores b's predeccessors
			for(int i =0;i<n;i++){	//search for predecessors
				it1 = sucessors[i].begin();
				for(;it1 != sucessors[i].end();it1++)
				{
					if(*it1 == b){
					//find item in predeccesor list
					   if(mark[i] == false)	
			//only adds item if it has not been outputted
					     predeccessors.push_front(i);
					}
				}
			}	
			cout << "item " << b << " has " << 
				count[b] << " predeccessors:" ;
			//list predeccessors
			predeccessors.sort();//sorts it smallest to largest
			it1=predeccessors.begin();		
			for(int j=0;j<count[b];j++, it1++)
			{	
				cout<< " " << *it1;//output predeccessor
				if(j<(count[b]-1)) cout << ",";
					//out put commas
			}
			cout << "." << endl;//outputs final period
			return false;
		}
		it1 = sucessors[b].begin();
		for(;it1 != sucessors[b].end();it1++)
			count[*it1]--; //reduce the count of b's successors
		mark[b] = true;//mark b as outputted
		
	}
	return true;
}
