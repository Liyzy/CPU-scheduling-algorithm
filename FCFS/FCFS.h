//
// Created by lihui on 18-5-16.
//

#ifndef FCFS_FCFS_H
#define FCFS_FCFS_H

#include <iostream>
#include <vector>
#include "PCB.h"
#define NUMBER 9    //宏定义进程数

using namespace std;

void FCFS()
{
    double systemTime=0;    //程序运行的时间
    double sumturnTime=0;   //总周转时间
    double avgturnTime=0;   //平均周转时间
    double sumrightTime=0;  //总带权周转时间
    double avgrightTime=0;  //平均带权周转时间

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
        auto FristProcess=readyQueue.begin();
        vector<PCB>::iterator it=readyQueue.begin();
        //找到最先到达的进程调度
        for(it; it!=readyQueue.end(); it++)
        {
            if(it->GetreadyQueueTime() < FristProcess->GetreadyQueueTime())
            {
                FristProcess=it;
                it++;
            }
        }
        FristProcess->ChangestartExecutionTime(systemTime);
        FristProcess->ChangeendExecutionTime(systemTime+FristProcess->GetexecutionTime());
        FristProcess->ChangeturnRoundTime(systemTime+FristProcess->GetexecutionTime()-FristProcess->GetreadyQueueTime());
        FristProcess->ChangerightTime(FristProcess->GetturnRoundTime()/FristProcess->GetexecutionTime());
        sumturnTime+=FristProcess->GetturnRoundTime();
        sumrightTime+=FristProcess->GetrightTime();
        systemTime+=FristProcess->GetexecutionTime();
        cout<<"进程号："<<FristProcess->Getpname()<<" "<<"到达时间："<<FristProcess->GetreadyQueueTime()
            <<" "<<"执行开始时间："<<FristProcess->GetstartExecutionTime()<<" "<<"执行结束时间："<<FristProcess->GetendExecutionTime()
            <<" "<<"周转时间："<<FristProcess->GetturnRoundTime()<<" "<<"带权时间:"<<FristProcess->GetrightTime()<<endl;
        readyQueue.erase(FristProcess);
    }
    avgrightTime=sumrightTime/NUMBER;
    avgturnTime=sumturnTime/NUMBER;
    cout<<"平均周转时间:"<<avgturnTime<<endl;
    cout<<"平均带权周转时间:"<<avgrightTime<<endl;
}
#endif //FCFS_FCFS_H
