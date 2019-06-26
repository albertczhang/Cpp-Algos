#include <iostream>
#include <time.h>
#include <vector>
#include "Matrix.h"

using namespace std;


int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printList(vector<int> list);

void insert(vector<int> &list, int i, int item);

void remove(vector<int> &list, int i);

void swap(vector<int> &list, int i, int j);

void selectsort(vector<int> &list);

void insertsort(vector<int> &list);

void mergesort(int *list);

void quicksort(int *list);


int main() {
    vector<int> a = {2, 1, 3, 6, 2, 11, 6, 23, 0};
    printList(a);
    insertsort(a);
    printList(a);
    return 0;
}

void printList(vector<int> list) {
    cout << "[";
    for (int i = 0; i < list.size() - 1; i++) {
        cout << list[i] << ", ";
    }
    cout << list[list.size() - 1] << "]" << endl;
}

void insert(vector<int> &list, int i, int item) {
    list.insert(list.begin() + i, item);
}

void remove(vector<int> &list, int i) {
    list.erase(list.begin() + i);
}

void swap(vector<int> &list, int i, int j) {

}

void selectsort(vector<int> &list) {
    int size = list.size();
    for (int i = 0; i < size; i++) {
        int min = list[i];
        int index = i;
        for (int l = i + 1; l < size; l++) {
            if (list[l] < min) {
                min = list[l];
                index = l;
            }
        }
        int temp = list[index];
        list[index] = list[i];
        list[i] = temp;
        printList(list);
    }
}

void insertsort(vector<int> &list) {
    int size = list.size();
    for (int i = 0; i < size; i++) {
        int item = list[i];
        for (int l = i - 1; l >= 0; l--) {
            if (item > list[l]) {
                remove(list, i);
                insert(list, l + 1, item);
                printList(list);
                break;
            } else if (l == 0) {
                remove(list, i);
                insert(list, 0, item);
                printList(list);
                break;
            }
        }
    }
}