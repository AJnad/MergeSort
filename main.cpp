/*
    Ajay Nadhavajhala
    5/3/19
    This program utilizes the merge sort 
    algorithm by taking in an unsorted linked
    list and return its sorted version. The 
    algorithm runs in nlogn runtime complexity. 
    The reason I chose merge sort is because it
    has a worst case, average case, and best case
    time complexity of nlogn which displays a strong
    level of consistency when implementing this algorithm
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
   int data;
   Node* next;
};

Node* SortedMerge(Node* a, Node* b);
void splitList(Node* source,
                   Node** frontRef, Node** backRef);

void MergeSort(Node** headRef)
{
   Node* head = *headRef;
   Node* a;
   Node* b;

   // if there is nothing in the list 
   if ((head == NULL) || (head->next == NULL)) {
       return;
   }

   // spltting into two separate lists
   splitList(head, &a, &b);
   MergeSort(&a);
   MergeSort(&b);

   // combines the two sorted lists together as one 
   *headRef = SortedMerge(a, b);
}


Node* SortedMerge(Node* a, Node* b)
{
   Node* result = NULL;

   if (a == NULL)
       return (b);
   else if (b == NULL)
       return (a);

   if (a->data <= b->data) {
       result = a;
       result->next = SortedMerge(a->next, b);
   }
   else {
       result = b;
       result->next = SortedMerge(a, b->next);
   }
   return (result);
}

// Splits the list in half and then returns the two seperate lists 
// as one. This is also known as a divide and conquer algorithm 
void splitList(Node* source,
                   Node** frontRef, Node** backRef)
{
   Node* ptr1;
   Node* ptr2;
   ptr2 = source;
   ptr1 = source->next;

   while (ptr1 != NULL) {
       ptr1 = ptr1->next;
       if (ptr1 != NULL) {
           ptr2 = ptr2->next;
           ptr1 = ptr1->next;
       }
   }

   *frontRef = source;
   *backRef = ptr2->next;
   ptr2->next = NULL;
}

// prints the linked list 
void printSort(Node* node)
{
   while (node != NULL) {
       cout << node->data << " ";
       node = node->next;
   }
}

// Insert node at beginning of list 
void push(Node** head_ref, int new_data)
{
   Node* new_node = new Node();

   // fill list with data
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}

int main()
{
   Node* a = NULL;
   // Testing an unsorted list
   // 1->7->23->9->47->17
   push(&a, 17);
   push(&a, 47);
   push(&a, 7);
   push(&a, 23);
   push(&a, 1);
   push(&a, 9);
   MergeSort(&a);

   cout << "After running sort: \n";
   printSort(a);

   return 0;
}

