#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class Listener
{
public:
    Listener()
    {}
};

class A
{
public:
    void setListener(shared_ptr<Listener> listener)
    {
         listener_ = listener; 
    }
private:
    shared_ptr<Listener> listener_;
};

int main()
{
    shared_ptr<Listener> listener = make_shared<Listener>(); 

    std::cout<<listener.use_count()<<std::endl;

    A *a = new A();

    a->setListener(listener);
    
    std::cout<<listener.use_count()<<std::endl;

    // listener.reset();
    std::cout<<listener.use_count()<<std::endl;
    delete a;
    std::cout<<listener.use_count()<<std::endl;
}
