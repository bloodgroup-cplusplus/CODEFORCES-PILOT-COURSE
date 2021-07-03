#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin>>s;
	s+="$";
	// now n is the length of string with dollar sign
	int n=s.size();
	vector<int> p(n); //contains strings
	vector<int> c(n);// contains equivalance classes


	vector<pair<char,char>> a(n);

	for(int i=0;i<n;++i) a[i]={s[i],i};

	sort(a.begin(),a.end());


	for(int i=0;i<n;++i) p[i]=a[i].second;

	c[p[0]]=0;

	for(int i=1;i<n;++i)
	{
		if(a[i].first== a[i-1].first)
		{
			c[p[i]]=c[p[i-1]];
		}

		else
		{
			c[p[i]]=c[p[i-1]]+1;
		}

	}

	//make transitions 
	//untile 2n*k less than n
	//
	int k=0;
	while((1<<k)<n)
	{
		vector<pair<pair<int,int> ,int>> a(n);
		for(int i=0;i<n;++i)
		{
			a[i]={{c[i],c[i+(1<<k)%n]},i};
		}

		sort (a.begin(),a.end());
		for(int i=0;i<n;++i)
		{
			p[i]=a[i].second;
		}

		c[p[0]]=0;

		for(int i=1;i<n;++i)
		{
			if(a[i].first==a[i-1].first)
			{
				c[p[i]]=c[p[i-1]];
			}

			else
			{
				c[p[i]]=c[p[i-1]]+1;
			}
		}
		k++;
	}


	for(int i=0;i<n;++i)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;


	return 0;
}

