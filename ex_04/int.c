#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
  Class base;
  int value;
  char *display;
} IntClass;

static void Int_ctor(Object* self, va_list *args)
{
  IntClass *tmp;

  tmp = (IntClass *)self;
  if (args != NULL)
    tmp->value = va_arg(args, int);
}

static void Int_dtor(Object* self)
{
  IntClass *tmp;

  tmp = (IntClass *)self;
  free(tmp->display);
}

static char const *Int_to_string(Object* self)
{
  IntClass *tmp;
  char *all;

  tmp = (IntClass *)self;
  if (tmp->display != NULL)
    free(tmp->display);
  all = malloc(sizeof(char) * 12);
  snprintf(all, 12, "%d", tmp->value);
  tmp->display = all;
  return (all);
}

static Object *Int_add(const Object* self, const Object *other)
{
  IntClass *to_return;
  IntClass *tmp;
  IntClass *tmp2;

  to_return = new(Int);
  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  to_return->value = tmp->value + tmp2->value;
  return (to_return);
}

static Object *Int_sub(const Object* self, const Object *other)
{
  IntClass *to_return;
  IntClass *tmp;
  IntClass *tmp2;

  to_return = new(Int);
  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  to_return->value = tmp->value - tmp2->value;
  return (to_return);
}

static Object *Int_mul(const Object* self, const Object *other)
{
  IntClass *to_return;
  IntClass *tmp;
  IntClass *tmp2;

  to_return = new(Int);
  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  to_return->value = tmp->value * tmp2->value;
  return (to_return);
}

static Object *Int_div(const Object* self, const Object *other)
{
  IntClass *to_return;
  IntClass *tmp;
  IntClass *tmp2;

  to_return = new(Int);
  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  to_return->value = tmp->value / tmp2->value;
  return (to_return);
}

static bool Int_eq(const Object* self, const Object *other)
{
  IntClass *tmp;
  IntClass *tmp2;

  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  return (tmp->value == tmp2->value);
}

static bool Int_gt(const Object* self, const Object *other)
{
  IntClass *tmp;
  IntClass *tmp2;

  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  return (tmp->value > tmp2->value);
}

static bool Int_lt(const Object* self, const Object *other)
{
  IntClass *tmp;
  IntClass *tmp2;

  tmp = (IntClass *)self;
  tmp2 = (IntClass *)other;
  return (tmp->value < tmp2->value);
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_to_string, &Int_add, &Int_sub, &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt },
  0, NULL
};

Class* Int = (Class*) &_description;
