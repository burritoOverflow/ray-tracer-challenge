#ifndef RTC_SHAPES_SHAPE_H
#define RTC_SHAPES_SHAPE_H

#include "primitives/intersections.h"
#include "primitives/matrix.h"
#include "primitives/tuple.h"
#include "primitives/ray.h"
#include "shapes/material.h"

#include <vector>

class Shape {
 public:
  ~Shape() = default;

  Intersections Intersect(const Ray r) const;
  const Tuple Normal(const Tuple p) const;

  void SetTransform(Matrix m) { transform_ = m; };
  Matrix Transform() const { return transform_; };

  void set_material(Material material) { material_ = material; };
  Material material() const { return material_; };

  Color PatternAt(const Tuple& world_point) const;

  bool operator==(const Shape &o) const;

 protected:
  virtual const Intersections ObjectIntersect(const Ray object_ray) const = 0;
  virtual const Tuple ObjectNormal(const Tuple world_point) const = 0;

  Matrix transform_ = IdentityMatrix(4);
  Material material_ = Material();
};

#endif    // RTC_SHAPES_SHAPE_H
