/**************************************************************************\
 *
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

#ifndef __SOMFROTATION_H__
#define __SOMFROTATION_H__

#include <Inventor/fields/SoMField.h>
#include <Inventor/fields/SoSubField.h>
#include <Inventor/SbRotation.h>


class SoMFRotation : public SoMField {
  typedef SoMField inherited;

  SO_MFIELD_HEADER(SoMFRotation, SbRotation, const SbRotation &);

public:
  static void initClass(void);

  void setValues(const int start, const int num, const float q[][4]);
  void set1Value(const int idx, const float q0, const float q1, const float q2, const float q3);
  void set1Value(const int idx, const float q[4]);
  void set1Value(const int idx, const SbVec3f & axis, const float angle);
  void setValue(const float q0, const float q1, const float q2, const float q3);
  void setValue(const float q[4]);
  void setValue(const SbVec3f & axis, const float angle);

private:
  virtual void convertTo(SoField * dest) const;
};

#endif // !__SOMFROTATION_H__
