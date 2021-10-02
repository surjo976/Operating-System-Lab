#include<bits\stdc++.h>
using namespace std;

void findWatingTime(int processes[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
	
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
	
}
void findavgTime(int processes[], int n, int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	
	findWatingTime(processes,n,bt,wt);
	findTurnAroundTime(processes,n,bt,wt,tat);
	
	
	cout<<"Preocess \t" <<"Brust Time \t"<<"Waiting Time \t"<<"Turn around Time "<<endl;
	
	
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<"  "<<i+1<<"\t\t  "<<bt[i]<<"\t\t  "<<wt[i]<<"\t\t  "<<tat[i]<<endl;
	}
	
	cout<<"\nAverage waiing time \t = "<<(float)total_wt/(float)n;
	cout<<"\nAverage turn around time = " <<(float)total_tat/(float)n;
} 

int main()
{
	int processes[] ={1,2,3};
	int n=sizeof processes/ sizeof processes[0];
	
	int brust_time[]={10,5,8};
	
	findavgTime(processes,n,brust_time);
	
	
	
	
	return 0;
}
