#include<stdio.h> 
int g_pid[11],g_at[11],g_bt[11],g_rt[11],g_end,i,k,g_lrgst,g_gnt[25],uniq;
   int rmn=0,g,g_time,s_wait=0,s_turnaround=0;
   void input() 
   {  
    printf("\t\t******************SHORTEST EXUCUTION TIME FIRST***********************\nEnter no of Processes :");
	scanf("%d",&g);
    for(k=0;k<g;k++) 
	{
	 printf("Give u r input for PROCESS ID:-- %d : ",k+1); 
	 scanf("%d",&g_pid[k]);     
	 printf("Give input of their ARRIVAL TIME :-- %d : ",k+1); 
     scanf("%d",&g_at[k]);  
	 if(g_at[k]>10) 
    {    
     printf("plz enter the process arrival with less than 10 value\n"); 
     scanf("%d",&g_at[k]); 
    }   
	 printf("Give the input of their BURST TIME:-- %d : ",k+1);  
	 scanf("%d",&g_bt[k]);
	 if(g_bt[k]>10) 
    {
	 printf("plz enter the process burst with less than 10 value\n");  
	 scanf("%d",&g_bt[k]);    
    }
														   
     g_rt[k]=g_bt[k]; 
	  }     
 
 
}  
void show()
 {
      printf("\n\nProcess\t||Turnaround Time|| Waiting Time\n\n");
	  g_rt[9]=9999; 
	  for(g_time=0;rmn!=g;g_time++) 
	  {
	   
	   g_lrgst=9;
	    for(i=0;i<g;i++)
		 {
    if(g_at[i]<=g_time && g_rt[i]<g_rt[g_lrgst] && g_rt[i]>0)
		   
   {
    g_gnt[g_time]=i; g_lrgst=i;
			 
	}
			 
	}
	g_rt[g_lrgst]--;
	if(g_rt[g_lrgst]==0) 
	{
	 rmn++;
	 g_end=g_time+1;
     printf("\nP[%d]\t||\t%d\t||\t%d",g_lrgst+1,g_end-g_at[g_lrgst],g_end-g_bt[g_lrgst]-g_at[g_lrgst]); 
	 s_wait+=g_end-g_bt[g_lrgst]-g_at[g_lrgst];
	 s_turnaround+=g_end-g_at[g_lrgst];
					 
					 } }
					  
 
} 
void show1()
 {
   printf("\nAverage   Waiting Time = %f\n",s_wait*1.0/g);
    printf("\nAverage Turnaround  Time = %f\n\n",s_turnaround*1.0/5);
	 for(i=1;i<=g_time;i++)
	  {
	    if(i<g_time)
		
		
		 
 {  
  printf("%d->P%d \n",i,g_gnt[i]+1);
 }
  else 
{
	
 printf("%d->P%d \n",i,uniq); 
}
  }
 }
 int main()
 {
 input();
 show();
 show1();
 }
