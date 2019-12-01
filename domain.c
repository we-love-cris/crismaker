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
