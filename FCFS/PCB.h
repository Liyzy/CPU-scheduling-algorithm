//
// Created by lihui on 18-5-16.
//

#ifndef FCFS_PCB_H
#define FCFS_PCB_H
#include <string.h>
#include <iostream>
using namespace std;

class PCB
{
private:
    int pname;   //进程名称
    double executionTime;   //进程需要执行时间
    double readyQueueTime;  //进程就绪队列时间
    double startExecutionTime;  //进程执行开始时间
    double endExecutionTime;    //进程执行结束时间
    double turnRoundTime;   //周转时间
    double rightTime;   //带权周转时间

public:
    PCB(){}
    PCB(int name,double etime,double rtime,double stime=0,double endtime=0,double ttime=0,double rigtime=0)
    {
        pname=name;
        executionTime=etime;
        readyQueueTime=rtime;
        startExecutionTime=stime;
        endExecutionTime=endtime;
        turnRoundTime=ttime;
        rightTime=rigtime;
    }
    ~PCB(){}

    int Getpname() const
    {
        return pname;
    }
    double GetexecutionTime() const
    {
        return executionTime;
    }
    double GetreadyQueueTime() const
    {
        return readyQueueTime;
    }
    double GetstartExecutionTime() const
    {
        return startExecutionTime;
    }
    double GetendExecutionTime() const
    {
        return endExecutionTime;
    }
    double GetturnRoundTime()
    {
        return turnRoundTime;
    }
    double GetrightTime()
    {
        return rightTime;
    }

    void ChangestartExecutionTime(double cst)
    {
        startExecutionTime=cst;
    }
    void ChangeendExecutionTime(double cet)
    {
        endExecutionTime=cet;
    }
    void ChangeturnRoundTime(double ctt)
    {
        turnRoundTime=ctt;
    }
    void ChangerightTime(double crt)
    {
        rightTime=crt;
    }
};
#endif //FCFS_PCB_H
