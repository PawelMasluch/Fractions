//#include<cstdio>
#include<iostream>


using namespace std;


int NWD(int a, int b)
{
	int tmp;
	
	while( b )
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	
	return a;
}

int NWW(int a, int b)
{
	return ( a / NWD(a,b) ) * b;
}


class Ulamek // klasa ulamkow nieujemnych
{
	private:
		int numerator; // licznik
		int denominator; // mianownik
	
	public:
		friend int NWD(int a, int b);
		
		friend int NWW(int a, int b);
		
		void simplify()
		{
			int nwd = NWD( (*this).numerator, (*this).denominator );
			
			(*this).numerator /= nwd;
			(*this).denominator /= nwd;
		}
		
		Ulamek(int __numerator = 0, int __denominator = 1) : numerator(__numerator), denominator(__denominator) // assumption: __denominator > 0 
		{
			(*this).simplify();
		}
		
		~Ulamek(){}
		
		Ulamek(const Ulamek &u)
		{
			(*this).numerator   = u.numerator;
			(*this).denominator = u.denominator; // assumption: u.denominator > 0
		}
		
		int get_numerator()
		{
			return (*this).numerator;
		}
		
		void set_numerator(int __numerator)
		{
			(*this).numerator = __numerator;
		}
		
		int get_denominator()
		{
			return (*this).denominator;
		}
		
		void set_denominator(int __denominator) // assumption: __denominator > 0
		{
			(*this).denominator = __denominator;
		}
		
		Ulamek operator +(Ulamek u)
		{
			Ulamek result;
			
			int den = NWW( (*this).denominator, u.denominator );
			
			int num = (*this).numerator * ( den / (*this).denominator )   +   u.numerator * ( den / u.denominator );
			
			
			result.numerator = num;
			result.denominator = den;
			
			
			result.simplify();
			
			
			return result;
		}
		
		Ulamek operator +=(Ulamek u)
		{
			Ulamek tmp = (*this) + u;
			(*this) = tmp;
			return (*this);
		}
		
		Ulamek operator *(Ulamek u)
		{
			Ulamek tmp = (*this);
			
			
			swap( tmp.numerator, u.numerator );
			tmp.simplify();
			  u.simplify();
			
			
			Ulamek result;
			
			
		    result.numerator   = tmp.numerator   * u.numerator;
			result.denominator = tmp.denominator * u.denominator;
			
			
			return result;
		}
		
		Ulamek operator *=(Ulamek u)
		{
			Ulamek tmp = (*this) * u;
			(*this) = tmp;
			return (*this);
		}
		
		Ulamek inverse()
		{
			Ulamek result;
			
			
			result.numerator = (*this).denominator;
			result.denominator = (*this).numerator;
			
			
			return result;
		}
		
		Ulamek operator /(Ulamek u)
		{
			return (*this) * u.inverse();
		}
		
		Ulamek operator /=(Ulamek u)
		{
			Ulamek tmp = (*this) / u;
			(*this) = tmp;
			return (*this);
		}
		
		bool operator == (Ulamek u)
		{
			return (   (*this).numerator == u.numerator  &&  (*this).denominator == u.denominator   );
		}
		
		void input()
		{
			cout << "Podaj licznik: ";
			cin >> (*this).numerator;
			
			cout << "Podaj mianownik: ";
			cin >> (*this).denominator; // assumption: (*this).denominator > 0
			
			cout << endl;
			
			
			(*this).simplify();
		}
		
		void output()
		{
			cout << "\nLicznik: " << (*this).numerator << ", Mianownik: " << (*this).denominator << "\n\n";
		}
};


int main()
{
	Ulamek u1, u2, u3;
	
	u1.input();
	u1.output();
	
	cout << "\n\n";
	
	u2.input();
	u2.output();
	
	cout << "\n\nOperacja 1:\n\n";
	
	u3 = u1 + u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 2:\n\n";
	
	u3 = u1 * u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 3:\n\n";
	
	u3 = u1 / u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 4:\n\n";
	
	u3 = u1;
	u3.output();
	u3 *= u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 5:\n\n";
	
	u3 = u1;
	u3.output();
	u3 /= u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 6:\n\n";
	
	u3 = u1;
	u3.output();
	u3 += u2;
	u3.output();
	u1.output();
	u2.output();
	
	cout << "\n\nOperacja 7:\n\n";
	
	if( u1 == u2 )
	{
		cout << "Ulamki u1, u2 sa rowne\n\n";
	}
	else
	{
		cout << "Ulamki u1, u2 nie sa rowne\n\n";
	}
	
	return 0;
}
