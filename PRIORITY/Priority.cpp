#include<iostream>
 
using namespace std;
 
int main()
{
    int burstTime[20],proc[20],Waiting[20],tat[20],Prior[20],i,j,n,pos,temp;
	float total=0,avg_tat,avg_wt;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    	for(i=0;i<n;i++)
    	{
        	cout<<"\nP["<<i+1<<"]\n";
        	cout<<"Burst Time:";
        	cin>>burstTime[i];
       	 	cout<<"Priority:";
        	cin>>Prior[i];
        	proc[i]=i+1;           
    	}
 
    	for(i=0;i<n;i++)
    	{
       		pos=i;
			
        	for(j=i+1;j<n;j++)
        	{
            	if(Prior[j]<Prior[pos])
                pos=j;
        	}
 
       		temp=Prior[i];
        	Prior[i]=Prior[pos];
        	Prior[pos]=temp;
 
        	temp=burstTime[i];
        	burstTime[i]=burstTime[pos];
        	burstTime[pos]=temp;
 
        	temp=proc[i];
        	proc[i]=proc[pos];
        	proc[pos]=temp;
    		}
 
    		Waiting[0]=0;           
 
    
    	for(i=1;i<n;i++)
    	{
       		Waiting[i]=0;
        	for(j=0;j<i;j++)
            	Waiting[i]+=burstTime[j];
 
        	total+=Waiting[i];
    	}
 
    	avg_wt=total/n;      
    	total=0;
 
    	cout<<"\nProcess\t\t    Burst Time    \tWaiting Time\tTurnaround Time";
		
    	for(i=0;i<n;i++)
    	{
        	tat[i]=burstTime[i]+Waiting[i];     
        	total+=tat[i];
        	cout<<"\nProcess["<<proc[i]<<"]\t\t  "<<burstTime[i]<<"\t\t    "<<Waiting[i]<<"\t\t\t"<<tat[i];
    	}
 	
    	avg_tat=total/n;     
		
    	cout<<"\n\nAverage Waiting Time = "<<avg_wt;
    	cout<<"\nAverage Turnaround Time = "<<avg_tat;
		cout<<"\n\n";
 
    return 0;
}

