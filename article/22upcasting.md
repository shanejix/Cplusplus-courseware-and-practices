## conversions

- public inheritance should imply（意味着） substitution（代替）
  - if B is a A,you can use a B anywhere an A can be used
    - if B is a A, then everything that is true for A is also true of B
  - be careful if the substitution if not valid

|      | D is deriver(派生) from B |      |
| :--: | :-----------------------: | ---- |
|  D   |            =>             | B    |
|  D*  |            =>             | B*   |
|  D&  |            =>             | B&   |

> 子类的对象可以当作父类来看待

## upcasting

- upcasting is the act of converting from a Derived reference or pointer to a base class reference or pointer

![1541594882785](https://github.com/shanejix/Cplusplus-best-practices/blob/master/images/22.png)

## upcasting examples

```cpp
Mannager pete("Pere"."88888888","Bakery");
Employee* ep = &pete;	//upcast
Employee& er = pete;	//upcast
```

- lose type information about the object:

```cpp
ep->print(cout);	//print base class version
```

> 子类中的函数如果与父类中的函数重名则父类的中的函数隐藏



```cpp
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


--------------------------------
10-------10
4       8
0x6ffe00        10
20
0x6ffdf0        10
b.j=50

--------------------------------
```

