#ifndef __ANTS_H_INCLUDED__
#define __ANTS_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <random>
#include <array>

class ants
{
private:
	 std::array<bool, 100 * 100> plain, temp_plain;
	 bool flag_up = false, flag_down = false, flag_right = false, flag_left = false;
public:
	int random_ants();
	ants();
	~ants();
	void print_ants();
	void check_life();
	void print_ants1();
	void print_ants2();
	void print_temp();
	bool left_check(int i, int j);
	bool right_check(int i, int j);

	void kill(int i, int j);
	void god();
};

#endif