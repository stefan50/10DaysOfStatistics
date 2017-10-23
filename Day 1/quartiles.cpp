//Programme that evaluates quartiles

#include <iostream>
#include <algorithm> 
#include <stdlib.h>
using namespace std;

float median(float* arr,int num);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    float* arr;
    arr = (float*)malloc(sizeof(float)*n);
    for(int i=0; i<n; i++)
    {
        cin >> *(arr+i);
    }
    sort(arr,arr+n);
    float q2 = median(arr,n);
    float q3;
    if(n%2 == 0)
    {
        n -= 2;
        q3 = median(arr+n/2+2,n/2);
    }
    else 
    {
        n -= 1; 
        q3 = median(arr+n/2+1,n/2);
    }
    float q1 = median(arr,n/2);
    cout << q1 << endl << q2 << endl << q3 << endl;
    free(arr);
    return 0;
}

float median(float* arr,int num)
{
    float to_return = 0;
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
