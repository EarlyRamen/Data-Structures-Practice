#include <stdexcept>
#include "bucket_interface.h"

#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
class LinkListBucket:public Bucket<T>{
    public:
        LinkListBucket(){
            head=nullptr;
            count=0;
        }

        ~LinkListBucket(){while(!empty())remove();}

        //adds an item to the collection
        void add(const T& item){
            head=new Node{item,head};
            ++count;
        }

        //removes and returns an arbitrary item from the collection
        T remove(){
            if(empty()) throw std::logic_error("remove on empty bucket");
            T removedItem=head->item;

            Node *tmp{head};
            head=head->next;
            delete tmp;
            --count; 

            return removedItem;
        }
        
        //removes all of the items that match the argument
        bool remove(const T& item){
            if(empty()) throw std::logic_error("remove on empty bucket");

            bool removed{false};

            while(head!=nullptr&&head->item==item){
                remove();
                removed=true;
            }

            if(head==nullptr) return true;

            Node* ptr{head};

            while(ptr->next!=nullptr){
                if(ptr->next->item==item){
                    Node* tmp=ptr->next;
                    ptr->next=ptr->next->next;
                    delete tmp;
                    removed=true;
                    --count;
                }
                else{
                    ptr=ptr->next;
                }
            }
            return removed;  
        }

        //checks collection for membership
        bool contains(const T& item) const{
            Node* ptr{head};
            while(ptr!=nullptr){
                if(ptr->item == item){
                    return true;
                }
                ptr=ptr->next;
            }
            return false; 
        }

        //returns an array of items
        T* toArray() const{
            T* rtnArray=new T[count];
            Node* ptr{head};
            for (size_t i = 0; i < count; ++i){
                rtnArray[i]=ptr->item;
                ptr=ptr->next;
            }
            return rtnArray;
        }

        //empties the collection 
        void clear(){
            head=nullptr;
            count=0;
        }

        //returns the number of items
        size_t size() const{
            return count; 
        } 

        //retuns true if empty or false otherwise
        bool empty() const{
            return head == nullptr;
        }

    private:
        size_t count;
        struct Node{
            T item;
            Node* next; 
        };
        Node* head;  
};

#endif /*BUCKET_H"*/