/*
 * LGLaserParser.h
 *
 *  Created on: 7 okt 2015
 *      Author: CART
 */

#ifndef LGLASERPARSER_H_
#define LGLASERPARSER_H_

#ifdef __cplusplus
extern "C" {
#endif
  
typedef int (*LGLaserParser_handler_ui)(void*, unsigned int);
typedef int (*LGLaserParser_handler_uc)(void*, unsigned char* str);
typedef int (*LGLaserParser_handler_f)(void*, float);

typedef struct _LGLaserParser_Callbacks
{
  void*                     instance;
  LGLaserParser_handler_ui status;
  LGLaserParser_handler_ui mode;
  LGLaserParser_handler_uc version;
  LGLaserParser_handler_uc firmware;
  LGLaserParser_handler_ui serialNbr;
  LGLaserParser_handler_f  pulseWidth;
  LGLaserParser_handler_f  frequency;
  LGLaserParser_handler_f  poip;
  LGLaserParser_handler_f  systemOnCounter;
  LGLaserParser_handler_f  tecCounter;
  LGLaserParser_handler_f  powerAmpCounter;
  LGLaserParser_handler_f  preAmpCounter;
  LGLaserParser_handler_f  tecResistance;
  LGLaserParser_handler_f  externalResistance;
  LGLaserParser_handler_f  boardResistance;
  LGLaserParser_handler_ui error;
} LGLaserParser_Callbacks;
  
typedef struct _LGLaserParser
{
  LGLaserParser_Callbacks  m_callbacks;
} LGLaserParser;

int LGLaserParser_init(LGLaserParser*           self,
						LGLaserParser_Callbacks  callbacks);
  
int LGLaserParser_scan(LGLaserParser* self, unsigned char* fifo, int len);

#ifdef __cplusplus
}
#endif

#endif /* LGLASERPARSER_H_ */
