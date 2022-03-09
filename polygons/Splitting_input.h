#pragma once
#include <iostream>
#include <cstdlib>
#include"points.h"
#include"polygon.h"
using namespace std;

class Splitting_input
{
	
public:
	Splitting_input();

	vector<polygon> setting_all_polygons( string & Data_input);

	~Splitting_input();
	
};

