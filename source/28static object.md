## static in c++

two basic meanings

- static storage
  - allocated one at fixed address
- visibility of a name
  - internal linkage
- don't use static expect inside functions and classed

## uses of "static" in c++

| static free functions   | ~~internal linkage~~(deprecated)                             |
| ----------------------- | ------------------------------------------------------------ |
| static global variables | ~~internal linkage~~(deprecated)                             |
| static local variable   | persistent storage                                           |
| static member variable  | shared by all instances                                      |
| static member function  | shared by all instances,can only access static member variables |

## global static hidden in file

![1541673625014](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541673625014.png)

## static inside functions

- value is remembered for entire program
- initialization occurs only once

- example

  - count the numbers times the function has been called

    ```cpp
    void f(){
        static int num_calls = 0;
        ...
        num_calls++;
    }
    ```


  > static 其实其实就是全局变量

## static applied to objects

- suppose you have a class

  ```cpp
  class X{
      X(int ,int);
      ~X();
      ...
  };
  ```

- and a function with a static X object

  ```cpp
  void f(){
      static X my_X(10,20);
      ...
  }
  ```

  > 它在哪里和什么时候初始化是不一样的，内存在link的时候已经被分配好了，内存里的变量需要去初始化的，C++可以利用的一点是vPtr，如果如果vPtr被初始化过那么它是有效的东西--vtable的地址，否则是乱七八糟的东西，不是所有的类都有vPtr，目前的格局是实现不了的（通过类的某个已有的成员是实现不了的，想法不错，将来可以自己实现OOP语言）。在java中没有被初始化的东西是不能得到的，只有通过new才行

## static applied to objects...

- construction occurs when definition is encountered
  - constructor called at-most once
  - the constructor arguments must be satisfied
- destruction takes place on exit from *program* 
  - compiler assures LIFO order of destructors

##conditional construction

- example:conditional construction

  ```cpp
  void f(int x){
      if(x>10){
          static X my_X(x,x*21);
          ...
      }
  }
  ```


- my_X
  - is constructed once,if f() is ever called with x>10
  - retains its value
  - destroyed only if constructed

## global objects

- consider

  ```cpp
  #include "X.h"
  X gloable_x(12,34);
  X gloable_X2(8,16);
  ```

- constructors are called before main() is entered
  - order controlled by appearance in fine
  - in this case,global_x before global_x2
- main() is no longer the *first* function called
  - main() exits
  - exit() is called

## static initialization dependency

- order of construction within a file is known
- order between files is *unspecified*!
- problem when non-local static objects in different files have dependences
- a non-local static object is:
  - defined at global or namespace scope
  - declared static in a class
  - defined static at file scope