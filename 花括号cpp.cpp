#include<iostream>
#include<fstream>
#include<vector>
#define MAX 512
using namespace std;
struct re
{
	bool full;
	int length;
};
re full(char buffer_area[],int size=1024) 
{
	for (int i=0;i<size;i++)
	{
		if (buffer_area[i] =='\0'&&i!=1023) 
		{
			re place{ false,i };
			return place;
		}
	}
	re is_full{true,size};
	return is_full;
}
int main() 
{
	vector<char>code;
	ifstream file_open;
	char file_name[MAX];
	cin.getline( file_name,MAX);
	file_open.open(file_name);
	if (file_open.is_open()==false)
	{
		cout << "please check the name or try later";
	}
	char buffer_area[1024]{};
	while (file_open.good()) 
	{
		file_open.getline(buffer_area,1024);
		if (full(buffer_area).full) 
		{
			for (int i = 0; i < 1024; i++) 
			{
				code.push_back(buffer_area[i]);
			}
		}
		else 
		{
			re a = full(buffer_area, 1024);
			for (int i = 0; i < a.length; i++) 
			{
				code.push_back(buffer_area[i]);
			}
		}
	}
	int is_right = 0;
	for (char x : code) 
	{
		switch (x)
		{
		case '{':
			is_right++;
			break;
		case'}':
			is_right--;
		}
	}
	if (is_right == 0) 
	{
		cout << "It's right";
	}
	else 
	{
		cout << "It's wrong";
	}
}