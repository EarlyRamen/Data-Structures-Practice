# Heap Assignment
### 2023-04-04
### by Professor Atanasio

## Description
The purpose of this assignment is to achieve a better familiarity with the workings of the heap functions described in class. 

## Requirements
Implement the ArrayHeap data structure following the provided Heap interface. Then, write a priority queue which has a heap as a data member.
- Do not change the interface
- The Arrayheap should have 3 constructors
	- A constructor that takes in a comparator function as an argument
	- A constructor that takes the comparator function and an initial array size; in that order
	- A constructor that takes in a comparator function, an array to initialize it, and the array size; in that order
		- the elements of the provided array should be copied into the heap's data store
		- heapify should be run on the internal store to put it into minheap/maxheap order 
- The ArrayHeap should dynamically resize when adding an item to a full array
- The priority queue should take in the comparator function to be passed to the internal heap.
- It should provide the standard queue functions:
	- enqueue
	- dequeue
	- front
	- empty
	- clear
- Write a test program to thoroughly test your priority queue

## Submission
- Copy your .h and .cpp files to a directory called, username_heap_ex where *username* is replaced with your MtSAC username
- Compress the folder using zip, rar, tar, tar.gz, 7zip, etc.
- Submit it via canvas before the deadline

