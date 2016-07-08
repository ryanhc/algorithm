#include <cstdio>

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void qsort(int a[], int start, int end) {
    if (start < end) {
        int pivot = a[start];
        int left = start;
        int right = end;

        while (left <= right) {
            while (a[left] <= pivot) {
                left++;
            }
            while (a[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(a, left, right);
                left++;
                right--;
            }
        }

        swap(a, right, start);
        qsort(a, start, right-1);
        qsort(a, left, end);
    }
}

int main(int argc, char *argv[]) {
    int data[] = {3,9,5,4,8,2,0,4,2,5};
    int len = sizeof(data)/sizeof(data[0]);

    qsort(data, 0, len-1);

    for(int i=0; i < len; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
