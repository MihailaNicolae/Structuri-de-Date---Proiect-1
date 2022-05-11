#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
ifstream f("shell_sort.in");
ofstream g("shell_sort.out");
long long n,maxi,v[100000005];
void verificare()
{   for(int i=0;i<n-1;i++)
        if(v[i]>v[i+1])
        {   cout<<"Sortarea nu s-a efectuat corect"<<'\n';
            return;
        }
    cout<<"Sortarea s-a efectuat corect"<<'\n';
    return;
}

void Shell_Sort()
{   int interval = n/2;
    while(interval!=0)
    {   for(int i=interval;i<n;i++)
        {   long long temp=v[i];
            int j=i;
            while(j>=interval && v[j-interval]>temp)
            {   v[j]=v[j-interval];
                j= j-interval;
            }
            v[j]=temp;
        }
        interval=interval/2;
    }
    return;
}

int main()
{   for(int t=1;t<=10;t++)
    {   f>>n>>maxi;
        cout<<"Testul "<<t<<'\n'<<"N = "<<n<<" si MAX = "<<maxi<<'\n';
        for(int i=0;i<n;i++)
            f>>v[i];
        auto start = high_resolution_clock::now();
        Shell_Sort();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<< "Shell Sort a durat "<<duration.count()<<" microsecunde"<< endl;
        verificare();
        for(int i=0;i<n;i++)
            g<<v[i]<<' ';
        g<<'\n';
    }
    return 0;
}
