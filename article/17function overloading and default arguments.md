## function overloading

- same function with different arguments lists

  ```cpp
  void print(char *str,int width);//#1
  void print(double d,int width);//#2
  void print(long l,int width);//#3
  void print(int i,int width);//#4
  void print(char *str);//#5
  
  print("pancekes",15);
  print("syrup");
  print(1999.0,10);
  print(1999,12);
  print(1999L,15);
  ```

  > overload and auto-cast

## default arguments

- a default argument is a value given the declaration that the compiler automatically inserts if you don't provide a value in the function call

```cpp
Stash(int szie,int initQuantity=0);
```

- to define a function with an argument list,defaults ,must be added from right to left

```cpp
int harpo(int n,int m = 4,int j = 5);
int chico(int n,int m =6,int j);//illeagle
int groucho(int k = 1,int m=2，int n = 2);

beeps = harpo(2);
beeps = harpo(1,8);
beeps = harpo(8,7,6);
```

> default arguments 写在“.h”声明中，“.cpp”中不能重复
>
> default arguments 的机制是编译时刻的事
>
> 建议：不要使用default arguments