// author : ahmed hussein ahmed mohammed saleh
// id : 20230015
// section number 24
// about : create my own set with linked list
// Assignment 2 task 1.1
// version 2: 12 November 2023
// file name : A2_24_20230015_pb4
//-----------------------------
// functions :
// 1- getSize
// 2- isEmpty
// 3- isExist
// 4- insert
// 5- at
// 6- find
// 7- print
// 8- pop_front
// 9- pop_pack
// 10- pop_element

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include<algorithm>


using namespace std;

template<class T>
class Set {
protected:
    struct Node {
        T element;
        Node *next;
    };

    int size;
    Node *head;
    Node *tail;

public:
    Set() : size(0), head(nullptr), tail(nullptr) {}

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return !size;
    }

    bool isExist(const T &value) {
        Node *cur = head;
        while (cur != nullptr) {
            if (cur->element == value) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void insert(T value) {
        if (isExist(value)) {
            return;
        }
        Node *newnode = new Node;
        newnode->element = value;
        if (isEmpty()) {
            newnode->next = nullptr;
            head = tail = newnode;
        } else if (head->element > value) {
            newnode->next = head;
            head = newnode;
        } else {
            Node *cur = head;
            while (cur->next != nullptr && cur->next->element < value) {
                cur = cur->next;
            }
            newnode->next = cur->next;
            cur->next = newnode;
            if (newnode->next == nullptr) {
                tail = newnode;
            }
        }
        size++;
    }

    T at(int pos) {
        if (pos == 0) {
            return head->element;
        } else if (pos == size - 1) {
            return tail->element;
        } else if (pos > 0 && pos < size - 1) {
            Node *newptr = new Node;
            Node *cur = head;
            for (int i = 0; i < pos; i++) {
                cur = cur->next;
            }
            return cur->element;

        } else {
            cout << "Invalid position!" << endl;
            return 0;
        }
    }



    int find(T ele) {
        Node *cur = head;
        int pos = 0;
        while (cur != NULL) {
            if (cur->element == ele)return pos;

            pos++;
            cur = cur->next;
        }
        return -1;
    }


    void print() {
        Node *printa = head;
        cout << "{ ";
        while (printa != nullptr) {
            cout << printa->element << " ";
            printa = printa->next;
        }
        cout << "}" << endl;
    }

    void pop_front() {
        if (!isEmpty()) {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        } else {
            cout << "is empty " << endl;
        }
    }

    void pop_back() {
        if (isEmpty()) {
            cout << "your set is empty !" << endl;
        } else if (size == 1) {
            delete head;
            head = tail = nullptr;
            size--;
        } else {
            Node *cur = head->next;
            Node *pre = head;
            while (cur != tail) {
                pre = cur;
                cur = cur->next;
            }
            tail = pre;
            delete cur;
            tail->next = nullptr;
            size--;
        }
    }

    void pop_element(T item) {
        if (isEmpty()) {
            cout << "is empty " << endl;
        } else if (item == head->element) {
            pop_front();
        } else if (tail->element == item) {
            pop_back();
        } else {
            Node *cur = head->next;
            Node *pre = head;
            while (cur != NULL) {

                if (item == cur->element) {
                    break;
                }
                pre = cur;
                cur = cur->next;
            }
            if (cur == NULL)cout << "the item not exist " << endl;
            else {
                pre->next = cur->next;
                delete cur;
                size--;
            }
        }

    }

    ~Set() {
        Node *current = head;
        while (current != nullptr) {
            Node *toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

int main() {

    // try our Set on the integers number , note that the first char is capital letter"Set"

    Set<int> set1;
    if (set1.isEmpty()) {
        cout << "The set now is empty" << endl<< endl;
    } else {
        cout << "The set have elements " << endl<<endl;
    }
    cout<< "after adding number "<<endl<<endl ;
    set1.insert(4);
    if (set1.isEmpty()) {
        cout << "The set now is empty" << endl<<endl;
    } else {
        cout << "The size is " << set1.getSize() << endl<<endl;
        cout << "the element is " << endl<<endl;
        set1.print();
    }
    if (set1.isExist(4)) {
        cout << "yes 4 is element in our set " << endl<<endl;
    } else {
        cout << "NO 4 is not element in our set " << endl<<endl;
    }

    if (set1.isExist(5)) {
        cout << "yes 5 is element in our set " << endl<<endl;
    } else {
        cout << "NO 5 is not element in our set " << endl<<endl;
    }
    set1.insert(4);
    set1.insert(4);
    set1.insert(0);
    set1.insert(6);
    set1.insert(2);
    set1.insert(10);
    set1.print();
    cout << "The size is " << set1.getSize() << endl<<endl;
    cout << "the element at position 2 is " << set1.at(2) << endl<<endl;
    cout << "the element at position 0 is " << set1.at(0) << endl<<endl;
    set1.pop_back();
    cout << "The size after delete element is " << set1.getSize() << endl<<endl;
    set1.print();
    cout << "we will delete element '4' " << endl<<endl;
    set1.pop_element(4);
    set1.print();

    cout<< "number 6 in position number " <<set1.find(6);

    // let make you try with char set  :-)

    cout << endl<<endl;
    cout << "------------------" << endl<<endl;

    Set<char> set2;
    cout << "Enter the number of element do you want to store in character set  " << endl;
    int n;
    cin >> n;
    cout << "enter Your elements " << endl;
    char a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        set2.insert(a);
    }
    cout << "your Set has size : " << set2.getSize() << endl;
    cout << "print element by for statement :  " << endl;
    for (int i = 0; i < set2.getSize(); i++) {
        cout << set2.at(i) << endl;
    }
    cout << "print elements by print function " << endl;
    set2.print();
    cout << "enter element to check if it in the set " << endl;
    char c;
    cin >> c;
    if (set2.isExist(c)) {
        cout << "Yes is exist " << endl;
    } else {
        cout << "NO it is not exist" << endl;
    }
    cout << "now we will compare two element , please enter two position to compare" << endl;
    int pos1, pos2;
    cin >> pos1 >> pos2;
    cout << "Your element at position " << pos1 << " is " << set2.at(pos1) << endl;
    cout << "Your element at position " << pos2 << " is " << set2.at(pos2) << endl;
    if (set2.at(pos1) > set2.at(pos2)) {
        cout << set2.at(pos1) << " > " << set2.at(pos2) << endl;
    } else {
        cout << set2.at(pos2) << " > " << set2.at(pos1) << endl;

    }
    cout<< "enter element to know were it is "<< endl ;
    char i ;
    cin>> i;
    if(set2.find(i) != -1) {
        cout << "your element " << i << " in index " << set2.find(i) << endl;
    }
    else {
        cout<< "we not have this element "<< endl;
    }
    cout << "Finally we will delete an element " << endl;
    set2.pop_back();
    cout << "Your size is " << set2.getSize() << endl;
    set2.print();
    cout << "now we will delete an element from front " << endl;
    set2.pop_front();
    cout << "Your size is " << set2.getSize() << endl;
    set2.print();
    cout << "enter element to delete " << endl;
    char g;
    cin >> g;
    set2.pop_element(g);
    cout << "Your size is " << set2.getSize() << endl;
    set2.print();
    cout << "Thank you :-) " << endl;
}
