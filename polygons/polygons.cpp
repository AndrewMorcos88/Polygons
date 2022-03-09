#include "pch.h"
#include <iostream>
#include<string>
#include"Splitting_input.h"
#include"Max_Min_Points.h"
#include"Remove_Redundant_Points.h"
#include"Level_2_Operations.h"
using namespace std;

 int Number_Redundant_Points(vector <polygon> All_polygons_Added, vector<polygon>All_Polygons_without_Reduandant);

int main()
{
	cout << "Enter Polygons Data :" << endl;
	string Input_Data;
	getline(cin, Input_Data);
	vector<polygon>All_polygons_Added;

	vector <polygon>All_Polygons_without_Reduandant;

	Splitting_input Splitting_Data;

	All_polygons_Added = Splitting_Data.setting_all_polygons(Input_Data); 
	
	Max_Min_Points Max_Min_Values(All_polygons_Added);


	Remove_Redundant_Points Removing_Red_Points;


	All_Polygons_without_Reduandant = Removing_Red_Points.Formation_All_Polygons_Without_Reduandant_Points(All_polygons_Added);

	Level_2_Operations Operations_level_two(All_polygons_Added, All_Polygons_without_Reduandant);

	string Operation ="";
	cout << " Enter Operation needed : " << endl;

	// getting Operations From the User 
	while (true)
	{
		Operation = "";
		cin >> Operation;

		// Level 1 Done :D 

		if (Operation == "Quit")
			break;
		else if (Operation == "Number_Polygons")
			cout << All_polygons_Added.size() << endl;
		else if (Operation == "Total_Number_Points")
			cout << Max_Min_Values.get_Number_All_Points() << endl;
		else if (Operation == "Minimum_X")
			cout << Max_Min_Values.get_Min_X() << endl;
		else if (Operation == "Maximum_X")
			cout << Max_Min_Values.get_Max_X() << endl;
		else if (Operation == "Minimum_Y")
			cout << Max_Min_Values.get_Min_Y() << endl;
		else if (Operation == "Maximum_Y")
			cout << Max_Min_Values.get_Max_Y() << endl;
		else if (Operation == "Enclosing_Rectangle")
			cout << Max_Min_Values.get_Min_Rectangle() << endl;
		else if (Operation == "Total_Redundant_Points")
			cout << Number_Redundant_Points(All_polygons_Added, All_Polygons_without_Reduandant) << endl;

		


		// stating Level 2 
	
		else if (Operation.substr(0, 14) == "Polygon_Points")
		{
			int N;
			cin >> N;
			cout<<Operations_level_two.Polygon_Points(N)<<endl;
		}

		else if (Operation.substr(0, 14) == "Point_Polygons")
		{
			string N;
			cin >> N;
			cout << Operations_level_two.Points_Polygons(N) << endl;
		}
		else if (Operation.substr(0, 20) == "List_Polygons_Points")
		{
			string N;
			cin >> N;
			if (N == "More")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Polygons_Points_More(Temp) << endl;
			}
			if (N == "Less")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Polygons_Points_Less(Temp) << endl;
			}
			if (N == "Equal")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Polygons_Points_Equal(Temp) << endl;

			}
		}


		else if (Operation.substr(0, 20) == "List_Points_Polygons")
		{
			string N;
			cin >> N;
			if (N == "More")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Points_Polygons_More(Temp) << endl;
			}
			if (N == "Less")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Points_Polygons_Less(Temp) << endl;
			}
			if (N == "Equal")
			{
				int Temp;
				cin >> Temp;
				cout << Operations_level_two.List_Points_Polygons_Equal(Temp) << endl;

			}
		}

		else if (Operation.substr(0, 17) == "Polygon_Perimeter")
		{
			int N;
			cin >> N;
			cout << Operations_level_two.Polygon_Perimeter(N) << endl;
		}
		else if (Operation == "List_Triangles")
		{
			cout << Operations_level_two.List_Triangles() << endl;
		}



	}

	

}

int Number_Redundant_Points(vector <polygon> All_polygons_Added, vector<polygon>All_Polygons_without_Reduandant)
{
	int res = 0;
	for (int i = 0; i < All_polygons_Added.size(); i++)
		res += All_polygons_Added[i].Get_polygon().size() - All_Polygons_without_Reduandant[i].Get_polygon().size();
	return res;
}


