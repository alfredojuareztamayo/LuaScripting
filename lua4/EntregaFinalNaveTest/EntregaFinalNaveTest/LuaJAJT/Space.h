#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
using namespace sf;

class Space
{
	float x1, y1;
public:
	Space();
	Space(float x, float y);
	CircleShape hoop;
		int dir = 0;
		CircleShape ball;
		bool isShot = false;

private:

};

/*, int Colorx1,
		int Colorx2, int Colorx3,
		int Colory1, int Colory2, int Colory3,
		int Colorz1, int Colorz2, int Colorz3*/