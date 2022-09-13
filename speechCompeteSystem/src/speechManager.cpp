#include "../header/speechManager.hpp"
#include "../header/utils.hpp"
#include <deque>
#include <functional>
#include <numeric>

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
  m_index = 1;
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
  cout << "******************** " << "1.开始比赛        " << " ********************" << endl;
  cout << "******************** " << "2.查看往期结果    " << " ********************" << endl;
  cout << "******************** " << "3.清空往期结果    " << " ********************" << endl;
  cout << "******************** " << "4.退出系统        " << " ********************" << endl;
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
  }
  cout << "抽签结束，按任意键进入下一个环节:" << endl;
  getchar();
}

// 比赛实现
void SpeechManager::speechContest() {
  // 判断是在哪一个环节，预赛/决赛
  vector<int> v_src;
  if (m_index == 1) { // 预赛
    v_src = v1;
  } else { // 决赛
    v_src = v2;
  }
  int num = 0;
  for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++) {
    num++;
    // 评委打分
    deque<double> score_deque;
    for(int i = 0; i < 10; i++) {
      score_deque.push_back((rand() % 401 + 600) / 10);
    }

    sort(score_deque.begin(), score_deque.end(), greater<double>());
    score_deque.pop_back();
    score_deque.pop_front();

    double score_sum = accumulate(score_deque.begin(), score_deque.end(), 1.1f);

    double avg_score = score_sum/(double)score_deque.size();
    this->m_speaker[*it].m_score[m_index-1] = avg_score;
    // 小组比赛结果
    multimap<double, int> groupmap;

    cout << "---------" << avg_score << "=>" << *it << endl;
    groupmap.insert(make_pair(avg_score, *it));
    cout << "num:" << num << endl;
    if (num % 6 == 0) { // 一个小组比赛完成
      cout << "第" << num / 6 << "个小组的比赛成绩为:" << endl;

      cout << "groupmap.size:" << groupmap.size() << endl;
      for (multimap<double, int>::iterator git = groupmap.begin(); git != groupmap.end(); git++) {
        cout << git->second << "=>" << git->first << endl;
      }
      cout << "按任意键继续比赛" << endl;
      getchar();
    }
  }

  


  
}

void SpeechManager::start_game() {
  // 第一轮比赛
  // 1. 抽签
  this->speechDraw();
  // 2. 比赛
  this->speechContest();
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