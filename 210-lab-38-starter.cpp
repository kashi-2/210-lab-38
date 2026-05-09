#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Function prototypes
void load_file(IntBinaryTree &tree);

int main() {
    IntBinaryTree tree;

    load_file(tree);

    cout << "\nBST Inorder Traversal:\n";
    tree.displayInOrder();

    return 0;
}

// Load records from file
void load_file(IntBinaryTree &tree) {
    ifstream fin("codes.txt");
    string code;

    if (!fin) {
        cout << "Error opening file.\n";
        return;
    }

    while (fin >> code) {
        tree.insertNode(code);
    }

    fin.close();

    cout << "Codes loaded into BST successfully.\n";
}
