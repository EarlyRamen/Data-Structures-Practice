#ifndef BF653ED4_8E65_40F7_A092_6E10E0875A98
#define BF653ED4_8E65_40F7_A092_6E10E0875A98

// Type T should have relational operators overloaded

template<typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree() : root{nullptr} { }
        ~BinarySearchTree() { }

        const T* get(const T& item) const
        { 
            return get(root, item);
        }

        void add(const T& item)
        { 
            if(empty())
            {
                root = new BinaryTreeNode{item, nullptr, nullptr};
                return; 
            }
            add(root,item);
        }

        void remove(const T& item) 
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

        size_t getHeight() const
        {
            if(root==nullptr) return 0;

            return root->height(); 
        }

        bool empty() const { return root==nullptr;}
    
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

            size_t height() const
            {
                size_t leftHeight{};
                size_t rightHeight{};

                leftHeight = (lchild == nullptr) ? 0:lchild->height();
                rightHeight = (rchild == nullptr) ? 0:rchild->height();

                return 1 + std::max(leftHeight, rightHeight);
            }
        };

        BinaryTreeNode* root;

        const T* get(BinaryTreeNode* r, const T& item) const
        {
            BinaryTreeNode* node{find(root, item)};
        
            return (node==nullptr) ? nullptr : &node->item;
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

        void add(BinaryTreeNode* r, const T& item)
        {
            BinaryTreeNode** child { (item<=root->item) ? &root->lchild : &root->rchild};

            if(*child == nullptr)
                *child = new BinaryTreeNode{item, nullptr, nullptr};
            else
                add(*child, item);
        }

        bool isLeaf(const BinaryTreeNode* node) const
        {
            return node->lchild==nullptr && node->rchild==nullptr;
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


#endif /* BF653ED4_8E65_40F7_A092_6E10E0875A98 */
