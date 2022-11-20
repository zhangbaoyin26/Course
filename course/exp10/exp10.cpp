//
// Created by 张宝印 on 2022/11/15.
//

#include "iostream"

void Display(int R[], int n){
    for (int i= 0; i < n;++i)
        std::cout << R[i] << ' ';
    std::cout << std::endl;
}

inline void swap_int(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}


void BinInsertSort(int R[], int n) {
    int i, j, low, high, mid;
    int temp;
    for (i = 1; i < n; ++i) {
        if (R[i] < R[i - 1]) {}
        printf("  i = %d, inster %d, after sorted-> ", i, R[i]);
        Display(R, n);
        temp = R[i];
        low = 0, high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (temp < R[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i-1; j >= high+1; --j)
            R[j+1] = R[j];
        R[high+1] = temp;
    }
    std::cout << "AfterSorted-> ";
    Display(R, n);
}

void BubbleSort(int R[], int n){
    int i , j ;
    bool exchange;
    for (i = 0; i < n-1; ++i){
        exchange = false;
        for (j = n-1; j > i; --j){
            if (R[j] < R[j-1]){
                swap_int(R[j], R[j-1]);
                exchange = true;
            }
        }
        printf("  i = %d: palce_elem:%d, after placed-> ", i, R[i]);
        Display(R, n);
        if (!exchange) {
            std::cout << "AfterSorted: ";
            Display(R, n);
            return;
        }
    }
}

int main() {
    using namespace std;
    int arr[] = {6,8,7,9,0,1,3,2,4,5};
    cout << "before sort: " << endl;
    Display(arr, 10);
#if 0
    cout << "BinInsertSort" << endl;
    BinInsertSort(arr, 10);
#else
    cout << "BubbleSort" << endl;
    BubbleSort(arr, 10);
#endif
}
