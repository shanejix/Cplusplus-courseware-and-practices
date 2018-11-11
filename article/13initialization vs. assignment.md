## initializer list

```cpp
cladd Point{
private:
    const float x,y;
    Point(float xa =0.0,float ya=0.0):y(ya),x(xa){}
};
```

- can initialize any type of data
  - pseudo-constructor calls for built-ins
  - no need to perform assignment within body of constructor
- order of initialization is order of ***declaration***
  - not the order in the list!
  - destroyed in the reverse order

## initialization vs. assignment

```cpp
Student::Student(sting s):name(s){}
```

- initialization
- before constructor

```cpp
Student::Student(string s){name=s;}
```

- assignment
- inside constructor
- string must have a default constructor

> initializer list 的初始化会早于构造函数的执行
>
> assignment赋值之前已经初始化
>
> 如果类的成员是对象，未被初始化则会自动调用默认构造函数，如果没有默认构造函数则会导致错误
>
> 建议：类的成员变量都在initialization list中做初始化不要在constructor中赋值