#pragma once
class interface_distance
{
public:
	/// <summary>
	/// Reutrn distance between 2 point 
	/// </summary>
	/// <param name="x1"></param>
	/// <param name="y1"></param>
	/// <param name="x2"></param>
	/// <param name="y2"></param>
	/// <returns></returns>
	virtual float distance_point_to_point(double x1, double y1, double x2, double y2) = 0;


	/// <summary>
	/// Reutrn distance between point and line
	/// </summary>
	/// <param name="x1"></param>
	/// <param name="y1"></param>
	/// <param name="A"></param>
	/// <param name="B"></param>
	/// <param name="C"></param>
	/// <returns></returns>
	virtual float distance_point_to_line(double x1, double y1, double A, double B, double C) = 0;

	/// <summary>
	/// Reutrn distance between point and Circle
	/// </summary>
	/// <param name="x1"></param>
	/// <param name="y1"></param>
	/// <param name="A"></param>
	/// <param name="B"></param>
	/// <param name="R"></param>
	/// <returns></returns>
	virtual float distance_point_circle(double x1, double y1, double A, double B, double R) = 0;
};

