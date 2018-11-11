## run-time error

- the basic philosophy of c++ is that "badly formed code will not be run" 
- there's always something happen in run-time
- it is very important to deal with all possible situation in the future running

## read a file

- open the file
- determine its size
- allocate that much memory
- read the file into memory
- close the file

```cpp
errorCode Type readeFile{
    initialize errorCode = 0;
    open the file;
    if(theFileOpen){
        determine its size;
        if(gotTheFileLength){
            allocate that much memory;
            if(gotEnoughMemoty){
                read the file into memory;
                if(readFailed){
                    errorCode = -1;
                }
            }else{
                errorCode = -2;
            }
        }else{
            errorCode = -3;
        }
        close the file;
        if(theFIEDidntClose&&errorCode ==0){
            errorCode = -4;
        }else{
            errorCode = errorCode and -4;
        }
    }else{
        errorCode = -5;
    }
    return errorCode;
}
```

## working w/exception

```cpp
try{
    open the file;
    determine its size;
    allocate that much memory;
    read the file into memory;
    close the file;
}catch(fileOpenFailed){
    doSomting;
}catch(sizeDeterminationFailed){
    doSomting;
}catch(memoryAllocationFailed){
    doSomting;
}catch(readFailed){
    doSomting;
}catch(fileCloseFailed){
    doSomting;
}
```

## exception

- i  take exception to that
- at the point where the problem occurs,you might not known what to do with it,but you do know that you can't just continue on merrily;you must stop ,and somebody,somewhere,must figure out what to do

## why exception?

- the significant benefit of exceptions is that they clean up error handing code
- it separates the code that describes what you want to do from the code that is executed

## example:Vector

```cpp
template <class T> class Vector{
private:
    T* m_elements;
    int m_size;
public:
    Vector (int size = 0):m_size(size)...
    ~Void(){delete [] m_elements;}
    void length(int);
    int length(){return m_size;}
    T& operator[](int);
};
```

## problem

```cpp
template <class T>
T& Vector<T>::operator[](int indx){}
```

- **what should the [] operator do if the index is not valid?**

  **1.)return random memory object**

  ```cpp
  return m_elements[indx];
  ```

  **2.)return a special error value**

  ```cpp
  if (indx < 0 || indx >= m_size){
      T* error_marker = new T("some magic value");
      return *error_marker;
  }
  return m_elements[indx];
  ```

  **but this throws the baby out with the bath!*

  ```cpp
  x = v[2] + v[4];//not safe code
  ```

  **3.)just die!**

  ```cpp
  if (indx < 0 || indx >= m_size){
      exit(22);
  }
  return m_elements[indx];
  ```

  **4.)die *gracefully (with autopsy!)***

  ```cpp
  assert(indx >= 0 && indx < m_size);
  retrun m_elements[indx];
  ```

## when to use exceptions

- many times ,you don't know what should be done

- if you do *anything* you'll be wrong

- solution:turf the problem

  **make your caller(or its caller...) responsible**

## how to raise an exception

```cpp

template<class T>
    T& Vector<T>::operator[](int indx){
        if(indx < 0 || indx >= m_size){
            //throw is a keyword
            //exception is raised at this point
            trow --someting--
        }
        return m_elements[indx];
    }
```

## what do you throw?

**//what do you have? Data!**

**//define a class to represent the error**

```cpp
class VectorIndexError{
public:
    VectorIndexError(int v):m_badValue{}
    ~VectorIndexError(){}
    void diagnostic(){
        cerr << "index" << m_badValue <<"out of range";
    }
private:
    int m_badValue;
};
```

## how to raise an exception

```cpp
template<class T>
    T& Vector<T>::operator[](int indx){
        if(indx < 0 || indx >= m_size){
            //VectorIndexError
            //throw e;
            trow VectorIndeError e(indx)
        }
        return m_elements[indx];
    }
```



##what about your caller?

- **case 1** Doesn't care

  - code never even suspects a problem

    ```cpp
    int func(){
        Vector<int> v(12);
        v[3] = 5;
        int i = v[42];//out of range
        //control never gets here!
        return i*5;
    }
    ```

- **case2** cares deeply

  ```cpp
  void outer(){
      try{
          func();func();
      }catch(VectorIndexError& e){
          e.diagnostic();
          //this excpetion does not propagete
      }
      cout << "control is here after exception"
  }
  ```

