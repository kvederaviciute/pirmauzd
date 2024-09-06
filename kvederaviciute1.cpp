#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>
#include <cmath>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct metai{
    int d,m,M[1000];
};
void Skaityti(int & n, metai A[]);
int Penktadieniai(int i,metai A[]);
int main()
{
int n,penkt;
metai A[20];
Skaityti(n,A);
ofstream out("U1rez.txt");
for(int i=0;i<n;i++)
{
    penkt=Penktadieniai(i,A);
    out<<penkt<<endl;
}
out.close();
return 0;
}
void Skaityti(int & n, metai A[])
{
    ifstream in("U1.txt");
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>A[i].d>>A[i].m;
        for(int j=0;j<A[i].m;j++)
        {
            in>>A[i].M[j];
        }
    }
    in.close();
}
int Penktadieniai(int i,metai A[])
{
    int B[100],sum=A[i].M[0],penkt=0,P[100],n=0;
    B[0]=13;
    for(int j=1;j<A[i].m;j++)
    {
        B[j]=sum+13;
        sum=sum+A[i].M[j];
    }
    for(int p=6;p<=A[i].d;p++)
    {
        if((p+1)%7==0)
        {
            P[n]=p;
            n++;
        }
    }
    for(int l=0;l<A[i].m;l++)
    {
        for(int k=0;k<n;k++)
        {
            if(B[l]==P[k])
            {
                penkt++;
            }
        }
    }
    return penkt;
}
