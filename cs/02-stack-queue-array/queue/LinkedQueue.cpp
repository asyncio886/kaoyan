#include <stdlib.h>
#include <ListNode.h>
template<typename T = int>
class LinkedQueue
{
private:
    ListNode<T> *head;
    ListNode<T> *rear;
    int _size;

public:
    LinkedQueue();
    ~LinkedQueue();
    void clear(ListNode<T> *ptr);
    bool isEmpty();
    int size();
    void offer(T value)
    {
        ListNode<T>* node = new ListNode<T>(value);
        this->rear->next = node;
        this->rear = node;
        _size++;
    }
    int poll()
    {
        if(isEmpty()) {
            return -1;
        }
        ListNode<T>* front = head->next;
        T value = front->value;
        head->next = front->next;
        free(front);
        return value;
    }
    T peek()
    {
        if(isEmpty()) {
            return -1;
        }
        return head->next->value;
    }
};

template<typename T> bool LinkedQueue<T>::isEmpty()
{
    return rear == head;
}

template<typename T> int LinkedQueue<T>::size()
{
    return _size;
}

template<typename T> LinkedQueue<T>::LinkedQueue()
{
    this->head = new ListNode<T>();
    this->_size = 0;
    this->rear = head;
}

template<typename T> LinkedQueue<T>::~LinkedQueue()
{
    clear(head);
}

template<typename T> void LinkedQueue<T>::clear(ListNode<T> *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    clear(ptr->next);
    free(ptr);
}

int main()
{
    LinkedQueue<int>* q = new LinkedQueue<int>();
    for(int i = 0; i < 100;i++) {
        q->offer(i);
    }
    return 0;
}
