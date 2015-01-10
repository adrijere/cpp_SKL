#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
  Class base;
  int x, y;
  char *display;
} PointClass;

static void Point_ctor(Object* self, va_list *args)
{
  PointClass *tmp;

  tmp = (PointClass *)self;
  if (args != NULL)
    {
      tmp->x = va_arg(args, int);
      tmp->y = va_arg(args, int);
    }
}

static void Point_dtor(Object* self)
{
  PointClass *tmp;

  tmp = (PointClass *)self;
  free(tmp->display);
}

static char const *Point_to_string(Object* self)
{
  PointClass *tmp;
  char *all;

  tmp = (PointClass *)self;
  if (tmp->display != NULL)
    free(tmp->display);
  all = malloc(sizeof(char) * (strlen(tmp-> base.__name__) + 31 ));
  snprintf(all, strlen(tmp-> base.__name__) + 31, "<%s (%d, %d)>", tmp->base.__name__, tmp->x, tmp->y);
  tmp->display = all;
  return (all);
}

static Object *Point_add(const Object* self, const Object *other)
{
  PointClass *to_return;
  PointClass *tmp;
  PointClass *tmp2;

  to_return = new(Point);
  tmp = (PointClass *)self;
  tmp2 = (PointClass *)other;
  to_return->x = tmp->x + tmp2->x;
  to_return->y = tmp->y + tmp2->y;
  return (to_return);
}

static Object *Point_sub(const Object* self, const Object *other)
{
  PointClass *to_return;
  PointClass *tmp;
  PointClass *tmp2;

  to_return = new(Point);
  tmp = (PointClass *)self;
  tmp2 = (PointClass *)other;
  to_return->x = tmp->x - tmp2->x;
  to_return->y = tmp->y - tmp2->y;
  return (to_return);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_to_string, &Point_add, &Point_sub },
  0, 0, NULL
};

Class* Point = (Class*) &_description;
