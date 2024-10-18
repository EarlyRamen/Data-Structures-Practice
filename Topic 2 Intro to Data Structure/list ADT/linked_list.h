#include <stdexcept>

#include "list.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template<typename T>
class LinkedList : public List<T>
{
    public:
        LinkedList()
        {
            head,tail=nullptr;
            count=0;
        }

        ~LinkedList() override
        {
            clear();
        }

        void add(const T& item) override
        {
            Node* ptr=new Node{nullptr, item};

            ((empty())? head:tail->next) = ptr;

            tail=ptr; 
            ++count;
        }

        void insert(const T& item, size_t pos) override
        {   
            if(pos<1 || pos>count) throw std::out_of_range("insert on a out of range position");

            Node* tmp=head;
            Node* ptr=new Node{nullptr, item};

            for (size_t i = 1; i <= count; ++i)
            {
                if(i==pos-1)
                {   
                    ptr->next=tmp->next;
                    tmp->next=ptr;
                }
                tmp=tmp->next;
            }
            ++count;
        }

        T remove(size_t pos) override
        {
            if(pos<1 || pos>count) throw std::out_of_range("remove on a out of range position");

            T rtnItem=at(pos);

            Node* tmp=head;
            for (size_t i = 1; i <= count; ++i)
            {
                if(i==pos-1)
                {   
                    Node* removedNode=tmp->next;
                    tmp->next=tmp->next->next;
                    delete removedNode;
                    break;
                }
                tmp=tmp->next;
            }
            --count;
            return rtnItem;
        }

        T remove() override
        {   
            if(empty()) throw std::logic_error("remove on empty list");

            T rtnItem=head->item;
            Node* tmp=head;
            head=head->next;
            delete tmp;
            --count;
            return rtnItem;
        }

        void replace(const T& item, size_t pos) override
        {
            if(pos<1 || pos>count) throw std::out_of_range("replace on a out of range position");

            Node* tmp=head;
            for (size_t i = 1; i <= count; ++i)
            {
                if(i==pos)
                {   
                    tmp->item=item;
                    break;
                }
                tmp=tmp->next;
            }
        }

        T at(size_t pos) const override
        {
            if(pos<1 || pos>count) throw std::out_of_range("at on a out of range position");

            Node* tmp=head;
            for (size_t i = 1; i <= count; ++i)
            {
                if(i==pos) return tmp->item;
                tmp=tmp->next;
            }
        }

        bool contains(const T& item) const override
        {   
            if(empty()) return false;

            Node* tmp=head;
            while(tmp!=nullptr)
            {
                if(tmp->item==item) return true;
                tmp=tmp->next;
            }
            return false;
        }

        size_t size() const override
        {
            return count;
        }

        bool empty() const override
        {
            return count==0;
        }

        void clear() override
        {
            while(!empty()) remove();
            
        }

    private:
        struct Node
        {
            Node* next;
            T item;
        };
        
        Node* head;
        Node* tail;
        size_t count;
};

#endif /* LINKED_LIST */
