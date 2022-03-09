#pragma once
#include"points.h"
#include<vector>
using namespace std;

class polygon
{
	vector<points>points_Form_polygon;


public:
	polygon();
	void Set_polygon(vector<points>);
	vector<points> Get_polygon();
	void Clear_polygon_data();
	~polygon();
};

