## dynamic memory allocation

- **new**
  - new int;
  - new Stash;
  - new int[10]
- **delete**
  - delete p;
  - delete[] p;

> 相当于c中**malloce**和**free**
>
> 任何运算都有结果，new操作返回的是地址

## new and delete

- new is the way to allocate memory as a program runs.pointers become the only access to that memory

- delete enables you to return memory to the memory pool when you are finished with it

## dynamic arrays

int * psome = new int [10];

- the new operator returns the address of the first element of the block

delete [] psome;

- the presence of the brackets tells the program that it should free the whole array,not just the element

## tips for new an delete

- don't use **delete** to free memory that **that ** didn't allocate
- don't use **delete** to free the same block of memory twice in succession(连续)

- use **delete** (no brackets) if you used **new** to allocate an array

- use **delete[]** if you used **new []** to allocate an array

- it's safe to apply **delete** to the null pointer (noting happwns)
