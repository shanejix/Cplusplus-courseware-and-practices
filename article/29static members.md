## can we apply static to  members?

- static means
  - hidden
  - persistent
- hidden:*A static member is a member*
  - obeys usual access rules
- persistent: *independent of instances*

- static members are class-wide
  - variables or
  - functions

## static members

- static member variables
  - global to all class member function
  - *initialized* once,at *file* scope
  - provide a place for this variable and init it in .cpp
  - no "static" in .cpp

> 静态的成员变量一定要在.cpp中定义
>
> initialize list只能对非静态成员初始化
>
> 静态的函数只能访问静态的成员变量，原因是静态函数是没有*this*的--因为需要类的成员函数在没有对象的时候就可以被调用