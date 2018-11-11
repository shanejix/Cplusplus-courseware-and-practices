#include <iostream>
using namespace std;

class A{
public:
	A():i(10){};
	virtual void f(){
		cout<<"A::f()---->i="<<i<<endl;
	}
	int i;
};

int main(){
	A a;
	A b;
	
	int*p=(int*)&a;
	int*q=(int*)&b;
	
	cout<<*p<<endl<<*q<<endl;
	
	return 0;
}
