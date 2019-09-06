#include <iostream>
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
	LARGE_INTEGER freq;
  	QueryPerformanceFrequency(&freq);
  	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
void ordenshell (int a[], int N){
	int i,j,h;  
	int v;
	for(h=1; h<=N/9; h= 3*h+1);
	for(; h>0; h/=3){
		for(i=h;i<N; i+=1){
			v=a[i]; 
			j=i;
            while(j >=h && a[j-h] > v){
				a[j] = a[j-h]; 
				j-=h;
			}
            a[j]=v;
        }		
	}
	//for(int i=0;i<N;i++){
	//	cout<<a[i]<<" ";
	//}
	//cout<<endl;
	
}

int main(int argc, char** argv) {
	for(int n=10;n<=500;n=n+10){
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=1000*(i+1);
		}
		
		LARGE_INTEGER t_ini, t_fin;
		double secs;
		QueryPerformanceCounter(&t_ini);
		
		ordenshell(a,n);
		
		QueryPerformanceCounter(&t_fin);
		secs = performancecounter_diff(&t_fin, &t_ini);
		printf("%.16g \n", secs * 1000.0);	
	}
	return 0;
}
