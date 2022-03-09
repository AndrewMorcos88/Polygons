#include "pch.h"
#include "Splitting_input.h"


Splitting_input::Splitting_input()
{ 

}

vector<polygon> Splitting_input::setting_all_polygons(string & Data_input) 
{
	vector<points>My_Points;
	vector<polygon>My_polygons;
	polygon Temp_polygon;
	string X, Y;
	bool X_first = false, Y_first = false , points_separator = false;

	for (int i = 0; i < Data_input.size(); i++)
	{
		if (Data_input[i] == ';' || Data_input[i] == ']')
		{
			if (My_Points.size() == 0)
				continue;

			Temp_polygon.Set_polygon(My_Points);
			My_polygons.push_back(Temp_polygon);
			Temp_polygon.Clear_polygon_data();
			My_Points.clear();
			points_separator = false;
			continue;
		}
		if (points_separator == true && Data_input[i] == ',')
		{
			points_separator = false;
			continue;
		}

		if (Data_input[i] == '(' )
		{
			X_first = true;
			Y_first = false;
			continue;

		}
		if (Data_input[i] == ',')
		{
			X_first = false;
			Y_first = true;
			continue;

		}

		if (Data_input[i] == ')')
		{
			points A_A(atof(X.c_str()), atof(Y.c_str()) );

			My_Points.push_back(A_A) ;
			points_separator = true;
			Y_first = false;
			X = "";
			Y = "";
			continue;
		}

		if (X_first == true)
		{
			X += Data_input[i];
			continue;
		}
		if (Y_first == true)
		{
			Y += Data_input[i];
			continue;
		}


	}


	return My_polygons;
}


Splitting_input::~Splitting_input()
{
}
