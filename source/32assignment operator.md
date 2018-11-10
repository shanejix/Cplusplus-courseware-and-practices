## copying vs. initialization

```cpp
MyType b;
MyType a = b;//拷贝构造
a = b;//赋值

------------------------
class Fi{
public:
    Fi(){}
};
class Fee{
public:
    Fee(int){}
    Fee(const Fi&){}
};

int main(){
    Fee fee = 1;//Fee(int)
    
    Fi fi;
    Fee fum = fi;//Fee(Fi)
    
    fum	=	fi;//????
}


```

## automatic operator= creation

- the compiler will automatically create a **type::oprator=(type)** if you don't make one

- memberwise assignment

  ```cpp
  class Cargo{
  public:
      Cargo& operator=(const Cargo&){
          cout<<"inside Cargo::operator=()"<<endl;
          return *this;
      }    
  };
  class Truck{
      Cargo b;
  };
  int main(){
      Truck a, b;
      a = b;//prints:"inside Cargo::operator=()"
  }
  ```

## assignment operator

- must be a member function

- will be generated for you if you don't provide one

  - same behavior as automatic copy ctor -- memberwise assignment

- check for assignment to self

- be sure to assign to all data members

- return a reference to "*this"

  ```cpp
  A = B = c;//executed as A = (B = c);
  ```

## skeleton assignment operator

```cpp
T& T::operator=(const T& rhs){
    //check for self assignment
    if(this != &rhs){//如果是自己赋值给自己，可能在自己被赋值之前被释放，比如new到的东西
        //perform assignment
    }
    return *this;
}//this checks address vs. check value (*this != rhs)
```

## assignment operator

- for classes with dynamically allocated memory declare an assignment operator(and a copy constructor)
- to prevent assignment,explicitly declare operator= as private