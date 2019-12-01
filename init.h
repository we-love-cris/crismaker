#pragma once
//기본 라이브러리 추가 선언 장소

#include "declare.h" //기본 라이브러리 및, 상수값, 구조체 include
#include "util.h" //util 함수들 include
#include "view.h"
#include "domain.h"

//모든 기본적인 값들에 대한 초기화
status* init_status();


void make_status(status* game);
void make_student(student* std);
void make_player_p(player_p* choi);
void make_prof(prof* pp);
void make_day(day* wk);


//콘솔창 초기화
void init_consol(status* game);
