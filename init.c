#include "init.h"

void init_status(status* game) {

}


void make_status(status* game) {

}
void make_student(student* std) {
	std->attend_count = 0;
	std->attend_rate = 0;
	std->happiness = 0;
	std->move = 0;
	std->progress = 0;
	std->skill = 0;
	std->tired = 0;
	std->type = 2;

	std->name = "";
}
void make_player_p(player_p* choi) {
	choi->assignment = 0;
	choi->chat = 0;
	choi->move = 0;
	choi->progress = 0;
	choi->test = 0;
	choi->type = 0;

	choi->name = "";
}
void make_prof(prof* pp) {
	pp->chat_rate = 0;
	pp->progress_rate = 0;
	pp->type = 0;

	pp->name = "";
}
void make_day(day* wk) {
	wk->attend_rate = 0;
	wk->move = 0;
	wk->type = 0;
}