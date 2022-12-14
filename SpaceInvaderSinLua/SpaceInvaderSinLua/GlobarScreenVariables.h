#pragma once
#include <cmath>
constexpr unsigned char BaseSize = 16;
constexpr unsigned short ScreenWidth = 320;
constexpr unsigned short ScreenHeight = 180;
constexpr unsigned char ScreenResize = 4;
constexpr unsigned char PLAYER_MOVE_SPEED = 2;
constexpr std::chrono::microseconds FRAME_DURATION(16667);
constexpr unsigned char RELOAD_DURATION = 31;
constexpr unsigned char PLAYER_BULLET_SPEED = 4;

//struct Bullet
//{
//	bool dead;
//
//	float real_x;
//	float real_y;
//	float step_x;
//	float step_y;
//
//	short x;
//	short y;
//
//	std::array<short, 3> previous_x;
//	std::array<short, 3> previous_y;
//
//	Bullet(float i_step_x, float i_step_y, short i_x, short i_y) :
//		dead(0),
//		real_x(i_x),
//		real_y(i_y),
//		step_x(i_step_x),
//		step_y(i_step_y),
//		x(i_x),
//		y(i_y)
//	{
//		previous_x.fill(x);
//		previous_y.fill(y);
//
//	} 
//	//void update()
//	//{
//	//	if (0 == dead)
//	//	{
//	//		//I hate using floats, so we'll change real_x and _y and work only with integer values.
//	//		real_x += step_x;
//	//		real_y += step_y;
//
//	//		for (unsigned char a = 0; a < previous_x.size() - 1; a++)
//	//		{
//	//			previous_x[a] = previous_x[1 + a];
//	//			previous_y[a] = previous_y[1 + a];
//	//		}
//
//	//		previous_x[previous_x.size() - 1] = x;
//	//		previous_y[previous_y.size() - 1] = y;
//
//	//		x = round(real_x);
//	//		y = round(real_y);
//
//	//		if (x <= -BaseSize || y <= -BaseSize || ScreenHeight <= y || ScreenWidth <= x)
//	//		{
//	//			dead = 1;
//	//		}
//	//	}
//	//}
//};