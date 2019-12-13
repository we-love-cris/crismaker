#include "play_game.h"

int play_game_prof(status* game) {//교수 모드의 메인
	int week = 0;
	int does = 0;
	int work[9];
	int i = 0;
	int ret = 0;

	memset(work, 0, sizeof(work));
	work[0] = 1; work[1] = 1; work[8] = 1;
	start_game_p(game);// 학기 단위

	for(week = 0; week < ACADEMIC_WEEK; week++) {// 주 단위
		start_day_p(game, week, work);

		while (game->choi->move > 0) {//하루 단위
			configureWork(game->choi, work);
			v_main_game_show_p(game, work);
			does = do_what_p(work);
			p_do(game, does);
			p_endturn(game);
		}
		nextDay_p(game);

	}
	ret = endSemester_p(game);
	
	return ret;
}

int play_game_std(status* game) {//학생 모드의 메인
	int week = 0;
	int does = 0;
	int over = 0;
	int work[6];
	int isProgress = 0;
	int ret = 0;

	memset(work, 0, sizeof(work));
	work[0] = 1; work[1] = 1; work[2] = 1; work[3] = 1; work[5] = 1;

	start_game_s(game);
	for (week = 0; week < ACADEMIC_WEEK; week++) {
		start_day_s(game, week, work);
		
		while (game->student_list[game->std_no]->move > 0) {
			isProgress = figureChatorClass(game->pp);
			v_main_game_show_s(game, work);
			v_what_prof_do(isProgress);
			does = do_what_s(work);
			s_do(game, does, isProgress, work);
			over = s_endturn(game);
			if (over) return 0;
			
		}

		evening_day(game);
		over = statusCheck_s(game);
		if (over) return 0;
		
		nextDay_s(game);
	}

	endSemester_s(game);

	return 1;
}

void start_day_p(status* game, int week, int* work) {
	int move = 0;
	int attend = 0;
	int i = 0;
	int temp = 0;
	day* today = game->academic_calender[week];


	srand((unsigned)time(NULL));

	move = game->academic_calender[week]->move;
	attend = game->academic_calender[week]->attend_rate;
	
	for (i = 0; i < STD_AMOUNT; i++) {
		game->student_list[i]->attend_rate = game->academic_calender[game->week]->attend_rate;
	}

	game->choi->move = move;
	for (i = 0; i < STD_AMOUNT; i++) { // 학생들 출석시키기
		temp = (rand() % 10) + 1;
		if (temp > game->student_list[i]->attend_rate) {
			game->student_list[i]->isAttend = 0;
		}
		else game->student_list[i]->isAttend = 1;
		game->student_list[i]->isWake = 1;
	}
	
	if (today->type == 3) // 시험날
		game->choi->test++;

	if (today->isSt) work[4] = 1; // 쪽지시험날
	else work[4] = 0;

	if (today->type == 2) { // 팀플날
		game->academic_calender[week]->isTp = 1;
		if (!game->choi->didAnnTp) game->choi->chat -= 100;
		game->choi->didAnnTp = 0;
	}

	if (week < ACADEMIC_WEEK - 2) {
		if (game->academic_calender[week + 2]->type == 2)
			work[7] = 1;
		else work[7] = 0;
	}


	return;
}

void start_game_p(status* game) {
	int i = 0;

	game->week = 0;

	game->db->func_list.screen_size[1]();
	v_board();
	v_main_game_frame_p();

	game->choi->assignment = 0;
	game->choi->chat = 0;
	game->choi->progress = 0;
	game->choi->test = 0;
	game->choi->didAnnSt = 0;
	game->choi->didAnnTp = 0;
	game->choi->didWake = 0;


	return;
}
void p_endturn(status* game) {


	if (!game->choi->didWake) {
		snooze_p(game->student_list);
	}
	game->choi->didWake = 0;


}

int do_what_p(int* work) {
	int temp = 0;
	while (1) {
		temp = getch();
		if ('1' <= temp && temp <= '9') {
			if (work[temp - '1']) break;
		}
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
	case 8:
		announce_tp_p(game);
		break;
	case 9:
		announce_st_p(game);
		break;
	default:

		break;
	}
}

