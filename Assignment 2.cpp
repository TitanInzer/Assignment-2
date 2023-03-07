#include <iostream>
#include "Assignment 2.h"

using namespace std;

int main() {
    // Create an empty list
    Single_Linked_List<int> my_list;

    // Test push_front() and front()
    my_list.push_front(5);
    my_list.push_front(10);
    my_list.push_front(15);
    cout << "Front element after push_front(): " << my_list.front() << endl;

    // Test push_back() and back()
    my_list.push_back(20);
    my_list.push_back(25);
    my_list.push_back(30);
    cout << "Back element after push_back(): " << my_list.back() << endl;

    // Test pop_front()
    my_list.pop_front();
    cout << "Front element after pop_front(): " << my_list.front() << endl;

    // Test pop_back()
    my_list.pop_back();
    cout << "Back element after pop_back(): " << my_list.back() << endl;

    // Test insert() and remove()
    my_list.insert(1, 35);
    cout << "Element at index 1 after insert(): " << my_list[1] << endl;

    my_list.remove(2);
    cout << "Element at index 2 after remove(): " << my_list[2] << endl;

    // Test find()
    int index = my_list.find(20);
    cout << "Index of element 20: " << index << endl;

    return 0;
}