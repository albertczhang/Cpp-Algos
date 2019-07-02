#include <iostream>
#include <time.h>
#include <vector>
#include <queue>
#include "Matrix.h"


using namespace std;


int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printList(vector<int> list);

void insert(vector<int> &list, int i, int item);

int remove(vector<int> &list, int i);

void swap(vector<int> &list, int i, int j);

void selectsort(vector<int> &list);

void insertsort(vector<int> &list);

void mergesort(vector<int> &list);

vector<int> merge(vector<int> l1, vector<int> l2);

void quicksort(vector<int> &list, int start=-1, int end=-1);


int main() {
    vector<int> a = {1, 34, 2, -1, 22, 0, 1, 1, 8, 12, 67, 11};

    vector<int> b = a;
    printList(a);
    mergesort(a);
    printList(a);
    printList(b);
    quicksort(b);
    printList(b);
    return 0;
}

void printList(vector<int> list) {
    cout << "[";
    if (!list.empty()) {
        for (int i = 0; i < list.size() - 1; i++) {
            cout << list[i] << ", ";
        }
        cout << list[list.size() - 1] << "]" << endl;
    } else {
        cout << "]" << endl;
    }
}

void insert(vector<int> &list, int i, int item) {
    list.insert(list.begin() + i, item);
}

int remove(vector<int> &list, int i) {
    int x = list[i];
    list.erase(list.begin() + i);
    return x;
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

void mergesort(vector<int> &list) {
    int size = list.size();
    queue<vector<int>> to_merge;

    for (int i = 0; i < size; i++) {
        vector<int> chunk;
        int x = remove(list, 0);
        insert(chunk, 0, x);
        to_merge.push(chunk);
    }
    vector<int> l1, l2, l3;
    while (to_merge.size() > 1) {
        l1 = to_merge.front();
        to_merge.pop();
        l2 = to_merge.front();
        to_merge.pop();

        l3 = merge(l1, l2);
        to_merge.push(l3);
    }


    list = to_merge.front();
}

vector<int> merge(vector<int> l1, vector<int> l2) {
    vector<int> merged;
    int x, y;
    while (!l1.empty() && !l2.empty()) {
        x = l1.front(); y = l2.front();
        if (x < y) {
            merged.push_back(x);
            remove(l1, 0);
        } else {
            merged.push_back(y);
            remove(l2, 0);
        }
    }
    if (l1.empty()) {
        int n = l2.size();
        for (int i = 0; i < n; i++) {
            merged.push_back(l2.front());
            remove(l2, 0);
        }
    } else if (l2.empty()) {
        int n = l1.size();
        for (int i = 0; i < n; i++) {
            merged.push_back(l1.front());
            remove(l1, 0);
        }
    }

    return merged;
}

void quicksort(vector<int> &list, int start, int end) {
    if (start == -1 && end == -1) {
        start = 0; end = list.size() - 1;
    }
    if (start == end) {
        return;
    }
    else if (start + 1 == end) {
        if (list[start] > list[end]) {
            int temp = list[start];
            list[start] = list[end];
            list[end] = temp;
        }
        return;
    }
    int left = start;
    int right = end;
    int pivot = list[left];
    start++;
    while (start <= end) {
        while (list[start] <= pivot || list[end] >= pivot) {
            if (list[start] <= pivot)
                start++;
            if (list[end] >= pivot)
                end--;
        }
        if (start > end) {
            list[left] = list[end];
            list[end] = pivot;
        }
        else {
            int temp = list[start];
            list[start] = list[end];
            list[end] = temp;
        }
    }
    quicksort(list, left, end - 1);
    quicksort(list, end + 1, right);
}