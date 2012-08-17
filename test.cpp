/**********
*Copyright 2011 Gene Selkov, Samuel Volchenboum
*
*This file is part of Fragment-Singleton.
*
*Fragment-Singleton is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*Fragment-Singleton is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.
*
*You should have received a copy of the GNU General Public License
*along with Fragment-Singleton.  If not, see <http://www.gnu.org/licenses/>.
**********/

#include <iostream>
#include "peptide_fragment.hpp"
using namespace std;

// f = PeptideFragment( 1 ) # mass type = mono
PeptideFragment f(1);

int main () {
  ListD list;
  ListD::iterator el;

  // #                   charge   modifications
  //  f.analyze('ACKRM', 3,       "16.0@M 57.1@3")
  f.analyze(const_cast<char *>("ACKRM"), 3, const_cast<char *>("16.0@M 57.1@3"));

  cout << f.sequence() << ": " << f.composition() << endl;

  cout << "---- b-ions: ---- " << endl;
  list = f.b_ions();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  cout << "---- y-ions: ---- " << endl;
  list = f.y_ions();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  cout << "---- mass: ---- " << endl;
  list = f.peptide_mass();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  cout << endl;

  // f.analyze('KC')
  f.analyze(const_cast<char *>("KC"), 1, const_cast<char *>(""));
  cout << f.sequence() << ": " << f.composition() << endl;

  cout << "---- b-ions: ---- " << endl;
  // l = f.b_ions();
  //for i, m in enumerate(l):
  //    print "  ", m
  list = f.b_ions();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  cout << "---- y-ions: ---- " << endl;
  list = f.y_ions();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  cout << "---- mass: ---- " << endl;
  list = f.peptide_mass();
  for ( el = list.begin(); el != list.end(); el++ ) {
    cout << " " << *el << endl;
  }

  return 0;
}
