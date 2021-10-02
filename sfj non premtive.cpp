#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	cout<<"Enter number of process : ";
	cin>>n;
	cout<<"\n Enter brust time : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<" : ";
		cin>>bt[i];
		p[i]=i+1;
	}
	//sort
	for(i=0;i<n;i++)
	{
		
		pos =i;
		for(j=i+1;j<n;j++)
		{
			if(bt[j]<bt[pos])
			{
				pos=j;
			}
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
			
		}
		total+=wt[i];
	}
	avg_wt=(float)total/n;
	total=0;
	
	cout<<"\n process \tBrust time \twating time \tTurnAround Time \n";
	for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        cout<<"\n p"<<p[i]<<" \t\t "<<bt[i]<<" \t\t "<<wt[i]<<" \t\t "<<tat[i]<<endl;
        
    }
    avg_tat=(float)total/n;
    cout<<"\n Average Wating time =  " <<fixed <<setprecision(4)<<avg_wt<<endl;
    cout<<"Aveage Turnaround Time =  "<<fixed <<setprecision(4) <<avg_tat<<endl;
	
	
	
	
	return 0;
}
