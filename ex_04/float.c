#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
  Class base;
  float value;
  char *display;
} FloatClass;

static void Float_ctor(Object* self, va_list *args)
{
  FloatClass *tmp;

  tmp = (FloatClass *)self;
  if (args != NULL)
    tmp->value = (float)va_arg(args, double);
}

static void Float_dtor(Object* self)
{
  FloatClass *tmp;

  tmp = (FloatClass *)self;
  free(tmp->display);
}

static char const *Float_to_string(Object* self)
{
  FloatClass *tmp;
  char *all;

  tmp = (FloatClass *)self;
  if (tmp->display != NULL)
    free(tmp->display);
  all = malloc(sizeof(char) * 18);
  snprintf(all, 18, "%.6f", tmp->value);
  tmp->display = all;
  return (all);
}

static Object *Float_add(const Object* self, const Object *other)
{
  FloatClass *to_return;
  FloatClass *tmp;
  FloatClass *tmp2;

  to_return = new(Float);
  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  to_return->value = tmp->value + tmp2->value;
  return (to_return);
}

static Object *Float_sub(const Object* self, const Object *other)
{
  FloatClass *to_return;
  FloatClass *tmp;
  FloatClass *tmp2;

  to_return = new(Float);
  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  to_return->value = tmp->value - tmp2->value;
  return (to_return);
}

static Object *Float_mul(const Object* self, const Object *other)
{
  FloatClass *to_return;
  FloatClass *tmp;
  FloatClass *tmp2;

  to_return = new(Float);
  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  to_return->value = tmp->value * tmp2->value;
  return (to_return);
}

static Object *Float_div(const Object* self, const Object *other)
{
  FloatClass *to_return;
  FloatClass *tmp;
  FloatClass *tmp2;

  to_return = new(Float);
  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  to_return->value = tmp->value / tmp2->value;
  return (to_return);
}

static bool Float_eq(const Object* self, const Object *other)
{
  FloatClass *tmp;
  FloatClass *tmp2;

  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  return (tmp->value == tmp2->value);
}

static bool Float_gt(const Object* self, const Object *other)
{
  FloatClass *tmp;
  FloatClass *tmp2;

  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  return (tmp->value > tmp2->value);
}

static bool Float_lt(const Object* self, const Object *other)
{
  FloatClass *tmp;
  FloatClass *tmp2;

  tmp = (FloatClass *)self;
  tmp2 = (FloatClass *)other;
  return (tmp->value < tmp2->value);
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_to_string, &Float_add, &Float_sub, &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt },
  0, NULL
};

Class* Float = (Class*) &_description;
