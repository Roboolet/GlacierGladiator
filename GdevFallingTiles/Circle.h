#pragma once

class Circle {
private:
	int xpos = 0;
	int ypos = 0;
	int radius = 0;
public:
	Circle(int x, int y, int rad);
	void draw();
};