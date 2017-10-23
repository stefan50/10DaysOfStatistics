#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

float mean(float arr[],int num);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    float arr[n];
    float sum = 0; //sum = sum(xi - mean)
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    float mean_num = mean(arr,n);
    for(int i = 0; i < n; i++)
    {
        sum += pow((arr[i] - mean_num),2);
    }
    cout << fixed << setprecision(1) << sqrt((sum/n));
    return 0;
}

float mean(float arr[],int num)
{
    float mean_num; 
    for(int i = 0; i < num; i++)
    {
        mean_num += arr[i];
    }
    mean_num /= num;
    return mean_num;
}
