#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
ifstream f("quick_sort.in");
ofstream g("quick_sort.out");
long long n,maxi,a[100000005];
void verificare()
{   for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
        {   cout<<"Sortarea nu s-a efectuat corect"<<'\n';
            return;
        }
    cout<<"Sortarea s-a efectuat corect"<<'\n';
    return;
}

int poz(int s, int d)
{   int i=s;
    int j=d;
    int di=0;
    int dj=1;
    while(i<j)
    {   if(a[i]>a[j])
        {   long long aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            di=1-di;
            dj=1-dj;
        }
        i=i+di;
        j=j-dj;
    }
    return j;
}

void qs(int s, int d)
{   if(s<d)
    {   int p=poz(s,d);
        qs(s,p-1);
        qs(p+1, d);
    }
}

int main()
{   for(int t=1;t<=7;t++)
    {   f>>n>>maxi;
        cout<<"Testul "<<t<<'\n'<<"N = "<<n<<" si MAX = "<<maxi<<'\n';
        for(int i=0;i<n;i++)
           f>>a[i];
        auto start = high_resolution_clock::now();
        qs(0,n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Quick Sort a durat "<<duration.count()<<" microsecunde"<< endl;
        verificare();
        for(int i=0;i<n;i++)
            g<<a[i]<<' ';
        g<<'\n';
        cout<<'\n';
    }
    cout<<"Pentru testele 8,9,10 algoritmul nu poate sorta. Sunt prea multe elemente si se umple stiva"<<'\n';
    return 0;
}
