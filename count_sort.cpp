#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
ifstream f("count_sort.in");
ofstream g("count_sort.out");
long long fr[100000005],v[100000005],n,MAX,maxi,mini,k,r;
void verificare()
{   for(int i=0;i<n-1;i++)
        if(v[i]>v[i+1])
        {   cout<<"Sortarea nu s-a efectuat corect"<<'\n';
            return;
        }
    cout<<"Sortarea s-a efectuat corect"<<'\n';
    return;
}
int Count_Sort()
{   f>>k;
    fr[k]++;
    maxi=mini=k;
    for(int i=1;i<n;i++)
    {   f>>k;
        if(k>=100000000)
        {

        }
        fr[k]++;
        if(mini>k)
            mini=k;
        if(maxi<k)
            maxi=k;
    }
    k=0;
    auto start = high_resolution_clock::now();
    for(long long i=mini;i<=maxi;i++)
        while(fr[i]!=0)
        {   g<<i<<' ';
            v[k]=i;
            k++;
            fr[i]--;
        }
    g<<'\n';
    k--;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Count Sort a durat "<<duration.count()<<" microsecunde" << endl;
    return k;
}

int main()
{   for(int t=1;t<=10;t++)
    {   f>>n>>MAX;
        cout<<"Testul "<<t<<'\n'<<"N = "<<n<<" si MAX = "<<MAX<<'\n';
        if(MAX>100000000)
        {   for(int i=0;i<n;i++)
                f>>k;
            cout<<"Algoritmul nu a putut sorta. Intervalul de valori este prea mare pentru a fi memorat"<<'\n';
        }
        else
        {   k = Count_Sort();
            verificare();
        }
    }
    return 0;
}
