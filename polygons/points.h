#pragma once
#include<math.h>
class points
{

	float x, y;
public:
	points (float , float );

	bool Point_is_redundant(points A_1, points A_3);
	float get_X();
	float get_Y();

	float Distance_two_Points(points A);
	~points();
};

