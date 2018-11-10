## ticket machine

- ticket machines prints a ticket when a customer inserts the correct money for their fare
- our ticket machines work by customers inserting money into them ,and then requesting a ticket to be printed.a machine keeps a running total of the amount of money it has collected throughout its opration

## procedure-oriented

- step to the machine
- insert money into the machine
- the machine pints a ticket
- take the ticket and leave

## something is there

![1541425281604](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541425281604.png)

- TicketMachine

  - price
  - balance
  - tatal
  - showPrompt
  - getMoney
  - printTicket
  - showBalance
  - printError

  ```cpp
  class TicketMachine{
  public:
      void showPrompt();
      void getMoney();
      void printTicket();
      void showBalance();
      void printError();
  private:
      const int price;
      int balance;
      int total;
  };
  ```


## :: resolver域的解析符

- <class name>::<function name>
- ::<function name>

```
void S::f(){
    ::f();//woulde be recursive otherwise!
    ::a++;//select the aglobal a
    a--;//the a at class scope
}
```



