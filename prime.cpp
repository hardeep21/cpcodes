/* program to find prime numbers using sieve of eratosthenes
	time complex. O(n.log(log(n)))
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int MOD	= 1e9 + 7;

#define endl '\n'
#define loop(i,start,n,inc) for(int i = start; i < n; i+=inc)
#define tloop(i,n) for(int i = 0; i < n; ++i)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back

double tick(){static clock_t oldt,newt=clock();
			double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;
			return diff;}

bool check_prime(int n)
{
	loop(i, 2, int(pow(n, 0.5))+1, 1)
	{
		if(! (n%i))
			return false;
	}
	return true;
}


int main()
{	
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    // SIEVE OF ERATHO

    faster
    int t;
   	cin>>t; 
   	t++;
   	bool sieve[t];
   	//sieve initialized with 't' 1s
   	fill_n(sieve, t, true);
   	sieve[0] = sieve[1] = false;
   	loop(i,2,t,1)
   	{
   		if(sieve[i])
   		{
   			sieve[i] = check_prime(i);
   			// cout<<i<<' '<<sieve[i]<<endl;
   			if(sieve[i])
   			{
   				//to mark status of all multiples of that prime
   				loop(j, i, pow(t-1, 0.5)+1, 1)
   					sieve[i*j] = false;
   			}
   		}
   	}
    int counter = 0;
    tloop(i, t)
   		if(sieve[i])
   			counter++;
    cout<<counter;
	//cout<<endl<<"Execution time : "<<tick()<<endl;
    return 0;
}
