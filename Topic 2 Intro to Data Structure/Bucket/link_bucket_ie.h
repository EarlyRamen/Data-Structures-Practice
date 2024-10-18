#include <stdexcept>
#include "bucket_interface.h"

#ifndef LINK_BUCKET_IE_H
#define LINK_BUCKET_IE_H

template<typename T>
class LinkedBucket : public Bucket<T>{
    public:
        LinkedBucket():
            count{},
            head{}{ }

        ~LinkedBucket(){clear();}

        void add(const T& item){
            head=new Node{item,head};
            ++count;
        }

        T remove(){
            T item;

            if(empty()) throw std::logic_error("remove on empty bucket");

            removeHeadNode();

            --count;
            return item;
        }
        
        
        bool remove(const T& item){
            Node* it=head;
            bool found{};

            if(empty()) return found; 

            while(it!=nullptr){
                if(it->item==item){
                    found=true;
                    --count;

                    if (it==head){
                        it=it->next;
                        removeHeadNode();
                        continue;
                    }
                    
                it->item=head->item;
                removeHeadNode();
                }

                it=it->next;
            }
            //use it as iterator
            //if we find a node with item that equals item
            //copy head-> to deadnode->item
            //remove head

            return found;
        }


        bool contains(const T& item) const{
            Node* it=head;
            while(it!=nullptr){
                if(it->item==item) return true;
                it=it->next;
            }
            return false;
        }

       
        T* toArray(){
            T* rtnArray{new T[count]};
            Node* it=head;

            for (size_t i = 0; i < count; ++i){
                rtnArray[i]=it->item;
                it=it->next;
            }

            return rtnArray; 
        } 

        void clear(){
            while(head!=nullptr){
                removeHeadNode();
            }
        }

        size_t size() const {return count;}

        bool empty() const {return count==0;}
    
    private:
        struct Node{
            T item;
            Node* next;
        };

        Node* head;
        size_t count;

        void removeHeadNode(){
            Node* tmp{head};
            head=head->next;
            delete tmp;
        }
};

#endif /*"LINK_BUCKET_IE_H"*/