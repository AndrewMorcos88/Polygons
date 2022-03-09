#include "pch.h"
#include "points.h"



points::points(float _X , float _Y) :  x(_X) , y(_Y)
{
}

bool points::Point_is_redundant(points A_1, points A_3)
{
	if (this->get_X() == A_1.get_X() && this->get_Y() == A_1.get_Y()) // identical points 
		return true;

	if (this->get_X() == A_3.get_X() && this->get_Y() == A_3.get_Y()) // identical points 
		return true;
	
	 // same slope 

if ( A_1.get_X() == A_3.get_X() && (this->get_X()==A_1.get_X()) || 
	A_1.get_Y() == A_3.get_Y() && this->get_Y() == A_1.get_Y() )
	return true;


float First_Angle = (this->get_Y() - A_1.get_Y()) / (this->get_X() - A_1.get_X());
float Second_Angle = (A_3.get_Y() - this->get_Y()) / (A_3.get_X() - this->get_X());

if (Second_Angle == First_Angle)
	return true;


	return false;
}

float points::get_X()
{
	return this->x;
}

float points::get_Y()
{
	return this->y;
}

float points::Distance_two_Points(points A)
{
	return sqrt(pow(this->get_X() - A.get_X(), 2) + pow(this->get_Y() - A.get_Y(), 2));
}

points::~points()
{
}
