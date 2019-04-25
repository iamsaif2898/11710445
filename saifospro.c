#include<stdio.h>
#define N 10  

typedef struct
{
//pr_id is process id
//pr_prio is process priority
//btime is process burst time
//atime is process arrival time
      int pr_id, atime,btime,pr_prio;
      int p, ready;
}proces_structure;
int Queue(int t1)
{
      if(t1==0 || t1==1 || t1==2 || t1==3)
      {
            return 1;
      }
      else
      {
            return 2;
      }
}
int main()
{
      int limit, count, temp_proces, time, a, b;
      proces_structure temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d",&limit);  
      proces_structure proces[limit];
      for(count=0;count<limit;count++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &proces[count].pr_id);
            printf("Arrival Time: ");
            scanf("%d", &proces[count].atime);
            printf("Burst Time: ");
            scanf("%d", &proces[count].btime);
            printf("Process Priority: ");
            scanf("%d", &proces[count].pr_prio);
            temp_proces = proces[count].pr_prio;
            proces[count].p = Queue(temp_proces);
            proces[count].ready = 0;
      }
      time = proces[0].btime;
      for(b=0;b<limit;b++)
      {
            for(count=b;count<limit;count++)
            {
                  if(proces[count].atime < time)
                  {
                        proces[count].ready = 1;
                  }
            }
            for(count=b;count<limit-1;count++)
            {
                  for(a=count+1; a<limit; a++)
                  {
                        if(proces[count].ready == 1 && proces[a].ready == 1)
                        {
                              if(proces[count].p == 2 && proces[a].p == 1)
                              {
                                    temp = proces[count];
                                    proces[count] = proces[a];
                                    proces[a] = temp;
                              }
                        }
                  }
            }
            for(count=b;count<limit-1;count++)
            {
                  for(a=count+1;a<limit;a++)
                  {
                        if(proces[count].ready==1 && proces[a].ready==1)
                        {
                              if(proces[count].p==1 && proces[a].p==1)
                              {
                                    if(proces[count].btime > proces[a].btime)
                                    {
                                          temp=proces[count];
                                          proces[count]=proces[a];
                                          proces[a]=temp;
                                    }
                                    else
                                    {
                                          break;
                                    }
                              }
                        }
                  }
            }
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", proces[b].pr_id, time, time + proces[b].btime);
            time = time + proces[b].btime;
            for(count=b; count<limit; count++)
            {
                  if(proces[count].ready==1)
                  {
                        proces[count].ready=0;
                  }
            }
      }
      return 0;
}
