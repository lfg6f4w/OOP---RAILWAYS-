// #include <bits/stdc++.h>
#include "user.h"
#pragma once
// using namespace std;
struct Passengers{
  User* passenger;
  int price;
  bool pay;
};

class Train{
  string name;
  string station;
  string destination;
  string date;
  string time;
  string duration;
  vector<Passengers*>passengers;
  int num;
  int priceA;
  int priceB;
  int priceC;
  int numOfPassengers;
  int capacity;
  static int counter;
public:
  Train();
  Train(string, string, string, string, string, string, int, int, int, int, int);
  string getName() const;
  string getStation() const;
  string getDestination() const;
  string getDate() const;
  string getTime() const;
  string getDuration() const;
  int getNum() const;
  int getPriceA() const;
  int getPriceB() const;
  int getPriceC() const;
  int getNumOfPassengers() const;
  int getCapacity() const;
  Passengers *getPassenger(int) const;
  void setName(string);
  void setStation(string);
  void setDestination(string);
  void setDate(string);
  void setTime(string);
  void setDuration(string);
  void setPriceA(int);
  void setPriceB(int);
  void setPriceC(int);
  bool AddPassenger(User *,char);
  bool PayMoney(Passengers *);
  void CancelTicket(Passengers *);
  Passengers* findPassenger(User*) const;
  friend ostream &operator<<(ostream &, Train &);
  void PaintAll();
  ~Train();
};