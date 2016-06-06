
// Based in Wilkkipedia and improved for Rodrigo

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cstdlib>

int tamOriginal;
int percent;

using namespace std;

 void print(int a[], int tam) {
	 for (int i = 0; i < tam; i++) {
	 	
	 	if(i!=tam-1){
	 		cout << a[i] << "-";
	 		continue;
		 }
		 
		 cout << a[i];
	 		
	 }
	 cout << endl;
 }

 int partition(int a[], int p, int r) {
 	
	 int x = a[r];
	 int j = p - 1;
	 for (int i = p; i < r; i++) {
	
		 if (x <= a[i]) {
			 j = j + 1;
			 int temp = a[j];
			 a[j] = a[i];
			 a[i] = temp;
		 }
	 }
	 
	 a[r] = a[j + 1];
	 a[j + 1] = x;
	
	 return (j + 1);
	 
 }

 void quickSort(int a[], int p, int r){
 	
	 if (p < r) {
	 	
		 int q = partition(a, p, r);
		 
		 percent++;
		 
		 system("cls");
		 cout << "----------------------------------------------------------------------" << endl;
		 cout << "                        Progress>> " << ((float)percent/(float)(tamOriginal-1))*100 << "%" << endl;
		 cout << "----------------------------------------------------------------------" << endl;
		 
		 quickSort(a, p, q - 1);
		 quickSort(a, q + 1, r);
		 
	 }
	 
 }
 
 int numberRandom(){
 	
 	srand(time(NULL));
 	
 	return rand()%100;
 	
 }
 
 int pot(int b, int e){
 	
 	if(e<2)
 		return b;
 	else
 		return b*pot(b, e-1);
 	
 }
 
 void completeRandom(int *a, int tam){
 	
 	int i;
 	
 	for(i=0; i<tam; i++){
 		
 		a[i] = numberRandom()+(i);
 		
	 }
 	
 }

 int  main() {

	 int *a, tam;
	 int total;
	 
	 tam = pot(2, 15);
	 
	 a = (int *)malloc(tam*sizeof(int));
	 
	 completeRandom(a, tam);
	 
	 cout << "List mounted" << endl;
	 
	 cout << "Click anything for order!" << endl;
	 
	 getchar();
	 
	 if(a==NULL){
	 	cout << "Stack overflow" << endl;
	 	exit(1);
	 }
	 
	 cout << endl;
	 
	 print(a, tam);
	 
	 getchar();
	 
	 tamOriginal = tam;
	 percent = 0;
	 
	 cout << "Ordering..." << endl;
	 quickSort(a, 0, tam-1);
	 
	 print(a, tam);
	 cout << endl;
	 getchar();
	 
	 return 0;
 } 
