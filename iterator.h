#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

template <typename T>
class Iterator {
    private:
        Node<T> *current;
        stack<Node<T>*> forwardStack;

    public:
        Iterator(): current(nullptr) {}

        explicit Iterator(Node<T> *node){
            if(node){
                while(node){
                    forwardStack.push(node);
                    node=node->left;
                }
                current = forwardStack.top();
            }
            else current = nullptr;
        }

        Iterator<T>& operator=(const Iterator<T> other) {
            current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }


        Iterator<T>& operator++() {
            if(current && !forwardStack.empty()){
                if(current->right){
                    auto temp=current->right;
                    forwardStack.pop();
                    while(temp){
                        forwardStack.push(temp);
                        temp=temp->left;
                    }
                }
                else forwardStack.pop();

                if(!forwardStack.empty()) current = forwardStack.top();
                else current= nullptr;

                return *this;
            }
            throw out_of_range("Empty");
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            if(this->current) return this->current->data;
            throw out_of_range("Empty");
        }
};

#endif
