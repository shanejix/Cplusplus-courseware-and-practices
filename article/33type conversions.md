##value classes

- appear to be primitive data types
- passed to and returned from functions
- have overloaded operators(often)
- can be converted to and from other types
- example: Complex,Data,String

## user-defined type conversions

- a conversion operator can be used to convert an object of one class into:
  - an object of another class
  - a built-in type
- compilers perform implicit conversions using:
  - single-argument constructor
  - implicit type conversion operators

## single argument constructors

```cpp
class PathName{
    string name;
Public:
    //or could be muli-argument with defaults
    PathName(const string&);
    ~PathName();
};
...
string abc("abc");
PathName xyz(abc);//ok
xyz = abc;//ok abc => PathName
```

```cpp
class One{
public:
    One(){}
};
class Two{
public:
    Two(const One&){}
};
void f(Two){}
int main(){
    One one;
    f(one);//wants Two.has a One
}
```

# preventing implicit conversions

- new keyword:explicit

  ```cpp
  class PathName{
      string name;
  public:
      explicit PathName(const stirng&);
      ~PathName();
  };
  ...
  string abc("abc");
  PathName xyz(abc);//ok!
  xyz = abc;//error
  ```

  ```cpp
  class One{
  public:
      One(){}
  };
  class Two{
  public:
      explicit Two(const One&){}
  };
  void f(Two){}
  
  int main(){
      One one;
  //    f(one);//no auto conversion allowed
      f(Two(one));//ok--user performes conversion
  }
  ```

## conversion operations

- operator conversion
  - function will be called automatically
  - return type is same as function name

```cpp
class Rational{
public:
    ...
    operator double() const;//Rational to double
}
Rational::operator double() const{
    return numerator_/(double)denominator_;
}
Rational r(1,3);
double d = 1.3*r;//r=> double
```

## general form of conversion ops

- X::operator T()
  - operator name is any type descriptor
  - no explicit arguments
  - no return type
  - complier will use it as type conversion from X=>T

## c++ type conversions

- built-in conversions

  - *Primitivec*
    - char=>short=>int=>float=>double    int=>long
  - *implicit (for any type T)*
    - T=>T&    T&=>T    T*=>void*    T[]=>T*     T*=>T[]    T=>const T

- user-defined T=>C

  - *if "C(T)" is a valid constructor call for c* 
  - *if **operator**C()* is defined for T

- BUT

  ```cpp
  class Orange;//class declaration
  
  class Apple{
  Public:
      operator Orange() const;//Convert Apple to Orange
  };
  class Orange{
  public:
      Orange(Apple);//Convert Apple to Orange
  };
  void f(Orange){}
  
  int main(){
      Apple a;
      // f(a);//error:ambigunous conversion
  }
  ```

## do you want to use them?

- in genaral,no!

  - cause lots of problems when functions are called unexpectedly

- use explicit conversion functions.for example,in class Rational instead of the conversion operator ,declare a member function:

  ```cpp
  double toDouble() const;
  ```


​	