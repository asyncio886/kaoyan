#include <iostream>
#include<print.h>
// 两个数组
void move(int arr[], int step, int arrLength)
{
    // 如 123456 -> 561234
    // 只要 1234 56123 456 截取中间即可
    int temp_arr[arrLength * 2];
    for (int i = 0; i < arrLength * 2; i++)
    {
        temp_arr[i] = arr[i % arrLength];
    }
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = temp_arr[i + step];
    }
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
    int step;
    std::cin >> step;
    move(arr, step, len);
    print_int_arr(arr, len);
    return 0;
}
