/**                                                                                                
* @Description: This is the header file for the peopleDB class                                  
* @Name: Rylan Loukusa                                                                      
* @StarID: sq3572nq                                                                         
* @Due Date: Friday April 21st                                                              
* @Instructor: Dr. Jie Hu Meichsner                                                         
 */

#include <string>
#include "BinarySearchTree.h"
#include "people.h"
#ifndef PEOPLEDB
#define PEOPLEDB

class peopleDB
{
 private:
  BinarySearchTree<people> db;
  /** to store people in a BST **/

 public:
  peopleDB(string filename) throw(NotFoundException);

  bool addPerson(const people& p);

  bool removePerson(string name);

  people search(string name);

  void displayPreorder(void onVisit(people& p));

  void displaySorted(void onVisit(people& p));
};
#include "peopleDb.cpp"
#endif
