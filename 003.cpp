#include <iostream>

using namespace std;

void function1(int *array, int length, int &res)
{
    //根据《啊哈算法.pdf》第一章桶排序想到的,占用空间太大
    if ((nullptr == array) || (length <= 0))
        res = 0;

    int tmp[length - 1];
    int i = 0;

    for (i = 0; i < length; i++)
        tmp[i] = 0;

    for (i = 0; i < length; i++)
    {
        tmp[array[i]]++;
    }

    for (i = 0; i < length; i++)
    {
        if (tmp[i] > 1)
        {
            res = i;
            break;
        }
    }
}

int main(int argc, char **argv)
{
    int array[8] = {2, 2, 3, 4, 5, 6, 7, 1};
    int res = 10;
    function1(array, sizeof(array) / sizeof(array[0]), res);
    cout << "res= " << res << endl;
}