#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
long long n,v[100000005],maxi,MAX,ord[100000005];
ifstream f("radix_sort.in");
ofstream g("radix_sort.out");
void verificare()
{   for(int i=0;i<n-1;i++)
        if(v[i]>v[i+1])
        {   cout<<"Sortarea nu s-a efectuat corect"<<'\n';
            return;
        }
    cout<<"Sortarea s-a efectuat corect"<<'\n';
    return;
}

void sortare(long long p)
{   int cifre[12];
    for(int i=0;i<=9;i++)
        cifre[i]=0;
    for(int i=0;i<n;i++)
        ord[i]=0;
    for(int i=0;i<n;i++)
        cifre[v[i]/p%10]++;
    for(int i=1;i<=9;i++)
        cifre[i]+=cifre[i-1];
    for(int i=n-1;i>=0;i--)
    {   ord[cifre[v[i]/p%10]-1]=v[i];
        cifre[v[i]/p%10]--;
    }
    for(int i=0;i<n;i++)
        v[i]=ord[i];
}

void Radix_Sort()
{   long long p=1;
    while(maxi/p!=0)
    {   sortare(p);
        p=p*10;
    }
}

int main()
{   for(int t=1;t<=10;t++)
    {   f>>n>>MAX;
        cout<<"Testul "<<t<<'\n'<<"N = "<<n<<" si MAX = "<<MAX<<'\n';
        f>>v[0];
        maxi=v[0];
        for(int i=1;i<n;i++)
        {   f>>v[i];
            if(v[i]>maxi)
                maxi=v[i];
        }
        auto start = high_resolution_clock::now();
        Radix_Sort();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Radix Sort a durat "<<duration.count()<<" microsecunde"<<endl;
        verificare();
        for(int i=0;i<n;i++)
            g<<v[i]<<' ';
        g<<'\n';
    }
    return 0;
}
