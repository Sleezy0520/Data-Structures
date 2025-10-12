#include <iostream>
#include "ArraylistClasses.cpp" // I didn't wanna clutter the main file so I put the classes in a different file

using namespace std;

int main()
{
  // Create an instance of orderedArrayListType
  orderedArrayListType list(10);

  // Test insertAt
  cout << "Testing insertAt: (5, 7, 10)" << endl;
  list.insertAt(0, 5);
  list.insertAt(1, 10);
  list.insertAt(1, 7); // Insert in the middle
  list.print();

  // Test insertEnd
  cout << "\nTesting insertEnd: (15, 20)" << endl;
  list.insertEnd(15);
  list.insertEnd(20);
  list.print();

  // Test replaceAt
  cout << "\nTesting replaceAt: (index 2 replaced with 8)" << endl;
  list.replaceAt(2, 8); // Replace the value at index 2
  list.print();

  // Test seqSearch
  cout << "\nTesting seqSearch: (searching for 10)" << endl;
  int index = list.seqSearch(10);
  if (index != -1)
    cout << "Item 10 found at index: " << index << endl;
  else
    cout << "Item 10 not found." << endl;

  // Test remove
  cout << "\nTesting remove: (removing 8)" << endl;
  list.remove(8); // Remove the item 8
  list.print();

  // Test isEmpty and isFull
  cout << "\nTesting isEmpty and isFull: " << endl;
  cout << "List is empty: " << (list.isEmpty() ? "Yes" : "No") << endl;
  cout << "List is full: " << (list.isFull() ? "Yes" : "No") << endl;

  // Test clearList
  cout << "\nTesting clearList:" << endl;
  list.clearList();
  cout << "List cleared." << endl;
  list.print();
}