void attend_p(status* game) {
	int i = 0;
	int temp = 0;
	for (i = 0; i < STD_AMOUNT; i++) {
		if (!game->student_list[i]->isAttend) {
			srand((unsigned)time(NULL));
			temp = (rand() * i % 10) + 1;
			if (temp < 8)
				game->student_list[i]->isAttend = 1;
		}
	}
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
	int week = game->week;
	game->choi->move -= 1;

	if (week >= ACADEMIC_WEEK - 1) return;
	game->academic_calender[week + 1]->attend_rate += 2;
	game->academic_calender[week + 1]->isSt = 1;
	game->choi->didAnnSt = 1;

	return;
}
void announce_tp_p(status* game) {
	int week = game->week;
	game->choi->move -= 1;

	game->academic_calender[week + 2]->attend_rate += 2;
	game->choi->didAnnTp = 1;

	return;
}
void smallTest_p(status* game) {
	int attend = 0;
	attend = isAttend_p(game->student_list);
	game->choi->progress += (attend * 4);
	game->choi->test++;
	game->choi->move -= 10;
	game->choi->didAnnSt = 0;
	return;
}
void wakingUp_p(status* game) {
	int i = 0;
	for (i = 0; i < STD_AMOUNT; i++) {
		game->student_list[i]->isWake = 1;
	}
	game->choi->move -= 2;
	game->choi->didWake = 1;
	return;
}
void answerQuestion_p(status* game) {

}

