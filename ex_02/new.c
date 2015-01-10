#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "point.h"

Object* va_new(Class* class, va_list* ap)
{
  Class *tmp;
  
  tmp = malloc(class->__size__);
  memcpy(tmp, class, class->__size__);
  tmp->__init__(tmp, ap);
  return (tmp);
}

Object *new(Class *class, ...)
{
  Class *tmp;
  va_list ap;
  
  tmp = malloc(class->__size__);
  memcpy(tmp, class, class->__size__);
  va_start(ap, class); 
  tmp->__init__(tmp, &ap);
  va_end(ap);
  return (tmp);
}

void delete(Object *ptr)
{
  Class *tmp;

  tmp = (Class *)ptr;
  tmp->__del__(tmp);
}

