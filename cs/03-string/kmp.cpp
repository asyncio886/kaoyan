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
    arr[0] = -1;
    for (int i = 1; i < next.length; i++)
    {
        if (i == 1)
        {
            arr[i] = 0;
        }
        else
        {
            // 对[0, i - 1]范围进行运算
            // 拿到前面 i - 1 个字符的最长公共前后缀
            int len = arr[i - 1];
            // 需要加入的字符
            char target = s[i - 1];
            while (len > -1 && s[len] != target /* 公共前缀的后面一个字符和target不同，调整长度 */)
            {
                len = arr[len];
            }
            arr[i] = len + 1;
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