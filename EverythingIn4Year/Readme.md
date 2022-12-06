# The project review alogrithm and data structure

- [The project review alogrithm and data structure](#the-project-review-alogrithm-and-data-structure)
  - [Data Structure](#data-structure)
    - [Array](#array)
    - [Linked List](#linked-list)
    - [Stack](#stack)
    - [Queue](#queue)
    - [Tree](#tree)
    - [Heap](#heap)
    - [Hash Table](#hash-table)
    - [Graph](#graph)
    - [Sort](#sort)
    - [Search](#search)
  - [Algorithm](#algorithm)
    - [Mathematical Algorithms](#mathematical-algorithms)
  - [Reference](#reference)

## Data Structure

### Array

Array is a linear data structure, which stores elements in contiguous memory locations. The elements can be randomly accessed using their index. The index starts from 0 and ends at n-1, where n is the size of the array.

- Array of size 10, which stores marks of 10 students in a class. The index of the array represents the roll number of the student.

- Array of size 5, which stores the marks of 5 subjects of a student. The index of the array represents the subject number.

![Array]( https://www.tutorialspoint.com/data_structures_algorithms/images/array_representation.jpg )

### Linked List

A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.

- A linked list of size 5, which stores the marks of 5 students in a class. Here, each node stores the data and the address of the next node.

- A linked list of size 5, which stores the marks of 5 subjects of a student. Here, each node stores the data and the address of the next node.
  
![Linked List]( https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list.jpg )

### Stack

A stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

- Stack of plates, where the plate which is at the top, is the first one to be removed, i.e., the plate which has been placed at the top most position is removed first.
- Stack of books, where the book which is at the top, is the first one to be removed, i.e., the book which has been placed at the top most position is removed first.
- Stack of cards, where the card which is at the top, is the first one to be removed, i.e., the card which has been placed at the top most position is removed first.

![Stack]( https://www.tutorialspoint.com/data_structures_algorithms/images/stack_representation.jpg )

### Queue

A queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). A good example of queue is any queue of consumers for a resource where the consumer that came first is served first. The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

- Queue of people standing in a line to buy a ticket.

![Queue]( https://www.tutorialspoint.com/data_structures_algorithms/images/queue_diagram.jpg )
  
### Tree

A tree is a hierarchical data structure. The topmost node is called root of the tree. The elements that are directly under an element are called its children. The element directly above something is called its parent. For example, 'a' is a child of 'f', and 'f' is the parent of 'a'. Finally, elements with no children are called leaves.

- A family tree, where all the members are linked to their parents.
- A computer file system, where all the files and folders are linked to each other.
- A decision tree, where all the nodes are linked to their parent nodes.

![Tree]( https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg )

### Heap

A Heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary
heap, in which the tree is a complete binary tree.

- Heap of books, where the book which is at the top, is the first one to be removed, i.e., the book which has been placed at the top most position is removed first.
- Heap of cards, where the card which is at the top, is the first one to be removed, i.e., the card which has been placed at the top most position is removed first.

### Hash Table

A hash table is a data structure which implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

### Graph

A graph is a non-linear data structure consisting of nodes and edges. The nodes are sometimes also referred to as vertices and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph can be defined as, A Graph consists of a finite set of vertices(or nodes) and set of Edges which connect a pair of nodes.

### Sort

Sorting is the process of arranging data in a particular format. Sorting algorithm specifies the way to arrange data in a particular order. Most common orders are in numerical or lexicographical order. Sorting plays an important role in many computer science applications. For example, in computational geometry, the convex hull algorithm requires the input data points to be sorted according to their x-coordinates (or polar angles). Sorting is also often useful for canonicalizing data and for producing human-readable output.

### Search

Searching is the process of finding a particular item in a list of items. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.

- Linear Search: In this type of search, a sequential search is made over all items one by one. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.
- linear search is rarely used practically because other search algorithms such as the binary search algorithm and hash tables allow significantly faster searching comparison to Linear search.

![Search]( https://www.tutorialspoint.com/data_structures_algorithms/images/linear_search.jpg )

## Algorithm

### Mathematical Algorithms


## Reference

- [Data Structure and Algorithms](https://www.geeksforgeeks.org/data-structures/)
- [Data Structure and Algorithms](https://www.tutorialspoint.com/data_structures_algorithms/index.htm)
