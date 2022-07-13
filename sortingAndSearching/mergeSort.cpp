#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r){
	int n1=mid-l+1;
	int n2=r-mid;
	vector<int> a(n1,0);
	vector<int> b(n2,0);
    cout<<endl;
	for(int i=0;i<n1;i++){
		a[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
		b[i]=arr[mid+1+i];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(a[i]<=b[j]){
			arr[k]=a[i];
			k++;
			i++;
		}
		else{
			arr[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<n1){
		arr[k]=a[i];
		k++;
		i++;
	}
	while(j<n2){
		arr[k]=b[j];
		k++;
		j++;
	}
}

void mergeSorting(vector<int> &arr, int l, int r){
	if(l<r){
		int mid=(l+r)/2;
		mergeSorting(arr,l,mid);
		mergeSorting(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void mergeSort(vector<int> &arr) {
    mergeSorting(arr,0,arr.size());
}

int main(){
    vector<int> arr {10,4,23,1};
    mergeSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}