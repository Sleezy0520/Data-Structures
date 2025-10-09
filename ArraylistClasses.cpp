#include <iostream>

using namespace std;

class arrayListType
{
    public:
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, int item) const;
    virtual void insertAt(int location, int insertItem) = 0;
    virtual void insertEnd(int insertItem) = 0;
    void removeAt(int location);
    void retrieveAt(int location, int& retItem) const;
    virtual void replaceAt(int location, int repItem) = 0;
    void clearList();
    virtual int seqSearch(int searchItem) const = 0;
    virtual void remove(int removeItem) = 0;
    arrayListType(int size = 100);
    arrayListType(const arrayListType& otherList);
    virtual ~arrayListType();
    
    protected:
    int *list;
    int length;
    int maxSize;
};

bool arrayListType::isEmpty() const
{
    return (length == 0);
}

bool arrayListType::isFull() const
{
    return (length == maxSize);
}

int arrayListType::listSize() const
{
    return length;
}

int arrayListType::maxListSize() const
{
    return maxSize;
}

void arrayListType::print() const
{
    for(int i = 0; i < length; i++)
    {
        cout << list[i]<< " ";
    }

    cout << endl;
}

bool arrayListType::isItemAtEqual(int location, int item) const
{
    if(location < 0 || location >= length)
    {
        cout << "The location of the item to be removed is out of range." << endl;
        return false;
    }
    else 
    {
        return (list[location] == item);
    }
}

void arrayListType::removeAt(int location)
{
    if(location < 0 || location >= length)
    {
        cout << "The location of the item to be removed is out of range." << endl;
    }
    else
    {
        for(int i = location; i < length - 1; i++)
        {
            list[i] = list[i+1];
        }
        length--;
    }
}

void arrayListType::retrieveAt(int location, int& retItem) const
{
    if(location < 0 || location >= length)
    {
        cout << "The location of the item to be retrieved is out of range." << endl;
    }
    else
    {
        retItem = list[location];
    }
}

void arrayListType::clearList()
{
    length = 0;
}

arrayListType::arrayListType(int size)
{
    if(size <= 0)
    {
        cout << "The array size must be positive. Creating an array of size 100." << endl;
        maxSize = 100;
    }
    else 
    {
        maxSize = size;
    }
    length = 0;
    list = new int[maxSize];
}

arrayListType::~arrayListType()
{
    delete [] list;
}

arrayListType::arrayListType(const arrayListType& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new int[maxSize];

    for(int j = 0; j < length; j++)
    {
        list[j] = otherList.list[j];
    }
}

class orderedArrayListType : public arrayListType
{
    public:
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void replaceAt(int location, int repItem);
    int seqSearch(int searchItem) const;
    void insert(int insertItem);
    void remove(int removeItem);

    orderedArrayListType(int size = 100);
    private:
};

void orderedArrayListType::insert(int insertItem)
{
    if(length == 0)
    {
        list[length++] = insertItem;
    }
    else if(length == maxSize)
    {
        cout << "Cannot insert in a full list." << endl;
    }
    else 
    {
        int loc;
        bool found = false;
        for(loc = 0; loc < length; loc++)
        {
            if(list[loc] == insertItem)
            {
                found = true;
                break;
            }
        }
        
        for(int i = length; i = loc; i--)
        {
            list[i] = list[i-1];
        }

        list[loc] = insertItem;
        length++;
    }
}