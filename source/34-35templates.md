## why templates?

- suppose you need a list of X and a list of Y
  - the lists would use similar code
  - they differ by the type shored in the list

- choices
  - require common base class
    - may not be desirable
  - clone code
    - preserves type-safety
    - hard to manage
  - untyped lists
    - type unsafe

## templates

- reuse source code
  - generic programming
  - use types as parameters in class or function definitions
- template functions
  - example : sort function
- template classes
  - example:contains such as stack,list, queue...
    - stack operations are independent of the type of items in the stack
  - template member functions

## function templates

- perform similar operations on different types of data

- swap function for two int arguments:

  ```cpp
  void swap(int& x,int& y){
      int temp = x;
      x = y;
      y = temp;
  }
  ```

- what if we want to swap flats ,strings,Currency,Person?

## example:swap function template

```cpp
template <class T>
void swap(T& x,T& y){
 	T temp = x;
    x = y;
    y = temp;
}
```

- the **template** keyword introduces the template
- the **class T** specifies a parameterized type name
  - class means any built-in type or user-defined type
- inside the template,use T as a type name

## function template Syntax

- parameter types represent:
  - types of arguments to the function
  - return type of the function
  - declare variables within the function

## template instantiation

- generating a declaration from a template class/function and template arguments:
  - types are substituted into template
  - new body of function or class definition is created
    - syntax errors,type checking
  - specialization -- a version of a template for a particular argument(s)

## example:using swap

```cpp
int i = 3;
int j = 4;
swap(i,j);	//use explicit int swap

float k = 4.5;	float m = 3.7;
swap(k,m);	//instanstiate float swap
std::string s("hello");
std::string t("world");
swap(s,t);	//std::string swap
```

- a template function is an instantiation of a function template

## interactions

- only  *exact* match on types is used

- no conversion operations are applied

  ```cpp
  swap(int,int);	//ok
  swap(double,double);	//ok
  swap(int,double)	//error
  ```

- even *implicit* conversions are ignored
- template functions and regular functions coexist

## overloading rules

- check first for unique function match

- then check for unique function template match

- then do overloading on functions

  ```cpp
  void f(float i,float k)();
  template <class T>
  void f(T t,T u){};
  f(1.0,2.0);
  f(1,2);
  f(1,2.0)
  ```

## function instantiation

- the compiler deduces the template type from the actual arguments passed into the function

- can be explicit:

  - for example,if the parameter is not in the function signature(older compilers won't allow this)

    ```cpp
    template <class T>
        void foo(void){...}
    	foo<int>();//type T is int
    	foo<float>();//tyoe T is float
    ```

## class templates

- classes parameterized by types

  - abstract operations form the types being operated upon
  - define potentially infinite set of classes
  - another step towards reuse

- typical use:container classes

  ```cpp
  stack <int>
  //is a stack that is parameterized over int
  list  <Person&>
  queer <Job>
  ```

## example:Vector

```cpp
template <class T>
class Vector{
public:
    Vector(int);
    ~Vector();
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    T& operator[] (int);
private:
    T* m_elements;
    int m_size;
};
```

## usage

```cpp
Vector<int> v1(100);
Vertor<Complex> v2(256);

v1[20] = 10;
v2[20] = v1[20];	//ok if int -> Comlex defined
```

## Vector members

```cpp
template <class T>
Vector<T>::Vector(int size):m_size(size){
    m_elementds = new T[m_size];
}
template <class T>
T& Vertor<T>::operator[](int indx){
    if(indx < m_size && indx > 0){
        return m_elments[indx];
    }else{
        ...
    }
}
```

## a simple sort function

```cpp
//bubble sort -- don't use it

template <class T>
void sort(vector<T>& arr){
	const size_t last = arr.size()-1;
    for(int i = 0;i < last; i++){
        for(int j = last; i < j; j--){
            if(arr[j] < arr[j-1]){
                //which swap?
                swap(arr[j],arr[j-1]);
            }
        }
    }
}
```

## sorting the vector

```cpp
vector<int> vi(4);
vi[0] = 4;vi[2] = 7; vi[1]=3; vi[3] = 1;
sort(vi);	//sort(vector<int>&)

vector<string> vs;
vs.push_back("Fred");
vs.push_back("Willma");
vs.push_back("Barney");
vs.push_back("Dino");
vs.push_back("Prince");
sort(vs);	//sort (vector<string>&)
//note:sort uses operator < for comparation
```

## templates

- templates can use multiple types

  ```cpp
  template<class Key,class Value>
  class HashTable{
  	const Value& lookup(const Key&) const;
  	void install(const Key& ,const Value&);
  	...
  };
  ```

- templates nest ---they're just new types!

  ```cpp
  Vector< Vector<double*> >	//note sapce > >
  ```

- type arguments can be complicated

  ```cpp
  Vector<int (*)(Vector<double>&,int)>//内层是函数
  ```

## expression parameters

- template arguments can be *constant expressions*

- non-Type parameters

  - can have a default argument

  ```cpp
  template <class T, int bounds = 100>
  class FixedVector{
  public:
      FixedVector();
      //...
      T& oprator[](int);
  private:
  	T elements[bounds];//fixed size array
  }
  ```

##usage:Non-type parameters

- usage

  ```cpp
  FixedVector<int,50> v1;
  FixedVector<int,10*50> v2;
  FixedVector<int> v3;//uses default
  ```

- summary
  - embedding sizes not necessarily
  - can make code faster
  - makes use more complicated
    - size argument appears everywhere
  - can lead to (even more) code bloat

## templates and inheritance

- templates can inherit from non-template classes

  ```cpp
  template <class A>
  class Deried:public Base{...}
  ```

- templates can inherit form template classes

  ```cpp
  template<class A>
  class Derived : pubic List<A>{...}
  ```

- non-templates classes can inherit from templates

  ```cpp
  class SupervisorGroup:public List<Emoloyee*>
  ```

## writing templates

- get a non-template version working first
- establish a good set of test cases
- measure performance and tune