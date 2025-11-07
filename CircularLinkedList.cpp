#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main()
{
   CircularLinkedList<int> list;
   int num;

   cout << "Enter numbers on the list: ";
   cin >> num;

   while(num != -999)
   {
    list.insert(num);
    cin >> num;
   }

   cout << "List: ";
   list.print();

   cout << "What number do you want to search for: ";
   cin >> num;

   if(list.search(num))
   {
    cout << "Found "<< num << endl;
   }
   else
   {
    cout << "Could not find "<< num <<" in list" << endl;
   }


   cout << "Choose a number to delete:  ";
   cin >> num;
   list.deleteNode(num);

   cout <<"list after deletion: ";
   list.print();

   cout << "Is list empty? ";

   if(list.isEmpty())
   {
    cout << "Yes" << endl;
   }
   else
   {
    cout << "No" << endl;
   }


    return 0;
}