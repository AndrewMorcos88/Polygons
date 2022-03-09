#pragma once
#include"polygon.h"
class Max_Min_Points
{
	float Min_X, Min_Y, Max_X, Max_Y;
	vector<polygon>My_polygons;
	int Number_All_Points;
	string Min_Rectangle;
public:
	Max_Min_Points(vector<polygon>);
	float get_Max_X();
	float get_Max_Y();
	float get_Min_X();
	float get_Min_Y();
	int get_Number_All_Points();
	string get_Min_Rectangle();
	~Max_Min_Points();
};

