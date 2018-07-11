#pragma once

#include"hitable.h"

class sphere : public hitable
{
public:
	sphere() {};
	sphere(vec3 cen, float r) : center(cen), radius(r) {};
	virtual bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const;
	vec3 center;
	float radius;
};

bool sphere::hit(const ray &r, float t_min, float t_max, hit_record &rec) const
{
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = dot(oc, r.direction());//2*b
	float c = dot(oc, oc) - radius * radius;//t^2*dot(dir, dir) + 2*t*(dot(ori, dir) - dot(dir, center)) + (dot(ori,ori) + dot(center, center) - 2*dot(ori, center))
	float discriminant = b * b - a*c; //����b2-4ac����һ����
	if (discriminant > 0)
	{
		float temp = (-b - sqrt(b*b - a * c)) / a;//���˼�
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	else
	{
		float temp = (-b + sqrt(b*b - a * c)) / a;//���˼�
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}