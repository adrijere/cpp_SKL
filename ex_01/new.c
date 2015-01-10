#include <string.h>
#include <stdlib.h>

#include "point.h"

void *new(Class *class, ...)
{
  Class *tmp;

  tmp = malloc(class->__size__);
  memcpy(tmp, class, class->__size__);
  tmp->__init__(tmp);
  return (tmp);
}

void delete(Object *ptr)
{
  Class *tmp;

  tmp = (Class *)ptr;
  tmp->__del__(tmp);
}

