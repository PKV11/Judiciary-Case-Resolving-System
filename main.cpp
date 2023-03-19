#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<bits/stdc++.h>
#include<iostream>
#include<ctime>
using namespace std;



int main()
{
    int wish =1;
    
    priority_queue<int>pq;
   int num;
   map<string,int>mp;
   mp["murder"]=9;
   mp["assault"]=8;
   mp["theft"]=5;
   map<int,string>mapped;
   while(wish){
   printf("Do you want to:\n 1) Verify your case \n 2) See priority order of cases\n ");
   scanf("%d",&num);
   switch(num)
   {
      case 1: {

                  FILE *fp;
                  char word[50];


                  char ch;
                  char filename[128];
                  printf("Enter name of case to be validated\n");
                  scanf("%s",filename);
                  strcat(filename,".txt");
                  int priority=0;
                  fp = fopen(filename, "r");
                  do 
                  {
                     ch = fscanf(fp, "%s", word);
                     if(mp[word]>0)
                     {
                        priority+=mp[word];
                     }
                  }
                    while (ch != EOF);
            
                int dd,mm,yyyy;
                printf("Enter the case date(dd/mm/yyyy): ");
                string date;
                cin>>date;
                string dd2 = date.substr(0,2);
                string mm2 = date.substr(3 , 2);
                string yy2 = date.substr(6 , 4);
                dd=stoi(dd2);
                yyyy=stoi(yy2);
                mm=stoi(mm2);
                time_t ptime;
                time(&ptime);
                ptime = ptime/(3600*24); 
                int ctime = (((yyyy-1970)*365)+(mm*30)+dd);
                int dtime = abs(ptime - ctime);
                priority+=(dtime/20);   
                  mapped[priority]=filename;
                  printf("\n%d\n",priority);
                  pq.push(priority);
                  fclose(fp);
                }
                break;
                
          case 2: 
          {
            while(!pq.empty())
            {
                cout<<mapped[pq.top()]<<endl;
                pq.pop();
            }
          }
   
   }
   printf("Press 1 to go back to menu & 0 to exit the program\n");
    scanf("%d",&wish);
   }

   
   return 0;
}



