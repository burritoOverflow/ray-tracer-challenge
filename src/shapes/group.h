#ifndef RTC_SHAPES_GROUP_H
#define RTC_SHAPES_GROUP_H

#include "primitives/intersections.h"
#include "primitives/matrix.h"
#include "primitives/tuple.h"
#include "primitives/ray.h"
#include "shapes/material.h"
#include "shapes/shape.h"

#include <vector>

class Group : public Shape {
 public:
  Group();
  ~Group() = default;

  const Intersections ObjectIntersect(const Ray object_ray) const;
  const Tuple ObjectNormal(const Tuple p) const;

  bool operator==(const Group o) const;

  const int size() const { return children_->size(); };

  void AddChild(Shape * child);
  const std::vector<Shape *> *children() const { return children_; };

  void ExtendBoundsForChild(Shape *child);
  const Bounds UnitBounds() const;

 private:
  std::vector<Shape *> *children_;
  Bounds bounds_ = Bounds(Point(0, 0, 0), Point(0, 0, 0));

  const void CheckAxis(const float &origin, const float &direction, float *tmin, float *tmax, const float &direction_min, const float &direction_max) const;
};

#endif    // RTC_SHAPES_GROUP_H
