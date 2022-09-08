#include "../header/speechManager.hpp"

SpeechManager::SpeechManager() {
  this->init_speech();
  this->createSpeaker();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::init_speech(){
  v1.clear();
  v2.clear();
  v3.clear();
  m_speaker.clear();
  m_index = 0;
}

void SpeechManager::createSpeaker() {
  string nameSeed = "ABCDEFGHIJKL";
  for (int i = 0; i < nameSeed.size(); i++) {
    string name = "选手";
    name += nameSeed[i];
    cout << name << endl;
    Speaker sp;
    sp.m_name = name;
    // 两轮比赛的成绩都初始化为0
    sp.m_score[0] = 0;
    sp.m_score[1] = 0;
    // 创建选手编号
    v1.push_back(10001 + i);
    
    m_speaker.insert(make_pair(10001 + 1, sp));
  }
}

void SpeechManager::show_menu() {
  cout << "********************" << "欢迎使用演讲比赛系统" << "********************" << endl;
  cout << "*********************" << "1.开始比赛        " << "*********************" << endl;
  cout << "*********************" << "2.查看往期结果    " << "*********************" << endl;
  cout << "*********************" << "3.清空往期结果    " << "*********************" << endl;
  cout << "*********************" << "4.退出系统        " << "*********************" << endl;
  cout << "*********************" << "******************" << "*********************" << endl;
}

void SpeechManager::speechDraw () {
  cout << "第" << this->m_index << "轮演讲比赛正在抽签" << endl;
  cout << "---------------------" << endl;
  cout << "抽签结果如下:" << endl;
  if (this->m_index == 1) {
    // 第一轮比赛
    random_shuffle(v1.begin(), v1.end());
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
      cout << *it << ",";
    }
    cout << endl;
  } else {
    // 第一轮比赛
    random_shuffle(v2.begin(), v2.end());
    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
      cout << *it << ",";
    }
    cout << endl;
    cout << "抽签结束，按任意键进入下一个环节:" << endl;
    // string s;
    // cin >> s;
  }
}

void SpeechManager::start_game() {
  // 第一轮比赛
  // 1. 抽签
  this->speechDraw();
  // 2. 比赛
  // 3. 显示最终结果
  // 第一轮比赛
  // 1. 抽签
  // 2. 比赛
  // 3. 显示最终结果
  // 4. 保存最终分数到文件中

}
void SpeechManager::show_history(){
  cout << "查看往期结果" << endl;
}
void SpeechManager::empty_history(){
  cout << "清空记录" << endl;
}
void SpeechManager::exitSystem(){
  cout << "退出系统" << endl;
  exit(0);
}