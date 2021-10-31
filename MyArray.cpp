#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#include <cstdlib>

class Array
{
    int values [100]; //initalizes to 0
    int dummy;
    
public:
    Array(); //constructor
    int capacity() const; //getter
    int operator [] (int) const; //getter
    int& operator [] (int); //setter
};

Array::Array() //constructor
{
    for(int i = 0; i < 100; i++)
    {
        values[i] = int();
    }
}

int Array::capacity() const //getter returning data structure's capacity
{
    return 100;
}

int Array::operator [] (int index) const //getter
{
    if (index >= 0 && index < 100)
    {
        return 0;
    }
    
    return values[index];
}

int &Array::operator [] (int index) //setter
{
    if (index < 0 || index >= 100)
    {
        return dummy;
    }

    return values[index];
}

int main()
{
    Array a;
    string index, value;
    int i = 0, val = 0, count = 0;
    
    
    do
    {
        cout << "Input an index and a value [Q to quit]: ";
        cin >> index;
    if (index == "q" || index == "Q")
    break;
        cin >> value;
    if (index >= "a" && index <= "z" && index >= "A" && index <= "Z")
        i = 0;
    else
        i = atoi(index.c_str());
        val = atoi(value.c_str());
        a[i] = val;
        if (a[i] >= 0)
            count++;
    }
    while (1);
        cout << "You stored these many values: " << count << endl;
        cout << "The index-value pair are: \n";
    for (int i = 0; i < a.capacity(); i++)
    {
        if (a[i] > 0)
            cout << i << "=>" << a[i] << endl;
    }
        cout << "Input an index for me to look up [Q to quit]: ";
        cin >> index;
    if (index == "q" || index == "Q")
        return 0;
    if (i <= 0 || i>= 100)
        cout << "I didn't find it\n";
    else
        if (i < 100)
        cout << "Found it -- the value stored at " << i << " is " << a[i] << "\n";
}
