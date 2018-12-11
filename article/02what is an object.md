## what is an object?

​	

- object = entity(东西,实体)
- object may be
  - visible
  - or invisible
- object is **variable** in programming languages

objects=attributes+servers

​	

- data:the properties（性质） or status（身份）

- operations（操作）:the functions

  ![1541407129603](https://github.com/shanejix/Cplusplus-best-practices/blob/master/images/02-1.png)

## mapping（映射）

​	

- from the problem place to the solution one

<<<<<<< HEAD
  ![1541407386906](https://github.com/shanejix/Cplusplus-best-practices/blob/master/images/02-2.png)
=======
  ![1541407386906](https://github.com/shanejix/Cplusplus-best-practices/blob/master/images/02-1.png)
>>>>>>> 41037967ba65816ab1dcb043d11d593939f69890

## procedural（程序上的） languages

- c doesn't support relationship btw data and function

```c
typedef struct point3d{
    float x;
    float y;
    float z;
} Point3d;

void Point3d_print(const Point3d* pd);

Point3d a;
a.x=1;
a.y=2;
a.z=3;
Point3d_print(&a);
```

- c++ version

```cpp
class Point3d{
public:
    Point3d(float x,float y,float z);
    print();
private:
    float x;
    float y;
    float z;
}

Point3d a(1.2.3);
a.print();
```

> c的struc中只有数据，c++的class中既有数据还有操作
>
> c的操作是在结构体的外面的，你要让它做什么事情需要传它的指针进去，c++操作是结构体内部当你要做什么操作你让那个结构自己去做那个操作而不是要把那个地址传到一个函数当中去
>
> 最初的版本：在c的基础上做了class的东西

## what is object-oriented

- a way to organize
  - designs(找到问题的思路，办法)
  - implementations（实现，代码）
- objects,not control or data flow,**are the primary focus of the design and implementation**
- **to focus on tings**,not operation
