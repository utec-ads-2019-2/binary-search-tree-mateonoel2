#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();

    auto temp = new BSTree<int>();

    temp->insert(7);
    temp->insert(9);
    temp->insert(8);
    temp->insert(10);
    temp->insert(5);
    temp->insert(1);
    temp->insert(2);
    temp->insert(3);
    temp->insert(4);
    temp->insert(1);
    temp->insert(3);
    temp->insert(2);
    temp->insert(6);

    cout << "Is 6 in tree?: "<< temp->find(6)<<'\n';
    temp->remove(6);
    cout << "Is 6 in tree?: "<< temp->find(6)<<'\n';

    cout << "Tree's size: "<< temp->size()<<'\n';
    cout << "tree's height: "<<temp->height()<<'\n';

    cout<<"Pre order: ";
    temp->traversePreOrder();
    cout<<"In order: ";
    temp->traverseInOrder();
    cout<<"Post order: ";
    temp->traversePostOrder();

    cout<<"Iterator ++: ";
    for(auto it=temp->begin();it!=temp->end();++it){
        cout<<*it<<" ";
    }
    cout<<'\n';

    delete temp;
    return EXIT_SUCCESS;
}
