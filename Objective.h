#include <vector>
#include <string>
#include <map>
using namespace std;

class Objective
{
  typedef double (Objective::*MFP)(string);
  std::map <string,MFP> fmap;

  struct Task
  {
       string taskStr;
       double (Objective::*rwdFunc)(string);
       string inputStr;
  };

//vector of tasks
public:
   Objective();
   double GetReward(unsigned int);
   double GetReward();
   int AddTask(string str);
   double GetRwdFuncPtr(std::string taskStr);
   void PrintObjectiveSummary();
   double RwdBasic(string);
   double RwdJump(string);
   double RwdWalk(string);
   double RwdDance(string);
   double RwdDeadlift(string);
   double RwdCartwheel(string);
   double RwdKick(string);


   std::vector<Task> tasks;



};
