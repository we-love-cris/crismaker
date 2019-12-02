#include "init.h"

status* init_status() {
	status* game;
	game = (status*)malloc(sizeof(status));
	make_status(game);


	return game;
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

	game->db = (database*)malloc(sizeof(database));
	make_database(game->db);

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
void make_database(database* db) {
	db->func_list.show_menu[0] = select_main_menu;
	db->func_list.show_menu[1] = select_profvsstd;

	db->func_list.screen_size[0] = menu_screen;//메뉴 선택 창(작음)
	db->func_list.screen_size[1] = game_screen;//게임 창(큼)
	
	db->default_days = (day**)malloc(sizeof(day*) * ACAD_TYPES);
	make_default_days(db->default_days);

	return;
}
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

void init_consol(status* game) {
	textcolor(9, 15);
	v_clearall();
	system("title C프로그래밍 시뮬레이터");
	menu_screen();

	return;
}
