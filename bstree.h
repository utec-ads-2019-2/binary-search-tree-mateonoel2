#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    size_t nodes;
    bool der = false;
    bool izq = false;

    public:
        BSTree() : root(nullptr), nodes(0){};

        bool find(T data) {
            auto temp = root;
            if(root->data == data){
                return true;
            }
            while (true) {
                if (data > temp->data) temp = temp->right;
                else temp = temp->left;
                if (temp == nullptr){
                    return false;
                }
                if (temp->data == data) {
                    return true;
                }
            }
        }

        void insert(T data) {
            auto node = new Node<T>;
            node->data = data;
            if(root==nullptr){
                root = node;
            }
            else{
                auto temp = root;
                while(true){
                    if(node->data > temp->data){
                        if(temp->right == nullptr){
                            temp->right = node;
                            break;
                        }
                        else temp = temp->right;
                    }
                    else{
                        if(temp->left == nullptr){
                            temp->left = node;
                            break;
                        }
                        else temp = temp->left;
                    }
                }
            }
            nodes++;
        }

        void deleteNode(Node<T>* node, Node<T>* padre){
            if(node->right!=nullptr){
                swap(node->data, node->right->data);
                deleteNode(node->right, node);
                der = true;
                izq = false;
            }
            else if (node->left!=nullptr){
                swap(node->data, node->left->data);
                deleteNode(node->left, node);
                der = false;
                izq = true;
            }

            delete node;
            if (der) padre->right = nullptr;
            if (izq) padre->left = nullptr;
        }

        bool remove(T data) {
            nodes --;
            auto temp = root;
            if(root->data == data){
                deleteNode(temp, temp);
                return true;
            }
            while (true) {
                if (data > temp->data) temp = temp->right;
                else temp = temp->left;

                if(temp == nullptr){
                    return false;
                }
                if (temp->data == data) {
                    deleteNode(temp, temp);
                    return true;
                }
            }
        }

        size_t size() {
            return nodes;
        }

        size_t height() {
            unsigned int contador = 0;
            unsigned int max = 0;
            auto temp = root;
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            return Iterator<T> (root);
        }

        Iterator<T> end() {
            //return Iterator<T> (last);
        }

        ~BSTree() {
            root->killSelf();
        }
};

#endif
