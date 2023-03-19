#include <iostream>

int mainAttr(int arr[], int len)
{
    int limit = len / 2;
    int map[len + 1] = {};
    for (int i = 0; i < len; i++)
    {
        map[arr[i]]++;
    }
    for (int i = 1; i <= len; i++)
    {
        if(map[i] > limit) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int len;
    std::cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << mainAttr(arr, len) << std::endl;
    return 0;
}