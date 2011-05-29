#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <vector>
using  namespace std;

int main()
{
	cout << "hello world"<<endl;
	list<int> list1;
	list1.push_front(1);
	list1.push_back(2);	
	cout<< list1.front() <<endl;
	cout<< "test" <<endl;
	vector<list<int> > vector1(5);
	cout<<"vector 1 size:"<< vector1.size() <<endl;
	cout<<"vector 1 max size:"<< vector1.max_size()<<endl;
	cout << vector1.empty();
	cout<<"vector1[0] size:"<< vector1[0].size()<< endl;
	vector1[0].push_back(100);	
	cout<<"vector1[0] size:"<< vector1[0].size()<< endl;
	cout<<"vector1[0]1:" << vector1[0].front()<<endl;	

	return 0;
}
