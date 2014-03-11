#include<iostream>
#include<stdio.h>
using namespace std;

const int MAXH = 1000;

class Priority_Queue
{	
	public:
		int data[MAXH];
		int head;
		
		void fix_up()
		{	
			int temp = head;
			while(data[temp/2] < data[temp] && temp != 1)
			{
				swap(data[temp/2],data[temp]);
				temp /= 2;
			}
		}
		
		void fix_down(int temp)
		{
			if(2*temp+1 <= head)
			{
				if(data[temp] < data[2*temp] && data[2*temp+1] < data[2*temp])
				{
					swap(data[2*temp],data[temp]);
					fix_down(2*temp);
				}
				else if(data[temp] < data[2*temp+1])
				{	
					swap(data[2*temp+1],data[temp]);
					fix_down(2*temp+1);
				}
			}
			else if(2*temp <= head)
			{
				if(data[temp] < data[2*temp])
				{
					swap(data[temp],data[2*temp]); 
					fix_down(2*temp);
				}
			}	
		}

	public:

		Priority_Queue(){head = 0;}

		unsigned size(){return head;}
		bool empty(){return head == 0;}	
		int top(){return data[1];}

		void push(int el)
		{
			data[++head] = el; 
			fix_up();
		} 
		void pop()
		{
			swap(data[1],data[head--]);
			fix_down(1);
		}
};



int main()
{
	int n,m;
	Priority_Queue pq;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		pq.push(m);
	}
	for(int i=0;i<n;i++)pq.pop();
	for(int i=0;i<n;i++)
		printf("%d ",pq.data[i+1]);
	printf("\n");
	return 0;
}
