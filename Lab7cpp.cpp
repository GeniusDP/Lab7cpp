#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdio.h>

using namespace std;

const int INF = 40;//interval of generated numbers

//quick sort
void qsort(int* left, int* right);

//func to print array
void printArray(int* left, int* right);

//func of input
void init(int** arr, int* len);

//delete element from array arr, (size of arr=len),
//from index = position
void delElement(int* arr, int* len, int position);

//find maximu element, which is not on position exceptPos
int findMax(int* arr, int len, int exceptPos);

//program which implements algorithm
void allWork(int* a, int* n);



//*************************************************************
//MAIN BLOCK
//*************************************************************
int main() {
    int n, * a;//size of array and pointer to array


    init(&a, &n);//inputing information
    printArray(a, a + n - 1);


    allWork(a, &n);


    cout << "\n" << "Max elements have been deleted:\n";
    printArray(a, a + n - 1);


    delete[] a;
    return 0;
}
//*************************************************************




void allWork(int* a, int* n) {
    int pos1, pos2;//positions of maximums
    //find positions of max elements
    pos1 = findMax(a, *n, *n);
    pos2 = findMax(a, *n, pos1);

    cout << "posMax1 = " << pos1 + 1 << "(value = " << a[pos1] << ")";
    cout << "\t" << "posMax2 = " << pos2 + 1 << "(value = " << a[pos2] << ")\n";


    if (pos1 > pos2)swap(pos1, pos2);


    //sortin the part of array between pos1 and pos2
    qsort(a + pos1 + 1, a + pos2);
    cout << "\n" << "Sorted array: \n";
    printArray(a, a + *n - 1);

    //delete elements
    delElement(a, n, pos1);
    delElement(a, n, pos2 - 1);//pos2-1 because of shift
}


int findMax(int* arr, int len, int exceptPos) {
    int ind = 0, maxValue = arr[0];
    for (int i = 0; i < len; i++)
        if (i != exceptPos && arr[i] >= maxValue) {
            maxValue = arr[i];
            ind = i;
        }
    return ind;
}


void delElement(int* arr, int* len, int position) {
    for (int i = position; i < *len - 1; i++)
        arr[i] = arr[i + 1];
    (*len)--;
}

void init(int** arr, int* len) {
    printf("Input len of array: ");
    cin >> *len;
    srand(time(NULL));

    int* p = new int[*len];
    for (int i = 0; i < *len; i++)
        p[i] = rand() % INF + 1;
    *arr = p;
}

void printArray(int* left, int* right) {
    int* i;
    cout << "This is our array:\n";
    for (i = left; i <= right; i++)
        cout << *i << " ";
    cout << endl;
}

void qsort(int* left, int* right) {
    if (right - left > 0) {
        int* i, * j;//pointers to elements
        i = left; j = right;
        bool dest = false;
        int stepj = -1;

        while (i != j) {
            if ((*i > * j) == dest) {
                j += stepj;
            }
            else {
                swap(*i, *j);
                dest = !dest;
                swap(i, j);
                stepj = -stepj;
            }
        }
        qsort(left, i - 1);
        qsort(i + 1, right);
    }
}
