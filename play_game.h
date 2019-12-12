#pragma once
#include "declare.h"
#include "util.h"
#include "view.h"

int play_game_prof(status* game);
int play_game_std(status* game);

void start_day_p(status* game, int week);
void start_game_p(status* game);
void p_endturn(status* game);

int do_what_p();
void p_do(status* game, int does);

void attend_p(status* game); // 출석을 부른다
void lecture_p(status* game); // 수업을 진행한다
void chat_p(status* game); // 다른 얘기를 한다
void practice_p(status* game); // 실습을 진행한다
void announce_st_p(status* game); // 쪽지시험을 공지한다
void smallTest_p(status* game); // 쪽지시험을 본다
void wakingUp_p(status* game); // 학생들을 깨운다
void answerQuestion_p(status* game); // 질문을 받는다
void nextDay_p(status* game); // 하루가 끝났을 때 처리해주는 함수
void endSemester_p(status* game); // 학기가 끝났을 때 처리해주는 함수

int findOn_p(student** std_list);
int isAttend_p(student** std_list);

void statusCheck_p(status* game); // 게임오버 조건을 테스트
