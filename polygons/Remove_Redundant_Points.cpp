#include "pch.h"
#include "Remove_Redundant_Points.h"


Remove_Redundant_Points::Remove_Redundant_Points()
{
}

vector<polygon> Remove_Redundant_Points::Formation_All_Polygons_Without_Reduandant_Points(vector<polygon> All_polygons)
{
	vector<polygon> Polygons_without_Reduandant;

	polygon Polygon_without_Reduandant;

	vector<points> Points_without_Reduandant;

	for (int i = 0; i < All_polygons.size(); i++)

	{
		if (i != 0)
		{
			Polygon_without_Reduandant.Set_polygon(Points_without_Reduandant);
			Polygons_without_Reduandant.push_back(Polygon_without_Reduandant);
			Points_without_Reduandant.clear();
			Polygon_without_Reduandant.Clear_polygon_data();

		}

		vector<points> Polygon_Points = All_polygons[i].Get_polygon();
		

		for (int j = 0; j < Polygon_Points.size(); j++)

		{
			points Target_Point = Polygon_Points[j]; // first point in polygon
			if (j == 0)
			{
					Points_without_Reduandant.push_back(Target_Point);
					continue;
			

			}

			if (j == Polygon_Points.size() - 1) // last point in polygon
			{
				if (Target_Point.Point_is_redundant(Polygon_Points[j - 1], Polygon_Points[0]))
				{
					Polygon_Points.erase(Polygon_Points.begin()+j);
					j--;
					continue;
				}
				else
				{
					Points_without_Reduandant.push_back(Target_Point);
					continue;
				}
			}
			
			if (Target_Point.Point_is_redundant(Polygon_Points[j - 1], Polygon_Points[j + 1]))
			{
				Polygon_Points.erase(Polygon_Points.begin() + j);
				j--;
				continue;
			}
			else
			{
				Points_without_Reduandant.push_back(Target_Point);
				continue;
			}

		}

		if (Points_without_Reduandant[0].Point_is_redundant
		(Points_without_Reduandant[1], Points_without_Reduandant[Points_without_Reduandant.size() - 1]))
			Points_without_Reduandant.erase(Points_without_Reduandant.begin());

		if (i == All_polygons.size() - 1)
		{
			Polygon_without_Reduandant.Set_polygon(Points_without_Reduandant);
			Polygons_without_Reduandant.push_back(Polygon_without_Reduandant);
		}

	}


	return Polygons_without_Reduandant;

}


Remove_Redundant_Points::~Remove_Redundant_Points()
{
}
