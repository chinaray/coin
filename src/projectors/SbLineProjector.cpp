/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2001 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

/*!
  \class SbLineProjector SbLineProjector.h Inventor/projectors/SbLineProjector.h
  \brief The SbLineProjector class projects 2D points to 3D points along a line.
  \ingroup projectors

  The 3D projection of the 2D coordinates is for this projector class
  constrained to lie along a pre-defined line.

  Among other places, this is useful within the translation draggers,
  like for instance SoTranslate1Dragger, where we want to move
  "pieces" along one or more axes.
*/

#include <Inventor/projectors/SbLineProjector.h>

/*!
  \var SbLineProjector::line

  The projection line. Projected 3D points will be constrained to be
  on this line.
*/
/*!
  \var SbLineProjector::lastPoint

  The last projected point.
*/


/*!
  Constructor. Intializes the projector instance to use a line from
  <0, 0, 0> to <0, 1, 0>.
 */
SbLineProjector::SbLineProjector(void)
  : line(SbVec3f(0.0f, 0.0f, 0.0f), SbVec3f(0.0f, 1.0f, 0.0f)),
    lastPoint(0.0f, 0.0f, 0.0f)
{
}

// Overloaded from parent class.
SbVec3f
SbLineProjector::project(const SbVec2f & point)
{
  SbLine projline = this->getWorkingLine(point);
  SbVec3f thispt, projpt;
  SbBool nonparallel = this->line.getClosestPoints(projline, thispt, projpt);
  // if lines are parallel, we will never get an intersection, and
  // we set projection point to (0, 0, 0) to avoid strange rotations
  if (!nonparallel) thispt = SbVec3f(0.0f, 0.0f, 0.0f);
  this->lastPoint = thispt;
  return thispt;
}

/*!
  Set a new projection line. 3D points will be mapped to be on this
  line.
 */
void
SbLineProjector::setLine(const SbLine & line)
{
  this->line = line;
}

/*!
  Returns the currently set projection line.
 */
const SbLine&
SbLineProjector::getLine(void) const
{
  return this->line;
}

/*!
  Calculates and returns a vector between the projected 3D position of
  \a viewpos1 and \a viewpos2.
*/
SbVec3f
SbLineProjector::getVector(const SbVec2f & viewpos1, const SbVec2f & viewpos2)
{
  SbVec3f mp1 = this->project(viewpos1);
  SbVec3f mp2 = this->project(viewpos2);
  this->lastPoint = mp2;
  return mp2 - mp1;
}

/*!
  Returns the 3D vector between the last projection and the one
  calculated for \a viewpos.
*/
SbVec3f
SbLineProjector::getVector(const SbVec2f & viewpos)
{
  SbVec3f lp = this->lastPoint; // lastPoint is updated in project()
  return (this->project(viewpos) - lp);
}

/*!
  Explicitly set position of initial projection, so we get correct
  values for later calls to getVector() etc.
*/
void
SbLineProjector::setStartPosition(const SbVec2f & viewpos)
{
  this->lastPoint = this->project(viewpos);
}

/*!
  Explicitly set position of initial projection, so we get correct
  values for later calls to getVector() etc.
*/
void
SbLineProjector::setStartPosition(const SbVec3f & point)
{
  this->lastPoint = point;
}

// Overloaded from parent.
SbProjector *
SbLineProjector::copy(void) const
{
  return new SbLineProjector(*this);
}
