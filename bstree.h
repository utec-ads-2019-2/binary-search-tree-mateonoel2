#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    size_t nodes;

    public:
        BSTree() : root(nullptr), nodes(0){};

        bool findNode(Node<T> *node, T data) {
            if (node) {
                if (data == node->data)
                    return true;
                else if (data < node->data)
                    return findNode(node->left, data);
                else if (data > node->data)
                    return findNode(node->right, data);
            }
            return false;
        }

        void insertNode(Node<T> *node, T data) {
            if (data > node->data) {
                if (node->right) insertNode(node->right, data);
                else{
                    node->right = new Node<T>();
                    node->right->data = data;
                }
            }
            else {
                if (node->left) insertNode(node->left, data);
                else{
                    node->left = new Node<T>();
                    node->left->data = data;
                }
            }
        }

        Node<T> *findMinDataNode(Node<T>* node) {
        while (node->left) node = node->left;
        return node;
        }

        Node<T>* removeNode(Node<T>* node, T data){
        if (!node) return node;
        else if (data > node->data) node->right = removeNode(node->right, data);
        else if (data < node->data) node->left = removeNode(node->left, data);
        else {
            if (!node->right) {
                auto temp = node->left;
                delete node;
                return temp;
            }
            else if (!node->left) {
                auto temp = node->right;
                delete node;
                return temp;
            }
            auto minDataNode = findMinDataNode(node->right);
            node->data = minDataNode->data;
            node->right = removeNode(node->right, minDataNode->data);
        }
        return node;
    }

        size_t findHeight(Node<T> *node) {
            if (node) {
                if (findHeight(node->right) > findHeight(node->left)) return findHeight(node->right) + 1;
                else return findHeight(node->left) + 1;
            }
            return 0;
        }

        void preOrder(Node<T> *node) {
            if (node) {
                cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        void inOrder(Node<T> *node) {
            if (node) {
                inOrder(node->left);
                cout << node->data << " ";
                inOrder(node->right);
            }
        }

        void postOrder(Node<T> *node) {
            if (node) {
                postOrder(node->left);
                postOrder(node->right);
                cout << node->data << " ";
            }
        }

        bool find(T data) {
            return findNode(root, data);
        }

        void insert(T data) {
            if (root)
                insertNode(root, data);
            else{
                root = new Node<T>();
                root->data = data;
            }
            nodes++;
        }

        bool remove(T data) {
            if (find(data) and root) {
                root = removeNode(root, data);
                --nodes;
                return true;
            }
            return false;
        }

        size_t size() {
            return nodes;
        }

        size_t height() {
            return findHeight(root) > 0 ? findHeight(root) - 1 : 0;
        }

        void traversePreOrder() {
            preOrder(root);
            cout << '\n';
        }

        void traverseInOrder() {
            inOrder(root);
            cout << '\n';
        }

        void traversePostOrder() {
            postOrder(root);
            cout << '\n';
        }

        Iterator<T> begin() {
            return Iterator<T> (root);
        }

        Iterator<T> end() {
            auto last = root;
            while(last->right){
                last = last->right;
            }
            return Iterator<T> (last->right);
        }

        ~BSTree() {
            root->killSelf();
        }
};

#endif
