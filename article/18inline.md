## overhead for a function call

- the processing time required by a device prior to the execution of a command
  - push a parameters
  - push return address
  - prepare return values
  - pop all pushed

> 调取一个函数，利用堆“栈实现，额外开销如上

## inline functions

- an inline function is expanded in place,like a preprocessor macro,so the overhead of the function call is eliminated

- repeat **inline** keyword at declaration and definition

  > 会出现错误
  >
  > “**.h**”--声明--告诉编译器里面有什么，给调用这个函数的地方看的，不能生成成调用的代码，应该把函数的body插进来
  >
  > “**.cpp**”--定义--函数的body实体,产生函数的
  >
  > 解决方案：每一个类都有一个对应的“**.h**”和“**.cpp**”，“**.h**”放原型，“**.cpp**”放定义；如果在一个函数的前面有一个“inline”则不再是定义而是声明，因此**inline放在.h中**--->将函数的实体放入“**.h**”中

- an inline function definition may not generate any code in .obj file

## inline function in header file

- so you can put inline functions' bodies in header file.then #include it where the function is needed
- never be afraid of multi-definition of inline functions,since they no body at all
- definitions of inline functions are just declarations

## tradeoff of inline functions

- body of the called function is to be inserted into the caller
- this may expand the code size
- but deduces the overhead of calling time
- so it gains speed at the expenses of space
- in most time case,it is worth
- it is most much better than macro in C.it checks the types of parameters

## inline may not in-line

- the compile does not have to honor your request to make a function inline.it might decide the function is too large or notice that it calls itself(recursion is not allowed or indeed possible for inline functions),or the feature might not be implemented for your particular compiler

## inline inside classes

- any function you define inside a class declaration is automatically an inline

```cpp
class Point{
    int i,j,k;
public:
    Point(){i=j=k=0;}
    Point(int ii,int jj, int kk){i=ii,j=jj,k=kk;}
    void print(string&msg = ""){
        if(msg.size!=0) cout<<msg<<endl;
        cout<<i<<j<<k<<endl;
    }
｝;
int main(){
	Point p,q(1,2,3);     
    p.print();
    q.print();
}    
```

> 类的成员函数在声明的时候定义自动是内联函数

## access functions

- they are small functions that allow you to read or change part of the state of an object---that is ,an internal variable or variables

## reducing clutter

- member functions defined within classes use the Latin in situ(in place) and maintains that all definitions should be placed outside the class to keep the interface clean

> 另外一种写法
>
> 把函数的body放在class（.h中）的后面（本应该放在.cpp中）；保持class比较清爽

```cpp
class Point{
    int i,j,k;
public:
    Point();
    Point(int ii,int jj, int kk);
    void print(string&msg = "");
｝;
    
inline Point(){i=j=k=0;}
inline Point(int ii,int jj, int kk){i=ii,j=jj,k=kk;}
inline void print(string&msg = ""){
        if(msg.size!=0) cout<<msg<<endl;
        cout<<i<<j<<k<<endl;
}
```

## inline or not?

- inline:
  - small function,2 or 3 lines
  - Frequently called functions,e.g. inside loops
- not inline?
  - very large functions,more than 20 lines
  - recursive functions