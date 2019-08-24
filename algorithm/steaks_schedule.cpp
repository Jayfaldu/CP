#include<stdio.h>
#include<algorithm>

struct ans{
  int start_1;
  int start_2;
};

struct subproblem{
  int min;
  int end1;
  int no_steaks1;
  int end2;
  int no_steaks2;
};

struct data{
  int start_time;
  int end_time;
};

int steaks_schedule(int max_steak,int no_steaks,data timings[],ans answer[],subproblem opt[]){
  // initialize
  for(int j=1;j<no_steaks;j++){
    if(opt[j-1].end2-timings[j].start_time>=2){
      if(opt[j-1].no_steaks1<max_steak){
        opt[j].end1=opt[j-1].end1;
        opt[j].end2=opt[j-1].end2;
        opt[j].no_steaks1=opt[j-1].no_steaks1 + 1;
        opt[j].no_steaks2=opt[j-1].no_steaks2 + 1;
        opt[j].min =opt[j-1].min;
        answer[j].start_1=opt[j].end1 - 1;
        answer[j].start_2=answer[j].start_1 +1;
      }
      else if(opt[j-1].no_steaks2<max_steak){
        if(timings[j].end_time - opt[j-1].end1>=2){
          opt[j].end1=opt[j-1].end2;
          opt[j].end2=opt[j-1].end2 + 1;
          opt[j].no_steaks1=opt[j-1].no_steaks2 + 1;
          opt[j].no_steaks2=1;
          opt[j].min=opt[j-1].min + 1;
          answer[j].start_1=opt[j].end1;
          answer[j].start_2=answer[j].start_1 +1;
        }
        else{
          return 0;
        }
      }
      else if(timings[j].end_time-opt[j-1].end2>=2){
        opt[j].end1=opt[j-1].end2+1;
        opt[j].end2=opt[j-1].end2 + 2;
        opt[j].no_steaks1=1;
        opt[j].no_steaks2=1;
        opt[j].min=opt[j-1].min + 2;
        answer[j].start_1=opt[j].end2;
        answer[j].start_2=opt[j].end2+1;
      }
      else{
        return 0;
      }
    }
    else if(opt[j-1].end2 - timings[j].start_time>=1){
      if(opt[j-1].no_steaks2<max_steak){
        if(timings[j].end_time - opt[j-1].end1>=2){
          opt[j].end1=opt[j-1].end2;
          opt[j].end2=opt[j-1].end2 + 1;
          opt[j].no_steaks1=opt[j-1].no_steaks2 + 1;
          opt[j].no_steaks2=1;
          opt[j].min=opt[j-1].min + 1;
          answer[j].start_1=opt[j].end1 ;
          answer[j].start_2=answer[j].start_1 +1;
        }
        else{
          return 0;
        }
      }
      else if(timings[j].end_time - opt[j-1].end2>=2){
        opt[j].end1=opt[j-1].end2+1;
        opt[j].end2=opt[j-1].end2 + 2;
        opt[j].no_steaks1=1;
        opt[j].no_steaks2=1;
        opt[j].min=opt[j-1].min + 2;
        answer[j].start_1=opt[j].end2;
        answer[j].start_2=opt[j].end2+1;
      }
      else{
        return 0;
      }
    }
    else{
      opt[j].end1=timings[j].start_time+1;
      opt[j].end2=timings[j].start_time+2;
      opt[j].no_steaks1=1;
      opt[j].no_steaks2=2;
      opt[j].min=timings[j].start_time + 2 ;
      answer[j].start_1=timings[j].start_time;
      answer[j].start_2=answer[j].start_1+1;
    }
  }
  return 1;
}

int main(){
  int time_diff,max_steak;
  int f=1;
  scanf("%d%d",&time_diff,&max_steak);
  int no_steaks;
  scanf("%d",&no_steaks);
  data timings[no_steaks];
  for(int i=0;i<no_steaks;i++){
    scanf("%d",&timings[i].end_time);
    timings[i].start_time=timings[i].end_time - time_diff;
    if(timings[i].end_time<2){
      f=0;
    }
  }
  subproblem opt[no_steaks];
  opt[0].end1=1;
  opt[0].end2=2;
  opt[0].no_steaks1=1;
  opt[0].no_steaks2=1;
  opt[0].min=2;
  ans answer[no_steaks];
  answer[0].start_1=0;
  answer[1].start_2=1;
  if(f=0){
    printf("-1");
  }
  else{

    f=steaks_schedule(max_steak,no_steaks,timings,answer,opt);
    if(f==1){
      printf("%d\n",opt[no_steaks].min);
      for(int i=0;i<no_steaks;i++){
        printf("%d %d\n",answer[i].start_1,answer[i].start_2);
      }
    }
    else{
      printf("-1");
    }
  }
}
