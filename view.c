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

//▶표시하는 녀석
void v_menu_indi(int chosen, char ch[3]) {
	int go = 5 + 2 * chosen;
	gotoxy(12, go);
	printf("%s", ch);

	return;
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

void v_clearall() {
	int i = 0;

	for(i = 0; i < 50; i++)
	printf("                                                                                                         \n");
	
	return;
}
