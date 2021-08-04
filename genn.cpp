#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B>
string to_string( pair<A, B> p);

template<typename A, typename B, typename C>
string to_string( tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>

string to_string( tuple< A, B, C, D> p);

string to_string (const string &s)
{
	return '"' + s + '"';

}

string to_string( const char * s)
{
	return to_string((string) s);
}

string to_string( bool b)
{
	return (b? "true":"false");
}


string to_string( vector<bool> v)
{
	bool first= true;
	string res = "{";
	for(int i=0 ; i < static_cast<int>(v.size()); i++)
	{
		if(! first)
		{
			res + = ",";
		}
		first= false;
		res+ = to_string(v[i]);
	}

	res+ = "}";
	return res;
}


template<size_t N>
string to_string(bitset<N> v)
{
	string res= "";
	for(size_t i=0;i<N;++i)
	{
		res+= static_cast<char> ('0' + v[i]);
	}

	return res;
}

template<typename A>
string to_string (A v)
{
	bool first= true;
	string res= "{";
	for(const auto & x:v)
	{
		if(!first)
		{
			res+= ", ";
		}
		first=false;
		res+= to_string(x);
	}

	res+= "}";
	return res;
}


template<typename A, typename B>
string to_string(pair<A,B> p)
{
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A, typename B, typename C>
string to_string(tuple<A,B,C> p)
{
	return "(" +to_string(get<0> (p))+ ", " + to_string(get<1> (p))+ ", " + to_string(get<2> (p)) + ")";

}

template<typename A, typename B, typename C ,typename D>

string to_string( tuple<A, B, C, D> p)
{
	return "(" +to_string(get<0> (p))+ ", " + to_string(get<1> (p)) + ", " + to_string(get<2> (p) ) + " , " + to_string(get<3> (p))+")";
}

void debug_out() {cerr <<endl;}

template<typename Head, typename ... Tail>

void debug_out(Head H, Tail .. T)
{
	cerr << " " << to_string(H);
	debug_out( T...);
}

#ifdef LOCL
#define debug(...) cerr << "[" <<# __VA_ARGS__<<"]";debug_out(__VA_ARGS__)
#else
#define debug(..) 42
#endif

template<typename T>
struct TPoint
{
	T x;
	T y;
	int id;
	TPoint() :x(0), y(0), id(-1) {}
	TPoint(const T & x_, const T & y_, int id_):x(x_),y(y_),id(id_){}
	static constexpr T eps= static_cast<T> (1e-9);
	inline TPoint operator + (const TPoint & rhs) const {return TPoint(x+rhs.x,y+rhs.y);}
	inline TPoint operator -(const TPoint & rhs) const{return TPoint(x-rhs.x,y-rhs.y);}
	inline TPoint operator *(const T &rhs) const{return TPoint(x*rhs, y*rhs);}
	inline TPoint operator / (const T &rhs) const {return TPoint(x/rhs, y/rhs);}
	friend T smul (const TPoint &a, const TPoint &b)
	{
		return a.x*b.x+ a.y*b.y;
	}

	friend T vmul (const TPoint &a, const TPoint &b)
	{
		return a.x*b.y-a.y*b.x;
	}


	inline T abs2() const
	{
		return x*x+y*y;
	}
	inline bool operator <(const T Point &rhs) const
	{
		return (y<rhs.y||(y==rhs.y&& x<rhs.x));
	}



