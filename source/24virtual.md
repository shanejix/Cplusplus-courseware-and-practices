## how virtuals work in c++

```cpp
class XYPos{...};//x,y point
class shape{
public:
    Shape();
    virtual ~Shape();
    virtual void render();
    void move(const XYPos&);
    virtual void resize();
protected:
    XYPos center;
};
```

![1541641788899](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541641788899.png)

> vPtr----指针
>
> 所有virtual类的对象里面的最头上都会加上一个隐藏的指针---vPtr--指向一张表 vtable（里面是所有virtual函数的地址），vtable是这个类的不是这个类的对象的，所有的vPtr的值是一样的

```cpp
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
```

>

```cpp
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


4785264
4785264

--------------------------------
```

## ellipse

```cpp
class Ellipse:public Shape{
public:
    Ellipse(float maj,float mint);
    virtual void render();//will define own
protected:
    float major_axis,minor_axis;
};
```

![1541644435333](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541644435333.png)

> ellipse 有自己的vtable

## circle

```cpp
class Circls:public Ellipse{
public:
	Circle(float radius);
    virtual void render();
    virtual void resize();
    virtual void redius();
protected:
    float area;
};
```

![1541644739688](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541644739688.png)

## what happens if

```cpp
Ellipse elly(20F,40F);
Circle circ(60F);
elly = circ;	// 10 in 5 ?
```

- area of "circ" is sliced off

  - (only the part of "circ" that fits in "elly" gets copied)

- Vtable from "circ" is ignored;the vatable in "elly" is the Ellipse vatable

  ```cpp
  elly.render();	//Ellipse::render()
  ```

## what happens with pointers?

```cpp
Ellipse* elly = new Ellipse(20F,40F);
Circle* circ = new Circle(60F);
elly = circ;
```

- well,the orifinal Ellipse for "elly" is lost...

- "elly" and "circ" point to the same Circle object!

  ```cpp
  elly->render();	//Circle::render()
  ```

## virtuals and reference arguments

```cpp
void func(Ellipse& elly){
    elly.render();
}

Circle circ(60F);
func(circ);
```

- references act like pointers
  - "Circle::render" is called

## virtual destructors

- make destructors **virtual** if they might be inherited

  ```cpp
  Shape *p = new Ellipse(100.0F,200.0F);
  ...
  delete p;
  ```

  > 如果构造函数是virtual，析构函数也需要是virtual，否则出错
  >
  > C++默认是静态绑定（为了效率），其他OOP语言都是动态绑定

- want "Ellipse::~Ellipse()" to be called
  - must declare "Shape::~Shape()" virtual
  - it will call "Shape::~Shape()" automatically
- if "Shape::~Shape()" is not virtual,only "Shape::~Shape()" will be invoked!（调用）

## overriding

- overriding redefined the body of a virtual function

```cpp
class Base{
public:
    virtual void func();
}
class Derived:public Base{
public:
    virtual void func();
    //overrides Base::func()
}
```

## calls up the chain

- you can still call the overridden function:

  ```cpp
  void Derived::func(){
      cout<<"in derived::func!";
      Base::func();//call the base class
  }
  ```

- this is a common way to add new functionality
- no need to copy the old stuff!

## return types relaxation(current)

- suppose D is publicly derived from B
- "D::f()" can return a subclass of the return type defined in "B::f()"

- applies to pointer and reference types
  - e.g. D&,D*

## relaxation example

```cpp
class Expr{
public:
    virtual Expr* newExpr();
    virtual Expr& clone();
    virtual Expr self();
};
class BinaryExpr:public Expr{
public:
    virtual BinaryExpr* newExpr();	//ok
    virtual BinaryExpr& clone();	//	ok
    virtual BinaryExpr self();	//error
};
```

> 只有通过指针或者引用才能构成upcast，所以返回本身是不行的

## overloading and virtuals

- overloading adds multiple signature

  ```cpp
  class Base{
  public:
      virtual void func();
      virtual void func(int);
  };
  ```

- if you *override* an *overloaded* function,you must override all of the variants!
  - can't override just one
  - if you don't override all,some will be hidden

> 只有c++存在

