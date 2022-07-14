// Created by Benjamin Duncan
// for daily coding problem # 6 [hard]
// on July 14, 2022
// Time: 30 mins on July 14, 2022


/*
This was in the email:

    An XOR linked list is a more memory efficient doubly linked list. 
    Instead of each node holding next and prev fields, it holds a 
    field named both, which is an XOR of the next node and the 
    previous node. Implement an XOR linked list; it has an 
    add(element) which adds the element to the end, and a get(index) 
    which returns the node at index.

    If using a language that has no pointers (such as Python), you 
    can assume you have access to get_pointer and dereference_pointer 
    functions that converts between nodes and memory addresses.

Here's the wiki for XOR linked lists: Citation[1]

So, my questions are:
1.  How do you get the value of the previous node or next node from
    the XOR'ed value? Wouldn't you need one of the values?
    A:  While traversing the list we need to remember the address of
        the previously accessed node in order to calculate the next 
        node’s address (Citation[2])
2.  What syntax allows one to use XOR in c++?



Plan:
1.  Implement a XORNode class that has the following:
    a.  one pointer field that is the XOR of the prev and next values.
    b.  a value field that can take any sort of object.
    c.  a contructor that takes in the previous pointer value.
    d.  a method that returns a pointer pointing to the XOR of the 
        passed in pointer and the node's XOR'ed value.
2.  Implement a XORLinkedList class that has the following features:
    a.  a constructor that implementes an empty list.
    b.  a pop function
    c.  a remove(index) function
    d.  an push function
    e.  a add(index) function
    f.  a clearAll function
    g.  a at(index) function to return that index

    SHOULD I JUST MAKE AN ITERATOR INSTEAD?s

3.  Implement a main
*/

// Create XNode class here

// Create 


// Create main function here to test code.












/*
    Citations:
    1. https://en.wikipedia.org/wiki/XOR_linked_list
    2. https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
*/