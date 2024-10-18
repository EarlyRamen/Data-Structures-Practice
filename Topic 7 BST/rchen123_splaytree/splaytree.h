#ifndef CDCDDC9F_7954_4E48_8C15_3708DDE257AA
#define CDCDDC9F_7954_4E48_8C15_3708DDE257AA
#include <cstddef>

// Type T should have relational operators overloaded

template<typename T>
class SplayTree
{
    public:
        SplayTree() : root{nullptr}, count{0} { }
        ~SplayTree() { }

        void add(const T& item)
        {
            if(empty())
            {
                root = new BinaryTreeNode{item, nullptr, nullptr, nullptr};
                return; 
            }
            add(root,item);
            splay(find(root, item));
            ++count;
        }

        void remove(const T& item)
        {
            BinaryTreeNode* neighbor;
            BinaryTreeNode* node = find(root,item);
            if(node==nullptr || node==root) return;

            BinaryTreeNode* parent = node->parent;

            neighbor = (node==parent->lchild) ? parent->rchild : parent->lchild;

            if(neighbor==nullptr) helpRemove(item);
            else
            {
                helpRemove(item);
                splay(neighbor);
            }
            
            --count;
        }

        bool contains(const T& item) 
        {
            BinaryTreeNode* node = find(root, item);
            if (node==nullptr) return false;

            splay(node);
            return true;
        }

        size_t size() const {return count;}

        bool empty() const {return count==0;}
    
        T* preOrder() const
        {
            T* array {new T[count]};
            preOrder(root, array, 0);
            return array;
        }

        T* inOrder() const
        {
            T* array {new T[count]};
            inOrder(root, array, 0);
            return array;
        }

        T* postOrder() const
        {
            T* array {new T[count]};
            postOrder(root, array, 0);
            return array;
        }

        T* levelOrder() const
        {
            //TODO
            //I tried my best to implement this but had no clue how to do it 
        }

        T get()
        {
            return root->item;
        }

    private:
        struct BinaryTreeNode
        {
            T item;
            BinaryTreeNode* parent;
            BinaryTreeNode* lchild;
            BinaryTreeNode* rchild;

            bool isLeaf()
            {
                return lchild==nullptr && rchild==nullptr;
            }
        };
        BinaryTreeNode* root;
        size_t count;

        void splay(BinaryTreeNode* x)
        {
            if (x==root) return;
            if (x==root->lchild || x==root->rchild)
            {
                if (x==root->lchild) zig(root);
                else zag(root);
                return;
            }

            BinaryTreeNode* p = x->parent;
            BinaryTreeNode* g = p->parent;

            if (x==p->lchild && p==g->lchild)
            {
                zig(g);
                splay(zig(p));
            }

            if (x==p->rchild && p==g->rchild)
            {
                zag(g);
                splay(zag(p));
            }

            if (x==p->rchild && p==g->lchild)
            {
                zag(p);
                splay(zig(g));
            }

            if (x==p->lchild && p==g->rchild)
            {
                zig(p);
                splay(zag(g));
            }
        }

        BinaryTreeNode* zig(BinaryTreeNode* root)
        {
            BinaryTreeNode* newRoot = root->lchild;
            root->lchild = newRoot->rchild;
            if(newRoot->rchild!=nullptr)
                newRoot->rchild->parent = root;

            newRoot->parent = root->parent;

            newRoot->rchild = root;
            root->parent = newRoot;
            return newRoot;
        }

        BinaryTreeNode* zag(BinaryTreeNode* root)
        {
            BinaryTreeNode* newRoot = root->rchild;

            root->rchild = newRoot->lchild;
            if(newRoot->lchild!=nullptr)
                newRoot->lchild->parent = root;

            newRoot->parent = root->parent;

            newRoot->lchild = root;
            root->parent = newRoot;
            return newRoot; 
        }

        void preOrder(BinaryTreeNode* node, T* array, size_t index) const
        {
            if(node==nullptr) return;

            array[index++]=node->item;
            preOrder(node->lchild, array, index);
            preOrder(node->rchild, array, index);
        }

        void inOrder(BinaryTreeNode* node, T* array, size_t index) const
        {
            if(node==nullptr) return;

            inOrder(node->lchild, array, index);
            array[index++]=node->item;
            inOrder(node->rchild, array, index);
        }

        void postOrder(BinaryTreeNode* node, T* array, size_t index) const
        {
            postOrder(node->lchild, array, index);
            postOrder(node->rchild, array, index);
            array[index++]=node->item;
        }

        void levelOrder(BinaryTreeNode* node, T* array, size_t index)
        {
            //TODO
            //I tried my best to implement this but had no clue how to do it 
        }

        BinaryTreeNode* find(BinaryTreeNode* root, const T& item) const
        {
            if (root==nullptr) return nullptr;
            if(item < root->item) return find(root->lchild, item);
            if(item > root->item) return find(root->rchild,item);

            return root;       
        }

        BinaryTreeNode* findRightMost(BinaryTreeNode* root)
        {
            if(root==nullptr) return root;
            if(root->rchild==nullptr) return root;
            return findRightMost(root->rchild);
        }

        void add(BinaryTreeNode* root, const T& item)
        {
            BinaryTreeNode** child { (item<=root->item) ? &root->lchild : &root->rchild};

            if(*child == nullptr)
                *child = new BinaryTreeNode{item, root, nullptr, nullptr};
            else
                add(*child, item);
        }

        bool isLeaf(const BinaryTreeNode* node) const
        {
            return node->lchild==nullptr && node->rchild==nullptr;
        }

        void helpRemove(const T& item)
        {
            BinaryTreeNode* targetNode {find(root, item)};
            BinaryTreeNode* replaceNode{};

            if(targetNode==nullptr) return;

            if(targetNode->isLeaf()||targetNode->lchild==nullptr)
            {
                deleteNode(targetNode);
            }
            else
            {
                replaceNode = findRightMost(targetNode->lchild);
                targetNode->item=replaceNode->item;
                deleteNode(replaceNode);
            }   
        }

        void deleteNode(BinaryTreeNode* node)
        {
            BinaryTreeNode* parent{node->parent};
            BinaryTreeNode* child{};

            if(node==root)
            {
                if (node->isLeaf())
                    root=nullptr;
                else
                    root = (node->lchild==nullptr) ? node->rchild : node->lchild;
            }
            else if(node->isLeaf())
            {
                if(parent->lchild==node) parent->lchild = nullptr;
                else node->parent->rchild = nullptr; 
                delete node;
            }
            else
            {
                child = (node->lchild=nullptr) ? node->rchild : node->lchild;
                ((parent->lchild==node) ? parent->lchild : parent->rchild) = child;
                child->parent = parent;
            }

            delete node;
        }
};


#endif /* CDCDDC9F_7954_4E48_8C15_3708DDE257AA */
