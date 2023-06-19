/**                                                                                          
* @Description: This is the header file for the date class                                  
* @Name: Rylan Loukusa                                                                      
* @StarID: sq3572nq                                                                         
* @Due Date: Friday April 21st                                                              
* @Instructor: Dr. Jie Hu Meichsner                                                         
 */
#include <string>
#include <iostream>
#include "date.h"
#ifndef PEOPLE
#define PEOPLE

class people
{
 private:

  string name;
  date birthday;

 public:

  /**Constructor:
   * @param n the name
   * @param dob the date of birth/birthday
   * @pre None
   * @post sets people to : name(n), birthday(dob) */
  people(string n = " ", date dob = date());

  /** Constant Member Functions */

  void setName(string n);

  void setBirthday(date b);

  string getName() const;

  date getBirthday() const;
};

std::istream& operator >>(std::istream& ins, people& people);

std::ostream& operator <<(std::ostream& outs, const people& people);

bool operator ==(const people& a1, const people& a2);

bool operator >(const people& a1, const people& a2);

bool operator <(const people& a1, const people& a2);

#include "people.cpp"
#endif
