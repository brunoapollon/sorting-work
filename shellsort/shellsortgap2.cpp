#include <iostream>
#include<math.h>
using namespace std;
template <typename T>
void shellsort(T L[], int t, int gap) {
    do{
        for (int i = gap; i < t; i++){
            int num = L[i], j;
            for (j = i; j >= gap && L[j-gap] > num; j-=gap){ 
                L[j] = L[j - gap];
            }
            L[j] = num;
        }
        if (gap == 1){
            return;
        }
    } while (gap = gap / 2);
}
int maxGap(int tam){
    int g = 1, gap;
    do{
        gap = pow(2, g) - 1;
        g++;
    }while((pow(2, g) - 1) < tam);
    return gap;
}
int main() {
    int n = 16, g = 1; 
    int L[] = { 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1};
        cout << "Vetor desordenado GAP 2: " << endl;
    for (int i = 0; i < n; i++){
        cout << L[i] << " ";
    }
    cout << endl;
    int gap = maxGap(n);
    shellsort(L, n, gap);
    cout << "Vetor ordenado GAP 2: " << endl;
    for (int i = 0; i < n; i++){
        cout << L[i] << " ";
    }
    cout << endl;
}
