## Description
A Set is a type of collection that will hold exactly one of any object or value based on its *key*. If used to store an object, the **equality** operator of the object will need to be overloaded to determine if one object is equal to another. If the client program tries to insert two equal items, the set will throw a runtime exception. 

A HashSet is a set that requires a **hashcode** function to be defined for the type of items stored in it.  This function need not be in the object itself but can be defined anywhere that it can be accessed. **A better way of providing it is to pass it into the constructor of the HashSet**. This is what you should do.

Note: two objects with different keys, objects that are not equal, could generate the same hash code and/or be compressed such that the hash function will generate the same subscript at which to store those objects (a collision). You should write code to handle a collision. You will implement two private functions in the hash set that will probe for an open position. One should use linear probing, the other, quadratic probing.

## Set ADT
The set ADT has the following operations:
- add(item): Inserts an item into the set. If the item already exists, it's replaced by the one added.
- remove(item): Removes and returns an item from the Set. it throws a runtime error if the item is not a member.
- contains(item): Returns true of the item is a member of the set or false otherwise. 
- size(): Returns the number of items stored in the set. 
- empty(): Returns the number of items in the set

## Activity
In this exercise you must create  a class that implements the provided interface, *Set*, using two different probing methods. **Note: Do not alter the interface in any way** and **your class should be templated to store any data type**. 

You will implement the two private compression/probing functions and a resizable array that has a default size of 223. These two functions should be called **linearProbe** (for linear probing), and **quadraticProbe** (for quadratic probing), take as their input the hashcode and returns the available subscript at which to store the item or -1 if probing fails.  The item’s hashcode function, $h_1$, for type T should be passed into the constructor. Do not allow more than 15 probing attempts. If you cannot find a location in which to store the item after 15 attempts, return -1.  

The HashSet should have at least two constructors. These constructors must take the hashcode function and the type of probing to use. An enum has been provided for these two types. In addition, you can also create a constructor that only takes in the hashcode function and chooses a default probing technique.

The HashSet should resize dynamically when they reach 75% occupancy. On a resize you will need to locate each item in the set's old array and recalculate its destination for the size of the new array. In the new array be sure to initialize the status of all buckets to a **Empty** status before storing the items. On a resize, the size of the new array should be a prime number. You will need to create a function to calculate this number. 
 
For a compression algorithm, implement the division method: $h_2(k) = |k|\, MOD\, n$, where n = the size of the array, or the MAD method. 

When an item is removed, you will not need to relocate any items that were entered using probing. You should create a struct or parallel array to show if each element in the array has the status of: 
- **Occupied**: holds an item
- **Empty**: the element has never been used
- **Free**: the element was occupied but the item has been removed

Use an enum for these 3 status.
  
Test your program thoroughly.

## What to submit:

- Copy your hash_set.h, test_hashset.cpp, and any other headers that you might have created to a directory called, *username_hashset_ex* where *username* is replaced with your Mt SAC username.
- Compress the directory and submit it before the deadline.