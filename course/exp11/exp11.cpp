//
// Created by 张宝印 on 2022/11/17.
//

#include "iostream"

void Display(int R[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << R[i] << ' ';
    std::cout << std::endl;
}

inline void swap_int(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}


void disppart(int R[], int s, int t) {
    static int i = 1;
    int j;
    printf("  第%d次划分:", i);
    for (j = 0; j < s; j++)
        printf("   ");
    for (j = s; j <= t; j++)
        printf("%3d", R[j]);
    printf("\n");
    i++;
}

int partition(int R[], int s, int t) {
    int i = s, j = t;
    int tmp = R[i];
    while (i < j) {
        while (j > i && R[j] >= tmp)
            j--;
        if (j > i) {
            R[i] = R[j];
            i++;
        }
        while (i < j && R[i] <= tmp)
            i++;
        if (i < j) {
            R[j] = R[i];
            j--;
        }
    }
    R[i] = tmp;
    disppart(R, s, t);
    return i;
}

void QuickSort(int R[], int s, int t) {
    int i;
    if (s < t) {
        i = partition(R, s, t);
        QuickSort(R, s, i - 1);
        QuickSort(R, i + 1, t);
    }
}

void SelectSort(int R[], int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++)
            if (R[j] < R[k])
                k = j;
        if (k != i)
            swap_int(R[i], R[k]);
        printf("  i=%d, 选择关键字:%d, 排序结果为:", i, R[i]);
        Display(R, n);
    }
}


int main(){
    using namespace std;
    int arr[] = {6,8,7,9,0,1,3,2,4,5};
    cout << "排序前: ";
    Display(arr, 10);
#if 1
    cout << "QuickSort" << endl;
    QuickSort(arr, 0, 9);
    cout << "排序后：";
    Display(arr, 10);
#else
    cout << "SelectSort" << endl;
    SelectSort(arr, 10);
    cout << "排序后：";
    Display(arr, 10);
#endif
}