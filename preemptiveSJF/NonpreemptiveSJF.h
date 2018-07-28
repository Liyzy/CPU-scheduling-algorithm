//
// Created by lihui on 18-5-16.
//

#ifndef INC_4_NONPREEMPTIVESJF_H
#define INC_4_NONPREEMPTIVESJF_H

#include <iostream>
#include <vector>
#include "PCB.h"
#define NUMBER 9

using namespace std;

void NonpreemptiveSJF()
{
    double systemTime=0;
    double sumturnTime=0;
    double avgturnTime=0;
    double sumrightTime=0;
    double avgrightTime=0;

    vector<PCB> readyQueue;
    PCB p[]={
                {0,1,0},
                {1,35,1},
                {2,10,2},
                {3,5,3},
                {4,9,6},
                {5,21,7},
                {6,35,9},
                {7,23,11},
                {8,42,12}
             };
    for(int i=0; i<NUMBER; i++)
        readyQueue.push_back(p[i]);

    while(!readyQueue.empty())
    {
        vector<PCB>::iterator it=readyQueue.begin();
        auto MinProcess=readyQueue.begin();
        while(it!=readyQueue.end()&&it->GetreadyQueueTime()<=systemTime)
        {
            if(it->GetexecutionTime() <= MinProcess->GetexecutionTime())
                MinProcess=it;
            it++;
        }
        bool flag=false;
        for(it=readyQueue.begin(); it!=readyQueue.end()&&flag==false; it++)
        {
            if(it->GetexecutionTime() == MinProcess->GetexecutionTime()&&it->GetreadyQueueTime()<=systemTime)
            {
                MinProcess->ChangestartExecutionTime(systemTime);
                MinProcess->ChangeendExecutionTime(systemTime+MinProcess->GetexecutionTime());
                MinProcess->ChangeturnRoundTime(systemTime+MinProcess->GetexecutionTime()-MinProcess->GetreadyQueueTime());
                MinProcess->ChangerightTime(MinProcess->GetturnRoundTime()/MinProcess->GetexecutionTime());
                sumturnTime+=MinProcess->GetturnRoundTime();
                sumrightTime+=MinProcess->GetrightTime();
                systemTime+=MinProcess->GetexecutionTime();
                cout<<"进程号："<<MinProcess->Getpname()<<" "<<"到达时间："<<MinProcess->GetreadyQueueTime()
                    <<" "<<"执行开始时间："<<MinProcess->GetstartExecutionTime()<<" "<<"执行结束时间："<<MinProcess->GetendExecutionTime()
                    <<" "<<"周转时间："<<MinProcess->GetturnRoundTime()<<" "<<"带权时间:"<<MinProcess->GetrightTime()<<endl;
                readyQueue.erase(it);
                flag = true;
            }
        }
    }
    avgrightTime=sumrightTime/NUMBER;
    avgturnTime=sumturnTime/NUMBER;
    cout<<"平均周转时间:"<<avgturnTime<<endl;
    cout<<"平均带权周转时间:"<<avgrightTime<<endl;
}

#endif //INC_4_NONPREEMPTIVESJF_H