void nextDay_p(status* game) {
	v_clear_optbox();
	game->week++;
}
int endSemester_p(status* game) {
	char score[5];
	int total = 0;
	int progress = game->choi->progress,
		chat = game->choi->chat,
		tp = game->choi->assignment,
		test = game->choi->test;
	/*
	0. progress
	1. chat
	2. tp
	3. test
	4. All
	*/
	if (progress < 500) score[0] = 'F';
	else if (progress < 600) score[0] = 'D';
	else if (progress < 700) score[0] = 'C';
	else if (progress < 800) score[0] = 'B';
	else if (progress < 900) score[0] = 'A';
	total += ('F' - score[0]);

	if (chat < 300) score[1] = 'F';
	else if (chat < 400) score[1] = 'D';
	else if (chat < 500) score[1] = 'C';
	else if (chat < 600) score[1] = 'B';
	else if (chat < 700) score[1] = 'A';
	total += ('F' - score[1]);

	if (tp == 0 || tp >= 3) score[2] = 'F';
	else if (tp == 1) score[2] = 'A';
	else score[2] = 'B';
	total += ('F' - score[2]);

	if (test == 0 || test >= 2) score[3] = 'N';
	else {score[3] = 'P'; total += 5; }

	if (total >= 18) score[4] = 'A';
	else if (total >= 15) score[4] = 'B';
	else if (total >= 10) score[4] = 'C';
	else if (total >= 5) score[4] = 'D';
	else score[4] = 'F';


	v_end_game_p(score);

	free(game->choi->name);
	return 1;
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
void snooze_p(student** std_list) {
	int i = 0;
	int temp = 0;
	for (i = 0; i < STD_AMOUNT; i++) {
		srand((unsigned)time(NULL));
		do {
			temp = rand();
		} while (temp % 10 == 0);
		temp = (temp * i % 10) + 1;
		if (temp < 2 || !std_list[i]->isWake)
			std_list[i]->isWake = 0;
		else
			std_list[i]->isWake = 1;
	}
}
void configureWork(player_p* choi, int* work) {
	int move = choi->move;
	if (move < 10) work[4] = 0; else work[4] = 1;
	if (move < 3) work[2] = 0; else work[2] = 1;
	if (move < 2) {
		work[3] = 0; work[5] = 0;
	}
	else { work[3] = 1; work[5] = 1; }

	return;
}


int statusCheck_p(status* game) {

}

void start_game_s(status* game) {
	int i = 0;

	game->week = 0;

	game->db->func_list.screen_size[1]();
	v_board();
	v_main_game_frame_p();

	game->student_list[game->std_no]->happiness = 90;
	game->student_list[game->std_no]->attend_count = 0;
	game->student_list[game->std_no]->progress = 0;
	game->student_list[game->std_no]->skill = 0;
	game->student_list[game->std_no]->tired = 0;

	return;
}
void start_day_s(status* game, int week, int* work) {
	int move = 0;
	int attend = 0;
	int i = 0;
	int temp = 0;
	int doClass = 0;
	day* today = game->academic_calender[week];

	srand((unsigned)time(NULL));
	doClass = rand() % 3 + 8;

	game->pp->progress_rate = doClass;
	game->pp->chat_rate = 10 - doClass;

	
	move = game->academic_calender[week]->move;
	attend = game->academic_calender[week]->attend_rate;

	for (i = 0; i < STD_AMOUNT; i++) {
		game->student_list[i]->attend_rate = game->academic_calender[game->week]->attend_rate;
	}
	game->student_list[game->std_no]->move = move;
	for (i = 0; i < STD_AMOUNT; i++) { // 학생들 출석시키기
		temp = (rand() % 10) + 1;
		if (temp > game->student_list[i]->attend_rate) {
			game->student_list[i]->isAttend = 0;
		}
		else game->student_list[i]->isAttend = 1;
		game->student_list[i]->isWake = 1;
	}
	game->student_list[game->std_no]->isAttend = 1;


	if (today->type == 2) { // 팀플날
		game->academic_calender[week]->isTp = 1;
	}

	game->student_list[game->std_no]->attend_count++;

	return;

}
int figureChatorClass(prof* pp) {
	int temp = 0;
	srand((unsigned)time(NULL));

	temp = rand() % 10 + 1;
	if (pp->progress_rate >= temp)
		return 1;
	else return 0;
}
int s_endturn(status* game) {
	snooze_p(game->student_list);
	game->student_list[game->std_no]->isWake = 1;
	statusCheck_s(game);
}

int do_what_s(int* work) {
	int temp = 0;
	while (1) {
		temp = getch();
		if ('1' <= temp && temp <= '6') {
			if (work[temp - '1']) break;
		}
	}

	return temp - '0';
}
void s_do(status* game, int does, int isProgress, int* work) {
	switch (does) {
	case 1:
		takeNote_s(game, isProgress);
		break;
	case 2:
		coding_s(game, isProgress);
		break;
	case 3:
		webtoon_s(game);
		break;
	case 4:
		runaway_s(game, work);
		break;
	case 5:
		comeback_s(game, work);
		break;
	case 6:
		snooze_s(game);
		break;
	}
}

void takeNote_s(status* game, int isProgress) {
	game->student_list[game->std_no]->happiness -= 5;
	game->student_list[game->std_no]->move -= 1;
	game->student_list[game->std_no]->skill += 5;
	game->student_list[game->std_no]->progress += (5 * (isProgress + 1));
	game->student_list[game->std_no]->tired += 1;

	return;
}
void coding_s(status* game, int isProgress) {
	game->student_list[game->std_no]->happiness -= 5;
	game->student_list[game->std_no]->move -= 1;
	game->student_list[game->std_no]->skill += 5;
	game->student_list[game->std_no]->progress += (5 * (2 - isProgress));
	game->student_list[game->std_no]->tired += 1;

	return;
}
void webtoon_s(status* game) {
	game->student_list[game->std_no]->happiness += 5;
	game->student_list[game->std_no]->move -= 1;
	game->student_list[game->std_no]->tired += 1;

	return;
}
void runaway_s(status* game, int* work) {
	int i = 0;
	game->student_list[game->std_no]->move -= 5;
	game->student_list[game->std_no]->tired += 5;
	game->student_list[game->std_no]->happiness += 10;
	game->student_list[game->std_no]->isAttend = 0;
	for (i = 0; i < 6; i++) {
		work[i] = 0;
	}
	work[3] = 1;
	work[4] = 1;

	return;
}
void comeback_s(status* game, int* work) {
	int i = 0;
	game->student_list[game->std_no]->move -= 5;
	game->student_list[game->std_no]->tired += 5;
	game->student_list[game->std_no]->isAttend = 1;
	for (i = 0; i < 6; i++) {
		work[i] = 1;
	}
	work[4] = 0;

	return;
}
void snooze_s(status* game) {
	game->student_list[game->std_no]->move -= 2;
	game->student_list[game->std_no]->tired -= 10;
	game->student_list[game->std_no]->happiness += 3;

	return;
}

void evening_day(status* game) {
	int temp = 0;

	v_clear_optbox();
	gotoxy(2, 32); printf("<수업을 마치고 집에 오셨습니다>");
	gotoxy(2, 33); printf("무엇을 할까요?");
	gotoxy(2, 34); printf("1. 공부하기");
	gotoxy(2, 35); printf("2. 술마시기");
	gotoxy(2, 36); printf("3. 잠자기");
	while (1) {
		temp = getch();
		int a = temp - '0';
		switch (a) {
		case 1:
			study_s(game);
			break;
		case 2:
			drunk_s(game);
			break;
		case 3:
			sleep_s(game);
			break;
		}
		if (1 <= a && a <= 3) break;
	}

}
void study_s(status* game) {
	game->student_list[game->std_no]->happiness -= 10;
	game->student_list[game->std_no]->progress += 30;
	game->student_list[game->std_no]->skill += 30;
	game->student_list[game->std_no]->tired += 10;
}
void drunk_s(status* game) {
	game->student_list[game->std_no]->happiness += 20;
	game->student_list[game->std_no]->tired += 20;
}
void sleep_s(status* game) {
	game->student_list[game->std_no]->happiness += 10;
	game->student_list[game->std_no]->tired -= 40;
}



int statusCheck_s(status* game) {
	if (game->student_list[game->std_no]->happiness <= 0) return 1;
	if (game->student_list[game->std_no]->tired >= 100) return 1;

	if (game->student_list[game->std_no]->happiness >= 100)game->student_list[game->std_no]->happiness = 100;
	if (game->student_list[game->std_no]->tired <= 0) game->student_list[game->std_no]->tired = 0;

	return 0;
}

void endClass_s(status* game) {
	v_clear_optbox();
	v_gohome();
}
void nextDay_s(status* game) {
	v_clear_optbox();
	game->week++;
}
void endSemester_s(status* game) {
	char score[5];
	int total = 0;
	int progress = game->student_list[game->std_no]->progress,
		attend_count = progress = game->student_list[game->std_no]->attend_count,
		skill = progress = game->student_list[game->std_no]->skill;
	/*
	0. progress
	1. attend_count
	2. skill
	3. 
	4. All
	*/
	if (progress < 100) score[0] = 'F';
	else if (progress < 150) score[0] = 'D';
	else if (progress < 200) score[0] = 'C';
	else if (progress < 250) score[0] = 'B';
	else if (progress < 300) score[0] = 'A';
	total += ('F' - score[0]);

	if (attend_count < 2) score[1] = 'F';
	else if (attend_count < 3) score[1] = 'D';
	else if (attend_count < 4) score[1] = 'C';
	else if (attend_count < 6) score[1] = 'B';
	else if (attend_count < 9) score[1] = 'A';
	total += ('F' - score[1]);

	if (skill < 100) score[2] = 'F';
	else if (skill < 150) score[2] = 'D';
	else if (skill < 200) score[2] = 'C';
	else if (skill <250) score[2] = 'B';
	else if (skill < 300) score[2] = 'A';
	total += ('F' - score[2]);

	if (total >= 12) score[4] = 'A';
	else if (total >= 9) score[4] = 'B';
	else if (total >= 5) score[4] = 'C';
	else if (total >= 3) score[4] = 'D';
	else score[4] = 'F';


	v_end_game_s(score);
}
