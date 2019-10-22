#include "BinarySearchTree.h"
#include <climits>
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = INT_MAX;
}

BinarySearchTree::BinarySearchTree(int Root){
    root = Root;
}

void BinarySearchTree::setRoot(int n){
    root = n;
}

void BinarySearchTree::insert(int n){
    BinarySearchTree* ptr = this;
    while(true){
        if(n < ptr->root){
            if(ptr->left != nullptr)
                ptr = ptr->left;
            else{
                ptr->left = new BinarySearchTree(n);
                return;
            }
        }
        else{
            if(ptr->right != nullptr)
                ptr = ptr->right;
            else{
                ptr->right = new BinarySearchTree(n);
                return;
            }
        }
    }
}

void BinarySearchTree::recursiveInsert(int n){
    if(n < root){
        if(left == nullptr)
            left = new BinarySearchTree(n);
        else
            left->recursiveInsert(n);
    }
    else{
        if(right == nullptr)
            right = new BinarySearchTree(n);
        else
            right->recursiveInsert(n);
    }
}

bool BinarySearchTree::search(int n){
    BinarySearchTree* ptr = this;
    while(n != ptr->root){
        if(n < ptr->root){
            if(ptr->left == nullptr)
                return false;
            else
                ptr = ptr->left;
        }
        else{
            if(ptr->right == nullptr)
                return false;
            else
                ptr = ptr->right;
        }
    }
    return true;
}

bool BinarySearchTree::recursiveSearch(int n){
    if(n == root) return true;

    if(n < root && left != nullptr)
        return left->recursiveSearch(n);
    else if(n > root && right != nullptr)
        return right->recursiveSearch(n);
    else
        return false;
}

void BinarySearchTree::display(){
    if(left != nullptr)
        left->display();
    cout << root << " ";
    if(right != nullptr)
        right->display();
}
