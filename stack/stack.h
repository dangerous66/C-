#pragma once
class Stack
{
private:
	int *p;
	int m_depth;
	void copy(int *__p,int depth_copy,int *p2)
	{
		for (int i = 0; i < depth_copy; i++) 
		{
			p2[i] = __p[i];
		}
	}
public:
	bool is_empty();
	void push(int a);
	int pop();
	int depth();
	void show();
	Stack();
	~Stack();
};

