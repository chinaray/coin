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

/*!
  \class SoMFBitMask SoMFBitMask.h Inventor/fields/SoMFBitMask.h
  \brief The SoMFBitMask class ...
  \ingroup fields

  FIXME: write class doc
*/

#include <Inventor/fields/SoMFBitMask.h>
#include <Inventor/fields/SoSFBitMask.h>

#include <Inventor/errors/SoDebugError.h>
#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/SbName.h>

// *************************************************************************

//$ BEGIN TEMPLATE MFieldConstructor(SoMFBitMask)

/*!
  Constructor.
*/
SoMFBitMask::SoMFBitMask(void)
{
  // Make sure we have initialized class.
  assert(SoMFBitMask::classTypeId != SoType::badType());
  this->values = NULL;
}

/*!
  Destructor.
*/
SoMFBitMask::~SoMFBitMask(void)
{
  this->deleteAllValues();
}
//$ END TEMPLATE MFieldConstructor

//$ BEGIN TEMPLATE MFieldRequired(SoMFBitMask)

SoType SoMFBitMask::classTypeId = SoType::badType();

/*!
  Virtual method which returns the type identifier for an object.

  \sa getClassTypeId()
*/
SoType
SoMFBitMask::getTypeId(void) const
{
  return SoMFBitMask::classTypeId;
}

/*!
  Returns a unique type identifier for the SoMFBitMask class.

  \sa getTypeId(), SoType
 */
SoType
SoMFBitMask::getClassTypeId(void)
{
  return SoMFBitMask::classTypeId;
}

/*!
  Constructs and returns a new instance of the SoMFBitMask class.
*/
void *
SoMFBitMask::createInstance(void)
{
  return new SoMFBitMask;
}
/*!
  Copy all data from \a field into this object. \a field \e must
  be of the same type as the field we are copying into.
*/
void
SoMFBitMask::copyFrom(const SoField & field)
{
#if 0 // COIN_DEBUG
  // Calling field.getTypeId() here fails when "this" is connected to "field"
  // and "field" is destructed. The error message is "pure virtual method
  // called" with egcs 1.0.2 under Linux. 19990713 mortene.
  if (field.getTypeId() != this->getTypeId()) {
    SoDebugError::postWarning("SoMFBitMask::copyFrom",
                              "not of the same type: (this) '%s' (from) '%s'",
                              this->getTypeId().getName().getString(),
                              field.getTypeId().getName().getString());
    return;
  }
#endif // COIN_DEBUG

  this->operator=((const SoMFBitMask &)field);
}

/*!
  Tests \a field against this field for equality. Returns \a FALSE if they
  are not of the same type, or if they do not contain the same data.
*/
SbBool
SoMFBitMask::isSame(const SoField & field) const
{
  if (field.getTypeId() != this->getTypeId()) return FALSE;
  return this->operator==((const SoMFBitMask &) field);
}

/*!
  Copy all field values from \a field into this object.
*/
const SoMFBitMask &
SoMFBitMask::operator = (const SoMFBitMask & field)
{
  if (field.getNum() < this->getNum()) this->deleteAllValues();
  this->setValues(0, field.getNum(), field.getValues(0));
  return *this;
}
//$ END TEMPLATE MFieldRequired

// *************************************************************************

/*!
  Does initialization common for all objects of the
  SoMFBitMask class. This includes setting up the
  type system, among other things.
*/
void
SoMFBitMask::initClass(void)
{
//$ BEGIN TEMPLATE FieldInitClass(MFBitMask)
  // Make sure we only initialize once.
  assert(SoMFBitMask::classTypeId == SoType::badType());
  // Make sure superclass has been initialized before subclass.
  assert(inherited::getClassTypeId() != SoType::badType());

  SoMFBitMask::classTypeId =
    SoType::createType(inherited::getClassTypeId(),
                       "MFBitMask", &SoMFBitMask::createInstance);
//$ END TEMPLATE FieldInitClass
}

// *************************************************************************

SbBool
SoMFBitMask::read1Value(SoInput * in, int idx)
{
  SoSFBitMask sfbitmask;
  sfbitmask.setEnums(this->numEnums, this->enumValues, this->enumNames);
  SbBool result;
  if ((result = sfbitmask.readValue(in)))
    this->set1Value(idx, sfbitmask.getValue());
  return result;
}

void
SoMFBitMask::write1Value(SoOutput * out, int idx) const
{
  SoSFBitMask sfbitmask;
  sfbitmask.setEnums(this->numEnums, this->enumValues, this->enumNames);
  sfbitmask.setValue((*this)[idx]);
  sfbitmask.writeValue(out);
}

/*!
  FIXME: write function documentation
*/
SbBool
SoMFBitMask::findEnumValue(const SbName & name, int & val)
{
  // Look through names table for one that matches
  for (int i = 0; i < numEnums; i++) {
    if (name == enumNames[i]) {
      val = enumValues[i];
      return TRUE;
    }
  }
  return FALSE;
}

void
SoMFBitMask::convertTo(SoField * dest) const
{
  if (dest->getTypeId()==SoSFBitMask::getClassTypeId()) {
    if (this->getNum()>0)
      ((SoSFBitMask *)dest)->setValue((*this)[0]);
  }
#if COIN_DEBUG
  else {
    SoDebugError::post("SoMFBitMask::convertTo",
                       "Can't convert from %s to %s",
                       this->getTypeId().getName().getString(),
                       dest->getTypeId().getName().getString());
  }
#endif // COIN_DEBUG
}
