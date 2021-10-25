#ifndef StaticArray_h
#define StaticArray_h

template <typename T, int CAP>
class StaticArray
{
    T value[CAP]; // T datatype CAP compasity
    T dummy;
    
public:
    StaticArray();
    int capacity() const {return CAP;}
    T operator[ ] (int) const; // getter
    T& operator[ ] (int); // setter
};

// constructor
template<typename T, int CAP>
StaticArray<T, CAP>::StaticArray()
{
    dummy = T();
    for (int i = 0; i < 100; i++)
        value[i] = T();
}

template<typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const
{
    if (index < 0)
        return dummy;
    if (index >= CAP)
        return dummy;
    return value[index];
}

template<typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index)
{
    if (index < 0)
        return dummy;
    if (index >= CAP)
        return dummy;
    return value[index];
}

#endif /* StaticArray_h */
