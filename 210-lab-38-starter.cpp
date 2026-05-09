#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

// Function prototypes
void load_file(IntBinaryTree &tree);
void menu(IntBinaryTree &tree);

int main() {
    IntBinaryTree tree;

    load_file(tree);

    menu(tree);

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

// Menu
void menu(IntBinaryTree &tree) {
    int choice;

    string code;
    string newCode;

    do {
        cout << "\n=========================\n";
        cout << "BST MENU\n";
        cout << "=========================\n";
        cout << "[1] Display BST\n";
        cout << "[2] Search code\n";
        cout << "[3] Add code\n";
        cout << "[4] Delete code\n";
        cout << "[5] Modify code\n";
        cout << "[0] Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nBST Inorder Traversal:\n";
            tree.displayInOrder();
            break;

        case 2:
            cout << "Enter code to search: ";
            cin >> code;

            if (tree.searchNode(code))
                cout << "Code found.\n";
            else
                cout << "Code not found.\n";

            break;

        case 3:
            cout << "Enter code to add: ";
            cin >> code;

            tree.insertNode(code);

            cout << "Code added.\n";

            break;

        case 4:
            cout << "Enter code to delete: ";
            cin >> code;

            tree.remove(code);

            cout << "Code deleted.\n";

            break;

        case 5:
            cout << "Enter old code: ";
            cin >> code;

            if (tree.searchNode(code)) {

                tree.remove(code);

                cout << "Enter new code: ";
                cin >> newCode;

                tree.insertNode(newCode);

                cout << "Code modified.\n";
            }

            else {
                cout << "Original code not found.\n";
            }

            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}