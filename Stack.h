#ifndef Stack_h
#define Stack_h

template <typename V>
class Stack
{
    struct Node
    {
        V value;
        Node* next;
    };
    
    V dummy;
    Node* firstNode;
    int siz;
    
    public:
    Stack();
    ~Stack();
    Stack(const Stack& original); // copy constructor
    const Stack& operator= (Stack& right);
    void push (const V& v);
    const V& peek() const;
    void pop();
    int size() const { return this->siz;}
    bool empty() const { return (siz == 0)? true : false ;}
    void clear();
};

// constructor
template <typename V>
Stack<V>::Stack()
{
    this->firstNode = nullptr;
    siz = 0;
    dummy = V();
}

// copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
    firstNode = 0;
    Node* lastNode = 0;
    siz = original.siz;
    for (Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}

// destructor
template <typename V>
Stack<V>::~Stack()
{
    Node* temp;
    while(firstNode)
    {
        temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
    }
}

// push function
template <typename V>
void Stack<V>::push (const V& value)
{
    ++siz;
    Node* temp = new Node{value, nullptr};
    
    temp->next = firstNode;
    firstNode = temp;
}

// peek
template <typename V>
const V& Stack<V>::peek() const
{
    if (!firstNode)
    {
        return dummy;
    }
    
    return firstNode->value;
}

// pop
template <typename V>
void Stack<V>::pop()
{
    if (firstNode)
    {
        Node* temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
        siz--;
    }
}

// clear
template <typename V>
void Stack<V>::clear()
{
    Node* temp;
    while(firstNode)
    {
        temp = firstNode;
        firstNode = firstNode->next;
        delete temp;
    }
    
    siz = 0;
    //firstNode = nullptr;
}

//assignment operator
template <typename V>
const Stack<V>& Stack<V>::operator= (Stack& original)
{
    if (this != &original)
    {
        // deallocate existing list
        while (firstNode)
        {
            Node* p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }
        // build new queue
        Node* lastNode = 0;
        for (Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode) lastNode -> next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}

#endif
