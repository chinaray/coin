/**************************************************************************\
 *
 *  Copyright (C) 1998-2000 by Systems in Motion.  All rights reserved.
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
  \class SoMouseButtonEvent SoMouseButtonEvent.h Inventor/events/SoMouseButtonEvent.h
  \brief The SoMouseButtonEvent class contains information about
  mousebutton interaction.
  \ingroup events

  When the user presses any buttons on the mouse, these will be
  translated from a system specific event into a Coin event and sent
  to the scenegraph by using instances of this class.

  \sa SoEvent, SoButtonEvent, SoSpaceballButtonEvent, SoKeyboardEvent
  \sa SoEventCallback, SoHandleEventAction */

#include <Inventor/events/SoMouseButtonEvent.h>
#include <Inventor/SbName.h>
#include <assert.h>

/*!
  \enum SoMouseButtonEvent::Button
  This enum contains all mouse buttons detected by Coin.
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::ANY
  Unknown button.
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::BUTTON1
  First mouse button (usually the leftmost button).
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::BUTTON2
  Second mouse button (usually the middle button).
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::BUTTON3
  Third mouse button (usually the rightmost button).
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::BUTTON4
  Fourth mouse button (typically from a wheelmouse). This is
  \e not part of the original Open Inventor API.
*/
/*!
  \var SoMouseButtonEvent::Button SoMouseButtonEvent::BUTTON5
  Fifth mouse button (typically from a wheelmouse). This is
  \e not part of the original Open Inventor API.
*/

/*!
  \def SO_MOUSE_PRESS_EVENT(EVENT, BUTTON)
  This macro evaluates to \c TRUE iff the \c EVENT represents a press on the
  given \c BUTTON.
*/
/*!
  \def SO_MOUSE_RELEASE_EVENT(EVENT, BUTTON)
  This macro evaluates to \c TRUE iff the \c EVENT represents a release of the
  given \c BUTTON.
*/



//$ BEGIN TEMPLATE EventSource(SoMouseButtonEvent)
/*!
  \var SoMouseButtonEvent::classTypeId
  Unique type identification for the SoMouseButtonEvent class type.
*/
SoType SoMouseButtonEvent::classTypeId = SoType::badType();

/*!
  This is a virtual function overloaded in all subclasses which will
  return the type identificator of the class instance.

  \sa getClassTypeId(), isOfType()
*/
SoType
SoMouseButtonEvent::getTypeId(void) const
{
  return SoMouseButtonEvent::classTypeId;
}

/*!
  Returns the type identificator for the SoMouseButtonEvent class.

  \sa getTypeId(), isOfType()
*/
SoType
SoMouseButtonEvent::getClassTypeId(void)
{
  return SoMouseButtonEvent::classTypeId;
}
//$ END TEMPLATE EventSource

/*!
  Initialize the type information data.
 */
void
SoMouseButtonEvent::initClass(void)
{
//$ BEGIN TEMPLATE EventInitClass(MouseButtonEvent)
  // Make sure we only initialize once.
  assert(SoMouseButtonEvent::classTypeId == SoType::badType());
  // Make sure superclass get initialized before subclass.
  assert(inherited::getClassTypeId() != SoType::badType());

  SoMouseButtonEvent::classTypeId =
    SoType::createType(inherited::getClassTypeId(), "MouseButtonEvent");
//$ END TEMPLATE EventInitClass
}

/*!
  Constructor.
*/
SoMouseButtonEvent::SoMouseButtonEvent(void)
{
  this->button = SoMouseButtonEvent::ANY;
}

/*!
  Destructor.
*/
SoMouseButtonEvent::~SoMouseButtonEvent()
{
}

/*!
  Set the value of the button which the user interacted with.

  This method is used from the window specific device classes when
  translating events to the generic Coin library.

  \sa getButton()
 */
void
SoMouseButtonEvent::setButton(SoMouseButtonEvent::Button button)
{
  this->button = button;
}

/*!
  Returns the value of the button which was pressed or released.

  \sa getState()
  \sa wasShiftDown(), wasCtrlDown(), wasAltDown(), getPosition(), getTime()
 */
SoMouseButtonEvent::Button
SoMouseButtonEvent::getButton(void) const
{
  return this->button;
}

/*!
  Convenience method for quickly checking if the given event is a
  press on the given button, \c whichButton.

  \sa isButtonReleaseEvent(), isOfType(), getButton(), getState()
 */
SbBool
SoMouseButtonEvent::isButtonPressEvent(const SoEvent * e,
                                       SoMouseButtonEvent::Button whichButton)
{
  return (e->isOfType(SoMouseButtonEvent::getClassTypeId()) &&
          ((SoMouseButtonEvent *)e)->getButton() == whichButton &&
          ((SoButtonEvent *)e)->getState() == SoButtonEvent::DOWN);
}

/*!
  Convenience method for quickly checking if the given event is a
  release of the given button, \c whichButton.

  \sa isButtonPressEvent(), isOfType(), getButton(), getState()
 */
SbBool
SoMouseButtonEvent::isButtonReleaseEvent(const SoEvent * e,
                                         SoMouseButtonEvent::Button
                                         whichButton)
{
  return (e->isOfType(SoMouseButtonEvent::getClassTypeId()) &&
          ((SoMouseButtonEvent *)e)->getButton() == whichButton &&
          ((SoButtonEvent *)e)->getState() == SoButtonEvent::UP);
}
