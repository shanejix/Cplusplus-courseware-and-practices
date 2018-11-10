# a drawing program

circle rectangle ellipse

- data 
  - center
- operatons
  - render
  - move
  - resize

## inheritance in C++

- can define one class in term of another
- can capture the notion that
  - an ellipse is a shape
  - a circle is a special kind of ellipse
  - a rectangle is a different shape
  - circles,ellipses,and rectangles share common
    - attributes
    - services
  - circles,ellipses,and rectangles are not identical（同一的）

## conceptual（概念） model

![1541602795673](C:\Users\jixia\AppData\Roaming\Typora\typora-user-images\1541602795673.png)

## shape

- define the general properties of shape

  ```cpp
  class XYPos{...};//x,y point
  class shape{
  public:
      Shape();
      virtual ~Shape();
      virtual void render();
      void move(const XYPos&);
      virtual void resize();
  protected:
      XYPos center;
  }
  ```

## add new shapes

```cpp
class Ellipse:public Shape{
public:
    Ellipse(float maj,float mint);
    virtual void render();//will define own
protected:
    float major_axis,minor_axis;
};

class Circls:public Ellipse{
public:
	Circle(float radius):Ellispse(radius,radius){}
    virtual void render();
};
```

## example

```cpp
void render(Shape*p){
    p->render();	//calls correct render function for given shape
}	

void func(){
    Ellipse ell(10,20);
    ell.render();
    
    Circle circ(40);
    circ.render();
    
    render(&ell);
    reder(&circ);
}
```

## polymorphism

- upcast: take an object of the derived class as an object of base one
  - Ellipse can be treaded as a Shape

- dynamic binging(动态绑定)
  - binding:which function to be called
    - static binding:call the function as the code
    - dynamic binding:call the function of the object