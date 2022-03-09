#include "pch.h"
#include "Level_2_Operations.h"

Level_2_Operations::Level_2_Operations(vector<polygon> All_polygons_Added, vector<polygon> All_Polygons_without_Reduandant)
{
	this->All_polygons_Added = All_polygons_Added;
	this->All_Polygons_without_Reduandant = All_Polygons_without_Reduandant;
}

Level_2_Operations::~Level_2_Operations()
{
}

string Level_2_Operations::Polygon_Points(int Polygon_ID) // list of the polygon Points without reduandant 
{
	string res="";

	vector<points>Polygon_Points = All_Polygons_without_Reduandant[Polygon_ID - 1].Get_polygon();

	for (int i = 0; i < Polygon_Points.size(); i++)
	{
		if (i==0)
			res += "(" + to_string(Polygon_Points[i].get_X()) + "," + to_string(Polygon_Points[i].get_Y()) + ")";
		else
			res += ",(" + to_string(Polygon_Points[i].get_X()) + "," + to_string(Polygon_Points[i].get_Y()) + ")";

		
	}
	return res;

}

string Level_2_Operations::Points_Polygons(string Target_Point) // list polygons IDs that have target point in their list
{
	// splitting Input String To Get X , Y point Target 
	string res = "";
	string X_1 ="", Y_1 = "";
	bool X_first = true, Y_first = false;
	float X_target, Y_target;
	for (int i = 0; i < Target_Point.size(); i++)
	{
		if (Target_Point[i] == '(')
		{
			X_first = true;
			Y_first = false;
			continue;
		}
		if (Target_Point[i] == ')')
		{
			X_target = atof(X_1.c_str());
			Y_target = atof(Y_1.c_str());
			break;
		}
		if (Target_Point[i] == ',')
		{
			Y_first = true;
			X_first = false;
			continue;
		}
		if (X_first == true)
			X_1 += Target_Point[i];
		if (Y_first == true)
			Y_1 += Target_Point[i];
	}

	vector<points>My_Points;
	for (int i = 0; i < All_polygons_Added.size(); i++)
	{
		My_Points = All_polygons_Added[i].Get_polygon();

		for (int j = 0; j < My_Points.size(); j++)
		{
			if (My_Points[j].get_X() == X_target && My_Points[j].get_Y() == Y_target)
			{
				if (res == "")
					res += to_string(i + 1);
				else 
					res += ',' +to_string(i + 1);
			}

		}

	}
	if (res == "")
		return "none";
	return res;


}

string Level_2_Operations::List_Polygons_Points_More(int Polygon_ID)
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		if (All_Polygons_without_Reduandant[i].Get_polygon().size() > Polygon_ID)
		{
			if (res == "")
				res += to_string(i + 1);
			else
				res += ',' + to_string(i + 1);
		}
	}
	if (res == "")
		return "none";
	return res;
	
}

string Level_2_Operations::List_Polygons_Points_Less(int Polygon_ID) 
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		if (All_Polygons_without_Reduandant[i].Get_polygon().size() < Polygon_ID)
		{
			if (res == "")
				res += to_string(i + 1);
			else
				res += ',' + to_string(i + 1);
		}
	}
	if (res == "")
		return "none";
	return res;

}

string Level_2_Operations::List_Polygons_Points_Equal(int Polygon_ID)
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		if (All_Polygons_without_Reduandant[i].Get_polygon().size() == Polygon_ID)
		{
			if (res == "")
				res += to_string(i + 1);
			else
				res += ',' + to_string(i + 1);
		}
	}

	if (res == "")
		return "none";
	return res;

}

string Level_2_Operations::List_Points_Polygons_More(int Polygon_ID)
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		vector<points>Polygon_Points = All_Polygons_without_Reduandant[i].Get_polygon();
		if (All_Polygons_without_Reduandant[i].Get_polygon().size() > Polygon_ID)
		{
			for (int j = 0; j < Polygon_Points.size(); j++)
			{
				if (res == "")
					res += "(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
				else
					res += ",(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
			}

		}
	}
	if (res == "")
		return "none";
	return res;

}

string Level_2_Operations::List_Points_Polygons_Less(int Polygon_ID)
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		vector<points>Polygon_Points = All_Polygons_without_Reduandant[i].Get_polygon();

		if (All_Polygons_without_Reduandant[i].Get_polygon().size() < Polygon_ID)
		{
			for (int j = 0; j < Polygon_Points.size(); j++)
			{
				if (res == "")
					res += "(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
				else
					res += ",(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
			}

		}
	}
	if (res == "")
		return "none";
	return res;
}

string Level_2_Operations::List_Points_Polygons_Equal(int Polygon_ID)
{
	string res = "";

	for (int i = 0; i < All_Polygons_without_Reduandant.size(); i++)
	{
		vector<points>Polygon_Points = All_Polygons_without_Reduandant[i].Get_polygon();
		if (All_Polygons_without_Reduandant[i].Get_polygon().size() == Polygon_ID)
		{
			for (int j = 0; j < Polygon_Points.size(); j++)
			{
				if (res == "")
					res += "(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
				else
					res += ",(" + to_string(Polygon_Points[j].get_X()) + "," + to_string(Polygon_Points[j].get_Y()) + ")";
			}
			
			}
	}
	if (res == "")
		return "none";
	return res;
}

float Level_2_Operations::Polygon_Perimeter(int Polygon_ID)
{
	vector<points>My_Points = All_Polygons_without_Reduandant[Polygon_ID - 1].Get_polygon();

	float res = 0;

	for (int i = 0; i < My_Points.size(); i++)
	{
		if (i == My_Points.size() - 1)
			res += My_Points[i].Distance_two_Points(My_Points[0]);
		else
			res += My_Points[i].Distance_two_Points(My_Points[i+1]);
	}
	return res;
}

string Level_2_Operations::List_Triangles()
{
	return List_Polygons_Points_Equal(3);
	
}
