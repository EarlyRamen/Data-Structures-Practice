#include <stdexcept>

#ifndef D51229CF_0390_41F9_9D76_A57A8AC9816B
#define D51229CF_0390_41F9_9D76_A57A8AC9816B

//T must have the equality operator overloaded

template<typename T>
class BucketSet
{
    public:
        BucketSet(): count{}, head{nullptr} { }

        //when adding an item that is already a member, replace existing member
        void add(const T& item)
        { 
            Node* ptr(findItem(item));

            if(ptr==nullptr)
            {
                head = new Node{item, head};
                ++count;
            }
            else
            {
                ptr->item-item;
            }
        }

        //remove item if it exists
        void remove(const T& item)
        {
            Node* ptr = findItem(item);
            if(ptr != nullptr)
            {
                if(ptr != head)
                    ptr->item = head->item;
                ptr = head;
                head=head->next;
                delete ptr;

                --count;
            }
        }

        //get returns the item provided
        //throws exception if item does not exist
        T get(const T& item) const 
        { 
            Node* ptr = findItem(item);
            if(ptr==nullptr) throw std::logic_error("item does not exist");
            return ptr->item;
        }

        T getFirst()
        {
            if(empty()) throw std::logic_error("set is empty");
            return head->item;
        }

        //contains
        bool contains(const T& item) const
        {
            return findItem(item) != nullptr;
        }

        //empty
        bool empty() const {return count==0;}

        //size
        size_t size() const {return count;}

    private:
        struct Node
        {
            T item;
            Node* next;
        };

        Node* findItem(const T& item) const
        {
            Node* ptr{head};
            while(ptr!=nullptr)
            {
                if(item==ptr->item)
                    break; 
                ptr=ptr->next;
            }

            return ptr; 
        }

        size_t count;
        Node* head;
};


#endif /* D51229CF_0390_41F9_9D76_A57A8AC9816B */
