#include <iostream>
#include <cmath>

bool findValue(int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int getMinNotAppearNumber(int arr[], int len)
{
    int res = INT32_MAX;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }
        int nextValue = arr[i] + 1;
        if (nextValue < res && !findValue(arr, len, nextValue))
        {
            res = nextValue;
        }
    }
    return res;
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
    std::cout << getMinNotAppearNumber(arr, len) << std::endl;
    return 0;
}