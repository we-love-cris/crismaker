#include "acad_day.h"

int acad_main(status* game) {
	int chosenWeek = 0;
	int toWeek = 0;
	int flag = 1;
	while (flag) {
		chosenWeek = 1;
		toWeek = 1;
		v_board();
		v_acad_cal(game->academic_calender);
		chosenWeek = choose_week(chosenWeek, ACADEMIC_WEEK);
		if (chosenWeek == -100) return 0;
		gotoxy(60, 4); printf("<어떤 일정으로 바꿀까요?>");
		v_acad_days(game->db->default_days);
		toWeek = choose_toWeek(ACAD_TYPES);
		if (toWeek == -100) return 0;

		switch (toWeek) {
		case 1:
			toWeek = 2;
			break;
		case 2:
			toWeek = 1;
			break;
		case 3:
			toWeek = 6;
			break;
		case 4:
			toWeek = 8;
			break;
		case 5:
			toWeek = 5;
			break;
		case 6:
			toWeek = 3;
			break;
		}

		set_day(chosenWeek - 1, toWeek - 1, game->db, game->academic_calender);

		
		v_week_indi(chosenWeek, "  ");
		v_clear_right();
	}
}

//db의 default_days를 설정
void make_default_days(day** default_days) {
	int j = 0;
	int i = 0;
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
	default_days[0]->attend_rate = OT_ATTEND_RATE;
	default_days[0]->move = OT_MOVE;
	default_days[0]->type = 1;

	//수업
	for (j = 0; j < 3; j++) {
		if (j == 0) i = 1;
		if (j == 1) i = 3;
		if (j == 2) i = 6;
		default_days[i]->attend_rate = CLASS_ATTEND_RATE;
		default_days[i]->move = CLASS_MOVE;
		default_days[i]->type = 0;
	}

	//공휴일
	default_days[2]->attend_rate = HOLI_ATTEND_RATE;
	default_days[2]->move = HOLI_MOVE;
	default_days[2]->type = 5;

	//축제
	default_days[4]->attend_rate = FESTIV_ATTEND_RATE;
	default_days[4]->move = FESTIV_MOVE;
	default_days[4]->type = 4;

	//팀플
	default_days[5]->attend_rate = TP_ATTEND_RATE;
	default_days[5]->move = TP_MOVE;
	default_days[5]->type = 2;
	default_days[5]->isTp = 1;

	//시험
	default_days[7]->attend_rate = TEST_ATTEND_RATE;
	default_days[7]->move = TEST_MOVE;
	default_days[7]->type =3 ;
	

	return;
}

void set_day(int week, int forweek, database* db, day** acad) {
	acad[week]->attend_rate = db->default_days[forweek]->attend_rate;
	acad[week]->move = db->default_days[forweek]->move;
	acad[week]->type = db->default_days[forweek]->type;
	
	return;
}

int choose_week(int chosen, int max) {
	int get = 0;
	v_week_indi(chosen, "▶");
	while (get != ENTER) {
		get = get_wasd();
		v_week_indi(chosen, "  ");
		if (chosen < max && (get == DOWN || get == RIGHT)) {//아래나 오른쪽 누르면
			chosen++;//선택메뉴 증가
		}
		else if (chosen > 1 && (get == UP)) {//위누르면
			chosen--;//선택메뉴 감소
		}
		else if (chosen > 1 && (get == LEFT)) {
			return -100;
		}
		v_week_indi(chosen, "▶");
	}
	//v_week_indi(chosen, "  ");

	return chosen;
}

int choose_toWeek(int max) {
	int chosen = 1;
	int get = 0;
	v_toWeek_indi(chosen, "▶");
	while (get != ENTER) {
		get = get_wasd();
		v_toWeek_indi(chosen, "  ");
		if (chosen < max && (get == DOWN || get == RIGHT)) {//아래나 오른쪽 누르면
			chosen++;//선택메뉴 증가
		}
		else if (chosen > 1 && (get == UP)) {//위누르면
			chosen--;//선택메뉴 감소
		}
		else if (chosen > 1 && (get == LEFT)) {
			return -100;
		}
		v_toWeek_indi(chosen, "▶");
		v_toWeek_info(chosen);
	}
	v_toWeek_indi(chosen, "  ");

	return chosen;
}
