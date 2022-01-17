#include <iostream>
#include <string.h>

using namespace std;

class MyString
{
public:
    MyString(char *pData = nullptr)
    {
        if (nullptr == pData)
        {
            m_pData = new char[1];
            m_pData[0] = '\0';
        }
        else
        {
            m_pData = new char[strlen(pData) + 1];
            strcpy(m_pData, pData);
        }
    }
    MyString(const MyString &other)
    {
        m_pData = new char[strlen(other.m_pData) + 1];
        strcpy(m_pData, other.m_pData);
    }
    /*
        MyString &operator=(const MyString &str)
        {
            if (&str == this)
                return *this;

            delete[] m_pData;
            m_pData = nullptr;

            this->m_pData = new char[strlen(str.m_pData) + 1];
            strcpy(m_pData, str.m_pData);
            return *this;
        }
        */
    MyString &operator=(const MyString &str);
    ~MyString()
    {
        delete[] m_pData;
        m_pData = nullptr;
    }
    void Print()
    {
        printf("%s\n\n", m_pData);
    }

private:
    char *m_pData;
};

MyString &MyString::operator=(const MyString &str)
{
    if (&str != this)
    {
        MyString tmp(str);
        char *str_tmp = tmp.m_pData;
        tmp.m_pData = this->m_pData;
        this->m_pData = str_tmp;
    }
    return *this;
}

void Test1()
{
    printf("Test1 begins:\n");

    char *text = "Hello world";

    MyString str1(text);
    MyString str2;
    str2 = str1;

    str2.Print();
}

void Test2()
{
    cout << "TEST2 start" << endl;
    char *text = "Hello world";

    MyString str1(text);

    str1 = str1;
    str1.Print();
}

void Test3()
{
    cout << "" << endl;
    cout << "TEST3 start" << endl;
    char *text = "Hello world";

    MyString str1(text);

    MyString str2, str3;
    str3 = str2 = str1;
    str2.Print();
    str3.Print();
}

int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}