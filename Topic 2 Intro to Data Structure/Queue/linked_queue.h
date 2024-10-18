#include <stdexcept>
#include"simple_container.h"
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename T>
class LinkedQueue : public SimpleContainer<T>{
    public: 
        LinkedQueue(){
            head=nullptr;
            tail=nullptr;
        }

        ~LinkedQueue() override{
            while(!empty()){
                remove();
            }
        }

        void add(const T& item)override{
            Node* ptr=new Node{item, nullptr};

            ((empty())? head:tail->next) = ptr;

            tail=ptr; 
        }

        void remove()override{
            if(empty()){
                throw std::logic_error("remove on empty queue");
            }

            Node* ptr{head};
            head=head->next;
            delete ptr;

            if(empty()) tail=nullptr; 
        }

        T peek() const override{
            if(empty()){
                throw std::logic_error("peek on empty queue");
            }
            return head->item;
        }

        bool empty() const override{
            return head==nullptr;
        }

     private:
        struct Node{
            T item;
            Node* next;
        };
        Node* tail; //back
        Node* head; //front
};


#endif /*LINKED_QUEUE_H*/