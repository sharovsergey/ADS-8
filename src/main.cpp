// Copyright 2022 NNTU-CS
#include "train.h"

Train::Train() {
  operationCount = 0;
  firstCage = nullptr;
}

void Train::addCage(bool isLightOn) {
  Cage* newCage = new Cage();
  newCage->isLightOn = isLightOn;
  if (firstCage == nullptr) {
    firstCage = newCage;
    firstCage->next = newCage;
    firstCage->prev = newCage;
  } else {
    newCage->next = firstCage;
    newCage->prev = firstCage->prev;
    (firstCage->prev)->next = newCage;
    firstCage->prev = newCage;
  }
}

int Train::getLength() {
  int length = 0;
  firstCage->isLightOn = true;
  while (firstCage->isLightOn) {
    length = 0;
    Cage* currentCage = firstCage->next;
    operationCount++;
    length++;
    while (!currentCage->isLightOn) {
      operationCount++;
      length++;
      currentCage = currentCage->next;
    }
    currentCage->isLightOn = false;
  }
  operationCount *= 2;
  return length;
}

int Train::getOperationCount() {
  return operationCount;
}
