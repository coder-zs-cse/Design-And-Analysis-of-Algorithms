#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <time.h>
using namespace std;

void merge4(long int arr[],long int l,long int ml,long int mid,long int mr,long int r){
    long int s1=ml-l+1;
    long int s2=mid-ml;
    long int s3=mr-mid+1;
    long int s4=r-mr;

    int *B=new int[s1];
    int *C=new int[s2];
    int *D=new int[s3];
    int *E=new int[s4];

    for(long int i=0;i<s1;i++){
        B[i]=arr[l+i];
    }
    for(long int j=0;j<s2;j++){
        C[j]=arr[ml+1+j];
    }
    for(long int k=0;k<s3;k++){
        D[k]=arr[mid+1+k];
    }
    for(long int l=0;l<s4;l++){
        E[l]=arr[mr+1+l];
    }
    long int i=0;
    long int j=0;
    long int k=0;
    long int l1=0;
    long int m=0;
    while((i<s1)&&(j<s2)&&(k<s3)&&(l1<s4)){
        if((B[i]<=C[j])&&(B[i]<=D[k])&&(B[i]<=E[l1])){
            arr[m]=B[i];
            i++;
            
        }
        else if((C[j]<=B[i])&&(C[j]<=D[k])&&(C[j]<=E[l1])){
            arr[m]=C[j];
            j++;
            
        }
        else if((D[k]<=B[i])&&(D[k]<=C[j])&&(D[k]<=E[l1])){
            arr[m]=D[k];
            k++;
            
        }
        else{
            arr[m]=E[l1];
            l1++;
            
        }
        m++;
    }
    while((i<s1)&&(j<s2)&&(k<s3)){
        if((B[i]<=C[j])&&(B[i]<=D[k])){
            arr[m]=B[i];
            i++;
        }
        else if((C[j]<=B[i])&&(C[j]<=D[k])){
            arr[m]=C[j];
            j++;
        }
        else{
            arr[m]=D[k];
            k++;
        }
        m++;
    }
    while((j<s2)&&(k<s3)&&(l1<s4)){
        if((C[j]<=D[k])&&(C[j]<=E[l1])){
            arr[m]=C[j];
            j++;
        }
        else if((D[k]<=C[j])&&(D[k]<=E[l1])){
            arr[m]=D[k];
            k++;
        }
        else{
            arr[m]=E[l1];
            l1++;
        }
        m++;
    }
    while((i<s1)&&(k<s3)&&(l1<s4)){
        if((B[i]<=D[k])&&(B[i]<=E[l1])){
            arr[m]=B[i];
            i++;
        }
        else if((D[k]<=B[i])&&(D[k]<=E[l1])){
            arr[m]=D[k];
            k++;        
        }
        else{
            arr[m]=E[l1];
            l1++;
        }
        m++;
    }
    while((i<s1)&&(j<s2)&&(l1<s4)){
        if((B[i]<=C[j])&&(B[i]<=E[l1])){
            arr[m]=B[i];
            i++;
        }
        else if((C[j]<=B[i])&&(C[j]<=E[l1])){
            arr[m]=C[j];
            j++;
        }
        else{
            arr[m]=E[l1];
            l1++;
        }
        m++;
    }
    while(i<s1){
        arr[m]=B[i];
        i++;
        m++;
    }
    while(j<s2){
        arr[m]=C[j];
        j++;
        m++;
    }
    while(k<s3){
        arr[m]=D[k];
        k++;
        m++;
    }
    while(l1<s4){
        arr[m]=E[l1];
        l1++;
        m++;
    }
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;
}

void merge_sort4(long int arr[], long int l, long int r) {
    if (l >= r) {
        return;
    }

    long int m = l+ (r-l)/2;
    long int mid_l= l + (m-l)/2;
    long int mid_r= m+1 + (r-m-1)/2;

    
    merge_sort4(arr, l, mid_l);
    merge_sort4(arr, mid_l+1, m);
    merge_sort4(arr,m+1,mid_r);
    merge_sort4(arr,mid_r+1,r);
    merge4(arr, l,mid_l, m,mid_r, r);
}

void merge2(long int arr[], long int l, long int m,long int r) {
    long int n1 = m - l + 1;
    long int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (long int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (long int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    long int i = 0;
    long int j = 0;
    long int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort2(long int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    long int m = l + (r - l) / 2;
    merge_sort2(arr, l, m);
    merge_sort2(arr, m+1, r);
    merge2(arr, l, m, r);
}

int main(){
    long int n = 10;
	int it = 0;

	double tim1[10], tim2[10];

	cout<<"A_size,Merge-2,Merge-4\n";

	
		long int a[n], b[n];
		for (int i = 0; i <n; i++) {
			long int no =  i;
			b[n-i-1] = no;
		}

        for(int i=0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;
        merge_sort4(b,0,n-1);
        for(int i=0;i<n;i++) cout<<b[i]<<" ";
        cout<<endl;

    return 0;

}