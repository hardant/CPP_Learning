#include <iostream>
#include "../header/speechManager.hpp"
#include "../header/utils.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
  SpeechManager sm;

  for(map<int, Speaker>::iterator it = sm.m_speaker.begin(); it!=sm.m_speaker.end(); it++) {
    cout << it->first << "=>" << it->second.m_name << ", " << it->second.m_score[0] << endl;
  }

  for(vector<int>::iterator it = sm.v1.begin(); it != sm.v1.end(); it++) {
    cout << *it << endl;
  }


  while(true) {
    sm.show_menu();
    int selection = standardIn<int>("请输入您的选择:");
    
    switch (selection)
    {
    case 1: // 开始比赛
      sm.start_game();
      break;
    case 2: // 查看往期结果
      sm.show_history();
      break;
    case 3:
      sm.empty_history();
      break;
    case 4:
      sm.exitSystem();
      break;
    default:
      break;
    }
    
  }
  return 0;
}
