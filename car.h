#ifndef CAR_H
#define CAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vehicle.h"

typedef struct {
  Vehicle parent;
  void (* accel)(struct Car_priv *this, int amount);
  void (* deaccel)(struct Car_priv *this, int amount);
  int (* get_system_type)(struct Car_priv *this);
} Car;

typedef struct {
  Car public;
  int SystemType;
} Car_priv;

void Car__accel(Car *this, int amount) {
  this->parent.Speed += amount;
}

void Car__deaccel(Car *this, int amount) {
  this->parent.Speed -= amount;
}

int Car__get_system_type(Car_priv *this) {
  return this->SystemType;
}

Car *Car__create(int speed, char *color) {
  Car_priv *this = (Car_priv *)malloc(sizeof(Car_priv));
  this->public.parent = *Vehicle__create(speed, color);
  this->public.parent.Speed = speed;
  this->public.parent.Color = color;
  this->public.accel = &Car__accel;
  this->public.deaccel = &Car__deaccel;
  this->public.get_system_type = &Car__get_system_type;
  this->SystemType = 1;
  return &this->public;
}

void Car__destroy(Car_priv *this) {
  Vehicle__destroy(&this->public.parent);
  free(this);
}

#endif
