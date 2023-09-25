// Merge Sort
#include <iostream>
using namespace std;

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_array(int a[], int l, int m, int r);

int main() {
    int arr[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(arr, length);

    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

void merge_sort(int a[], int length) {
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r) {
    if (l < r) {
        int m = floor(l + r) / 2;    // midpoint

        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        merge_sorted_array(a, l, m, r);
    }
}

void merge_sorted_array(int a[], int l, int m, int r) {
    int left_length = m - l + 1;
    int right_length = r - m;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = a[l + i];

    for (j = 0; j < right_length; j++)
        temp_right[j] = a[m + 1 + j];

    // i for left arr, j for right arr
    for (i = 0, j = 0, k = l; k <= r; k++) {
        if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j])) {
            a[k] = temp_left[i];
            i++;
        } else {
            a[k] = temp_right[j];
            j++;
        }
    }
}
