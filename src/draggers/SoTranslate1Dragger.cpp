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

#include <Inventor/draggers/SoTranslate1Dragger.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSwitch.h>


SO_KIT_SOURCE(SoTranslate1Dragger);


void
SoTranslate1Dragger::initClass(void)
{
  SO_KIT_INTERNAL_INIT_CLASS(SoTranslate1Dragger);
}

SoTranslate1Dragger::SoTranslate1Dragger(void)
{
  SO_KIT_INTERNAL_CONSTRUCTOR(SoTranslate1Dragger);

  SO_KIT_ADD_CATALOG_ENTRY(translatorSwitch, SoSwitch, TRUE, geomSeparator, feedbackSwitch, FALSE);
  SO_KIT_ADD_CATALOG_ENTRY(translator, SoSeparator, TRUE, translatorSwitch, translatorActive, TRUE);
  SO_KIT_ADD_CATALOG_ENTRY(translatorActive, SoSeparator, TRUE, translatorSwitch, "", TRUE);
  SO_KIT_ADD_CATALOG_ENTRY(feedbackSwitch, SoSwitch, TRUE, geomSeparator, "", FALSE);
  SO_KIT_ADD_CATALOG_ENTRY(feedback, SoSeparator, TRUE, feedbackSwitch, feedbackActive, TRUE);
  SO_KIT_ADD_CATALOG_ENTRY(feedbackActive, SoSeparator, TRUE, feedbackSwitch, "", TRUE);

  SO_NODE_ADD_FIELD(translation, (0.0f, 0.0f, 0.0f));

  SO_KIT_INIT_INSTANCE();
}


SoTranslate1Dragger::~SoTranslate1Dragger()
{
  COIN_STUB();
}

SbBool
SoTranslate1Dragger::setUpConnections(SbBool onoff, SbBool doitalways)
{
  COIN_STUB();
  return FALSE;
}

void
SoTranslate1Dragger::fieldSensorCB(void * f, SoSensor * s)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::valueChangedCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::startCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::motionCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::finishCB(void * f, SoDragger * d)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::dragStart(void)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::drag(void)
{
  COIN_STUB();
}

void
SoTranslate1Dragger::dragFinish(void)
{
  COIN_STUB();
}
