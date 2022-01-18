#include <iostream>
#include <stdio.h>

using namespace std;

class Singleton
{
public:
    static Singleton *GetInterface()
    {
        cout << "This is Get" << endl;
        if (nullptr == Interface)
            Interface = new Singleton();
        return Interface;
    }
    ~Singleton()
    {
        cout << "析构函数" << endl;
        if (Interface != nullptr)
        {
            delete Interface;
            Interface = nullptr;
        }
    }

private:
    Singleton()
    {
        cout << "构造函数" << endl;
    };
    static Singleton *Interface;
};

Singleton *Singleton::Interface = nullptr;

int main(int argc, char *argv[])
{
    Singleton *test1 = Singleton::GetInterface();
    Singleton *test2 = Singleton::GetInterface();
    if (test1 == test2)
    {
        cout << "====================" << endl;
    }
    printf("test1-- > %p\n", test1);
    printf("test2-- > %p\n", test2);

    // delete test1;
    return 0;
}