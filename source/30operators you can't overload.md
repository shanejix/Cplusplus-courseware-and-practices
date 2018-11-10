## overloaded operators

- allows user-defined types to act like built in types
- another way to make a function call

- unary and binary operators can be overloaded:

  ```cpp
  + - * / % ^ & | ~
  = < > += -= *= /= %=
  ^= &=  |= << >> <<= >>= ==
  != <= >= ! && || ++ --
      , ->* -> () []
  ```

  operator new    operator delete

  operator new []    operator delete[]

## operators you can't overload

```cpp
	. .* :: ?:
	sizeof typeid
    static_cast dynamic_cast const_cast
    reinterpret_cast
```

## restrictions

- only existing operators can be overloaded(you can't create a ** operator for exponentiation)
- operators must be overloaded on a class or enumeration type
- overloaded operators must:
  - preserve number of operands
  - preserve precedence（优先级）

## c++ overloaded operator

- just a function with an operator name!

  - use the "operator" keyword as a prefix to name

    ```cpp
    operator *(...)
    ```

- can be a member function

  - implicit first argument

  ```cpp
  const String String::operator +(const String& that);//this + that
  ```

- can be a global (free) function

  - both arguments explicit

  ```cpp
  const String operator +(const String& r,const String& l);
  ```

## how to overload

- an member function
  - implicit first argument
  - no type conversion performed on receiver
  - must have access to class definition
- as a global function
  - explicit first argument
  - type conversions performed on both arguments
  - can be made a friend

## operators as member functions

```cpp
class Integer{
public:
    Integer(int n=0):i(n){}
    const Integer operator+(const Integer& n) const{
        return Integer(i+n.i);
    }
    ...
private:
    int i;    
};
```

## member functions

```cpp
Integer x(1),y(5),z;
x+y;---------> x.operator+(y)//x is receiver
```

- implicit first argument

- developer must have access to class definition

- members have full access to all data in class

- no type conversion performed on receiver

  ```cpp
  z = x + y;//ok
  z = x + 3;//ok
  z = x + y;//error
  ```

- for binary operaters(+,-,*,etc) member functions require one argument.

- for unary operators (unary -,!,etc) member functions require no arguments:

  ```cpp
  const Integer operator-() const{
      return Integer(-i);
  }
  ...
  z=-x;//z.operator=(x.oprator-());
  ```

## operator as a global function

```cpp
const Integer operator+(const Integer& rhs,const Integer& lhs);
Integer x,y;
x+y;----------->oprator+(x,y);
```

- explicit first argument
- developer does not need special access to classes
- may need to be a friend
- type conversions performed on both arguments

##global operators(friend)

```cpp
class Integer{
    friend const Integer operator+(const Integer&rhs,const Integer& lhs);
    ...
}
const Integer operator+(const Integer&rhs,const Integer& lhs){
    return Integer(lhs.i,rhs.i);
}
```

- binary operators require two arguments

- unary operators require one argument

- conversion

  ```cpp
  z=x+y;//ok
  z=x+3;//ok
  z=3+y;//ok
  z=3+7;//ok
  ```

  - if you don't have access to private data members, then the global function must use the pubic interface

## tips:members vs. free functions

- unary operators should be members
- = () -> ->* must be members
- assignment operators should be members
- all other binary operators as non-members