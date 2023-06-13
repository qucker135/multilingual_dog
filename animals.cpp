#include <iostream>

class Animal{
    public:
        virtual void voice() = 0;
};

class Dog : public Animal {
    public:
        void voice() {
            std::cout << "Bark!" << std::endl;
        }
};

class Cat : public Animal {
    public:
        void voice() {
            std::cout << "Meow!" << std::endl;
        }
};

int main() {
    Dog d;
    Animal* an = &d;

    d.voice();
    an->voice();

    void (**vptr)() = *((void (***)())an);

    (*vptr)();

    Cat c;

    *((void (***)())an) = *(void (***)())&c;
    
    d.voice();
    an->voice();

    return 0;
}
