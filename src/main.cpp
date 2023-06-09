// Copyright 2022 NNTU-CS
#include 

using namespace std;

int main() {
  int n, count = 1;
  bool light;
  cout << "Введите количество вагонов: ";
  cin >> n;
  cout << "Включить свет в первом вагоне? (1 - да, 0 - нет)\n";
  cin >> light;
  bool prevLight = light;
  for (int i = 2; i <= n; i++) {
    cout << "Включить свет в " << i << " вагоне? (1 - да, 0 - нет)\n";
    cin >> light;
    if (prevLight != light) {
      count++;
      prevLight = light;
    }
  }
  if (prevLight != light) {
    count++;
  }
  cout << "Общее количество вагонов: " << count << endl;
  return 0;
}
