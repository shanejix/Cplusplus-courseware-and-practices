## const

- declares a *variable* to have a constant value

## constants

- constants are variables
  - observe scoping rules
  - declared with "const" type modifier

## compile time constants

```cpp
const int bufsize = 1024;
```

- value must be initialized
- unless you make an explicit extern declaration

```cpp
enxtern const int bufsize;
```

- complier won't let you change it
- compile time constants are entries in compiler symbol table,not really variables

## run-time constants

- const value can be exploited

```cpp
const int class_size = 12;
int finalGrade[class_size];//ok

int x;
cin>>x;
const int size = x;
double classAverage[size];//error
```

> 编译器不知道x的值

## pointer and const

```cpp
char *const q = "abc";//q is const
*q = "c"//ok
q++;//error

const char *p = "abcd";//(*p) is a cosnt char
*p = "b";//error
```

## quiz: what do these mean?

```cpp
cosnt person* p = &p1;
person const* = &p1;
person *const p= &p1;
```

> *的前面还是后面

## pointers and constants

|               | int i;  | cosnt int ci=3; |
| ------------- | ------- | --------------- |
| int *ip;      | ip=&i;  | ip=&i;//error   |
| cosnt int *p; | cip=&i; | cip=&i;         |

- remember

  ```cpp
  *ip=54//always legal since ip points to int
      
  *cip=54;//never legal since cip points to const int
  ```


## string literals

```cpp
char* s = "hello,world";
```

- s is a pointer initialized to point to string constant

- this is actually a "const char* s" but compiler accepts it without the const
- don't try and change the character values(it is undefined behavior)

if you want to change the string ,put it in an array:

```cpp
char s[] = "hello,world!";
```

> C++中三种内存模型：
>
> 本地变量，在**栈**中；
>
> 全局变量在**全局数据区**里，全局变量中的这种常量（“hello，world”）在**代码段**里-，代码段不可写的；
>
> new出来的东西在**堆**中；

## conversions

- can always treat a non-const value as const

  ```cpp
  void f(coonst int* x){...}
  int a = 15;
  f(&a);//ok
  const int b = a;
  f(&b);//ok
  b=a+1;//error
  ```

- you con not treat a constant object as non-constant without an explicit cast(const_cast)

## passing by const value

```cpp
void f(cosnt int i){
    i++;//illegal -- compile-time error
}
```

## returning by const value?

```cpp
int f(){return 1;}
cosnt int f2(){return 1;}
int main(){
    const int j = f();//work fine
    int k = f2();//but this works fine too
}
```

## passing and returning addresses

- passing a whole object may cost you a lot.it is better to pass by a pointer.but it's possible for the programmer to take it and modify the original value

- in fact ,whenever you're passing an address into a function,you should make it a **const** if at all possible

## constant objects

- what if an object is const?

  ```cpp
  const Currency the_raise(42,38);
  ```

- what members can access the internals?

- how can the object be protected from change?

## const member functions

- cannot modify their 

  ```cpp
  int Data::set_day(int d){
      //...error check d here...
      day = d;//ok,non-const so can modify
  }
  
  int Data::get_day() const{
      day++; //error modifies data member
      set_day(12); //error calls non-const member
      return day;//ok
  }
  ```

## const member function usage

- repeat the const keyword in the definition as well as the declaration

  ```cpp
  int get_day() const;//this ------ is const
  int get_day() const {return day;}
  ```

- functon members that do not modify data should be declared const

- const member function are safe for const objects

## constant in class

```cpp
class A{
    const int i;
};
```

- has to be initialized in initializer list of the cosnstructor

## compile-time constants *in classes*

```cpp
class HasArray{
    const iht size;
    int array[size];//error,不能作为数组的大小，1.使用static后者枚举
    ...
}
```

- make the const value static:

  ```cpp
  static const int size = 100;
  ```

  static indicates only one per class (not one per object)

- or use "anonymous enum" hack

  ```cpp
  class HasArray{
      enum{size = 100};
      int array[size];//ok
      ...
  }
  ```


