#ifndef LIST
#define LIST

template<typename T>
struct List
{
    /** virtual destructor */
    virtual ~List() { }

    /** Add an item to the back of the list 
     * Param1: the item to add */
    virtual void add(const T&) = 0;

    /** Add an item to the list at a certain position
     * Param1: the item to add
     * Param2: the position (1 <= p <= n + 1) in which to insert the item 
     * Throws: std::out_of_range error if param1 is out of range */ 
    virtual void insert(const T&, size_t) = 0;
    
    /** Remove and return an item at a certain position 
     * Param1: the poisition of the item to remove and return (1 <= p <= n) */
    virtual T remove(size_t) = 0;

    /** Remove and return the item at the front of the list 
     * Param1: None */
    virtual T remove() = 0;

    /** Replace an item in the list at a certain position
     * Param1: The item to add to the list
     * Param2: The position of the item that gets replaced (1 <= p <= n)
     * Throws: std::out_of_range error if param1 is out of range */ 
    virtual void replace(const T&, size_t) = 0;

    /** Returns the item at a certain position but does not remove it
     * Param1: the position of the item to be returned (1 <= p <= n) 
     * Return: the item at the position
     * Throws: std::out_of_range error if param1 is out of range */ 
    virtual T at(size_t) const = 0;

    /** Check for containment of an item
     * Param1: the search term
     * Return: true if the list contains the item or false otherwise */
    virtual bool contains(const T&) const = 0;

    /** Returns the quantity of items stored in the list */
    virtual size_t size() const = 0;

    /** Test if the list is empty  
     * Return true if the list is empty or false otherwise */
    virtual bool empty() const = 0;

    /** Clear the list */
    virtual void clear() = 0;
};

#endif /* LIST */