- **case3** mildly interested

  ```cpp
  void outer2(){
      String err("exception caught");
      try{
          func();
      }catch(VextorIndexError){
          cout << err;
          throw;//propagate the exception
      }
  }
  ```

- **case4** does't care about the particulars

  ```cpp
  void outer3(){
      try {
          outer2();
      }catch(...){
          //...catches **all** exceptions!
          cout << "the exception stops here"
      }
  }
  ```

## what happened?

![1541848264942](https://github.com/shanejix/Cplusplus-best-practices/blob/master/images/363738.png)

## how to raise an exception

```cpp
template<class T>
    T& Vector<T>::operator[](int indx){
        if(indx < 0 || indx >= m_size){
            //VectorIndexError e(indx);
            //throw e;
            trow VectorIndeError(indx)
        }
        return m_elements[indx];
    }
```

## review

- throw statement **raise** the exception
  - control propagates back to first handler for that exception
  - propagation follows the **call** chain
  - objects on **stack** are properly destroyed
- "throw exp"
  - throws values for matching
- "throw"
  - **reraises** the exception being handled
  - valid only within a handler

## catch exceptions by reference:

```cpp
struct B{
    virtual void print(){...}
}
struct D : public B{...};

try {
    throw D("D error");
}
catch(B& b){
    b.print() // print D's error
}
```

## try blocks

- try blocks

  ```cpp
  try {...}
  catch...
  catch...
  ```

- establishes any number of handers

- not needed if you don't use *any* handlers

- shows where you expert to handle exceptions

- const cycles

## exception handlers

- select exception by type

- can re-raise exceptions

- two forms

  ```cpp
  catch (SomeType v){}//handler code
  catch(...){}//handler code
  ```

- take a single argument(like a formal parameter)

## selecting a handler

- can have any number of handlers

- handlers are checked in order of appearance

  1. check for exact match
  2. apply base class conversions
     - reference and pointer type,only
  3. ellipses(...) match all

  **inheritance can be used to structure exceptions**

## example:using inheritance

- **hierarchy of exception types**

  ```cpp
  class MathErr{
      ...
      virtual void diagnstic();
  };
  class OverflowErr:pubic MathErr{...}
  class UnderflowErr:pubic MathErr{...}
  class ZeroDivideErr:pubic MathErr{...}
  ```


## using handlers

```cpp
try{
    //code to expercise math options throw UnderFlowErr
}catch(ZeroDivideErr& e){
    //handle zero divide cade
}catch(MathErr& e){
    //handle other math errors
}catch(...){
    //any other exceptions
}
```

## exception specifications

- declare which exceptions function *might* raise

- part of function prototypes

  ```cpp
  void abc(int a):throw(MathErr){...}
  ```

- not checked at compile time
- at run time

  - if an exceptions not in the list propagates out,the "unexpected" exception is raised

##examples

```cpp
Printer::print(Document&):trow(PrinterOfffLine,BadDocument){
    ...
        PintManager::print(Document&):throw (BadDocument){
        //raises or doesn't handle BadDocuement
    	}
    void  googguy():throw(){
        //handle all exceptions
    }
    voi average(){}//no spec, no checking
}
```

## exceptions and new

- new does NOT returned 0 on failure

- new raises a bad_alloc() exception

  ```cpp
  void func(){
      try{
          while(1){
              char*p = new char[10000];
          }
      }catch(bad_alloc& e)
   }	
  }
  ```

## failure in constructors:

- no return value is possible
- use an "uninitialized flag" 
- defer work to an init() function

better throw an exception

if you constructor can't complete,throw an exception

- dtors for objects whose ctor didn't complete *won't be called*
- clean up allocated resources before throwing

## programming with exceptions

prefer catching exceptions by reference

- throwing/catching by value involves slicing

  ```cpp
  struct X{}
  struct Y:pubic X{}
  try{
      throw Y():
  }catch(X x){
      //was it or Y?
  }
  ```

- throwing/catching by pointer introduces coupling between normal and handler code:

  ```cpp
  try{
      throw new Y();
  }catch(Y* p){
      //whoop ,forgot to delete
  }
  ```


