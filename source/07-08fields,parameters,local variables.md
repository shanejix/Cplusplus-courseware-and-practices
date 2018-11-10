## local variable

- local variables are defined inside a method,have a scope limited to the method to which they belong

- a local variable of the same name as a field will prevent the filed being accessed form within a   method

  > 和c类似，重名时本地变量会屏蔽成员变量

## fields,parameters,local variables

- all three kinds of variable are able to store a value that is appropriate to their defined type

- fields are defined outside constructors and methods

- fields are used to store data that persists（持续） throughout the life of an object.as such,they maintain the current state of object.they have a lifetime that lasts as long as their objects lasts.
- fields have class scope:their accessibility extends throughout the whole class,and so they can be used within any of the constructor methods of the class in which they are defined

> field :成员变量
>
> parameters：函数的参数
>
> local variable：本地变量

## call functions in a class

```cpp
Point a;
a.print();
```

- there is  a relationship with the function be called and the variable calls it
- the function itself knowns it is doing something with the variable

## this: the hidden parameter

- this is a hidden parameter for all member functions,with the type of the class

  ```cpp
  void Point::pint()
      ->(can be regarded as)
  void Point::print(Point *p)
  ```

> 类是抽象的，是概念，虚的，不是实体，不拥有成员变量。类的实例中拥有成员变量
>
> 成员函数属于类，不属于类的实例。当实例调用成员函数时，调用时类中的同一个函数，类中的函数知道是那个实例调用函数
>
> --->（形同C语言中：要修改结构中的变量将结构的的地址作为函数的参数传入函数中---**指针的方式**----c++类中隐藏的参数=>**this**）--->c++中所有的机制都是通过c语言实现的

```cpp
#include <iostream>
using namespace std;

class A{
	public:
		int i;
		void f();
};

void A::f(){
	cout<<"A的是"<<i<<endl;
	i=20;
	cout<<"A修改后的i是"<<i<<endl;
}

struct B{
	int i=20;
};

void f(struct B*p){
	cout<<p->i<<endl;
}

int main(){
	A a;
	a.i=10;
	cout<<"a的i"<<a.i<<endl;
	a.f();
	
	B b;
	f(&b);	
} 
```

```cpp
#include <stdio.h>
using namespace std;

class A{
	public:
		int i;
		void f();
};

void A::f(){
	i=20;
	printf("A::f()--&i=%p\n",&i);
	printf("this=%p",this);
}



int main(){
	A a;
	a.i=10;
	printf("&a=%p\n",&a);
	printf("&a.i=%p\n",&a.i);
	a.f();	
} 

--------------------------------
&a=000000000062FE10
&a.i=000000000062FE10
A::f()--&i=000000000062FE10
this=000000000062FE10
--------------------------------
```



