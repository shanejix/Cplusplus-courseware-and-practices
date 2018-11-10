## copying

- create a new object from an existing one 

  - for example,when calling a function

    ```cpp
    //currency as pass-by-value argument
    void function(Currency p){
        cout<<"X = "<<p.dollars;
    }
    ...
    Currency bucks(100,0);
    func(bucks);//bucks is copied into p
    ```

## the copy constructor

- copying is implemented by the **copy constructor**

- has the unique signature

  ```cpp
  T::T(const T&);
  ```

  - call-by-reference is used for the explicit argument

- c++ builds a copy constructor for you if you don't provide one!

  - copies each member variable
    - good for numbers,objects,arrays
  - copies each pointer
    - data may become shared!

## what if class contains pointers?

```cpp
class Person{
public:
    Person(const char *s);
    ~Person();
    void print();
    //... accessor functions
//private:
    char* name;//char* instead of string
    //...more info e.g. age ,address,phone
};  
```

```cpp
int main(){
    Person p1("john");
    Person p2(p1);
    printf("p1.name=%p\n",p1.name);
    printf("p2.name=%p\n",p2.name);
    return 0;
}
//p1.name==p2.name,地址一样，被析构了两次，出错
```

## character strings

- in c++,a character string is
  - an array of characters
  - with a special terminator--"\0" or ASCII null
- the string "c++" is represented,in memory,by an array of *four* (4,count'em) characters

## standard c library string functions

- declared in <cstring>

  ```cpp
  size_t strlen(const char *s);
  ```

  - s is a null-terminated string
  - returns the length of s
  - length does not include the terminator!

  ```cpp
  char *strcpy (char *dest,const char *src);
  ```

  - copies src to dest stopping after the terminating null-character is copied
  - dest should have enough memory space allocated to contain src string

## Person(char*) implementation

```cpp
#inlcude <cstring>
ussing namespace std;

Person::Person(const char *s){
    name = new char[::strenlen(s)+1];
    ::strcpy(name,s);
}

Person::~Person(){
    delete [] name;//array delete
}
```

## Person copy constructor

- to Person declaration add copy constructor prototype

  ```cpp
  Person(const Person& w);//copy ctor
  ```

- to Person .cpp add copy ctor definition

  ```cpp
  Person::Person char(const Person& w){
      name = char[::strlen(w.name)+1];
      ::strcpy(name,w.name);
  }
  ```

- no value return
- accesses "w.name" across client boundary
- the copy ctor initializes uninitialized memory

## when are copy constructor called?

- during call by value

  ```cpp
  void roster(Person);//declare function
  Person child("Ruby");//create object
  roster(child);//call function
  ```

- during initialization

  ```cpp
  Person baby_a("Fred");
  //these use the copy ctor
  Person baby_b = baby_a;//not an assignment
  Person baby_c(baby_a);//not an assignment
  ```

- during function return

  ```cpp
  Person captain(){
      Person player("George");
      return player;
  }
  ...
  Person who("")
  ...
  ```

## copies and overhead

- compilers can "optimize out" copies when safe
- programmers need to
  - program for "dumb" compilers
  - be ready to look for optimizations

## example

```cpp
Person copy_func(char *who){
    Person local(who);
    local.print();
    return local;//copy ctor called
}

Person nocopy_func(char *who){
    return Peron(who);
    //no copy needed
}
```

## construction vs. assignment

- every object is constructed once
- every object should be destroyed once
  - failure to invoke delete()
  - invoking delete() more than once
- once an object is constructed,it can be the target of many assignment operations

## Person:string name

- what if the name was a string (and not a char*)

  ```cpp
  #include <string>
  class Person{
  public:
      Person(const string&);
      ~Person();
      void print();
      //...other accessor fxns
  private:
      string name;//embedded object(composition)
      //...other data members
  };
  ```

- in the default ctor ,the compiler recursively calls the copy ctors for all member objects(and base classes)
- default is memberwise initialization

## copy ctor guidelines

- in general,be explicit
  - create your own copy ctor--don't rely on the default
- if you don't need on declare a private copy ctor
  - prevents creation of a a default copy constructor
  - generates a compiler error if try to pass-by -value
  - don't need a definition

> 一旦写一个类就写下：
>
> default constructor
>
> virtual constructor
>
> copy constructor