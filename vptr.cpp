// Example program
#include <iostream>
#include <string>

class Base{
    public:
    int a;
    virtual int foo() = 0;
};

class Derived :public Base{
    public:
    int b;
    
    int foo() {
        return 123;
    };
    
};

int main()
{
  Derived d;
  Base* b = &d;
  b -> a = 5;
  
  std::cout << sizeof(int) << std::endl;
  std::cout << sizeof(void*) << std::endl;
  std::cout << sizeof(*b) << std::endl;
  std::cout << "b -> a == " << b -> a << std::endl;
  (b+1) -> a = 23777;
  std::cout << "(xd!) b -> b == " << (b+1) -> a << std::endl;
  std::cout << sizeof(d) << std::endl;
  std::cout << d.a << std::endl;
  std::cout << d.b << std::endl;
  
  std::cout<<"///////////////////"<<std::endl;
  
  // int f[4] = {2,3,5,7};
  
  // std::cout<< f[1] <<std::endl;
  // std::cout<< *(f+1) <<std::endl;
  
  // std::cout << ((b-1)->a) << std::endl;

  void* vptr = (void*)&d;
  vptr=(void *)*vptr;
  //std::cout << ((int (*)()) *vptr )() << std::endl;  
}
