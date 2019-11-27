#pragma once
//선언된 공용 라이브러리
#include <stdio.h>

// 상수값들 include
#include "constants.h"

typedef struct player_professor {// 플레이어가 플레이할 교수. 이름은 아마 최운정? ㅎㅎ
	//선언 메모리 관리 해주기
	int assignment; //과제 낸 횟수
	int chat; //잡담
	int move; //행동력
	int progress; //진도
	int test; //시험 본 횟수
	int type; //0이면 교수

	char* name;
} player_p;

typedef struct student {// 최교수님이 되어 만날 학생들
	int attend_count; //출석 횟수
	int attend_rate; //출셕률
	int happiness; //행복도
	int move; //행동력
	int progress; //따라간 진도
	int skill; //실력, 질문할 확률
	int tired; //피로도
	int type; //1이면 학생, 플레이어가 아니면 2

	char* name;
} student;

typedef struct professor {// 학생 모드일 대 만날 교수님
	int chat_rate; //딴 얘기 할 확률
	int progress_rate; //진도 나갈 확률
	int type; //플레이어가 아니면 3

	char* name;

} prof;

typedef struct Day {
	int attend_rate; //예상 출석률
	int move; //행동력
	int type;
	/* 
	// 0 : 일반 수업
	// 1 : OT
	// 2 : 축제
	// 3 : 시험
	// 4 : 
	...
	*/

} day;

typedef struct now_status {//현재 학교의 상황
	//선언 메모리 관리 해주기
	int std_no; //학생 모드일 경우 자신의 출석 번호(0 ~ STD_AMOUNT - 1)
	int type; //현재 모드 0 : 교수 모드, 1 : 학생 모드
	int week; //현재 몇 주차인지, week < ACADEMIC_WEEK

	player_p* choi; //교수 모드일 경우의 교수
	student* me; //학생 모드일 경우의 플레이어
	prof* pp; //학생 모드일 경우의 교수

	day* academic_calender; //학사 일정, 총 8주차일 예정

	student* student_list; //출석부, 학생을 12명 할 예정. 가나다순으로 정렬해 보자(가능?)


} status;