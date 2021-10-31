#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <algorithm>
using namespace std;

template<typename V>
class PriorityQueue
{
    V* values;
    int cap;
    int siz;
    void capacity(int);
    
public:
    PriorityQueue(int = 2);  // default constructor
    PriorityQueue(const PriorityQueue<V>&); // copy constructor
    ~PriorityQueue() {delete [] values;}
    PriorityQueue<V>& operator=(const PriorityQueue<V>&); // assignment operator
    
    void push(const V&);
    void pop();
    V top() const {return siz == 0 ? V() : values[0];}
    int size () const {return siz;}
    bool empty() const {return siz == 0 ? true : false;}
    void clear() {siz = 0;}
};

// void capacity function
template<typename V>
void PriorityQueue<V>::capacity(int cap)
{
    V* temp = new V[cap];
    for (int i = 0; i < this->cap; i++)
        temp[i] = values[i];
    for (int i = this->cap; i < cap; i++)
        temp[i] = V();
    delete[] values;
    values = temp;
    this->cap = cap;
}

// default constructor
template<typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
    siz = 0;
    this-> cap = cap;
    values = new V[cap];
}

// copy constructor
template<typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& org)
{
    cap = org.cap;
    siz = org.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
        values[i] = org.values[i];
}

// assignment operator
template<typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& org)
{
    if (this != &org)
    {
        delete [] values;
        
        cap = org.cap;
        siz = org.siz;
        
        values = new V[cap];
        for (int i = 0; i < cap; i++)
            values[i] = org.values[i];
    }
    return *this;
}

// push function
template<typename V>
void PriorityQueue<V>::push(const V& value)
{
    if (siz >= cap) capacity(cap * 2);
        values[siz] = value;
    int index = siz;
    int p_index = (index + 1) / 2 - 1;
    while (index > 0)
    {
        if (values[p_index] < values[index])
            swap (values[p_index], values[index]);
        else
            break;
        index = p_index;
        p_index = (index + 1) / 2 - 1;
    }
    siz++;
}

// pop function
template <typename V>
void PriorityQueue <V>::pop()
{
    if (siz == 0)
        return;
    int index = 0;
    
    while (true)
    {
        int l_index = 2 * index + 1;
        int r_index = 2 * index + 2;
        
        if (l_index >= siz)
            break;

        if (values[r_index] < values[l_index] || r_index >= siz)
        {
            values[index] = values[l_index];
            index = l_index;
        }
        else
        {
            values[index] = values[r_index];
            index = r_index;
        }
    }
    siz--;
        if(index == siz)
            values[index] = values[siz];

    while (true)
    {
        int index2 = ((index + 1) / 2) - 1;
        if (index2 < 0 || values[index] < values[index2])
            break;

        swap(values[index], values[index2]);
        index = index2;
    }
}

#endif
