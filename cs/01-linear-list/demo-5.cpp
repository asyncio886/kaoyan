#include <iostream>
int getSubDict(int value1, int value2)
{
    int res;
    return (res = (value1 - value2)) < 0 ? -res : res;
}

int minDict(int **arrs, int len)
{
    int *arr1 = arrs[0], *arr2 = arrs[1], *arr3 = arrs[2];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++)
            {

            }
        }
    }
    return -1;
}

int main()
{
    int len;
    std::cin >> len;
    int **arrs;
    arrs = (int **)malloc((sizeof(int *)) * 3);
    for (int i = 0; i < 3; i++)
    {
        arrs[i] = (int *)malloc(sizeof(int *) * len);
        for (int j = 0; j < len; j++)
        {
            std::cin >> arrs[i][j];
        }
    }
    std::cout << minDict(arrs, len) << std::endl;
    return 0;
}