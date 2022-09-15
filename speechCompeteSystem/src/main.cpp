#include <iostream>
#include "../header/speechManager.hpp"
#include "../header/utils.hpp"

using namespace std;


int main(int argc, char const *argv[])
{
  SpeechManager sm;
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
