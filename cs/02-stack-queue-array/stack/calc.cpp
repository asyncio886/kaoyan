#include <LinkedStack.h>
#include <string>
#include <iostream>
/**
 * 逆波兰表达式构建与计算
*/
using namespace std;
// 记录优先级
const char op[][2] = {{'+', '-'},
                      {'*', '/'},
                      // e是凑数的
                      {'(', 'e'}};

int getState(char c)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (op[i][j] == c && op[i][j] != 'e')
            {
                return i;
            }
        }
    }
    return -1;
}

string getCalcString(string input)
{
    LinkedStack<char> *stack = new LinkedStack<char>();
    string res = "";
    for (char c : input)
    {
        if (c >= '0' && c <= '9')
        {
            res += c;
        }
        else
        {
            if (c == ')')
            {
                while (stack->peek() != '(')
                {
                    res += stack->pop();
                }
                stack->pop();
            }
            else
            {
                int newState = getState(c);
                int topState = getState(stack->peek());
                if (stack->peek() == '(' || newState > topState)
                {
                    stack->push(c);
                }
                else
                {
                    res += stack->pop();
                    stack->push(c);
                }
            }
        }
    }
    while (!stack->isEmpty())
    {
        res += stack->pop();
    }
    return res;
}
int calc(string translatedString) {
    LinkedStack<int>* stack = new LinkedStack<int>();
    for(char c : translatedString) {
        if(c >= '0' && c <= '9') {
            stack->push(c - '0');
        }
        else {
            int pop0 = stack->pop(), pop1 = stack->pop();
            int temp = 0;
            if(c =='+') {
                temp = pop1 + pop0;
            }
            else if(c == '-') {
                temp = pop1 - pop0;
            }
            else if(c == '/') {
                temp = pop1 / pop0;
            }
            else if(c == '*') {
                temp = pop1 * pop0;
            }
            stack->push(temp);
        }
    }
    return stack->pop();
}
int main()
{
    string input;
    std::cin >> input;
    string t = getCalcString(input);
    std::cout << t << std::endl;
    std::cout << "计算结果 : " << calc(t) << endl; 
}