## reusing the implementation

- composition(组合):construct new object with existing objects
- it is the relationship of "has-a"

## composition

- objects can be used to build up other objects
- ways of inclusion
  - fully
  - by reference
- inclusion by reference allows sharing
- for example,an employee has a
  - name
  - address
  - health plan
  - salary history
    - collection of raise objects
  - supervisor
    - another employee object!

## composition in action

![1541504524980](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541504524980.png)

## example

```cpp
class Person{...};
class Currency{...};
class SavingAccount{
public:
    SavingAccount(const char* name,const char* address,int cents);
    ~ SavingAccount();
    void print();
private:
    Person m_svaer;
    Currency m_balance;
};

SavingAccount::SavingAccount(const char* name,const char* address,int cents):m_saver(name,address),m_balance(0,cents){}
void SavingAccount::print(){
    m_saver.print();
    m_balance.print();
}
```

## embedded objects

- all embedded objects（嵌入对象） are initialized

  - the default constructor is called if 
    - you don't supply the arguments,and there is a default constructor(or one can be built)

- constructors can have initialization list

  - any number of objects separated by commas（逗号）
  - is optional
  - provide arguments to sub-constructors

- syntax:

  ```cpp
  name(args)  [':' init-lsit]  '{'
  ```

## question

- if we wrote the constructor as (assuming we have the set accessors for the subobjects):

  ```cpp
  SavingsAccount::SavingAcount (const char *,const char * assress, int cents){
      m_saver.set_name(name);
      m_saver.set_address(address);
      m_balance.set_cents(cents);
  }
  ```

- default constructors wold be called

## public vs. private

- it is common to make embedded objects private:

  - they are part of the underlying implementation
  - the new class only has part of the public interface of the old class

- can embed as a public  object if you want to have the entire public interface of the subobject available in the new object:

  ```cpp
  class SavingAcdount{
      public:
      Person m_saver;...
  }//assume Person class has set_name
  SavingAccount account;
  account.m_saver.set_name("Fred");
  ```
