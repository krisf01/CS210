#ifndef Queue_H
#define Queue_H

template <typename V>
class Queue
{
    struct Node
    {
        V value;
        Node *next;
    };
    
    int siz;
    Node *firstNode;
    Node *lastNode;
    V dummy;
    
    public:
        Queue();
        Queue(const Queue&);
        Queue<V> &operator=(const Queue<V> &);
        ~Queue();
        void push(const V &);
        const V &front() const;
        const V &back() const;
        void pop();
        int size() const { return siz; }
        bool empty() const { return siz == 0; }
        void clear();
};

template <typename V>
Queue<V>::Queue()
{
    lastNode = 0;
    siz = 0;
}

template <typename V>
void Queue<V>::push(const V &value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = 0;
    if (lastNode)
        lastNode->next = temp;
    else
        firstNode = temp;
        lastNode = temp;
    ++siz;
}

template <typename V>
const V &Queue<V>::front() const
{
    return firstNode->value;
}

template <typename V>
const V &Queue<V>::back() const
{
    return lastNode->value;
}

template <typename V>
void Queue<V>::pop()
{
    if (firstNode)
    {
        Node *p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
    if (siz == 0)
    {
        lastNode = 0;
    }
}

template <typename V>
void Queue<V>::clear()
{
    while (firstNode)
    {
        Node *p = firstNode;
        firstNode = firstNode->next;
        
        delete p;
        
        --siz;
    }
lastNode = 0;
}

template <typename V>
Queue<V>::Queue(const Queue &original)
{
    firstNode = 0;
    lastNode = 0;
    siz = original.siz;
    
    for (Node *p = original.firstNode; p; p = p->next)
    {
        Node *temp = new Node;
        
        temp->value = p->value;
        temp->next = p->next;
        
        if (lastNode)
            lastNode->next = temp;
        else
            firstNode = temp;
            lastNode = temp;
    }
    
}

template <typename V>
Queue<V> & Queue<V>::operator=(const Queue &original)
{
    if (this != &original)
    {
// deallocate existing list
        while (firstNode)
        {
            Node *p = firstNode->next;
            delete firstNode;
            
            firstNode = p;
        }
        
        lastNode = 0;
        
        for (Node *p = original.firstNode; p; p = p->next)
        {
            Node *temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            
            if (lastNode)
                lastNode->next = temp;
            else
                firstNode = temp;
                lastNode = temp;
        }
        siz = original.siz;
}
    return *this;
}

template <typename V>
Queue<V>::~Queue()
{
    Node* temp;
    while(firstNode)
    {
        temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
    }
}

#endif
