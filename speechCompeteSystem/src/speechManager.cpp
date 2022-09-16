#include "../header/speechManager.hpp"
#include "../header/utils.hpp"
#include <deque>
#include <functional>
#include <numeric>
#include <time.h>
#include <fstream>

#define OUTPUT_FILE "speech.csv"

SpeechManager::SpeechManager() {
  this->init_speech();
  this->createSpeaker();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::init_speech(){
  cout << "clear" << endl;
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
    Speaker sp;
    sp.m_name = name;
    // 两轮比赛的成绩都初始化为0
    sp.m_score[0] = 0;
    sp.m_score[1] = 0;
    // 创建选手编号
    v1.push_back(10001 + i);
    m_speaker.insert(make_pair(10001 + i, sp));
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

int myrandom(int i) {
  return rand() % i;
}

void SpeechManager::speechDraw () {
  cout << "第" << this->m_index << "轮演讲比赛正在抽签" << endl;
  cout << "---------------------" << endl;
  cout << "抽签结果如下:" << endl;
  if (this->m_index == 1) {
    // 第一轮比赛
    srand(time(NULL));
    random_shuffle(v1.begin(), v1.end());
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
      cout << *it << ",";
    }
    cout << endl;
  } else {
    // 第二轮比赛
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
  multimap<double, int, greater<double> > vectory_map;
  multimap<double, int, greater<double> > groupmap;
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
    groupmap.insert(make_pair(avg_score, *it));
    if (num % 6 == 0) { // 一个小组比赛完成
      if (m_index == 1) {
        cout << "第" << num / 6 << "个小组的比赛成绩为:" << endl;
      } else {
        cout << "总决赛赛成绩为:" << endl;
      }
      int r = 0;
      for (multimap<double, int>::iterator git = groupmap.begin(); git != groupmap.end(); git++) {
        if (r++ < 3) {
          vectory_map.insert(make_pair(git->first, git->second));
        } 
        cout << git->second << "=>" << git->first << endl;
      }
      groupmap.clear();
      cout << "按任意键继续比赛" << endl;
      getchar();
    }
  }



  for(multimap<double, int>::iterator vit = vectory_map.begin(); vit != vectory_map.end(); vit++) {
    if (m_index == 1) {
      v2.push_back(vit->second);
    } else {
      v3.push_back(vit->second);
    }
    
  }
  
}

void SpeechManager::show_score() {
  vector<int> v;
  if (m_index == 1) {
    v = v2;
  } else {
    v = v3;
  }
  cout << "-------第" << m_index << "轮比赛的胜出的选手有:-------" << endl;
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "编号: " << *it << ",姓名: " << m_speaker[*it].m_name << ",成绩: " << m_speaker[*it].m_score[m_index-1] << endl;
  }

  cout << "按任意键继续比赛" << endl;
  getchar();
}

void SpeechManager::save_record() {

  ofstream ofs;
  ofs.open(OUTPUT_FILE, ios::app);// 追加方式打开
  // 写入数据
  for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {
    ofs << *it << ",";
    ofs << m_speaker[*it].m_name << ",";
    ofs << m_speaker[*it].m_score[1] << ",";
  }
  ofs << endl;
  ofs.close();
}

void SpeechManager::start_game() {

  v2.clear();
  v3.clear();
  m_index = 1;
  // 第一轮比赛
  // 1. 抽签
  this->speechDraw();
  // 2. 比赛
  this->speechContest();
  // 3. 显示最终结果
  show_score();
  // 第二轮比赛
  // 1. 抽签
  this->m_index++;
  this->speechDraw();
  // 2. 比赛
  this->speechContest();
  // 3. 显示最终结果
  show_score();
  // 4. 保存最终分数到文件中
  save_record();
}
void SpeechManager::show_history(){
  ifstream ifs;
  ifs.open(OUTPUT_FILE, ios::in);
  int is_empty = 0;
  if (!ifs.is_open()) {
    // 文件不存在
    is_empty = 1;
  }

  char c;
  ifs >> c;
  if(ifs.eof()) {
    //文件为空
    cout << "文件为空" << endl;
    ifs.close();
    is_empty = 1;
  }
  if (is_empty) {
    cout << "历史记录为空！" << endl;
  }
  ifs.putback(c);
  // 文件存在，且不为空
  string record;

  map<int, vector<Speaker> > m_records;
  int season = 0;
  while(getline(ifs, record)) {
    vector<string> v_record = split(record, ",");
    season++;
    cout << "第" << season << "届演讲比赛成绩: " << endl;
    vector<Speaker> v_speakers;
    int index = 0;
    for(int i = 0; i < 3; i++) {
      switch (i)
      {
      case 0:
        cout << "冠军:";
        break;
      case 1:
        cout << "亚军:";
        break;
      case 2:
        cout << "季军:";
        break;
      default:
        break;
      }
      cout << endl;
      int num = stoi(v_record[index++]);
      string name = v_record[index++];
      double score = stod(v_record[index++]);
      cout << "选手编号:" << num << ", 选手姓名:" << name << ", 选手成绩:" << score << endl;
    }
  }
}
void SpeechManager::empty_history(){
  cout << "清空记录" << endl;
  ifstream ofs;
  ofs.open(OUTPUT_FILE, ios::out|ios::trunc);

  ofs.close();
}
void SpeechManager::exitSystem(){
  cout << "退出系统" << endl;
  exit(0);
}