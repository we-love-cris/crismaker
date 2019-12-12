#include "view.h"

void v_start() {

}

void v_main_menu() {
	gotoxy(17, 7); printf("게임시작");
	gotoxy(15, 9); printf("학사일정 수정");
	gotoxy(15, 11); printf("시험문제 수정");
	gotoxy(17, 13); printf("게임종료");

	return;
}

void v_profvsstd() {
	gotoxy(16, 7); printf("교 수 모 드");
	gotoxy(16, 9); printf("학 생 모 드");
}

void v_acad_cal(day** acad_cal) {
	int i = 0;
	int type;
	char* name = (char*)malloc(sizeof(char) * 10);
	for (i = 0; i < ACADEMIC_WEEK; i++) {
		type = acad_cal[i]->type;
		name = util_day(type);
		gotoxy(17, 4 + 3 * i); printf("%d 주차 : %s", i + 1, name);
	}
	gotoxy(17, 4 + 3 * i); printf("나가려면 <-를 누르세요");
	free(name);
	return;
}

void v_acad_days(day** default_days) {
	char* name;
	int i = 0;
	for (i = 0; i < ACAD_TYPES; i++) {
		name = util_day(i);
		gotoxy(70, 7 + 3 * i); printf("%s", name);
	}
	free(name);
	return;
}

//▶표시하는 녀석
void v_menu_indi(int chosen, char ch[3]) {
	int go = 5 + 2 * chosen;
	gotoxy(12, go);
	printf("%s", ch);

	return;
}
void v_week_indi(int chosen, char ch[3]) {
	int go = 1 + 3 * chosen;
	gotoxy(12, go);
	printf("%s", ch);

	return;
}
void v_toWeek_indi(int chosen, char ch[3]) {
	int go = 4 + 3 * chosen;
	gotoxy(65, go);
	printf("%s", ch);

	return;
}
void v_toWeek_info(int chosen) {
	gotoxy(2, 32);

	//아직 미완성
}


//메뉴 화면이 나올 테두리 표시하기
void v_menusquare() {
	int i = 0;
	gotoxy(0, 0); printf("┌");
	v_row(0, MENU_HOR);
	gotoxy(MENU_HOR + 2, 0); printf("┐");
	v_ver(0, MENU_HOR + 2, 1, MENU_VER);
	gotoxy(0, MENU_VER + 1); printf("└");
	v_row(MENU_VER + 1, MENU_HOR);
	gotoxy(MENU_HOR + 2, MENU_VER + 1); printf("┘");
	return;
}

void v_board() {
	int i = 0;

	gotoxy(0, 0); printf("┌");
	v_row(0, VIEW_HOR);
	gotoxy(VIEW_HOR + 2, 0); printf("┐");

	v_ver(0, VIEW_HOR + 2, 1, VIEW_MAIN_VER);

	gotoxy(0, VIEW_MAIN_VER + 1); printf("├");
	v_row(VIEW_MAIN_VER + 1, VIEW_HOR);
	gotoxy(VIEW_HOR + 2, 31); printf("┤");

	v_ver(0, VIEW_HOR + 2, VIEW_MAIN_VER + 2, VIEW_INFO_VER);
	
	gotoxy(0, VIEW_MAIN_VER + VIEW_INFO_VER + 2); printf("└");
	v_row(VIEW_MAIN_VER + VIEW_INFO_VER + 2, VIEW_HOR);
	gotoxy(VIEW_HOR + 2, VIEW_MAIN_VER + VIEW_INFO_VER + 2); printf("┘");

	return;
}

void v_row(int height, int amount) {
	int i = 0;

	gotoxy(i + 2, height);
	for (i = 0; i < amount; i += 2) {
		printf("─");
	}
	return;
}

void v_ver(int start, int end, int height, int amount) {
	int i = 0;

	for (i = height; i < height + amount; i++) {
		gotoxy(start, i);
		printf("│");
		gotoxy(end, i);
		printf("│");
	}

	return;
}

void v_clear_menusquare() {
	int i = 0;

	
	for (i = 1; i < MENU_VER + 1; i++) {
		gotoxy(2, i);
		printf("                                        ");
	}

	return;
}

