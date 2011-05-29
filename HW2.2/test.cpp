#include <iostream>

using namespace std;

void test(int & a)
{
	a=5;
}

int main()
{
	int b = 0;
	test(b);
	cout << b << endl;

}
