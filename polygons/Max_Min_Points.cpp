#include "pch.h"
#include "Max_Min_Points.h"
#include<string>

Max_Min_Points::Max_Min_Points(vector<polygon>x):My_polygons(x)
{
	Max_X = -10000000, Max_Y = -10000000;
	Min_X = 100000000, Min_Y = 100000000;
	Number_All_Points = 0;
	for (int i = 0; i < My_polygons.size(); i++)
	{
		vector<points>My_Points = My_polygons[i].Get_polygon();
		Number_All_Points += My_Points.size();
		for (int j = 0; j < My_Points.size(); j++)
		{
			if (My_Points[j].get_X() > Max_X)
				Max_X = My_Points[j].get_X();
			if (My_Points[j].get_X() < Min_X)
				Min_X = My_Points[j].get_X();
			if (My_Points[j].get_Y() > Max_Y)
				Max_Y = My_Points[j].get_Y();
			if (My_Points[j].get_Y() < Min_Y)
				Min_Y = My_Points[j].get_Y();
		}
	}
}

float Max_Min_Points::get_Max_X()
{
	return this->Max_X;
}

float Max_Min_Points::get_Max_Y()
{
	return this->Max_Y;
}

float Max_Min_Points::get_Min_X()
{
	return this->Min_X;
}

float Max_Min_Points::get_Min_Y()
{
	return this->Min_Y;
}

int Max_Min_Points::get_Number_All_Points()
{
	return this->Number_All_Points;
}

string Max_Min_Points::get_Min_Rectangle()
{
	string res ="";

	res = "(" + to_string(Max_X) + "," + to_string(Max_Y) + ")";

	res += ",(" + to_string(Max_X) + "," + to_string(Min_Y) + ")";
	
	res += ",("  + to_string(Min_X) + "," + to_string(Min_Y) + ")";

	res += ",(" + to_string(Min_X) + "," + to_string(Max_Y) + ")";

	return res;
}

Max_Min_Points::~Max_Min_Points()
{
}
