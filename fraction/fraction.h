#pragma once
int min(int a,int b) 
{
	if (a < b) 
	{
		return a;
	}
	else
	{
		return b;
	}
}
int max(int a, int b) 
{
	if (a > b) 
	{
		return a;
	}
	else 
	{
		return b;
	}
}
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
	int common_denomintor(Fraction b) 
	{
		for (int i = max(m_denominator,b.m_denominator); i <= m_denominator * b.m_denominator; i++) 
		{
			if (i%m_denominator == 0 && i%b.m_denominator == 0) 
			{
				return i;
			}
		}
	}
	int gcd() 
	{
		for (int i = min(m_denominator,m_numerator); i >=1; i--) 
		{
			if (m_denominator%i == 0 && m_numerator%i == 0) 
			{
				return i;
			}
		}
	}
	Fraction common_sum(Fraction b) 
	{
		return Fraction(m_numerator+b.m_numerator,b.m_denominator);
	}
public:
	Fraction();
	Fraction(int numerator,int denominator);
	Fraction operator+(Fraction b);
	void show();
};


