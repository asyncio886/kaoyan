#include <string>
#include <iostream>
#include <print.h>
using namespace std;

struct Next
{
    int length;
    int *arr;
};
// next[i]代表着[0, i - 1]中公共的前后缀长度
Next createNext(string s)
{
    Next next;
    next.length = s.size();
    next.arr = (int *)malloc(sizeof(int) * s.size());
    int *arr = next.arr;
    for (int i = 0; i < next.length; i++)
    {
        if (i == 0 || i == 1)
        {
            arr[i] = 0;
        }
        else
        {
            // 最长前后缀是否可以拓展
            if (s[i - 1] == s[arr[i - 1]])
            {
                arr[i] = arr[i - 1] + 1;
            }
            else
            {
                arr[i] = 0;
            }
        }
    }
    return next;
}

int search(string model, string target)
{
    Next next = createNext(target);
    int i = 0, j = 0;
    cout << "next array is" << endl;
    print_int_arr(next.arr, next.length);
    while (j < target.size() && i < model.size())
    {
        if (model[i] == target[j])
        {
            i++;
            j++;
        }
        else
        {
            // 第一个字符已经没地方匹配了，直接i++
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = next.arr[j];
            }
        }
        if (j == target.size())
        {
            return i - target.size();
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        string txt, pat;
        cin >> txt;
        cin >> pat;
        cout << search(txt, pat) << endl;
    }
    return 0;
}