void v_clear_right() {
	int i = 0;
	for (i = 1; i < VIEW_MAIN_VER; i++) {
		gotoxy(50, i); printf("                                                  ");
	}
}

void v_clear_optbox() {
	int i = 32;
	for (i = 32; i < VIEW_INFO_VER + 32; i++) {
		gotoxy(2, i); printf("                                                                                                         ");
	}
}

void v_clearall() {
	int i = 0;

	for(i = 0; i < 50; i++)
	printf("                                                                                                         ");
	
	return;
}

void v_main_game_show_p(status* game, int* work) {
	int i = 0;
	int y = 0;

	for (i = 0; i < STD_AMOUNT; i++) {
		v_attend(i, game->student_list[i]->isAttend, game->student_list[i]->isWake);
	}

	y = 30;
	for (i = 8; i >= 0; i--) {
		if (work[i]) {
			gotoxy(2, y);
			switch (i) {
			case 0: printf("1. 강의하기    "); break;
			case 1: printf("2. 잡담하기    "); break;
			case 2: printf("3. 실습하기    "); break;
			case 3: printf("4. 출석하기    "); break;
			case 4: printf("5. 쪽지시험    "); break;
			case 5: printf("6. 깨우기      "); break;
			case 6: printf("7. 질문 답하기 "); break;
			case 7: printf("8. 팀플 공지   "); break;
			case 8: printf("9. 쪽지시험공지"); break;
			}
			y--;
		}
	}
	for (y; y >= 22; y--) {
		gotoxy(2, y); printf("               ");
	}
	v_prof_status(game);

}

void v_main_game_frame_p() {
	int i = 0, j = 0, k = 0;
	int x[3] = { 17, 45, 73 };
	int y = 0;

	y = 6;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			gotoxy(x[j], y); printf("┌────┐");
		}
		y++;
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				gotoxy(x[k], y); printf("│        │");
			}
			y++;
		}
		for (j = 0; j < 3; j++) {
			gotoxy(x[j], y); printf("└────┘");
		}
		y += 3;
	}

	return;
}

void v_attend(int std_no, int isAttend, int isWake) {
	//10 17 24 31
	//22,23 50,51 78,79
	

	int x = std_no % 3;
	int y = std_no / 3;

	switch (x) {
	case 0: x = 22; break;
	case 1: x = 50; break;
	case 2: x = 78; break;
	}

	switch (y) {
	case 0: y = 10; break;
	case 1: y = 16; break;
	case 2: y = 22; break;
	case 3: y = 28; break;
	}

	gotoxy(x, y);
	if (isAttend) {
		printf("○");
		if (isWake) {
			gotoxy(x + 2, y + 1); printf("      ");
		}
		else {
			gotoxy(x + 2, y + 1); printf("Zzz...");
		}
	}
	else {
		printf("  ");
		gotoxy(x + 2, y + 1); printf("      ");
	}

	return;
}
void v_gohome() {
	int x[3] = { 22, 50, 78 };
	int y[4] = { 10, 16, 22, 28 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(x[i], y[j]);
			printf("  ");
			gotoxy(x[i] + 2, y[j] + 1);
			printf("      ");
		}
	}
}

void v_prof_status(status* game) {
	int x = 3, y = 32;
	int week = game->week;

	gotoxy(x, y); printf("<교수 %s 정보>", game->choi->name); y++;
	gotoxy(x, y); printf("행동력    : %-5d", game->choi->move); y++;
	gotoxy(x, y); printf("현재 진도 : %-5d", game->choi->progress); y++;
	gotoxy(x, y); printf("학생 흥미 : %-5d", game->choi->chat); y++;
	gotoxy(x, y); printf("시험 횟수 : %-5d", game->choi->test); y++;
	gotoxy(x, y); printf("팀플 횟수 : %-5d", game->choi->assignment); y++;
	
	x = 50; y = 32;
	gotoxy(x, y); printf("<%d 주차 정보>", week + 1); y++;
	gotoxy(x, y); printf("수업 내용   : %-10s", util_day(game->academic_calender[week]->type)); y++;
	gotoxy(x, y); printf("예상 출석률 : %d0%%", game->academic_calender[week]->attend_rate); y++;
	gotoxy(x, y); printf(""); y++;
	gotoxy(x, y); printf(""); y++;
	gotoxy(x, y); printf(""); y++;
}

