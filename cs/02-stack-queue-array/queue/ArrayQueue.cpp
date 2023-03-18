#include <stdlib.h>
#include <stdio.h>
class ArrayQueue
{
private:
    int *arr;
    int length;
    int rear;
    int front;
    int addLimit(int value)
    {
        return (value + 1) % length;
    };

public:
    ArrayQueue(int length);
    ArrayQueue();
    ~ArrayQueue();
    bool offer(int val);
    int poll();
    int peek();
    bool isEmpty();
    bool isFull();
    void printValue();
};

ArrayQueue::ArrayQueue()
{
    ArrayQueue(10);
}

ArrayQueue::ArrayQueue(int len)
{
    this->arr = (int *)malloc(sizeof(int) * (len + 1));
    this->length = len + 1;
    this->front = 0;
    this->rear = 0;
}
ArrayQueue::~ArrayQueue()
{
    free(this->arr);
}

bool ArrayQueue::isEmpty()
{
    return front == rear;
}

bool ArrayQueue::offer(int val)
{
    if (isFull())
    {
        return false;
    }
    arr[rear] = val;
    rear = addLimit(rear);
    return true;
}

bool ArrayQueue::isFull()
{
    return (rear + 1) % length == front;
}

int ArrayQueue::poll()
{
    int val = arr[front];
    front = addLimit(front);
    return val;
}

int ArrayQueue::peek()
{
    return arr[front];
}

void ArrayQueue::printValue()
{
    int ptr = front;
    while (ptr != rear)
    {
        printf("%d ", arr[ptr]);
        ptr = addLimit(ptr);
    }
    printf("\n");
}

int main()
{
    ArrayQueue *queue = new ArrayQueue(5);
    for (int i = 0; i < 10; i++)
    {
        queue->offer(i);
    }
    printf("%d\n", queue->isFull());
    queue->printValue();
    queue->poll();
    queue->printValue();
}
