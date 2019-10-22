#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


class BinarySearchTree
{
    public:
        BinarySearchTree();
        BinarySearchTree(int);
        void setRoot(int);
        void insert(int);
        void recursiveInsert(int);
        bool search(int);
        bool recursiveSearch(int);
        void display();
    private:
        int root;
        BinarySearchTree* left = nullptr;
        BinarySearchTree* right = nullptr;
};

#endif // BINARYSEARCHTREE_H
