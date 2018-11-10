## setting limits

- to keep the client programmer's hands off members they shouldn't touch
- to allow the library designer to change the internal working of the structure without worrying about how it will affect the client programmer

## C++ access control

- the members of a class can be cataloged,marked as:
  - public
  - private
  - protected

> public公开的所有的都可以访问
>
> private私有的成员函数可以访问;private是对类来说的不是对对象来说的，同一个类的对象是可以互相访问私有变量的，private的这种限制仅仅是在编译时刻，运行时刻仍然有办法访问别的类的私有成员
>
> protected类自己以及子子孙孙可以访问

## public

- **public** means all member declarations that follow are available to everyone

## private

- the **private** keyword means that no one can access that member except inside function members of that type

## friends

- to explicitly grant access to a function that isn't member of the structure
- the class itself controls which code has access to its members
- can declare a global function as a **friend**, as well as a member function of another class,or even an entire class,as a **friend**

## class vs. struct

- class defaults to **private**
- **struct** defaults to **public**

