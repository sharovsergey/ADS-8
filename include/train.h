#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
class Train {
 private:
  struct Cage {
    bool light; // состояние лампочки
    Cage *next;
    Cage *prev;
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  int count1;
  Cage *first; // точка входа в поезд (первый вагон)
  Cage *last;
 public:
  Train();
  Train():first(nullptr), last(nullptr), countOp(0), count1(0) {}
  void addCage(bool light); // добавить вагон с начальным состоянием лампочки
  int getLength();          // вычислить длину поезда
  int getOpCount();         // вернуть число переходов (из вагона в вагон)
};
#endif  // INCLUDE_TRAIN_H_
