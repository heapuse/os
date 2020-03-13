#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(int argc,char ** argv)
{
    int sum = 0;
    if(argv[1] == NULL)
        cout<<"[Child] : The sum of given array is 0"<<endl;
        return 0;
    char *data = strtok(argv[1],",");
    vector<int> arr;
    while(data != NULL)
    {
        sum += atoi(data);
        data = strtok(NULL,",");
    }
    cout<<"[Child] : The sum of given array is "<<sum<<endl; 
    return 0;
}