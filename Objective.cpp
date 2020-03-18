#include "Objective.h"
#include <sstream>
#include <iostream>
using namespace std;

Objective::Objective()
{
  Task basic;
  basic.taskStr = "basic";
  basic.inputStr = "basic_input";
  basic.rwdFunc = &Objective::RwdBasic;
  tasks.push_back(basic);

  fmap.insert(std::make_pair("jump", &Objective::RwdJump));
  fmap.insert(std::make_pair("walk", &Objective::RwdWalk));
  fmap.insert(std::make_pair("dance", &Objective::RwdDance));
  fmap.insert(std::make_pair("deadlift", &Objective::RwdDeadlift));
  fmap.insert(std::make_pair("cartwheel", &Objective::RwdCartwheel));
  fmap.insert(std::make_pair("kick", &Objective::RwdKick));
  //add new task here
}

double Objective::GetReward(unsigned int indx)
{
  if(tasks.size()-1 < indx )
  {
    return -1;
  }
  else
  {
    return (this->*(tasks[indx].rwdFunc))(tasks[ind].inputStr);
  }
}

int Objective::AddTask(std::string str)
{
    string taskStr;
    string index;
    string inputStr;
    stringstream ss;
    ss.str(str);
    ss>>index;
    ss>>taskStr;
    getline(ss, inputStr);

    if(fmap.find(taskStr) == fmap.end())
    {
      return -1; //Could not find reward function
    }

    Task task;
    task.taskStr = taskStr;
    task.rwdFunc = fmap[taskStr];
    task.inputStr = inputStr;
    tasks.push_back(task);
    return 1;
}

double Objective::GetReward()
{
  double reward = 0;

  for( unsigned int i = 0; i < tasks.size(); i++)
  {
    reward  = reward + (this->*(tasks[i].rwdFunc))(tasks[i].inputStr);
  }

  return reward;
}

void Objective::PrintObjectiveSummary()
{
  for(unsigned int i = 0; i < tasks.size();i++)
  {
    std::cout << "Task " << i << "\t:" << tasks[i].taskStr
     << "    \tInput String " << tasks[i].inputStr << "\n";
  }
}

double Objective::RwdBasic(string inputStr){
  return 100.0;
}

double Objective::RwdJump(string inputStr){
  return 10.0;
}

double Objective::RwdWalk(string inputStr){
  return 1.0;
}

double Objective::RwdDance(string inputStr){
  return 0.1;
}

double Objective::RwdDeadlift(string inputStr){
  return 0.01;
}

double Objective::RwdCartwheel(string inputStr){
  return 0.001;
}

double Objective::RwdKick(string inputStr){
  return 0.0001;
}
