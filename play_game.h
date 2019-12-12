#pragma once
#include "declare.h"
#include "util.h"
#include "view.h"

int play_game_prof(status* game);
/*
1. 강의 -1
2. 잡담 -1
3. 실습 -3
4. 출석 -2
5. 쪽지시험 -10
6. 깨우기 -2
7. 질문 답하기 -1
8. 팀플 공지 -1
9. 쪽지시험 공지 -1
*/
int play_game_std(status* game);
/*
1. 노트 필기하기
2. 개인 코딩하기
3. 웹툰 보기
4. 출튀하기
5. 출튀 복귀하기
6. 졸기
*/

void start_day_p(status* game, int week, int* work);
void start_game_p(status* game);
void p_endturn(status* game);

int do_what_p(int* work);
void p_do(status* game, int does);

void attend_p(status* game); // 출석을 부른다
void lecture_p(status* game); // 수업을 진행한다
void chat_p(status* game); // 다른 얘기를 한다
void practice_p(status* game); // 실습을 진행한다
void announce_st_p(status* game); // 쪽지시험을 공지한다
void smallTest_p(status* game); // 쪽지시험을 본다
void wakingUp_p(status* game); // 학생들을 깨운다
void answerQuestion_p(status* game); // 질문을 받는다
void announce_tp_p(status* game);

void nextDay_p(status* game); // 하루가 끝났을 때 처리해주는 함수
int endSemester_p(status* game); // 학기가 끝났을 때 처리해주는 함수

int findOn_p(student** std_list);
int isAttend_p(student** std_list);
void snooze_p(student** std_list);
void configureWork(player_p* choi, int* work);

int statusCheck_p(status* game); // 게임오버 조건을 테스트

void start_game_s(status* game);
void start_day_s(status* game, int week, int* work);
int figureChatorClass(prof* pp);
int s_endturn(status* game);

int do_what_s(int* work);
void s_do(status* game, int does, int isProgress, int* work);

void takeNote_s(status* game, int isProgress); // 노트 필기하기
void coding_s(status* game, int isProgress); // 개인 코딩하기
void webtoon_s(status* game); // 웹툰 보기
void runaway_s(status* game, int* work); // 출튀하기
void comeback_s(status* game, int* work); // 출튀했다 돌아오기
void snooze_s(status* game); // 졸기
void configure_work_s(status* game, int* work);

void evening_day(status* game);
void study_s(status* game); // 집에 가서 공부
void drunk_s(status* game); // 집에 가서 음주
void sleep_s(status* game); // 집에 가서 수면

int statusCheck_s(status*game); // 게임오버 조건을 체크한다

void endClass_s(status* game); // 수업이 끝났을 때
void nextDay_s(status* game); // 하루가 끝났을 때
void endSemester_s(status* game); // 학기가 끝났을 때
