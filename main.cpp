#include <iostream>
#include <sstream>
using namespace std;
#include "Utility.h"
#include "Random.h"
#include "Key.h"
#include "Record.h"
#include "Ordered_list.h"
#include "Sortable_list.h"
#include "Timer.h"



void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate);
int introduction();
int main1();
int main2();
int main3();
int main4();
int main5();


Error_code sequential_search(const List<Record> &the_list,
                             const Key &target, int &position);
void test_search(int searches, List<Record> &the_list);
void test_search_p2(int searches, Ordered_list &the_list);
void print_the_list (List<Record> &list, int list_position = 5);
Error_code recursive_binary_2(const Ordered_list &the_list, const Key &target,
                              int bottom, int top, int &position);


int main()
/*
Main program which includes 5 versions*/
{
    bool end = false;
    
    while (!end) {
        int variant = introduction();
        switch (variant) {
            case 1 :
                main1();
                break;
            case 2 :
                main2();
                break;
                
            case 3 :
                main3();
                break;
                
            case 4 :
                main4();
                break;
                
            case 5 :
                main5();
                break;
                
            case 6 :
                end = true;
                break;
                
            default:
                cout << "Nothing was selected. Try again." << endl << endl;
        }
    }
    
    return 0;

}





int introduction()
{
    int variant;
    cout << "Select the program to run:" << endl;
    cout << "1.    Sequential search" << endl
         << "2.    Binary search" << endl
         << "3.    Insertion sort" << endl
         << "4.    Merge sort" << endl
         << "5.    n^2 sorting algorithm" << endl
         << "6.    Quit the program" << endl
         << "Your choice: "
    << flush;
    if (cin >> variant);
    else
    {
        cin.clear();
        cin.ignore(10000, '\n');
        variant = 6;
    }
    cout << endl;
    return variant;
}




int main1()     //  Sequential search

{

    List<Record> records;
    int size;
    //int value = 0,
    
    cout << "Enter the data size (up to 100,000): ";
    cin >> size;

    //cout << "Enter the key value: ";
    //cin >> value;
    //Key main_key(value);

    //filling the list
    for (int i=0; i < size; i++) {
        records.insert(i, i*2+1);
    }
    
    //printing the list
    print_the_list (records);
    
    test_search (1, records);
    
    
    return 0;
}






int main2()     //  Binary search

{

    Ordered_list records;
    int size;
    //int value = 0,
    
    cout << "Enter the data size (up to 100,000): ";
    cin >> size;

    //filling the list
    for (int i=0; i < size; i++) {
        records.insert(i, i*2+1);
    }
    
    //printing the list
    print_the_list (records);
    
    test_search_p2 (100, records);
    
    return 0;
    
}
    



int main3()     //  Insertion sort

{
    
    int size, positions;
    List<Record> list_unordered; //for intial random data - unsorted array
    Ordered_list list_ordered; //sorted array as an outcome
    Sortable_list<Record> sortable_list; //sortable list with contiguous implementation
    Timer clock;

    cout << "Enter the data size to be generated (up to 100,000): ";
    cin >> size;
    cout << "How many positions of both sides to print?: ";
    cin >> positions;
    if (positions > size/2 || positions < 1) positions = size/2;
    
    //filling both lists with the same random numbers
    Random number;
    for (int i = 0; i < size; i++) {
        int num = number.random_integer(0, size*10);
        list_unordered.insert(i, num);
        sortable_list.insert(i, num);
    }
    cout << "\n1. With 'ordered_list:insert()' method:" << endl;
    cout << "BEFORE sorting:" << endl;
    print_the_list(list_unordered, positions);
    
    //Insertion sort - from unordered list into ordered list
    Key value;
    clock.reset();
    for (int i = 0; i < size; i++)
    {
        list_unordered.retrieve(i, value);
        list_ordered.insert(value);
    }
    cout << "\nAFTER sorting:" << endl;
    print_the_list(list_ordered, positions);
    cout << "--------------------------------------" << endl;
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << endl;
    
    //==SORTABLE list==
    cout << "\n2. With 'sortable_list:insertion_sort()' method:" << endl;
    cout << "BEFORE sorting:" << endl;
    print_the_list(sortable_list, positions);
    
    //Insertion sort - for contigious list
    clock.reset();
    sortable_list.insertion_sort();
    cout << "\nAFTER sorting:" << endl;
    print_the_list(sortable_list, positions);
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << endl;
    
    
    
    return 0;
};





int main4()     //  Insertion sort

