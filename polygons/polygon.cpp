#include "pch.h"
#include "polygon.h"


polygon::polygon()
{
}
void polygon:: Set_polygon(vector<points> x)
{
	this->points_Form_polygon = x;
}
vector<points>polygon::Get_polygon()
{
	return this->points_Form_polygon;
}

void polygon::Clear_polygon_data()
{
	this->points_Form_polygon.clear();
}

polygon::~polygon()
{
}
