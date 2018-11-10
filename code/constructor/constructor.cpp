#include <stdio.h>
using namespace std;

class A{
	public:
		int i;
		void f();
		A();
};

void A::f(){
	i=20;
	printf("A::f()--&i=%p\n",&i);
	printf("this=%p",this);
}

A::A(){
	i=0;
	printf("A::A()--&i=%p\n",&i);
	printf("A::A()--this=%p\n",this);
}


int main(){
	A a;
	a.i=10;
	printf("&a=%p\n",&a);
	printf("&a.i=%p\n",&a.i);
	a.f();	
} 
