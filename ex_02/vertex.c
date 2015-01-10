#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vertex.h"

typedef struct
{
  Class base;
  int x, y, z;
  char *display;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *args)
{
  VertexClass *tmp;

  tmp = (VertexClass *)self;
  if (args != NULL)
    {
      tmp->x = va_arg(args, int);
      tmp->y = va_arg(args, int);
      tmp->z = va_arg(args, int);
    }
}

static void Vertex_dtor(Object* self)
{
  VertexClass *tmp;

  tmp = (VertexClass *)self;
  free(tmp->display);
}

static char const *Vertex_to_string(Object* self)
{
  VertexClass *tmp;
  char *all;

  tmp = (VertexClass *)self;
  if (tmp->display != NULL)
    free(tmp->display);
  all = malloc(sizeof(char) * (strlen(tmp-> base.__name__) + 42 ));
  snprintf(all, strlen(tmp-> base.__name__) + 31, "<%s (%d, %d, %d)>", tmp->base.__name__, tmp->x, tmp->y, tmp->z);
  tmp->display = all;
  return (all);
}

static VertexClass _description = {
  { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_to_string },
  0, 0, 0, NULL
};

Class* Vertex = (Class*) &_description;
