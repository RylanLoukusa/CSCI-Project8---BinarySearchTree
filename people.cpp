/**                                                                                                  
 * @Description: This is the implementation file for the people  class                                          
 * @Name: Rylan Loukusa                                                                              
 * @StarID: sq3572nq                                                                                 
 * @Due Date: Monday April 24th
                                                          
 * @Instructor: Dr. Jie Hu Meichsner                                                                 
 */
#include <iostream>
#include "people.h"
using namespace std;

people::people(string n, date dob) : name(n), birthday(dob) {
}

void people::setName(string n)
{
  name = n;
}

void people::setBirthday(date dob)
{
  birthday = dob;
}

string people::getName() const 
{
  return name;
}

date people::getBirthday() const 
{
  return birthday;
}

/** Nonmember Functions */

istream& operator >>(istream & ins, people& people) {

  string name;
  date bday;

  ins >> name >> bday; // read name and birthday

  people.setName(name); // set name and birthday
  people.setBirthday(bday);

  return ins;
}

ostream& operator <<(ostream & outs, const people& people) {

  outs << people.getName() << " " <<  people.getBirthday(); // Display name and birthday

  return outs;
}

bool operator ==(const people& a1, const people& a2) {

  return a1.getName() == a2.getName(); 
}

bool operator >(const people& a1, const people& a2) {

  return a1.getName() > a2.getName(); 
}

bool operator <(const people& a1, const people& a2) {

  return a1.getName() < a2.getName(); 
}