void v_end_game_p(char* score) {
	int temp = 0;
	v_clearall();

	gotoxy(46, 5); printf("진도 점수 : ");
	Sleep(500); printf("%c", score[0]); Sleep(500);
	gotoxy(46, 7); printf("흥미 점수 : ");
	Sleep(500); printf("%c", score[1]); Sleep(500);
	gotoxy(46, 9); printf("팀플 평가 : ");
	Sleep(500); printf("%c", score[2]); Sleep(500);
	gotoxy(46, 11); printf("시험 평가 : ");
	Sleep(500); printf("%c", score[3]); Sleep(500);
	gotoxy(46, 13); printf("최종 평가 : ");
	Sleep(1000); printf("%c", score[4]);

	gotoxy(46, 20); printf("Press enter");
	while(temp != 13) temp = getch();

}

void v_main_game_show_s(status* game, int* work) {
	int i = 0;
	int y = 0;

	for (i = 0; i < STD_AMOUNT; i++) {
		v_attend(i, game->student_list[i]->isAttend, game->student_list[i]->isWake);
	}
	if (game->student_list[game->std_no]->isAttend) {
		int x = game->std_no % 3;
		int yy = game->std_no / 3;

		switch (x) {
		case 0: x = 22; break;
		case 1: x = 50; break;
		case 2: x = 78; break;
		}

		switch (yy) {
		case 0: yy = 10; break;
		case 1: yy = 16; break;
		case 2: yy = 22; break;
		case 3: yy = 28; break;
		}
		gotoxy(x, yy); printf("★");
	}

	y = 30;
	for (i = 5; i >= 0; i--) {
		if (work[i]) {
			gotoxy(2, y);
			switch (i) {
			case 0: printf("1. 노트필기하기"); break;
			case 1: printf("2. 개인코딩하기"); break;
			case 2: printf("3. 웹툰 보기   "); break;
			case 3: printf("4. 출튀하기    "); break;
			case 4: printf("5. 출튀복귀    "); break;
			case 5: printf("6. 졸기        "); break;
			}
			y--;
		}
	}
	for (y; y >= 22; y--) {
		gotoxy(2, y); printf("               ");
	}
	v_std_status(game);


}

void v_std_status(status* game) {
	int x = 3, y = 32;
	int week = game->week;
	student* me = game->student_list[game->std_no];
	
	gotoxy(x, y); printf("<학생 %s 정보>", me->name), y++;
	gotoxy(x, y); printf("행동력 : %-5d", me->move); y++;
	gotoxy(x, y); printf("행복도 : %-5d", me->happiness); y++;
	gotoxy(x, y); printf("진도   : %-5d", me->progress); y++;
	gotoxy(x, y); printf("실력   : %-5d", me->skill); y++;
	gotoxy(x, y); printf("피로도 : %-5d", me->tired); y++;

	x = 50; y = 32;
	gotoxy(x, y); printf("<%d 주차 정보>", week + 1); y++;
	gotoxy(x, y); printf("수업 내용   : %-10s", util_day(game->academic_calender[week]->type)); y++;
	gotoxy(x, y); printf("예상 출석률 : %d0%%", game->academic_calender[week]->attend_rate); y++;
}

void v_what_prof_do(int isProgress) {
	gotoxy(50, 35);
	if (isProgress)
		printf("현재 교수님 : 수업 중");
	else {
		printf("현재 교수님 : 잡담 중");
	}
}

void v_end_game_s(char* score) {
	int temp = 0;
	v_clearall();

	gotoxy(46, 5); printf("진도 점수 : ");
	Sleep(500); printf("%c", score[0]); Sleep(500);
	gotoxy(46, 7); printf("출석 점수 : ");
	Sleep(500); printf("%c", score[1]); Sleep(500);
	gotoxy(46, 9); printf("실력 점수 : ");
	Sleep(500); printf("%c", score[2]); Sleep(500);
	gotoxy(46, 13); printf("최종 평가 : ");
	Sleep(1000); printf("%c", score[4]);

	gotoxy(46, 20); printf("Press enter");
	while (temp != 13) temp = getch();
}