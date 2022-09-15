#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include "speaker.hpp"
using namespace std;

// 设计演讲比赛的管理类
class SpeechManager {
  public:
    vector<int> v1; // 第1轮选手
    vector<int> v2; // 第2轮选手
    vector<int> v3; // 第3轮选手

    map<int, Speaker> m_speaker;

    int m_index;

    void init_speech();

    void createSpeaker();

    // 构造函数
    SpeechManager();
    // 析构函数
    ~SpeechManager();
    // 菜单功能
    void show_menu();
    // 开始比赛 比赛整个流程的控制函数
    void start_game();
    // 抽签
    void speechDraw();
    // 比赛
    void speechContest();
    // 显示比赛成绩
    void show_score();
    void show_history();
    void empty_history();
    void exitSystem();
};
