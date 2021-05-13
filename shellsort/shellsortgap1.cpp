#include <iostream>
#include<math.h>
using namespace std;
template <typename T>
void shellsort(T L[], int t, int g) {
    int gap, i, inter = 0; // c0
    do{
        gap = 2*floor(t/pow(2, (g+1))) + 1;
        for (i = gap; i < t; i++){ 
            int num = L[i], j;
            for (j = i; j >= gap && L[j-gap] > num; j-=gap){
                L[j] = L[j - gap];
            }
            L[j] = num; 
        }
        g++;
    } while (gap != 1); 
    
}
int main() {
    int n = 16; 
    int L[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Vetor desordenado GAP 1: " << endl;
    for (int i = 0; i < n; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    shellsort(L, n, 1);
    cout << "Vetor ordenado GAP 1: " << endl;
    for (int i = 0; i < n; i++){
        cout << L[i] << " ";
    }
    cout << endl;
}
