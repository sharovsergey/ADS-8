// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  countOp = 0;
  first = nullptr;
}

void Train::addCage(bool light) {
  Cage* train = new Cage();
  train->light = light;
  if (first == nullptr) {
    first = train;
    first->next = train;
    first->prev = train;
  } else {
    train->next = first;
    train->prev = first->prev;
    (first->prev)->next = train;
    first->prev = train;
  }
}

int Train::getLength() {
  int length = 0;
  first->light = true;
  while (first->light) {
    length = 0;
    Cage* cur_train = first->next;
    countOp++;
    length++;
    while (!cur_train->light) {
      countOp++;
      length++;
      cur_train = cur_train->next;
    }
    cur_train->light = false;
  }
  countOp *= 2;
  return length;
}

int Train::getOpCount() {
  return countOp;
}
