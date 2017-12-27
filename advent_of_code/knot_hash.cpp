// It's a circular linked list
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class CircularLinkedList {
    private:
        struct cnode {
            int value;
            int index;
            cnode *next;
        }*head;
    
    public:
        CircularLinkedList() {
            head = NULL;
        }

        void insert(cnode *root, int value, int index) {
            if(root == NULL) {
                root = new cnode();
                root->value = value;
                root->index = index;
                root->next = NULL;
                cout << "1\n";
            }
            else {
                cnode *temp = root;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                cnode *temp2 = new cnode();
                temp2->value = value;
                temp2->index = index;
                temp->next = temp2;
                temp2->next = root;
                cout << "else\n";
            }
        }

        void insert_helper(int value, int index) {
            insert(head, value, index);
        }

        void display() {
            map<int, bool> mp;
            cnode *root = head;
            while(root != NULL) {
                cout << root->value << " ";
                if(mp.find(root->index) !=  mp.end()) { mp[root->index] = true; }
                else { break; }
            }
            cout << endl;
        }
};


int main() {
    CircularLinkedList c;
    c.insert_helper(3, 0);
    c.insert_helper(4, 1);
    c.insert_helper(5, 2);
    c.display();
    return 0;
}
