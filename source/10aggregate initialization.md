## storage allocation

- the compiler allocates all the storage for a scope at the opening brace of scope
- the constructor call does't happen until the sequence point where the object is defined

## aggregate initialization

```cpp
struct Y{float f;float i;Y(int a);};

Y y1[]={Y(1),Y(2),Y(3)};//成员没有初始化导致错误
```

## the default constructor

- a default constructor is one that can be called with no arguments

> 自己写的或者编译器给你的那个没有参数的构造函数--->default constructor

