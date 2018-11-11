##object oriented programming

- object send and receive messages(object do things)

  ![1541417752354](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541417752354.png)

## objects send messages

- messages are
  - composed（组合） by the sender
  - interpreted(解释，说明) by the receiver
  - implemented（执行） by methods
- messages
  - may cause receiver to change state
  - may return results

## object vs. class

- objects(cat)
  - represent(表示) things ,events,or concepts
  - respond to messages at run-time
- classes(cat class)
  - define properties（性质） of instances
  - act like types in c++
  - fish is fish，bird is bird（物以类聚，人以群分）

## OOP characteristics

1. everting is an object
2. a program is a bunch of objects telling each other **what** to do by sending messages
3. each object has its own memory(内存) made up of other objects
4. every object has a type（先有类型后有东西，计算机科学是人为的科学，区别于大自然）
5. all objects of a particular type can receive the same messages（正过来，反过来理解：能接受相同消息可以被认为是同一类东西）

## an object has an interface(分界面=>接口)

- the interface is the way it receives messages
- it is defined in the class the object belong to

## functions of the interface

- communication（通信，交流）
- protection（保护）

## the hidden implementation

- inner part of an object,data members to present its state,and the actions it takes when messages is rcvd hidden
- class creators vs. client programmers
  - keep client programmers' **hands off** portions they should not touch
  - allow the class creators to change the internal(内部的) working of the class without worrying about how it will affect the client programming

## encapsulation（封装）---capsule（胶囊）

- bundle（捆） data and methods dealing with these data together in an object
- hide the details of the data and the action
- restrict only access to the publicized