#include <iostream>
using namespace std;

void aaa(){
	int a, b, c;
	a = 10;
	b = 20;
	
	c = a > b ? a : b;
	
	cout << "c=" << c << endl;
	
	a = 30;
	c = a > b ? a : b;
	
	cout << "c=" << c << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	
}
