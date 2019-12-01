#include "view.h"

void v_start() {

}

void v_main_menu() {
	gotoxy(45, 5); printf("게 임 시 작");
	gotoxy(42, 8); printf("학 사 일 정  수 정");
	gotoxy(42, 11); printf("시 험 문 제  수 정");
	gotoxy(45, 14); printf("게 임 종 료");

	return;
}

void v_profvsstd() {
	gotoxy(45, 5); printf("교 수 모 드");
	gotoxy(45, 8); printf("학 생 모 드");
}

void v_menu_indi(int chosen, char ch[3]) {
	int go = 2 + 3 * chosen;
	gotoxy(38, go);
	printf("%s", ch);

	return;
}

void v_menusquare() {
	int i = 0;
	v_board();
	gotoxy(2, VIEW_MAIN_VER + 1);
	for (i = 2; i < VIEW_HOR + 2; i++)
		printf(" ");
	v_ver(0, VIEW_HOR + 2, VIEW_MAIN_VER + 1, 1);
	return;
}

void v_board() {
	int i = 0;

	gotoxy(0, 0); printf("┌");
	v_row(0);
	gotoxy(VIEW_HOR + 2, 0); printf("┐");

	v_ver(0, VIEW_HOR + 2, 1, VIEW_MAIN_VER);

	gotoxy(0, VIEW_MAIN_VER + 1); printf("├");
	v_row(VIEW_MAIN_VER + 1);
	gotoxy(VIEW_HOR + 2, 31); printf("┤");

	v_ver(0, VIEW_HOR + 2, VIEW_MAIN_VER + 2, VIEW_INFO_VER);
	
	gotoxy(0, VIEW_MAIN_VER + VIEW_INFO_VER + 2); printf("└");
	v_row(VIEW_MAIN_VER + VIEW_INFO_VER + 2);
	gotoxy(VIEW_HOR + 2, VIEW_MAIN_VER + VIEW_INFO_VER + 2); printf("┘");

	return;
}

void v_row(int height) {
	int i = 0;

	gotoxy(i + 2, height);
	for (i = 0; i < VIEW_HOR; i += 2) {
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

void v_clearall() {
	for(int i = 0; i < 50; i++)
	printf("                                                                                                         \n");
	return;
}
