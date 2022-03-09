#pragma once
#include"polygon.h"
#include<string>
class Level_2_Operations
{
public:
	vector<polygon>All_polygons_Added;
	vector<polygon> All_Polygons_without_Reduandant;

	string Polygon_Points(int Polygon_ID);
	string Points_Polygons(string Target_Point);
	string List_Polygons_Points_More(int Polygon_ID);
	string List_Polygons_Points_Less(int Polygon_ID);
	string List_Polygons_Points_Equal(int Polygon_ID);


	string List_Points_Polygons_More(int Polygon_ID);
	string List_Points_Polygons_Less(int Polygon_ID);
	string List_Points_Polygons_Equal(int Polygon_ID);

	float Polygon_Perimeter(int Polygon_ID);

	string List_Triangles();
	string List_Rectangles();
	string List_Trapezoid();

	Level_2_Operations(vector<polygon>All_polygons_Added,vector<polygon> All_Polygons_without_Reduandant);
	~Level_2_Operations();
};

