#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={97,4,6,78,89,32,21,14,23};
    int length=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+length);
    cout<<"second largest element in the array is "<<arr[length-2]<<endl;
     return 0;
}