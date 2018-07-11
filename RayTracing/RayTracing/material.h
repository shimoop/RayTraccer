#pragma once

#include "ray.h"
#include "hitable.h"

vec3 random_in_unit_sphere()
{
	vec3 p;
	do
	{
		p = 2.0 * vec3((rand() / double(RAND_MAX)), (rand() / double(RAND_MAX)), (rand() / double(RAND_MAX))) - vec3(1, 1, 1);
	} while (dot(p, p) >= 1.0);
	return p;
}

class material
{
public:
	virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};

class lambertian : public material
{
public:

	vec3 albedo;
};
