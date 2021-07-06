#include "fraction.h"
#include<iostream>
Fraction::Fraction(){}

Fraction::Fraction(int numerator, int denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
}

Fraction Fraction::operator+(Fraction b)
{
	int common_deno=this->common_denomintor(b);
	m_numerator = m_numerator * (common_deno / m_denominator);
	m_denominator = common_deno;
	b.m_numerator = b.m_numerator * (common_deno / b.m_denominator);
	b.m_denominator = common_deno;
	Fraction halfway=this->common_sum(b);
	halfway.m_denominator = halfway.m_denominator / halfway.gcd();
	halfway.m_numerator = halfway.m_numerator / halfway.gcd();
	return halfway;
}
void Fraction::show()
{
	std::cout << m_numerator << "/" << m_denominator;
}
int main() 
{
	Fraction a{ 1,2 };
	Fraction b{1,3};
	(a + b).show();
}