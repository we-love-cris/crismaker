#include "play_game.h"

int play_game_prof(status* game) {//교수 모드의 메인
	int week = 0;
	int does = 0;

	start_game_p(game);// 학기 단위

	for(week = 0; week < ACADEMIC_WEEK; week++) {// 주 단위
		start_day_p(game, week);
		

		while (game->choi->move) {//하루 단위
			v_main_game_show_p(game);
			does = do_what_p();
			p_do(game, does);
			p_endturn(game);
		}


	}
	endSemester_p(game);

}

int play_game_std(status* game) {//학생 모드의 메인

}

void start_day_p(status* game, int week) {
	int move = 0;
	int attend = 0;
	int i = 0;
	int temp = 0;


	srand((unsigned)time(NULL));

	game->week = week;
	move = game->academic_calender[week]->move;
	attend = game->academic_calender[week]->attend_rate;

	game->choi->move = move;
	for (i = 0; i < STD_AMOUNT; i++) { // 학생들 출석시키기
		temp = (rand() % 10) + 1;
		if (temp > game->student_list[i]->attend_rate) {
			game->student_list[i]->isAttend = 0;
		}
		else game->student_list[i]->isAttend = 1;
	}
}

void start_game_p(status* game) {
	int i = 0;

	game->db->func_list.screen_size[1]();
	v_board();
	v_main_game_frame_p();

	for (i = 0; i < STD_AMOUNT; i++) {
		game->student_list[i]->attend_rate = game->academic_calender[game->week]->attend_rate;
	}




	return;
}

int do_what_p() {
	int temp = 0;
	while (1) {
		temp = getch();
		if ('0' <= temp && temp <= '9') break;
	}

	return temp - '0';
}

void p_do(status* game, int does) {
	switch (does) {
	case 1: 
		lecture_p(game);
		break;
	case 2:
		chat_p(game);
		break;
	case 3:
		practice_p(game);
		break;
	case 4:
		attend_p(game);
		break;
	case 5:
		smallTest_p(game);
		break;
	case 6:
		wakingUp_p(game);
		break;
	case 7: 
		answerQuestion_p(game);
		break;
	default:

		break;
	}
}

void p_endturn(status* game) {

}

void attend_p(status* game) {

}

void lecture_p(status* game) {
	int awake = 0;
	awake = findOn_p(game->student_list);
	game->choi->progress += awake;
	game->choi->move -= 1;
	return;
}
void chat_p(status* game) {
	int awake = 0;
	awake = findOn_p(game->student_list);
	game->choi->chat += awake;
	game->choi->move -= 1;
	return;
}
void practice_p(status* game) {
	int attend = 0;
	attend = isAttend_p(game->student_list);
	game->choi->progress += (attend * 2);
	game->choi->move -= 3;
	return;
}
void announce_st_p(status* game) {

}
void smallTest_p(status* game) {
	int attend = 0;
	attend = isAttend_p(game->student_list);
	game->choi->progress += (attend * 2);
	game->choi->test++;
	game->choi->move -= 5;
	return;
}
void wakingUp_p(status* game) {
	int i = 0;
	for (i = 0; i < STD_AMOUNT; i++) {
		game->student_list[i]->isWake = 1;
	}
	game->choi->move -= 1;
	return;
}
void answerQuestion_p(status* game) {

}

void nextDay_p(status* game) {

}
void endSemester_p(status* game) {

}


int findOn_p(student** std_list) {//출석하고 깨어 있는 학생 수 리턴
	int i = 0;
	int much = 0;

	for (i = 0; i < STD_AMOUNT; i++) {
		if (std_list[i]->isAttend && std_list[i]->isWake) {
			much++;
		}
	}

	return much;
}

int isAttend_p(student** std_list) {
	int i = 0;
	int much = 0;

	for (i = 0; i < STD_AMOUNT; i++) {
		if (std_list[i]->isAttend) {
			much++;
		}
	}

	return much;
}

void statusCheck_p(status* game) {

}