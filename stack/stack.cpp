#include "Stack.h"
#include<iostream>
using namespace std;

bool Stack::is_empty()
{
	if(m_depth==0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

void Stack::push(int a)
{
	int *p2 = new int[m_depth+1];
	copy(p,m_depth,p2);
	p2[m_depth ] = a;
	delete[] p;
	p = p2;
	m_depth++;
}

int Stack::pop()
{
	int pop = 0;
	int *p2 = new int[m_depth - 1];
	copy(p, m_depth - 1, p2);
	pop = p[m_depth - 1];
	delete[]p;
	p = p2;
	m_depth--;
	return pop;
}

int Stack::depth()
{
	return m_depth;
}

void Stack::show()
{
	for (int i = m_depth-1; i >=0; i--) 
	{
		cout << p[i] <<endl;
	}
}

Stack::Stack()
{
	p = new int[0];
}

Stack::~Stack()
{
	delete[] p;
}

int main() 
{
	Stack a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.show();
	cout << a.pop() << endl;
	cout << "====" << endl;
	a.show();
	cout << endl;
}