{
    int size, positions;
    Sortable_list<Record> sortable_list; //sortable list with contiguous implementation
    Timer clock;

    cout << "Enter the data size to be generated (up to 100,000): ";
    cin >> size;
    cout << "How many positions of both sides to print?: ";
    cin >> positions;
    if (positions > size/2 || positions < 1) positions = size/2;
    
    //filling both lists with the same random numbers
    Random number;
    for (int i = 0; i < size; i++) {
        sortable_list.insert(i, number.random_integer(0, size*10));
    }
    
    cout << "\nWith 'sortable_list:merge_sort()' method:" << endl;
    cout << "BEFORE sorting:" << endl;
    print_the_list(sortable_list, positions);
    
    //Insertion sort - for contigious list
    clock.reset();
    sortable_list.merge_sort();
    cout << "\nAFTER sorting:" << endl;
    print_the_list(sortable_list, positions);
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << endl;
    cout << endl;

    return 0;
};





int main5()     //  Insertion sort

{
    int size, positions;
    Sortable_list<Record> sortable_list_insert, sortable_list_merge, sortable_list_quicksort ; //sortable list with contiguous implementation
    Timer clock;

    cout << "Enter the data size to be generated (up to 100,000): ";
    cin >> size;
    
    Random number;
    for (int i = 0; i < size; i++) {
        int target = number.random_integer(0, size*10);
        sortable_list_insert.insert(i, target);
        sortable_list_merge.insert(i, target);
        sortable_list_quicksort.insert(i, target);
    }
    
    cout << "\nWith 'insertion sort' method:" << endl;
    //cout << "BEFORE sorting:" << endl;
    //print_the_list(sortable_list_insert, positions);
    
    //Insertion sort - for contigious list
    clock.reset();
    Key::comparisons = 0;
    Key::assignments = 0;
    sortable_list_insert.insertion_sort();
    //cout << "\nAFTER sorting:" << endl;
    //print_the_list(sortable_list_insert, positions);
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << "Comparisons: " << Key::comparisons << endl;
    cout << "Assignments: " << Key::assignments << endl;
    cout << endl;
    cout << "=========================" << endl;
    
    
    
    cout << "\nWith 'merge_sort' method:" << endl;
    //cout << "BEFORE sorting:" << endl;
    //print_the_list(sortable_list_merge, positions);
    
    //Merge sort - for contigious list
    clock.reset();
    Key::comparisons = 0;
    Key::assignments = 0;
    sortable_list_merge.merge_sort();
    //cout << "\nAFTER sorting:" << endl;
    //print_the_list(sortable_list_merge, positions);
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << "Comparisons: " << Key::comparisons << endl;
    cout << "Assignments: " << Key::assignments << endl;
    cout << endl;
    cout << "=========================" << endl;
    
    
    
    cout << "\nWith 'quick sort' method:" << endl;
    //cout << "BEFORE sorting:" << endl;
    //print_the_list(sortable_list_quicksort, positions);
    
    //Quick sort - for contigious list
    clock.reset();
    Key::comparisons = 0;
    Key::assignments = 0;
    sortable_list_quicksort.quick_sort();
   // cout << "\nAFTER sorting:" << endl;
    //print_the_list(sortable_list_quicksort, positions);
    cout << "Time spent: " << clock.elapsed_time() << endl;
    cout << "Comparisons: " << Key::comparisons << endl;
    cout << "Assignments: " << Key::assignments << endl;
    cout << endl;
    cout << endl;

    return 0;
};





Error_code sequential_search(const List<Record> &the_list,
                             const Key &target, int &position)
/*
Post: If an entry in the_list has key equal to target, then return
      success and the output parameter position locates such an entry
      within the list.
      Otherwise return not_present and position becomes invalid.
*/
{
   int s = the_list.size();
   for (position = 0; position < s; position++) {
      Record data;
      the_list.retrieve(position, data);
      if (data == target) return success;
   }
    position = -1;
    return not_present;
}





void test_search(int searches, List<Record> &the_list)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for a
      sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
      together with an output function print_out
*/
{
   int list_size = the_list.size();
    int target;
   if (searches <= 0 || list_size < 0) {
      cout << " Exiting test: " << endl
           << " The number of searches must be positive." << endl
           << " The number of list entries must exceed 0." << endl;
      return;
   }
   int i, found_at = -1;
   Key::comparisons = 0;
   //Random number;
   Timer clock;

    //first target will be odd number (in the middle of the list)
    target = int(list_size / 2) * 2 + 1;
    cout << "\nTarget (odd): " << target << endl;
   for (i = 0; i < searches; i++) {
      //target = 2 * number.random_integer(0, list_size - 1) + 1;
       //cout << "Searched random number: " << target << endl;
      if (sequential_search(the_list, target, found_at) == not_present)
         cout << "\nError: Failed to find expected target, something went wrong!" << endl;
   }
    cout << "Successful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: " << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl;
    cout << "Position of the data found: " << found_at << endl;

    
    //second target will be even number (in the middle of the list)
    target = int(list_size / 2) * 2;
    cout << "\nTarget (even): " << target << endl;
   Key::comparisons = 0;
   clock.reset();
   for (i = 0; i < searches; i++) {
      //target = 2 * number.random_integer(0, list_size);
      if (sequential_search(the_list, target, found_at) == success)
         cout << "Error: Found unexpected target " << target
              << " at " << found_at << endl;
   }
    cout << "Unsuccessful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: "  << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl << endl;
}




