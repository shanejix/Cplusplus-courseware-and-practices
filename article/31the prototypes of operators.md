## argument passing

- if it is read-only pass it in as a const reference(except built-ins)
- make member functions const that don't change the class (boolean operators,+,-,etc)
- for global functions,if the left-hand side changes pass as a reference(assignment operators)

## return values

- select the return type depending on the expected meaning of the operator.for example
  - for operator + you need to generate a new object.return as a const object so the result cannot be modified as an value
  - logical operators should return bool(or int for older compilers)

## the prototypes of operators

- +-*/%^&|~

  ```cpp
  const T operatorX(const T& I,const T& r) const;
  ```

- ! && || < <= == >= >

  ```cpp
  bool operatorX(const T& I,const T& r) const;
  ```

- []

  ```cpp
  T& T::operator[](int index);
  ```

  ##operators ++ and --

- how to distinguish postfix from prefix?

- postfix forms take an int argument -- compiler will pass in () 0 as that int

  ```cpp
  class Ineger{
  public:
      ...
      const Integer& operator++();//prefix++
      const Integer  operator++(int);//postfix++
      const Integer& operator--();//prefix--
      const Integer  operator--(int);//prefix--
      ...
  };
  
  const Integer& Integer::operator++(){
      *this += 1;//increment
      retrun *this;//fetch
  }
  //int argument not used so leave unnamed so won't get compiler warnings
  const Inreger Integer::operator++(int){
      Integer old(*this);//fetch
      ++(*this);//increment
      return old;//return
  }
  ```

  ## using the overloaded ++ and --

  ```cpp
  //decrement operators similar to increment
  Integer x(5);
  ++x;//calls x.operator++();
  x++;//calls x.operator++(0);
  --x;//calls x.operator--();
  x--;//calls x.operator--(0);
  ```

  - user-defined prefix is more efficient than postfix

## relational operators

- implement != in terms of ==

- implement >,>=,<= in terms of <

  ```cpp
  class Integer{
      public:
      ...
          bool operator=={const Integer& rhs} const;
       	bool operator!={const Integer& rhs} const;
       	bool operator<{const Integer& rhs} const;
      	bool operator>{const Integer& rhs} const;
       	bool operator<={const Integer& rhs} const;
       	bool operator>={const Integer& rhs} const;
  }
  bool Ineger::operator==(const Ineger& rhs) const{
      return i == rhs.i;
  }
  //implement ihs != rhs in terms of !(lhs == rhs)
  bool Integer::operator!=(const Integer& rhs) const{
      return !(*this == rhs);
  }
  bool Integer::operator<(const Integer& rhs) const{
      return !i < rhs.i;
  }
  bool Integer::operator>(const Integer& rhs) const{
      return rhs < *this;
  }
  bool Integer::operator<=(const Integer& rhs) const{
      return !(rhs< *this);
  }
  bool Integer::operator>=(const Integer& rhs) const{
      return !(*this < rhs);
  }
  ```

  > 其实只定义了等于和小于两个原函数--好处是方便重构

## operator[]

- must be a member function

- single argument

- implies that the object it is being called for acts like an array,so it should return a reference

  ```cpp
  Vector v(100);//create a vector of size 100
  v[10]=45;
  ```

  - note: if returned a pointer you would need to do

    ```cpp
    *v[10] = 45;
    ```


