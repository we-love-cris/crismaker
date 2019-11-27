#include "init.h"

void init_status(status* game) {
	game = (status*)malloc(sizeof(status));
	make_status(game);

	return;
}


void make_status(status* game) {
	int i = 0;

	game->std_no = 0;
	game->type = -1;
	game->week = 0;

	//할당실패 다뤄야 함
	game->choi = (player_p*)malloc(sizeof(player_p));
	make_player_p(game->choi);
	game->me = (student*)malloc(sizeof(student));
	make_student(game->me);
	//나중에(학생 모드일 때)me의 type변경 필요
	game->pp = (prof*)malloc(sizeof(prof));

	game->academic_calender = (day**)malloc(sizeof(day*) * ACADEMIC_WEEK);
	for (i = 0; i < ACADEMIC_WEEK; i++) {
		day* dd;
		dd = (day*)malloc(sizeof(day));
		make_day(dd);
		game->academic_calender[i] = dd;
	}

	game->student_list = (student**)malloc(sizeof(student*) * STD_AMOUNT);
	for (i = 0; i < STD_AMOUNT; i++) {
		student* std;
		std = (student*)malloc(sizeof(student));
		make_student(std);
		game->student_list[i] = std;
	}


	return;
}
void make_student(student* std) {
	std->attend_count = 0;
	std->attend_rate = 0;
	std->happiness = 0;
	std->move = 0;
	std->progress = 0;
	std->skill = 0;
	std->tired = 0;
	std->type = OTHER_STUDENT;

	std->name = NULL;

	return;
}
void make_player_p(player_p* choi) {
	choi->assignment = 0;
	choi->chat = 0;
	choi->move = 0;
	choi->progress = 0;
	choi->test = 0;
	choi->type = PLAYER_PROF;

	choi->name = NULL;

	return;
}
void make_prof(prof* pp) {
	pp->chat_rate = 0;
	pp->progress_rate = 0;
	pp->type = OTHER_STUDENT;

	pp->name = NULL;

	return;
}
void make_day(day* wk) {
	wk->attend_rate = 0;
	wk->move = 0;
	wk->type = 0;

	return;
}