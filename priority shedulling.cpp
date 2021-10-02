#include<bits\stdc++.h>
using namespace std;
int main()
{
	int n,i,bt[20],p[20],wt[20],tat[20],pr[20],j,total=0,pos,temp,avg_wt,avg_tat;;
	
	cout<<"Enter number of process : ";
	cin>>n;
	cout<<"\n ****Enter number of Brust time and Priority ****\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n p["<<i+1<<"]  : \t";
		cout<<"\nBrust Time : ";
		cin>>bt[i];
		cout<<"Priority :";
		cin>>pr[i];
		p[i]=i+1;
	}
	//sorting brust time,priority and process
	for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    wt[0]=0;    //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
    
    cout<<" \n  Process \t\t Brust Time \t\t Waiting Time \t\t TurnAround Time ";
    for(i=0;i<n;i++)
    {
    	tat[i]=bt[i]+wt[i];
    	total+=tat[i];
    	cout<<"\n  p["<<p[i]<<"]\t\t\t "<<bt[i]<<"\t\t\t "<<wt[i]<<"\t\t\t "<<tat[i];
	}
	avg_tat=total/n;
	
	cout<<"\n\nAverage Wating Time : "<<fixed<<setprecision(5)<<avg_wt<<endl;
	cout<<"\n\nAverage TurnAround Time : "<<fixed<<setprecision(5)<<avg_tat<<endl;
	
	
return 0;
}
