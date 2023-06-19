/**                                                                                                  
 * @Description: This is the implementation file for the date class                                          
 * @Name: Rylan Loukusa                                                                              
 * @StarID: sq3572nq                                                                                 
 * @Due Date: Monday April 24st                                                                      
 * @Instructor: Dr. Jie Hu Meichsner                                                                 
 */

#include "date.h"
using namespace std;

date::date(int d, int m, int y) : day(d), month(m), year(y)
{
}

void date::setDay(int d) {
  day = d;
}

void date::setMonth(int m) {
  month = m;
}

void date::setYear(int y) {
  year = y;
}

int date::getDay() const {
  return day;
}

int date::getMonth() const {
  return month;
}

int date::getYear() const {
  return year;
}

/* Nonmeber Functions */

istream& operator >>(istream & ins, date& date) {
  int day, month, year;

  ins >> month >> day >> year; // Read dates

  date.setDay(day);
  date.setMonth(month);
  date.setYear(year);

  return ins;
}

ostream& operator <<(ostream & outs, const date& date) {

  outs << date.getMonth() << " " << date.getDay()  << " " << date.getYear(); 

  return outs;
}
