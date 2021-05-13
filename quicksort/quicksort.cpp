#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int part(int *L, int p, int q) {
   int j = p-1;
   int pivo = L[q];
   for (int i=p; i < q; i++) {
       if (L[i] < pivo) {
          j++;
          int x = L[i];
          L[i] = L[j];
          L[j] = x;
       }
   }
   int r = j+1;
   int x = L[r];
   L[r] = L[q];
   L[q] = x;   
   return r;
}

void quicksort(int *L, int p, int q) {
   if (p < q) {
      int r = part(L, p, q);
      quicksort(L, p, r-1);
      quicksort(L, r+1, q);
   }
}
void copiarVet(int *L, int t, int *vet) {
   for (int i = 0; i < t; i++){
      vet[i] = L[i];
   }
}
int main() {
   ofstream stream("file.md", ofstream::out);
   int n = 5, cont = 1;
   clock_t  tempoCalculo[2];
   double tempo = 0;
   int L[] = {2, -1, 11, 5, 6}, vet[n];
   quicksort(L, 0, n-1);
   do {
   for (int i = 0; i < 1000; i++){
   	copiarVet(L, n, vet);
      tempoCalculo[0] = clock();
      quicksort(vet, 0, n-1);
      tempoCalculo[1] = clock();
      tempo += (double)(tempoCalculo[1] - tempoCalculo[0]) /CLOCKS_PER_SEC;
   }
   if (cont % 10 == 0){
      stream << cont << " " << tempo*1000 << endl;
   }
   cont++;
  } while (next_permutation(L,L+n));
   stream.close();
}
