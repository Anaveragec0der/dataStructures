//CODE CONTAINS FINDING DUPLICATES IN AN ARRAY 
//FIND MAX AND MIN IN SINGLE ITERATION IN AN ARRAY
//FINDING PAIR OF ELEMENTS IN THE ARRAY WITH SUM =K (a+b=k)


#include<iostream>
using namespace std;
int findmissing1(int *a ,int l)//FINDS MISSING IN THE ARRAY OF SEQUENCE OF SUM OF N NATURAL NUMBERS 
{
    int f=a[0];
    int le=a[l-1];
    int sum=0;
    for(int i=0;i<l;i++)
    {
        sum=sum+a[i];
    }
    int sum2;
    sum2=(le*(le+1))/2;
    int mis=sum2-sum;
    if(mis!=0)
    {
    return mis;
    }
    else
    {
        return 0;
    }
}
int findmissing2(int *a,int l)//WORKS FOR FINDING ANY MISSING NUMBER IN AN ARRAY STATRTING THE SEQUENCE FROM ANY
//GIVEN INDEX (THE ARRAY SHOULD BE SORTED AND SHOULD BE A ARITHMETIC PROGRESSION WITH DIFFERENCE 1)
{
    int diff=a[0];
    for(int i=0;i<l;i++)
    {
        if((a[i]-i)!=diff)
        {
            return i+diff;//(I+DIFF IS THE THE MISSING ELEMENT IN THE ARRAY )
            break;
        }
    }
    return -1;
}
void FindMultiMissing(int *a ,int len)//finds multiple as well as single missing elements in the array
//but has the complexity of O(n^2) thus we will using hash table method for finding missing elements 
{
    int diff=a[0];
    for(int i=0;i<len;i++)
    {
        if(a[i]-i!=diff)
        {
            while(diff<a[i]-i)
            {
                cout<<"missing element is "<<i+diff<<endl;
                diff++;
            }
        }
    }

}
int FindMax(int *a,int len)
{
    int max=a[0];
    for(int i=0;i<len;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
int FindMin(int *a,int len)
{
    int min=a[0];
    for(int i=0;i<len;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }
    return min;
}



//THE BEST OF ALL OF METHODS AS IT CAN FIND MISSING ELEMENTS IN AN UNSORTED ARRAY WITH TIME COMPLEXITY OF O(n)
//THE ONLY DISADVANTAGE IS THAT THE HASH TABLE CAN TAKE LOT OF SPACE AS IT HAS TOTAL ELEMENTS EQUAL TO THE 
//LARGEST ELEMENT IN THE ARRAY 1
void FindMissUsingHash(int *a ,int l,int h,int len)
{
    int *H=new int[h]{0};//creating an hash table dynamically and intitalizing it to zero;
    for(int i=0;i<len;i++)
    {
        H[a[i]]++;//increasing the value at index of hash table equal to value of array 1st by 1
    }
    for(int i=l;i<=h;i++)
    {
        if(H[i]==0)
        {
            cout<<"the missing element is "<<i<<endl;
        }
    }

}



//THIS METHOD CAN BE USED TO FIND DUPLICATES INSORTED AS WELL AS SORTED ARRAYS ***THE BEST METHOD FROM ALL OF THE 
//OTHER METHODS AS TIME COMPLEXITY IS O(n)

void DuplicatesInArray(int *a,int l,int h,int len)
{
    int *H=new int[h]{0};
    for(int i=0;i<len;i++)
    {
        H[a[i]]++;
    }
    for(int i=l;i<=h;i++)
    {
        if(H[i]>1)
        {
            cout<<"the missing element "<<i<<" is repeated "<<H[i]<<" times"<<endl;
        }
    }
  
}

void FindingPairWithSum(int *a,int len,int ma,int mi,int k)
{
    int *p=new int[ma]{0};
    for(int i=0;i<len;i++)
    {
        p[a[i]]++;
    }
    for(int i=mi;i<ma;i++)
    {
         if(p[k-a[i]]!=0)
         {
             cout<<"the pair is "<<a[i]<<" + "<<k-a[i]<<endl;
         }
        
    }
}

int main(){
    int arr[11]={1,2,3,4,5,6,7,8,9,10,11};
    int arr1[11]={6,7,8,9,10,11,13,14,15,16,17};
    int arr2[11]={6,7,8,9,11,12,15,16,17,19};
    int arr3[10]={3,7,4,9,12,6,1,11,2,10};
    int arr4[10]={6,8,9,9,7,9,5,6,12,1};
    int arr5[10]={6,3,8,10,16,7,5,9,2,14};
    //int missing=findmissing1(arr,11);
    // if( missing!=0)
    // {
    // cout<<"missing element is "<<missing<<endl;
    // }
    // else{
    //     cout<<"no missing element "<<endl;
    // }
    // int missing2=findmissing2(arr,11);
    // if(missing2!=-1)
    // {
    //     cout<<"missing element is "<<missing2<<endl;
    // }
    // else{
    //     cout<<"no missing element "<<endl;
    // }
    // FindMultiMissing(arr2,11);
    int maxm=FindMax(arr5,10);
    int minm=FindMin(arr5,10);
    //FindMissUsingHash(arr3,minm,maxm,10);
    //cout<<"max and min values in array are "<<maxm<<" "<<minm<<endl;
    //DuplicatesInArray(arr4,minm,maxm,10);
    FindingPairWithSum(arr5,10,maxm,minm,10);
    return 0;
}