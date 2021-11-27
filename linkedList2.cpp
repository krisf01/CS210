#include <iostream>
using namespace std;

class List
{
	private:
	struct Node
	{
        char c = ' ';
        struct Node *next;
	};
	
	Node *head;
	
	public:
	List();
    ~List();
	void append(char);
	void print() const;
    bool find(char) const;
    void remove(char);
    void clear();
    int vowels();
    char front();
};

List::List()
{
    head = nullptr;
}

List::~List()
{
    Node *nodePtr = head;
    Node *nextNode;

    while (nodePtr != nullptr)
        {
            nextNode = nodePtr->next;

            delete nodePtr;
            nodePtr = nextNode;
        }
}

void List::append(char letter)
{
    Node *newNode;
    Node *nodePtr;
    
    newNode = new Node;
    newNode-> c = letter;
    newNode-> next = nullptr;
    
    if (!head)
        head = newNode;
    else
    {
        nodePtr = head;
        
        while (nodePtr-> next)
            nodePtr = nodePtr->next;
            
        nodePtr->next = newNode;
    }
}

void List::print() const
{
	Node *nodePtr = head;
	while(nodePtr != nullptr)
	{
	    cout << nodePtr->c << endl;
	    nodePtr = nodePtr-> next;
	}
}

bool List::find(char c) const
{
    Node *nodePtr = head;
    while(nodePtr != NULL)
    {
         if (nodePtr -> c == c)
            return true;
        nodePtr = nodePtr->next;
    }
    return false;
}

void List::remove(char letter)
{
    Node *nodePtr;
    Node *previousNode;

    if(!head)
        return;
    if (head->c == letter)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr ->c != letter)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr ->next;
        }
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void List::clear()
{
    Node *nodePtr = head;
    Node *newNode;
    
    while(nodePtr!=NULL)
    {
        newNode = nodePtr;
        nodePtr = nodePtr -> next;
        delete newNode;
    }
    
    head = NULL;
}

int List::vowels()
{
    int count = 0;
    Node *nodePtr = head;
    
    while(nodePtr != NULL)
    {
        if (nodePtr->c == 'a' || nodePtr->c == 'e' || nodePtr->c == 'i' || 
            nodePtr->c == 'o' || nodePtr->c == 'u')
        {
            count ++;
        }
        nodePtr = nodePtr->next;
    }
    
        return count;
}

char List::front()
{
    if(head == NULL)
        return 'z';
    else
        return head->c;
}

int main()
{
	List l;
    l.append('a');
    l.append('b');
    l.append('c');
    l.append('d');
    l.append('e');
    l.append('f');
	
	cout << "Characters a -f in list: " << endl;
	l.print();
	
	cout << "Vowels count: " << l.vowels() << endl;
	cout << "Check the list for e: " << l.find('e') << " and was found" << endl;
	l.remove('d');
	cout << "Remove the d: " << endl;
	l.print();
	
	l.clear();
	
	return 0;
}
