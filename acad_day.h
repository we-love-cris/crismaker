#pragma once

#include "declare.h"

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

//acad를 default로 바꾸는 함수
//초기화일 뿐이며, 게임 시작 전에는 출석률에 대한 보정이 필요하다
//ex) 팀프 공지 날이 축제인 경우 팀프날 출석률 -20
int acad_default(day** academic_calender);