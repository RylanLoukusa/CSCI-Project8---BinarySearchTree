/** 
 * @Description: This is the header file for the date class
 * @Name: Rylan Loukusa
 * @StarID: sq3572nq
 * @Due Date: Friday April 21st
 * @Instructor: Dr. Jie Hu Meichsner
 */

#include <iostream>
#include <fstream>
#ifndef DATE
#define DATE

class date
{
 private:

  int month;
  int day;
  int year;

 public:

  /** Constructor
   * @param d the day
   * @param m the month
   * @param y the year
   * @pre None
   * @post sets date to day, month, year */
  date(int d = 0, int m = 0, int y = 0);

  /** Constant Member Functions */

  void setMonth(int m);
  
  void setDay(int d);

  void setYear(int y);

  int getMonth() const;

  int getDay() const;

  int getYear() const;
};
/** Nonmember Functions */

istream& operator >>(istream& ins, date& date);

ostream& operator <<(ostream& outs, const date& date);
#include "date.cpp"
#endif
