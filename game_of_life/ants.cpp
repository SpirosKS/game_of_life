#include "ants.h"

int ants::random_ants()
{
	std::random_device rd{};
	std::default_random_engine e{ rd() };
	std::uniform_int_distribution<int> d{ 0, 1 };
	int a = d(e);
	return a;
}

ants::ants()
{

	for(int i=0;i<100;++i)
	{
		for (int j = 0;j < 100;++j)
		{
			bool ant;
			int num_int=random_ants();
			if (num_int == 1) 
			{ ant = true; }
			else { ant = false; }
			
			
			plain[i + 100 * j] = ant;
			temp_plain[i + 100 * j] = ant;
			
		}
	}
	//print_temp();
}

ants::~ants()
{
}

void ants::print_ants()
{
	std::fstream out;
	
	out.open("game_of_life_test.ppm", std::fstream::out);
	if (out.is_open())
	{
		out << "P1\n100 100\n";
		for (int i = 0;i < 100;++i)
		{
			for (int j = 0;j < 100;++j)
			{
				out << plain[i + 100 * j];
			}
		}
	}
	else { std::cout << "Could not create file"; }
	out.clear();
	out.close();
}


void ants::print_ants2()
{
	std::fstream out;

	out.open("game_of_life_test2.ppm", std::fstream::out);
	if (out.is_open())
	{
		out << "P1\n100 100\n";
		for (int i = 0;i < 100;++i)
		{
			for (int j = 0;j < 100;++j)
			{
				out << plain[i + 100 * j];
			}
		}
	}
	else { std::cout << "Could not create file"; }
	out.clear();
	out.close();
}

void ants::print_temp()
{
	for (int i = 0;i < 100;++i) { for (int j = 0;j < 100;++j) { std::cout << temp_plain[i + j * 100] << " "; } }
}

void ants::check_life()
{
	
	for(int i=0;i<100;++i)
	{
		for (int j = 0;j < 100;j++)
		{

			if (plain[i + 100 * j] == true)
			{

				int num = 0;

				if (((i + 100 * j) + 1 < 9999) and ((i + 100 * j) - 1 > 0) and ((i + 100 * j) + 100 < 9999) and ((i + 100 * j) - 100 > 0) and ((i + 100 * j) - 101 > 0) and ((i + 100 * j) - 99 > 0) and ((i + 100 * j) + 99 < 9999) and ((i + 100 * j) + 101 < 9999))
				{
					flag_left = false;
					flag_right = false;
					flag_left = left_check(i, j);
					flag_right = right_check(i, j);

					if ((plain[(i + 100 * j) + 1] == true) and (i + 100 * j) % 100 != 99) { num++; }
					if ((plain[(i + 100 * j) - 1] == true) and (i + 100 * j) % 100 != 0) { num++; }
					if ((plain[(i + 100 * j) + 100] == true) and flag_right == false) { num++; }
					
					if ((plain[(i + 100 * j) - 100] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) - 101] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) - 99] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) + 99] == true) and flag_right == false) { num++; }
					if ((plain[(i + 100 * j) + 101] == true) and flag_right == false) { num++; }

					if (num == 2 or num == 3) { temp_plain[i + 100 * j] = true; }
					else { temp_plain[i + j * 100] = false; }
					//std::cout << num << " ";

				}
				else { kill(i, j); }

				

			}
			else if (plain[i + 100 * j] == false)
			{

				int num = 0;

				if (((i + 100 * j) + 1 < 9999) and ((i + 100 * j) - 1 > 0) and ((i + 100 * j) + 100 < 9999) and ((i + 100 * j) - 100 > 0) and ((i + 100 * j) - 101 > 0) and ((i + 100 * j) - 99 > 0) and ((i + 100 * j) + 99 < 9999) and ((i + 100 * j) + 101 < 9999))
				 {
					flag_left = false;
					flag_right = false;
					flag_left = left_check(i, j);
					flag_right = right_check(i, j);

					if ((plain[(i + 100 * j) + 1] == true)  and (i + 100 * j) % 100 != 99) { num++; }
					if ((plain[(i + 100 * j) - 1] == true) and (i + 100 * j) % 100 != 0  ) { num++; }
					if ((plain[(i + 100 * j) + 100] == true) and flag_right == false) { num++; }
					if ((plain[(i + 100 * j) - 100] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) - 101] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) - 99] == true) and flag_left == false) { num++; }
					if ((plain[(i + 100 * j) + 99] == true) and flag_right == false) { num++; }
					if ((plain[(i + 100 * j) + 101] == true) and flag_right == false) { num++; }


					if (num == 3) { temp_plain[i + 100 * j] = true; }
					else { temp_plain[i + j * 100] = false; }
					//std::cout << num << " "; 

				}
				else { kill(i, j); }
			}
			
		}
	}
	//std::cout << "\n\n\n";
	for (int i = 0;i < 100;++i) { for (int j = 0;j < 99;++j){ plain[i+j*100] = temp_plain[i+100*j]; } }
	//plain = temp_plain;
}

void ants::print_ants1()
{
	std::fstream out;

	out.open("game_of_life_test1.ppm", std::fstream::out);
	if (out.is_open())
	{
		out << "P1\n100 100\n";
		for (int i = 0;i < 100;++i)
		{
			for (int j = 0;j < 100;++j)
			{
				out << plain[i + 100 * j];
			}
		}
	}
	else { std::cout << "Could not create file"; }
	out.clear();
	out.close();
}

bool ants::left_check(int i, int j)
{
	for (int n = 0;n < 100;++n) 
	{
		if ((i + j * 100) == n) 
		{
			flag_left = true;
			break;
		}

	}
	return flag_left;
}

bool ants::right_check(int i, int j)
{
	for (int n = 9900;n < 10000;++n)
	{
		if ((i + j * 100) == n)
		{
			flag_right = true;
			break;
		}

	}
	return flag_right;
}

void ants::kill(int i, int j)
{
	temp_plain[i + j * 100] = false;
}

void ants::god()
{
	for (int i = 0;i < 100;++i)
	{
		for (int j = 0;j < 100;++j)
		{
			if( (i+100*j==9900) or (i + 100 * j == 9901)){ plain[i + j * 100] = true; }
			else {
				plain[i + j * 100] = false;
			}
			temp_plain[i + j * 100] = false;
		}
	}
}


