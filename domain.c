#include "domain.h"

int select_main_menu(int amount) {
	int ret = 0;
	v_clear_menusquare();
	v_menusquare();
	v_main_menu();
	ret = choose_menu(amount);

	return ret;
}

int select_profvsstd(int amount) {
	int ret = 0;
	v_clear_menusquare();
	v_menusquare();
	v_profvsstd();
	ret = choose_menu(amount);

	return ret;
}

int choose_menu(int max) {
	int chosen = 1;
	int get = 0;
	v_menu_indi(chosen, "▶");
	while (get != ENTER) {
		get = get_wasd();
		v_menu_indi(chosen, "  ");
		if (chosen < max && (get == DOWN || get == RIGHT)) {//아래나 오른쪽 누르면
			chosen++;//선택메뉴 증가
		}
		else if (chosen > 1 && (get == UP || get == LEFT)) {//위나 왼쪽 누르면
			chosen--;//선택메뉴 감소
		}
		v_menu_indi(chosen, "▶");
	}
	v_menu_indi(chosen, "  ");

	return chosen;
}

void get_prof_name(player_p* choi) {
	int a = -1, i = 0;
	char temp[100] = "";

	v_clear_menusquare();

	gotoxy(5, 5); printf("플레이할 교수의 이름을 정해 주세요");
	while (a == -1) {
		gotoxy(13, 7);
		a = get_string(temp, STRING_LENGTH);
		Sleep(1000);
	}
	choi->name = (char*)malloc(sizeof(char) * (a + 1));
	for (i = 0; i < a + 1; i++) {
		choi->name[i] = temp[i];
	}

	return;
}

void get_std_name(student* me) {
	int a = -1, i = 0;
	char temp[100] = "";

	v_clear_menusquare();

	gotoxy(5, 5); printf("플레이할 학생의 이름을 정해 주세요");
	while (a == -1) {
		gotoxy(13, 7);
		a = get_string(temp, STRING_LENGTH);
		Sleep(1000);
	}
	me->name = (char*)malloc(sizeof(char) * (a + 1));
	for (i = 0; i < a + 1; i++) {
		me->name[i] = temp[i];
	}

	return;
}
