#include <iostream>
#include <fstream>
#include <sstream>
#include "Objective.h"

using namespace std;
int main()
{
cout.precision(10);
double a;

Objective objective;

cout << "Learning C++ all over again\n";

string meta_file = "metadata_with_objectives.txt";

std::ifstream ifs(meta_file);
if(!(ifs.is_open()))
{
  std::cout<<"Can't read file "<<meta_file<<std::endl;
  return -1;
}
std::string str;
std::string index;
std::stringstream ss;

while(!ifs.eof())
{
  str.clear();
  index.clear();
  ss.clear();

  std::getline(ifs,str);
  ss.str(str);
  ss>>index;
  if(!index.compare("use_muscle"))
  {
    std::string str2;
    ss>>str2;
    if(!str2.compare("true"))
      ;
    else
      ;
  }
  else if(!index.compare("con_hz")){
    int hz;
    ss>>hz;
    ;
  }
  else if(!index.compare("sim_hz")){
    int hz;
    ss>>hz;
    ;
  }
  else if(!index.compare("sim_hz")){
    int hz;
    ss>>hz;
    ;
  }
  else if(!index.compare("skel_file")){
    std::string str2;
    ss>>str2;

    ;
  }
  else if(!index.compare("muscle_file")){
    std::string str2;
    ss>>str2;
    ;
  }
  else if(!index.compare("bvh_file")){
    std::string str2,str3;

    ss>>str2>>str3;
    bool cyclic = false;
    if(!str3.compare("true"))
      cyclic = true;
    ;
  }
  else if(!index.compare("reward_param")){
    double a,b,c,d;
    ss>>a>>b>>c>>d;
    ;

  }
  else if(!index.compare("objective")){
    //add to vector objective.


    int err = objective.AddTask(str);
    if(err == -1)
    {
      cout << "Could not find reward function for \"" << str << "\"\n";
    }
    else
    {
      cout << "New Task Added \n";
    }

  }

}
ifs.close();

a = objective.GetReward();
cout << "Reward: " << a << "\n";
objective.PrintObjectiveSummary();

}
