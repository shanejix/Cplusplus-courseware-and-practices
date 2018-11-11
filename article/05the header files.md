## definition of a class

- in c++,separated .h and .cpp files are used to define one class

- class declaration and prototypes in that class are in the header file(.h)
- all the bodies of those functions are in the source file(.cpp)

>(.h)--declaration---声明
>
>(.cpp)--definition--定义
>
>c++中严格区分声明和定义

## the header files

- if a function is declared in a header file,you **must** include the header file everywhere the function is used and where the function is defined
- if a class is declared in a header file,you **must** include the header file everywhere the class is used and where class member functions are defined



> c++中头文件，很关键的问题

##header = interface(接口)

- the header is a contract between you and the user of your code
- the compile(编辑译器) enforces the contract by requiring you to declare all structures and functions before they are used

## structure of c++ program

![1541468968452](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541468968452.png)

> "#"---pach 编译预处理指令
>
> extern 声明一个变量

## declarations vs. definitions

- a .cpp file is a compile unit(编译单元)
- only declarations are allowed to be in .h
  - extern variables
  - function prototypes
  - class/struct declaration

> c++一次只对一个.cpp文件进行编译，链接的时候可能会出现重复定义的变量而出错
>
> class/struct只有声明没有定义

## #inlcude

- "# include" is to insert the included file into the .cpp file at where the "#include" statement is
  - "#include xx.h" :first search in the current directory（当前目录）,then the directories declared somewhere
  - "#include <xx.h>":search in the specified directories（系统目录）
  - "#include <xx>":same as "#include <xx.h>"

> iostream.h----->istream

## standard header file structure

```cpp
#ifndef HEADER_FLAG
#define HEADER_FLAG
//type declaration here
#endif //HEADER_FLAG
```

> 标准头文件结构，防止声明重复出现

## tips for header

1. one class declaration per header file
2. associated with one source file in the same prefix of file name （源代码用相同前缀）
3. the contents of a header file is surrounded with "#ifndef #define #endif"

