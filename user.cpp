#include "user.h"

int User::counter = 0;

User::User() : User("","", "", "", 0, 0, 0){};

User::User(string name,string username, string email, string password,int creditCard, int age, char gender)
          : username(username), email(email), password(password),creditCard(creditCard), age(age), gender(gender), id(++counter){};

int User::getID()const{
  return id;
}
string User::getUserName() const{
  return username;
}
string User::getPassword() const{
  return password;
}
int User::getCredit() const{
  return creditCard;
}
void User::setCredit(int credit){
  creditCard = credit;
}
bool User::bayFood(food* f){
  if(creditCard >= f->getPrice()){
    FoodReserve.push_back(f);
    creditCard -= f->getPrice();
    f->setAmount(f->getAmount() - 1);
    return true;
  }
  else return false;
}
void User::PrintAll()const{
  cout << "Name: " << name << " - UserName: " << username << " - Password:" << password << " - Email: " << email << '\n';
  cout << "Age: " << age << " - Gender: " << gender << '\n';
}
istream &operator>>(istream & input, User &user){
  cout << "\nEnter Your Name: ";
  input >> user.name;
  cout << "\nEnter The Unique UserNama: ";
  input >> user.username;
  cout << "\nEnter Your Email: ";
  input >> user.email;
  cout << "\nEnter Your Password: ";
  input >> user.password;
  cout << "Enter Your Credit Card: ";
  input >> user.creditCard;
  cout << "\nEnter Your Age: ";
  input >> user.age;
  cout << "\nEnter Your Gender: ";
  input >> user.gender;
  return input;
}
ostream &operator<<(ostream & output, User user){
  output << "\nUser Info : "
         << "\n\tYour Name: " << user.name
         << "\n\tYour User Name: " << user.username
         << "\n\tYour Email: " << user.email
         << "\n\tYour Password: " << user.password
         << "\n\tYour Age: " << user.age
         << "\n\tYour Gender: " << user.gender;
  return output;
}
