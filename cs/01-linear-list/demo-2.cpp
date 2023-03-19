#include <iostream>

int get_mid(int arr1[], int arr2[], int len1, int len2)
{
    int ptr1 = 0, ptr2 = 0, cnt = 0;
    while (ptr1 < len1 || ptr2 < len2)
    {
        bool setArr1 = false;
        int value1, value2;
        if (ptr1 < len1 && ptr2 < len2)
        {
            value1 = arr1[ptr1], value2 = arr2[ptr2];
            if (value1 <= value2)
            {
                ptr1++;
            }
            else
            {
                ptr2++;
            }
        }
        else if(ptr1 < len1) {
            value1 = arr1[ptr1];
            ptr1++;
            setArr1 = true;
        }
        else if(ptr2 < len2) {
            value2 = arr2[ptr2];
            ptr2++;
        }

        cnt++;
        int mid = (len1 + len2) % 2 == 0 ? (len1 + len2) >> 2 + 1 : (len1 + len2 + 1) >> 2;
        if (cnt == mid)
        {
            if (setArr1)
            {
                return value1;
            }
            else
            {
                return value2;
            }
        }
    }
    return -1;
}

int main()
{
    int len1, len2;
    std::cin >> len1 >> len2;
    int arr1[len1], arr2[len2];
    for (int i = 0; i < len1; i++)
    {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        std::cin >> arr2[i];
    }
    std::cout << get_mid(arr1, arr2, len1, len2) << std::endl;
    return 0;
}