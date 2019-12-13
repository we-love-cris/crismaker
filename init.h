#pragma once
//기본 라이브러리 추가 선언 장소

#include "declare.h" //기본 라이브러리 및, 상수값, 구조체 include
#include "util.h" //util 함수들 include
#include "view.h"
#include "domain.h"
#include "acad_day.h"

//모든 기본적인 값들에 대한 초기화
status* init_status();


void make_status(status* game);
void make_student(student* std);
void make_player_p(player_p* choi);
void make_prof(prof* pp);
void make_day(day* wk);
void make_database(database* db);
/*
//1주차 OT
//2주차 수업
//3주차 공휴일
//4주차 수업
//5주차 축제
//6주차 팀플
//7주차 수업
//8주차 시험
*/
void make_default_days(day** default_days);


//콘솔창 초기화
void init_consol(status* game);
