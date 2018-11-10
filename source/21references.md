## declaring references

- references are a new data type in C++

  ```cpp
  char c;            //a character
  char* p = &c;      //a pointer to a character
  char& r = c;       //a reference to a character
  ```

- local or global variables
  - type& refname = name;
  - for ordinary varibles,the initial value is required
- in parameter lists and member variables
  - type& refname
  - binding defined by caller or constructor

## references

- declares a new name for an existing object

  ```cpp
  int X = 47;
  int& Y = X;//Y is a reference to X
  
  //X and Y now refer to the same variable
  
  cout<<Y;//print 47
  Y = 18;
  cout<<x;//print 18
  ```

## rules of references

- references must be initialized when defined

- initialization establishes a binding

  - in declaration

    ```cpp
    int x = 3;
    int& y = x;
    const int&z = x;//类似于指针
    ```

  - as a function argument

    ```cpp
    void f(int& x);
    f(y);	//initialized when function is called
    ```

- bindings don't change at run time, unlike pointers

- assignment changes the object referred-to

  ```cpp
  int& y = x;
  y = 12;//changes value of x
  ```

- the target of a reference must have a location!

  ```cpp
  void func(int &);
  func(i*3);		//warning or error
  ```

## pointers vs. references

- references
  - can't be null
  - are dependent on an existing variable,they are an alias（别名） for an variable
  - can't change to a new "address" location
- pointers
  - can be set to null
  - pointer is independent of existing objects
  - can be change to point to a different address

```cpp
int* f(int* x){
    (*x)++;
    return x;	//safe,x is outside this scope
}

int& g(int& x){
    x++;	//same effect as in f()
    return x;	//safe,outside this scope
}
```

> C++有三种方式放对象，有三种方式访问对象；Java只有一个地方可以放对象，所有对象都放在堆里面，只有一种方式访问对象，就是通过“指针”，因为它只能通过指针访问对象，因此他可以把那个“*”去掉，然后规定说这不叫指针这叫引用，这其实和C++的引用是不一样的，更像是C++的指针，因为引用是不能做引用之间的赋值的，实际上是指针，区别在于外形上没有那个星号，不能做运算（C的指针可以做计算）
>
> references实际上是一种指针，一种const的指针

## restrictions

- no references to references

- no pointers to references

  ```cpp
  int& * p;	//illegal
  ```

  - reference to pointer is ok

    ```cpp
    void f(int* &p);
    ```

- no arrays of references