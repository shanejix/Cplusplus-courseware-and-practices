## declare an employee class

```cpp
class Employee {
public:
    Employee(const std::string &name,const std::string &ssn);
    
    const std::sting &get_name() const;
    void print(std::ostrwam &out) const;
    void pint(std::ostrwam &out,const std::string &msg) const;
protected:
    std::string m_name;
    std::string m_ssn;
}
```

## constructor of employee

```cpp
Employee::Employee(const sting &name,const string &ssn):m_name(name),m_ssn(ssn){
    //initializer list sets up the values!
}
```

## employee member functions

```cpp
inline const std::sting & Employee::get_name() const{
    return m_name;
};
inline void Employee::print(std::ostrwam &out) const｛
	out<<m_name<<endl;
	out<<m_ssn<<endl;
｝;
inline Employee::void pint(std::ostrwam &out,const std::string &msg) const{
    out<<msg<<endl;
    print(out);
};
```

## now add manager

```cpp
class Manager:public Employee{
public:
    Manager(const std::string&name,const std::string ssn,const std::string&title);
    const std::string title_name() const;
    const std::string& get_title() const;
    void print(std::ostream& out) const;
private:
    std::string m_title;
};
```

## inheritance and constructors

- think of inherited traits as an embedded object
- base class is mentioned by class name

## manager member functions

```cpp
inline void Manager::print(std::ostream& out) const{
    Employee::print(out);//call the base class print
    out << m_title<<endl;
}
inline const std::string& Manager::get_title() const{
    return m_title;
}
inline const std::string Manager::title_name() const{
    return string(m_title + ":"+m_name);// access base m_naeme
}
```

## uses

```cpp
int main(){
    Employee bob("Bob Jones","555-444-8888");
    Manager bill("Bill Smith","555-444-6666","important person");
    
    string name = bill.get_name();//okay Manager inherits Empoyee
    //string title = bob.get_title();//error
    cout<<bill.title_name()<<"\n"<<endl;
    bill.print(cout);
    bob.print(cout);
    bob.print(cout,"Employee:");
    //bill.print(cout,"Employee:")//error hidden
}
```

> 子类中如果有与父类相同的函数，两者没有关系，父类中的函数被隐藏----->名字隐藏
>
> OOP中只有c++这么干

