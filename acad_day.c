#include "acad_day.h"

int acad_main(status* game) {
	
}

//acad를 default로 바꾸는 함수
void make_default_days(day** default_days) {
	/*
	//1주차 OT		0
	//2주차 수업	1
	//3주차 공휴일	2
	//4주차 수업	3
	//5주차 축제	4
	//6주차 팀플	5
	//7주차 수업	6
	//8주차 시험	7
	*/

	//OT
	day temp = { OT_ATTEND_RATE, OT_MOVE, 1 };
	default_days[0] = &temp;

	//수업
	day temp1 = { CLASS_ATTEND_RATE, CLASS_MOVE, 0 };
	default_days[1] = &temp1;
	default_days[3] = &temp1;
	default_days[6] = &temp1;

	//공휴일
	day temp2 = { HOLI_ATTEND_RATE,HOLI_MOVE, 5 };
	default_days[2] = &temp2;

	//축제
	day temp3 = { FESTIV_ATTEND_RATE, FESTIV_MOVE, 4 };
	default_days[4] = &temp3;

	//팀플
	day temp4 = { TP_ATTEND_RATE, TP_MOVE, 2 };
	default_days[5] = &temp4;

	//시험
	day temp5 = { TEST_ATTEND_RATE, TEST_MOVE, 3 };
	default_days[7] = &temp5;

	return;
}