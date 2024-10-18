#include <stdexcept>
#include <sstream>

#include "collection.h"

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack:public Collection<T>{
    public:
        Stack():head{nullptr}{};

        ~Stack(){
            while(!empty())remove();
        }

        void add(const T& item) override{
            head=new Node{item,head};
        }

        void remove() override{
            if(empty()) throw std::logic_error("remove on empty stack");
            Node *tmp{head};
            head=head->next;
            head=*head.next;
            delete tmp;
        }

        T get() const override{
            if(empty()) throw std::logic_error("get on empty stack");
            return head->item;
        }

        bool empty() const override{
            return head==nullptr;
        }

        std::string print() const override{
            return print(head);
        }

    private:
        struct Node{
            T item;
            Node* next; 
        };

        std::string print(const Node* ptr) const{
            std::stringstream ss;

            if(ptr==nullptr){return "";}

            ss<<(ptr->item)<<" "<<print(ptr->next);

            return ss.str();
        }

        Node* head;     
};


#endif /*STACK_H*/