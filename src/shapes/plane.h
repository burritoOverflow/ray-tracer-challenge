#ifndef RTC_SHAPES_PLANE_H
#define RTC_SHAPES_PLANE_H

#include "primitives/intersections.h"
#include "primitives/matrix.h"
#include "primitives/tuple.h"
#include "primitives/ray.h"
#include "shapes/material.h"

#include "shapes/shape.h"

class Plane : public Shape {
 public:
  Plane() {};
  ~Plane() = default;

  const Intersections ObjectIntersect(const Ray object_ray) const;
  const Tuple ObjectNormal(const Tuple world_point) const;

  bool operator==(const Plane o) const;
};

#endif    // RTC_SHAPES_PLANE_H
