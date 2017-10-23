//Programme that evaluates quartiles

#include <iostream>
#include <algorithm> 
#include <cmath>
#include <stdlib.h>
using namespace std;

int median(int* arr,int num);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int* arr;
    arr = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
    {
        cin >> *(arr+i);
    }
    sort(arr,arr+n);
    int q2 = median(arr,n);
    int* tmp = find(arr,arr+n,q2);
    n = floor(n/2);
    int q1 = median(arr,n);
    int q3 = median(tmp+1,n);
    cout << q1 << endl << q2 << endl << q3 << endl;
    free(arr);
    return 0;
}

int median(int* arr,int num)
{
    int to_return = 0;
    if(num % 2 != 0)
    {
        num /= 2;
        to_return = *(arr+num);
    }
    else
    {
        num /= 2;
        to_return = (*(arr+num) + *(arr+num-1))/2;
    }
    return to_return;
}
