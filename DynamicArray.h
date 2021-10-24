#ifndef DynamicArray_h
#define DynamicArray_h

template <typename T>
class DynamicArray
{
    T* value; // T dataype CAP compasity
    int cap;
    T dummy = T();
    
public:
    DynamicArray (int = 2); // constructor
    DynamicArray (const DynamicArray<T>&); // copy constructor
    ~DynamicArray () {delete [ ] value;} // deconstructor
    DynamicArray <T> &operator=(const DynamicArray<T>&); // assignment operator
    int capacity () const {return cap;};
    void capacity (int); // setter
    T operator [ ] (int) const; // getter
    T& operator [ ] (int); // setter
};

//constructor
template <typename T>
DynamicArray<T>::DynamicArray(int cap)
{
    dummy = T();
    this -> cap = cap;
    value = new T[cap];
    for (int i = 0; i < cap; i++)
        value[i] = T();
}

// copy constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& org)
{
    this -> cap = org.cap;
    this -> value = new T[cap];
    for (int i = 0; i < cap; i++) // assigns a copy one-by-one
        value[i] = org[i];
    dummy = org.dummy; // not necessary
}

// assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& org)
{
    if (this != &org)
    {
    delete [] value; // need to delete array before creating a new one
    
    this -> cap = org.cap;
    this -> value = new T[cap];
    for (int i = 0; i < cap; i++) // assigns a copy one-by-one
        value[i] = org.value[i];
    dummy = org.dummy; // not necessary
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::capacity(int cap)
{
    T* temp = new T[cap];
    int limit = cap < this-> cap ? cap : this->cap; // which one is smaller or larger?
    // copying the old content
    for (int i = 0; i < limit; i++)
        temp[i] = value[i];
    for (int i = limit; i < cap; i++)
        temp[i] = T();
    
    delete [] value; // deallocate the original array
    
    value = temp; // assign the data to the new array
    this->cap = cap;
}

template <typename T>
T DynamicArray<T>::operator[ ] (int index) const
{
    if(index < 0 || index >= cap) return T();
    return value[index];
}

template<typename T>
T& DynamicArray<T>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= cap)
        capacity(2 * index);
    return value[index];
}

#endif /* DynamicArray_h */

