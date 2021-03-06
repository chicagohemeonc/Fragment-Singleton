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

#ifndef __peptide_fragment_hpp_
#define __peptide_fragment_hpp_

#include <string>
#include <list>
using namespace std;

#define SAMPLEPEPTIDE "DIGSESTEDQAMEDIK"
#define MAX_SEQUENCE 100000
#define MAX_CHARGE   10
#define PROTON_MASS 1.00727646688

struct ProteaseStruct
{
   char szName[96];
   char szCut[24];
   char szNoCut[24];
   int  iSense;    /* 0=n-term, 1=c-term */
} *pProtease, *pTmp;


typedef std::list<double> ListD;


class PeptideFragment {

public:
  PeptideFragment ( int massType );
  void analyze( char * peptide, int charge, char *modification );
  string sequence ( void ) const;
  virtual ListD a_ions ( void );
  virtual ListD b_ions ( void );
  virtual ListD c_ions ( void );
  virtual ListD x_ions ( void );
  virtual ListD y_ions ( void );
  virtual ListD z_ions ( void );
  virtual ListD zdot_ions ( void );
  virtual ListD peptide_mass ( void );
  virtual string composition ( void );
  ListD a;
  ListD b;
  ListD c;
  ListD x;
  ListD y;
  ListD z;
  ListD zdot;
  ListD mass;

private:
  /* parameter values */
  char _szInputSequence[MAX_SEQUENCE];
  unsigned int _iLenPeptide;
  unsigned int _iMassType; /*
                   * bMassType=0 for average masses
                   * bMassType=1 for monoisotopic masses
                   */
  int _iCharge;          /* ion charge */
  string _modification;  /* specifies which residues are modified and how */
  std::list<int> _modifiedPos; /* remembers modified positions in the sequence, so they can be reset */

  /* work variables */
  double pdMassAA[128];
  double pdMassAA_template[128];
  double pdPositionMod[MAX_SEQUENCE];
  double dPepMass;
  double dNterm;
  double dCterm;

  int piCompC[128];
  int piCompH[128];
  int piCompN[128];
  int piCompO[128];
  int piCompS[128];

  /* private methods */
  void _initialize_mass ( void );
  void _copy_mass ( void );
  void _init_comp ( void );
};

#endif
