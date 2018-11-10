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
	a.f();
	cout<<sizeof(a)<<endl;
	
	int*p=(int*)&a;
	cout<<*p<<endl;
	p++;
	cout<<*p<<endl;
	
	return 0;
}
