#ifndef H_circularlinkedlist
#define H_circularlinkedlist
#include <iostream>
#include <cassert>

using namespace std;


template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class CircularLinkedList
{
    public:
    CircularLinkedList();
    bool isEmpty() const;
    void print() const;
    int length() const;

    void insert(const Type& newItem);
    bool search(const Type& searchItem) const;
    void deleteNode(const Type& deleteItem);

    private:
    nodeType<Type> *first;
    nodeType<Type> *last;
    int count;
};


template <class Type>
CircularLinkedList<Type>::CircularLinkedList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
bool CircularLinkedList<Type>::isEmpty() const
{
    return (first == nullptr);
}

template<class Type>
void CircularLinkedList<Type>::print() const
{
    if(first == nullptr)
    {
        return;
    }

    nodeType<Type> *current = first;

    do
    {

        cout << current -> info << " ";
        current = current -> link;
    }
    while(current != first);

    cout << endl;

}

template <class Type>
bool CircularLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> *current = first;
    bool found = false;

    do
    {
        if(current -> info >= searchItem)
        {
            found = true;
        }
        else
        {
            current = current -> link;
        }
    }
    while(current != first);

    if(found)
    {
        found = (current->info == searchItem);
    }

    return found;
}

template <class Type>
void CircularLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent = last;

    nodeType<Type> *newNode;

    bool found;

    newNode = new nodeType<Type>;
    newNode -> info = newItem;
    newNode -> link = nullptr;

    if(first == nullptr)
    {
        first = newNode;
        last = newNode;
        newNode -> link = first;
        count++;
    }
    else 
    {
        current = first;
        found = false;

        do
        {
            if(current -> info >= newItem)
            {
                found = true;
            }
            else 
            {
                trailCurrent = current; 
                current = current -> link;
            }
        }
        while(current != first && !found);

        if(current == first && newItem <= first -> info)
        {
            newNode -> link = first;
            first = newNode;
            last -> link = first;
        }
        else if(current == first && newItem > last -> info)
            {
                last -> link = newNode;
                newNode -> link = first;
                last  = newNode;
            }
        else 
        {
            newNode -> link = current;
            trailCurrent -> link = newNode;
        }
            count++;
            
    }

}

template <class Type>
void CircularLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent = last;

    bool found;

    if(first == nullptr)
    {
        cout << "Cannot delete from an empty list." << endl;
    }
    else 
    {
        current = first;
        found = false;

        do{
            if (current -> info >= deleteItem)
            {
                found = true;
            }
            else 
            {
                trailCurrent = current;
                current = current -> link;
            }
        }
            while(current != first && !found);

            if(current -> info != deleteItem)
            {
                cout << "The item to be deleted is not in the list."<< endl;
            }
            else
            {
                // case 1 delere only node
                if(first == last && first == current)
                {
                    delete current;
                    first = nullptr;
                    last = nullptr;
                }
                //case 2: delete first node
                else if(current == first)
                {
                    first = first -> link;
                    last -> link = first;
                    delete current;
            
                }
                //delete last node
                else if(current == last)
                {
                    trailCurrent -> link = first;
                    last = trailCurrent;
                    delete current;
                }

                //delete from the middle
                else
                {
                    trailCurrent -> link = current -> link;
                    delete current;
                }
                    count--;
            }
            
    }
}

template<class Type>
int CircularLinkedList<Type>::length() const
{
    return count;
}

#endif