// Example program
#include <iostream>
#include <string>
#include <cstring>

class Base{
    public:
    int a;
    int y;
    virtual int foo() = 0;
};

class Derived :public Base{
    public:
    int b;
    
    int foo() {
        return 0x6a;
    };
    
};

typedef int(*int_f_t)();

int main()
{
  Derived d;
  Base* b = &d;
  b -> a = 5;
  b -> y = 7;

  std::cout << std::hex;

  std::cout << ((int*)b)[0] << std::endl;
  std::cout << ((int*)b)[1] << std::endl;
  std::cout << ((int*)b)[2] << std::endl;
  std::cout << ((int*)b)[3] << std::endl;

  uint64_t* vptr = (uint64_t*)b;
  vptr = (uint64_t*)*vptr;
  std::cout << std::hex << "Vtable address: " << vptr << std::endl;

  uint64_t* addr_foo = (uint64_t*)(*vptr);

  std::cout << std::hex << "Address of Base::foo(): " << addr_foo << std::endl;

  int_f_t addr_foo_ptr;

  // std::cout << std::hex << (int(*)(void))addr_foo << std::endl;

  memcpy(&addr_foo_ptr, &addr_foo, sizeof(int_f_t));

  std::cout << std::hex << "Address of Base::foo() as fn ptr: " << addr_foo_ptr << std::endl;

  std::cout << std::hex << addr_foo_ptr() << std::endl;
  
  // std::cout << *(dynamic_cast<int_f_t>(addr_foo))() << std::endl;
  // (*addr_foo)();
  // int foo ()=0;
  // int (*foo_ptr)() = &foo;
  // int v[5] = {2,3,7,5,11};
  // int* a = v;
  // std::cout << "a[4]: " << a[4] << std::endl;

  
  std::cout << "///////////////////"<<std::endl;
  
  std::cout << "sizeof(int) == " << sizeof(int) << std::endl;
  std::cout << "sizeof(void*) == " << sizeof(void*) << std::endl;
  std::cout << "sizeof(Base) == " << sizeof(*b) << std::endl;
  std::cout << "sizeof(*Base) == " << sizeof(b) << std::endl;
  std::cout << "sizeof(int_f_t) == " << sizeof(int_f_t) << std::endl;
  std::cout << "b -> a == " << b -> a << std::endl;
  // (b+1) -> a = 23777;
  // std::cout << "(xd!) b -> b == " << (b+1) -> a << std::endl;
  std::cout << "sizeof(d) == " << sizeof(d) << std::endl;
  std::cout << "d.a == " << d.a << std::endl;
  std::cout << "d.b == " << d.b << std::endl;
  
  std::cout<<"///////////////////"<<std::endl;
  
  // int f[4] = {2,3,5,7};
  
  // std::cout<< f[1] <<std::endl;
  // std::cout<< *(f+1) <<std::endl;
  
  // std::cout << ((b-1)->a) << std::endl;

  // void* vptr = (void*)&d;
  // vptr=(void *)*vptr;
  // std::cout << ((int (*)()) *vptr )() << std::endl;  
}
