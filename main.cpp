#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();

    auto temp = new BSTree<int>();

    temp->insert(1);
    temp->insert(2);
    temp->insert(3);
    temp->insert(4);
    temp->insert(1);
    temp->insert(3);
    temp->insert(2);
    temp->insert(5);

    cout << temp->find(5)<<'\n';
    temp->remove(1);
    cout << temp->find(5)<<'\n';


    return EXIT_SUCCESS;
}
