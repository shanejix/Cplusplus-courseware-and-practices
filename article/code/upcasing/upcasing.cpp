#include <iostream>
using namespace std;

class A{
public:
	int i;
	A():i(10){};
};

class B:public A{
private:
	int j;
public:
	B():j(30){};
	void f(){
		cout<<"b.j="<<j<<endl;
	}
};

int main(){
	A a;
	B b;
	
	cout<<a.i<<"-------"<<b.i<<endl;
	cout<<sizeof(a)<<"	"<<sizeof(b)<<endl;
	
	int *p=(int*)&a;
	cout<<p<<"	"<<*p<<endl;
	*p=20;
	cout<<a.i<<endl;
	
	p=(int*)&b;
	cout<<p<<"	"<<*p<<endl;
	p++;
	*p=50;
	b.f();
	
	return 0;
	
}
