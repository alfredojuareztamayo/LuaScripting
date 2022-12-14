#include "Space.h"
//#include "LuaSystem.h"


Space::Space() {
	x1 = 50.f;
		y1 = 2.f;
}
Space::Space(float x, float y ) {
	x1 = x;
	y1 = y;
	hoop.setRadius(x);
	hoop.setFillColor(Color::Black);
	hoop.setOutlineThickness(2.f);
	hoop.setOutlineColor(Color::Green);
	hoop.setPosition(Vector2f(0, 10.f));

	ball.setRadius(y);
	ball.setFillColor(Color::Red);
	
}


//,int Colorx1,
//int Colorx2, int Colorx3,
//int Colory1, int Colory2, int Colory3,
//int Colorz1, int Colorz2, int Colorz3
