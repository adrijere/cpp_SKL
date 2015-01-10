#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "char.h"

#include "new.h"
#include "raise.h"

typedef struct
{
  Class base;
  char value;
  char *display;
} CharClass;

static void Char_ctor(Object* self, va_list *args)
{
  CharClass *tmp;

  tmp = (CharClass *)self;
  if (args != NULL)
    tmp->value = (char)va_arg(args, int);
}

static void Char_dtor(Object* self)
{
  CharClass *tmp;

  tmp = (CharClass *)self;
  free(tmp->display);
}

static char const *Char_to_string(Object* self)
{
  CharClass *tmp;
  char *all;

  tmp = (CharClass *)self;
  if (tmp->display != NULL)
    free(tmp->display);
  if ((all = malloc(sizeof(char) * 5)) == NULL)
    raise("Out of memory");
  snprintf(all, 5, "%d", tmp->value);
  tmp->display = all;
  return (all);
}

static Object *Char_add(const Object* self, const Object *other)
{
  CharClass *to_return;
  CharClass *tmp;
  CharClass *tmp2;

  to_return = new(Char);
  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  to_return->value = tmp->value + tmp2->value;
  return (to_return);
}

static Object *Char_sub(const Object* self, const Object *other)
{
  CharClass *to_return;
  CharClass *tmp;
  CharClass *tmp2;

  to_return = new(Char);
  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  to_return->value = tmp->value - tmp2->value;
  return (to_return);
}

static Object *Char_mul(const Object* self, const Object *other)
{
  CharClass *to_return;
  CharClass *tmp;
  CharClass *tmp2;

  to_return = new(Char);
  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  to_return->value = tmp->value * tmp2->value;
  return (to_return);
}

static Object *Char_div(const Object* self, const Object *other)
{
  CharClass *to_return;
  CharClass *tmp;
  CharClass *tmp2;

  to_return = new(Char);
  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  to_return->value = tmp->value / tmp2->value;
  return (to_return);
}

static bool Char_eq(const Object* self, const Object *other)
{
  CharClass *tmp;
  CharClass *tmp2;

  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  return (tmp->value == tmp2->value);
}

static bool Char_gt(const Object* self, const Object *other)
{
  CharClass *tmp;
  CharClass *tmp2;

  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  return (tmp->value > tmp2->value);
}

static bool Char_lt(const Object* self, const Object *other)
{
  CharClass *tmp;
  CharClass *tmp2;

  tmp = (CharClass *)self;
  tmp2 = (CharClass *)other;
  return (tmp->value < tmp2->value);
}

static CharClass _description = {
  { sizeof(CharClass), "Char", &Char_ctor, &Char_dtor, &Char_to_string, &Char_add, &Char_sub, &Char_mul, &Char_div, &Char_eq, &Char_gt, &Char_lt },
  0, NULL
};

Class* Char = (Class*) &_description;