void test_search_p2(int searches, Ordered_list &the_list)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for
      sequential and binary searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
      together with an output function
*/
{
   int list_size = the_list.size();
   int target;
   if (searches <= 0 || list_size < 0) {
      cout << " Exiting test: " << endl
           << " The number of searches must be positive." << endl
           << " The number of list entries must exceed 0." << endl;
      return;
   }
    int i, found_at = -1;
    Key::comparisons = 0;
    Random number;
    Timer clock;
    int array_of_odd_randoms [searches];
    int array_of_even_randoms [searches];
    
    cout << "Searched random numbers (odd): ";
    for (i = 0; i < searches; i++) {
       
       //target will be a random odd number
       target = 2 * number.random_integer(0, list_size - 1) + 1;
       array_of_odd_randoms[i] = target; // to store generated ODD randoms for binary search
       cout << target << ", ";
       if (sequential_search(the_list, target, found_at) == not_present)
           cout << "\nError: Failed to find expected target, something went wrong!" << endl;
   }
    
    cout << "\n\nSEQUENTIAL search:" << endl << "----------------";
    cout << "\nSuccessful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: " << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl;
    //cout << "Position of the data found: " << found_at << endl;
    
    //sequential - unsuccessful
    //cout << "\nTarget (even): " << target << endl;
   Key::comparisons = 0;
   clock.reset();
   for (i = 0; i < searches; i++) {
       target = 2 * number.random_integer(0, list_size - 1);
       array_of_even_randoms [i] = target; // to store generated EVEN randoms for binary search
      if (sequential_search(the_list, target, found_at) == success)
         cout << "Error: Found unexpected target " << target
              << " at " << found_at << endl;
   }
    cout << "\nUnsuccessful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: "  << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl;
    
    
    //BINARY search - successful
    cout << "\nBINARY search (recursive_binary_2):" << endl << "----------------" << endl;
    Key::comparisons = 0;
    clock.reset();
    for (i = 0; i < searches; i++) {
        
        target = array_of_odd_randoms [i];
        if (recursive_binary_2(the_list, target, 0, the_list.size() - 1, found_at) == not_present)
            cout << "\nError: Failed to find expected target, something went wrong!" << endl;
    }
     cout << "Successful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: " << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl;
     //cout << "Position of the data found: " << found_at << endl;
    
    
    //BINARY search - unsuccessful
    Key::comparisons = 0;
    clock.reset();
    for (i = 0; i < searches; i++) {
        target = array_of_even_randoms [i];
        if (recursive_binary_2(the_list, target, 0, the_list.size() - 1, found_at) == success)
            cout << "Error: Found unexpected target " << target
            << " at " << found_at << endl;
    }
    cout << "\nUnsuccessful, time per search: " << clock.elapsed_time() / searches << "   " << endl << "Comparisons per search: "  << Key::comparisons / searches << "  " << "\nSearches: " << searches << endl << endl;
}








void print_the_list (List<Record> &list, int list_position)
{
    cout << "List content: ";
    if (list.size() > 10)
    {
        Key x;
        for (int i = 0; i < list_position; i++)
        {
            list.retrieve(i, x);
            cout << x.the_key() << ", ";
        }
        cout << "... ";
        
        for (int i = list.size()-list_position; i < list.size()-1; i++)
        {
            list.retrieve(i, x);
            cout << x.the_key() << ", ";
        }
        list.retrieve(list.size()-1, x);
        cout << x.the_key() << endl;
        
    }
    else
    {
        Key x;
        for (int i = 0; i < list.size()-1; i++)
        {
            list.retrieve(i, x);
            cout << x.the_key() << ", ";
        }
        list.retrieve(list.size()-1, x);
        cout << x.the_key() << endl;
    }
}






Error_code recursive_binary_2(const Ordered_list &the_list, const Key &target,
                              int bottom, int top, int &position)
/*
Pre:  The indices bottom to top define the
      range in the list to search for the target.
Post: If a Record in the range from bottom to top in the_list
      has key equal to target, then position locates
      one such entry, and a code of success is returned.
      Otherwise, not_present is returned, and position is undefined.
Uses: recursive_binary_2, together with methods from the classes
      Ordered_list and Record.
*/
{
   Record data;
   if (bottom <= top) {
      int mid = (bottom + top) / 2;
      the_list.retrieve(mid, data);
      if (data == target) {
         position = mid;
         return success;
      }

      else if (data < target)
         return recursive_binary_2(the_list, target, mid + 1, top, position);
      else
         return recursive_binary_2(the_list, target, bottom, mid - 1, position);
   }
   else return not_present;
}
