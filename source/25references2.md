## references as class members

- declared without initial value

- must be initialized using constructor initializer list

  ```cpp
  class X{
  public:
      int& m_y;
      X(int& a);
  };
  X::X(int a):m_y(a){}
  ```

## returning references

- functions can return references

  - but they better refer to non-local variables!

    ```cpp
    #include <assert.h>
    const int SIZE = 32;
    double myarray[SIZE];
    double& subscript(const int i){
        return myarray[i];
    }
    ```


## example

```cpp
main{
    for(int i=0;i<SIZE;i++){
        mayarray[i]=i*0.5;
    }
    double value = subscript(12);
    subscript(3) = 34.5;
}
```

## const in functions arguments

- pass by const value --don't do it

- passing by const reference

  ```cpp
  Person(const string& name,int weight);
  ```

  - don't change the string object
  - more efficient to pass by reference(address) than to pass by value(copy)
  - const qualifier protects from change

## const reference parameters

- what if you don't want the argument changed?

- use *const* modifier

  ```cpp
  //y is constant!can't be modified 
  void func(const int & y,int & z){
      z = z*5;//ok
      y+=5;/error
  }
  ```

## temporary values are const

- what you type

  ```cpp
  void func(int &);
  func(i*3);//generates warning or error
  ```

- what the compiler generates

  ```cpp
  void func(int &);
  const int tem@ = i*3;
  func(tem@);//problem--bindling cons ref to non-const argument!
  ```

## const in function returns

- return by const value
  - for user defined types,it means "prevent use as an value"
  - for built-in's it means nothing
- return by const pointer or reference
  - depends on what you want your client to with the return value