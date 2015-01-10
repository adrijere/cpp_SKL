#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point.h"

typedef struct
{
  Class base;
  int x, y;
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
  else
    {
      tmp->x = 0;
      tmp->y = 0;
    }
}

static void Point_dtor(Object* self)
{

}

static char const *Point_to_string(Object* self)
{
  PointClass *tmp;
  char *all;

  tmp = (PointClass *)self;
  all = malloc(sizeof(char) * (strlen(tmp-> base.__name__) + 31 ));
  snprintf(all, strlen(tmp-> base.__name__) + 31, "<%s (%d, %d)>", tmp->base.__name__, tmp->x, tmp->y);
  return (all);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_to_string },
    0, 0
};

Class* Point = (Class*) &_description;
