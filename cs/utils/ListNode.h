#include <stdlib.h>
template<typename T = int>
class ListNode
{
public:
    T value;
    ListNode *next;
    ListNode(T value);
    ListNode();
    ~ListNode();
};
 
template<typename T> ListNode<T>::ListNode()
{
    ListNode<T>(-1);
}

template<typename T> ListNode<T>::ListNode(T value)
{
    this->value = value;
}

template<typename T> ListNode<T>::~ListNode()
{

}
