## point::init()

> c++是一个注重效率的语言，不会自己做初始化，区别于java，自己搬进来自己打扫;
>
> vs debug中未初始化的内存是十六进制的“0xcd，两个构成中文“烫”;
>
> 依赖于的程序员的自觉性，素养;

## guaranteed initialization with the constructor

- if a class has a constructor,the compiler(编译器) automatically calls that constructor at the point an object is created,before client programmers can get their hands on the object
- the name of the constructor is the same as the name of class

## how a constructor does?

```cpp
class X {
    int i;
public:
    X();
};
```

> X没有返回类型,和类名一模一样；
>
> 对象被创造的时候X()被自动调用;
>
> X()也是类的成员函数，this指的是那个对象的地址；
>
> X a;----->a.X()

```cpp
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


--------------------------------
A::A()--&i=000000000062FE10
A::A()--this=000000000062FE10
&a=000000000062FE10
&a.i=000000000062FE10
A::f()--&i=000000000062FE10
this=000000000062FE10
--------------------------------
```

## constructors with arguments

- the constructor can have arguments to allow you to specify how an object is created,give it initialization values,and so on

  ```cpp
  Tree(int i){...}
  Tree t(12);
  ```

## the destructor 

- in C++,cleanup is as important as initialization and is there guaranteed with destructor

- the destructor is named after the name of the class with a leading tilde （**~**）.the destructor never has any arguments

  ```cpp
  class Y{
  public:
      ~Y();
  };
  ```



>没有参数，没有返回类型；

## when is a destructor called?

- the destructor is automatically by the compiler when the object goes out of scope
- the only evidence for a destructor call is the closing brace of the scope that surrounds the object