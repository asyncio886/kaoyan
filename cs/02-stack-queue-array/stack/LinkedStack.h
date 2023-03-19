#include<ListNode.h>
#include<stdlib.h>
template<typename T = int>
class LinkedStack
{
private:
    ListNode<T>* head;
    int size;
public:
    LinkedStack();
    ~LinkedStack();
    bool push(T val){
        ListNode<T>* temp = head->next;
        head->next = new ListNode<T>(val);
        head->next->next = temp;
    }
    T pop() {
        if(isEmpty()) {
            return NULL;
        }
        T val = head->next->value;
        ListNode<T>* poped = head->next;
        head->next = head->next->next;
        free(poped);
        return val;
    }
    T peek() {
        if(isEmpty()) {
            return NULL;
        }
        return head->next->value;
    }
    bool isEmpty() {
        return head->next == NULL;
    }
};

template<typename T> LinkedStack<T>::LinkedStack()
{
    head = new ListNode<T>();
}

template<typename T> LinkedStack<T>::~LinkedStack()
{
    
}
