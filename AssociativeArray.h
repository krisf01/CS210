#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <queue>

template <typename K, typename V>
class AssociativeArray
{
    struct Node
    {
        K key;
        V value;
        Node* next;
    };
    
    Node* firstNode;
    int siz;
    
public:
    AssociativeArray() {firstNode = 0; siz = 0;} // default constructor
    AssociativeArray(const AssociativeArray&); // copy constructor
    AssociativeArray<K, V>& operator= (const AssociativeArray<K, V> &); // assignment operator
    ~AssociativeArray();// destructor
    V operator[] (const K&) const; // square bracket getter function
    V& operator[] (const K&); // square brackey setter function
    bool containsKey (const K&) const; // bool getter function
    void deleteKey (const K&); // setter function for delete key
    std::queue<K> keys() const; // queue template
    int size() const {return siz;} // return size
    void clear();
};

template<typename K, typename V> // copy constructor
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
    firstNode = 0;
    Node* lastNode = 0; //temporary tail
    siz = original.siz;
    
    for (Node* p = original.firstNode; p; p->next)
    {
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if (lastNode) lastNode->next = temp;
        
        else firstNode = temp;
        
        lastNode = temp;
    }
}

template <typename K, typename V> // assignment operator
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original)
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
        Node* lastNode = 0; // temporary tail
        for (Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if (lastNode) lastNode->next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}


template<typename K, typename V> // destructor
AssociativeArray<K, V>::~AssociativeArray()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;

        delete p;
        --siz;
    }
}

template<typename K, typename V> // square bracket getter function
V AssociativeArray <K, V>::operator[] (const K& key) const
{
    for (Node* p = firstNode; p; p = p-> next)
    {
        if(p-> key == key)
        {
            return p-> value;
        }
    }
    return V();
}

template<typename K, typename V> // square brackey setter function
V& AssociativeArray<K, V>:: operator[](const K& key)
{
    for(Node* p = firstNode; p; p = p-> next)
    {
        if(p-> key == key)
        {
            return p-> value;
        }
    }
    Node* temp = new Node{key, V(), firstNode};
    firstNode = temp;
    siz++;
    return firstNode-> value;
}

template<typename K, typename V> // bool getter function
bool AssociativeArray<K, V>:: containsKey(const K& key) const
{
    for(Node* p = firstNode; p; p = p-> next)
    {
        if(p-> key == key)
        {
            return true;
        }
    }
    return false;
}

template<typename K, typename V> // setter function for delete key
void AssociativeArray<K,V>:: deleteKey(const K& key)
{
    Node* p, prev;
    for(p = firstNode, prev = 0; p; prev = p, p = p-> next)
    {
        if(p->key == key)
        {
            break;
        }
        if(p)
        {
            siz = siz - 1;
            if (prev) prev -> next = p-> next;
            else firstNode = p->next;
            delete p;
        }
    }
}

template<typename K, typename V> // queue template
queue<K> AssociativeArray<K,V>::keys() const
{
    queue<K> keyQueue;
    for(Node* p = firstNode; p; p = p-> next)
    {
        keyQueue.push(p->key);
    }
    return keyQueue;
}

template<typename K, typename V> //clear
void AssociativeArray<K, V>::clear()
{
    while (firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

#endif
