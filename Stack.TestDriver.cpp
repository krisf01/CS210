#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#include "Stack.h"

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    // Int Testing
    Stack<int> a;
    cout << "Int StaticArray Test: \n";
    cout << "-------------------------\n";
    cout << "Testing Stack::size" << endl;
    cout << "Expected: 0 \n";
    cout << "Actual: " << a.size() << endl;
    assert(0 == a.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::peek & Stack::push" << endl;
    cout << "Expected: 1\n";
    a.push(1);
    a.peek();
    assert(a.peek());
    cout << "Actual: " << a.peek() << endl;
    cout << "Pass!\n" << endl;

    cout << "Testing Stack::pop" << endl;
    a.pop();
    a.push(2);
    assert(a.peek());
    cout << "Before pop: " << a.peek() << endl;
    a.pop();
    a.push(1);
    assert(a.peek());
    cout << "After pop: " << a.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing copy constructor" << endl;
    Stack<int> d = a;
    assert(a.size() == d.size());
    for (int i = 0; i < a.size(); i ++)
        assert(a.size() == d.size());
    a.empty();
    a.clear();
    for (int i = 0; i < a.size(); i ++)
        assert(a.size() != d.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing assignment operator" << endl;
    Stack<int> e; e = a;
    assert(a.size() == e.size());
    for (int i = 0; i < a.size(); i ++)
        assert(a.size() == e.size());
    a.empty();
    a.clear();
    for (int i = 0; i < a.size(); i ++)
        assert(a.size() != e.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::size" << endl;
    a.clear();
    a.pop();
    a.push(5);
    assert(a.peek());
    cout << "After pushing 5 now element size is: " << a.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::clear & empty" << endl;
    a.empty();
    a.clear();
    cout << "Pass!\n" << endl;
    
    cout << "Testing Constant object test: " << endl;
    const Stack<int> c = a;
    a.clear();
    a.pop();
    a.push(5);
    assert(a.peek());
    cout << "Size: " << a.peek() << endl;
    cout << "Pass!" << endl;
    cout << "Not Empty" << endl;
    cout << endl;
    
    // Double Testing
    Stack<double> a2;
    cout << "Double StaticArray Test: \n";
    cout << "-------------------------\n";
    cout << "Testing Stack::size" << endl;
    cout << "Expected: 0 \n";
    cout << "Actual: " << a2.size() << endl;
    assert(0 == a2.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::peek & Stack::push" << endl;
    cout << "Expected: 1.1\n";
    a2.push(1.1);
    a2.peek();
    assert(a2.peek());
    cout << "Actual: " << a2.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::pop" << endl;
    a2.pop();
    a2.push(2.2);
    assert(a2.peek());
    cout << "Before pop: " << a2.peek() << endl;
    a2.pop();
    a2.push(1.1);
    assert(a2.peek());
    cout << "After pop: " << a2.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing copy constructor" << endl;
    Stack<double> d2 = a2;
    assert(a2.size() == d2.size());
    for (int i = 0; i < a2.size(); i ++)
        assert(a2.size() == d2.size());
    a2.empty();
    a2.clear();
    for (int i = 0; i < a2.size(); i ++)
        assert(a2.size() != d2.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing assignment operator" << endl;
    Stack<double> e2; e2 = a2;
    assert(a2.size() == e2.size());
    for (int i = 0; i < a2.size(); i ++)
        assert(a.size() == e2.size());
    a2.empty();
    a2.clear();
    for (int i = 0; i < a2.size(); i ++)
        assert(a2.size() != e2.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::size" << endl;
    a2.clear();
    a2.pop();
    a2.push(5);
    assert(a2.peek());
    cout << "After pushing 5 now element size is: " << a2.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::clear & empty" << endl;
    a2.empty();
    a2.clear();
    cout << "Pass!\n" << endl;
    
    cout << "Testing Constant object test: " << endl;
    const Stack<double> c2 = a2;
    a2.clear();
    a2.pop();
    a2.push(5);
    assert(a2.peek());
    cout << "Size: " << a2.peek() << endl;
    cout << "Pass!" << endl;
    cout << "Not Empty" << endl;
    cout << endl;
    
    // String Testing
    Stack<string> a3;
    cout << "String StaticArray Test: \n";
    cout << "-------------------------\n";
    cout << "Testing Stack::size" << endl;
    cout << "Expected: 0 \n";
    cout << "Actual: " << a3.size() << endl;
    assert(0 == a3.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::peek & Stack::push" << endl;
    cout << "Expected: One\n";
    a3.push("One");
    a3.peek();
    cout << "Actual: " << a3.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::pop" << endl;
    a3.pop();
    a3.push("Two");
    assert(a2.peek());
    cout << "Before pop: " << a3.peek() << endl;
    a3.pop();
    a3.push("One");
    cout << "After pop: " << a3.peek() << endl;
    cout << "Pass!\n" << endl;
    
    cout << "Testing copy constructor" << endl;
    Stack<string> d3 = a3;
    assert(a3.size() == d3.size());
    for (int i = 0; i < a3.size(); i ++)
        assert(a3.size() == d3.size());
    a3.empty();
    a3.clear();
    for (int i = 0; i < a3.size(); i ++)
        assert(a3.size() != d3.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing assignment operator" << endl;
    Stack<string> e3; e3 = a3;
    assert(a3.size() == e3.size());
    for (int i = 0; i < a3.size(); i ++)
        assert(a3.size() == e3.size());
    a3.empty();
    a3.clear();
    for (int i = 0; i < a3.size(); i ++)
        assert(a3.size() != e3.size());
    cout << "Pass!\n" << endl;
    
    cout << "Testing Stack::size" << endl;
    a3.clear();
    a3.pop();
    a3.push("Five");
    cout << "After pushing 5 now element size is: " << a3.peek() << endl;
    cout << "Pass!\n" << endl;

    cout << "Testing Stack::clear & empty" << endl;
    a3.empty();
    a3.clear();
    cout << "Pass!\n" << endl;
    
    cout << "Testing Constant object test: " << endl;
    const Stack<string> c3 = a3;
    a3.clear();
    a3.pop();
    a3.push("Five");
    cout << "Size: " << a3.peek() << endl;
    cout << "Pass!" << endl;
    cout << "Not Empty" << endl;
    cout << endl;
    
}
