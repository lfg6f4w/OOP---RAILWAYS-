#include "train.h"
int Train::counter = 0;

Train::Train() : Train("", "", "", "", "", "", 0, 0, 0, 0, 1000){}
Train::Train(string name, string station, string destination,string date,string time,string duration, int numOfPassengers,int priceA,int priceB,int priceC,int capacity){
  this->name = name;
  this->station = station;
  this->destination =  destination;
  this->date = date;
  this->time = time;
  this->duration = duration;
  this->num = ++counter;
  this->priceA = priceA;
  this->priceB = priceB;
  this->priceC = priceC;
  this->numOfPassengers = 0;
  this->capacity = capacity;
  this->passengers.resize(capacity);
}
string Train::getName() const{
  return this->name;
}
string Train::getStation() const{
  return this->station;
}
string Train::getDestination() const{
  return this->destination;
}
string Train::getDate() const{
  return this->date;
}
string Train::getTime() const{
  return this->time;
}
string Train::getDuration() const{
  return this->duration;
}
int Train::getNum() const{
  return this->num;
}
int Train::getPriceA() const{
  return this->priceA;
}
int Train::getPriceB() const{
  return this->priceB;
}
int Train::getPriceC() const{
  return this->priceC;
}
int Train::getNumOfPassengers() const{
  return this->numOfPassengers;
}
int Train::getCapacity() const{
  return this->capacity;
}
Passengers* Train::getPassenger(int i) const{
  return passengers[i];
}
void Train::setName(string name){
  this->name = name;
}
void Train::setStation(string station){
  this->station = station;
}
void Train::setDestination(string destination){
  this->destination = destination;
}
void Train::setDate(string date){
  this->date = date;
}
void Train::setTime(string time){
  this->time = time;
}
void Train::setDuration(string duration){
  this->duration = duration;
}
void Train::setPriceA(int price){
  this->priceA = price;
}
void Train::setPriceB(int price){
  this->priceB = price;
}
void Train::setPriceC(int price){
  this->priceC = price;
}

bool Train::AddPassenger(User* user,char cls){
  if(numOfPassengers < capacity){
    passengers[numOfPassengers]->passenger = user;
    passengers[numOfPassengers]->price = (cls == 'a' ? priceA : (cls == 'b' ? priceB : priceC));
    passengers[numOfPassengers]->pay = false;
    numOfPassengers++;
    return true;
  }
  else return false;
}
bool Train::PayMoney(Passengers *passenger){
  if(passenger->passenger->getCredit() >= passenger->price){
    int money = passenger->passenger->getCredit() - passenger->price;
    passenger->passenger->setCredit(money);
    passenger->pay = true;
    return true;
  }
  return false;
}
void Train::CancelTicket(Passengers* passenger){
  numOfPassengers--;
  free(passenger);
}
Passengers* Train::findPassenger(User* user) const{
  for (int i = 0; i < numOfPassengers;i++){
    if(passengers[i]->passenger == user){
      return passengers[i];
    }
  }
  return nullptr;
}
void Train::PaintAll(){
  cout  << "Train Name: " << this->name << " - Train Station: " << this->station << " - Train Destination: " << this->destination << '\n'
        << "Train Date: " << this->date << " - Train Time: " << this->time << " - Train Duration: " << this->duration << '\n'
        << "Train Num: " << this->num << " - Train Price:" << this->priceA << ' ' << this->priceB << ' ' << this->priceC << '\n'
        << "Number of passengers: " << this->numOfPassengers << '\n';
}
ostream &operator<<(ostream &output, Train &train){
  output << train.name << "\n\t"
         << train.date << ' '
         << train.time << ' '
         << train.duration
         << "hr Class A-" << train.priceA
         << "P Class B-" << train.priceB
         << "P Class C-" << train.priceC << '\n';
  return output;
}

Train::~Train(){
  delete &passengers;
}