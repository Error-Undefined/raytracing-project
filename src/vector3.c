#include <stdlib.h>
#include <math.h>

#include "vector3.h"

struct vector3 *copy_vector3(struct vector3* v)
{
  struct vector3* vec = malloc(sizeof(struct vector3));
  vec->x = v->x;
  vec->y = v->y;
  vec->z = v->z;
  return vec;
}

void vec3_copy_into(struct vector3* to, struct vector3* from)
{
  to->x = from->x;
  to->y = from->y;
  to->z = from->z;
}
 
void vec3_add(struct vector3 *u, struct vector3 *other)
{
  u->x += other->x;
  u->y += other->y;
  u->z += other->z;
}

void vec3_sub(struct vector3 *u, struct vector3 *other)
{
  u->x -= other->x;
  u->y -= other->y;
  u->z -= other->z;
}

void vec3_mul(struct vector3 *u, double t)
{
  u->x *= t;
  u->y *= t;
  u->z *= t;
}

void vec3_cross(struct vector3 *u, struct vector3 *v)
{
  double x = u->y*v->z - u->z*v->y;
  double y = u->z*v->x - u->x*v->z;
  double z = u->x*v->y - u->y*v->x;

  u->x = x;
  u->y = y;
  u->z = z;
}

void vec3_norm(struct vector3 *u)
{
  double len = vec3_len(u);
  if (len == 0)
    return;
  
  u->x /= len;
  u->y /= len;
  u->z /= len;
}

double vec3_dot(struct vector3 *u, struct vector3 *v)
{
  return u->x*v->x + u->y*v->y + u->z*v->z;
}

double vec3_len(struct vector3 *u)
{
  return sqrt(vec3_dot(u, u));
}


struct vector3 vec3_add_new(struct vector3 *u, struct vector3 *other)
{
  struct vector3 new_vec = {u->x, u->y, u->z};
  vec3_add(&new_vec, other);
  return new_vec;
}

struct vector3 vec3_sub_new(struct vector3 *u, struct vector3 *other)
{
  struct vector3 new_vec = {u->x, u->y, u->z};
  vec3_sub(&new_vec, other);
  return new_vec;
}

struct vector3 vec3_mul_new(struct vector3 *u, double t)
{
  struct vector3 new_vec = {u->x, u->y, u->z};
  vec3_mul(&new_vec, t);
  return new_vec;
}

struct vector3 vec3_cross_new(struct vector3 *u, struct vector3 *other)
{
  struct vector3 new_vec = {u->x, u->y, u->z};
  vec3_cross(&new_vec, other);
  return new_vec;
}
