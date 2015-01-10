#include <string.h>
#include <stdlib.h>
#include "raise.h"

#include "object.h"

void *new(Class *class, ...)
{
  Class *tmp;

  if ((tmp = malloc(class->__size__)) == NULL)
  	raise("Out of memory");
  memcpy(tmp, class, class->__size__);
  tmp->__init__(tmp);
  return (tmp);
}

void delete(Object *ptr)
{
  Class *tmp;

  tmp = (Class *)ptr;
  tmp->__del__(tmp);
  free (tmp);
}

