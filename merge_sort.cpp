#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
ifstream f("merge_sort.in");
ofstream g("merge_sort.out");
long long v[100000005],n,a[100000005],maxi;
void verificare()
{   for(int i=0;i<n-1;i++)
        if(v[i]>v[i+1])
        {   cout<<"Sortarea nu s-a efectuat corect"<<'\n';
            return;
        }
    cout<<"Sortarea s-a efectuat corect"<<'\n';
    return;
}

void merge_sort(int st,int dr)
{   if(st<dr)
    {   int mij=(st+dr)/2;
        merge_sort(st,mij);
        merge_sort(mij+1,dr);
        int i=st;
        int j=mij+1;
        int k =0;
        while(i<=mij && j<=dr)
        {   if(v[i]<=v[j])
            {   k++;
                a[k]=v[i];
                i++;
            }
            else
            {   k++;
                a[k]=v[j];
                j++;
            }
        }
        while(i<=mij)
        {   k++;
            a[k]=v[i];
            i++;
        }
        while(j<=dr)
        {   k++;
            a[k]=v[j];
            j++;
        }
        j=1;
        for(i=st;i<=dr;i++)
        {   v[i]=a[j];
            j++;
        }
    }
}
int main()
{   for(int t=1;t<=10;t++)
    {   f>>n>>maxi;
        cout<<"Testul "<<t<<'\n'<<"N = "<<n<<" si MAX = "<<maxi<<'\n';
        for(int i=0;i<n;i++)
            f>>v[i];
        auto start = high_resolution_clock::now();
        merge_sort(0,n-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Merge Sort a durat "<<duration.count()<<" microsecunde"<<endl;
        verificare();
        for(int i=0;i<n;i++)
            g<<v[i]<<' ';
        g<<'\n';
    }
    return 0;
}
