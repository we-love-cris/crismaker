#pragma once

#include "declare.h"
#include "acad_day.h"
#include "view.h"
#include "util.h"

/*
//학사 일정을 편집하는 함수들을 모아 두었다
//학사 일정으로는 다음이 있다
//0. 일반 수업
//1. OT
//2. 팀플(+ 팀 짜기)
//3. 시험(+ 공지)
//4. 축제
//5. 공휴일


//쪽지시험의 경우 학사 일정이 편집되어야 한다
*/

/*
//acad(academic day)의 메인 함수
//이 함수를 통해 입출력과 편집이 이루어진다.
*/
int acad_main(status* game);

//
void make_default_days(day** default_days);

void set_day(int week, int forweek, database* db, day** acad);

int choose_week(int chosen, int max);
int choose_toWeek(int max);