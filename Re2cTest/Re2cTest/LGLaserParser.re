// Generated as: re2c -sio LGLaserParser.c LGLaserParser.re
// -*- c++ -*-

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "LGLaserParser.h"

/******************************************************************************/

#define atoi(s) atoi((char*)s)

/******************************************************************************/

int LGLaserParser_init(LGLaserParser*           self,
					   LGLaserParser_Callbacks  callbacks)
{
  assert(self);
  assert(callbacks.status);
  assert(callbacks.mode);
  assert(callbacks.version);
  assert(callbacks.firmware);
  assert(callbacks.serialNbr);
  assert(callbacks.pulseWidth);
  assert(callbacks.frequency);
  assert(callbacks.poip);
  assert(callbacks.systemOnCounter);
  assert(callbacks.tecCounter);
  assert(callbacks.powerAmpCounter);
  assert(callbacks.preAmpCounter);
  assert(callbacks.tecResistance);
  assert(callbacks.externalResistance);
  assert(callbacks.boardResistance);
  assert(callbacks.error);

  self->m_callbacks = callbacks;

  return 0;
}

/******************************************************************************/

static int getFloat(unsigned char* t, float* value)
{
  char* end;
  *value = strtof((char*)t, &end);
  return errno == ERANGE;
}

/******************************************************************************/

int LGLaserParser_scan(LGLaserParser* self, unsigned char* fifo, int len)
{
  unsigned char *p = fifo;
  unsigned char *t = 0;
  unsigned char *q = 0;  
  int res = 0;
  float fVal;
  
  if (len == 0)
	{
	  return 0;
	}
  
#define YYCTYPE         unsigned char
#define YYCURSOR        p
#define YYMARKER        q  
	
	while (!res && p <= &fifo[len-1])
	{
		t = p;
/*!re2c
	re2c:indent:top = 2;
	re2c:yyfill:enable = 0;

	DIGIT	 = [0-9] ;
	HEX      = ( [0-f] | [0-F] ) ;
	SIGN     = [-+] ;
	BOOL     = [01] ;
	DOT      = "." ;
	EQ       = "=" ;
	STATUS   = HEX{8} ;
	FLOAT	 = SIGN? DIGIT* DOT? DIGIT+ ;
	STRING   = [^]+ ;
	END      = "\000" ;
	ANY      = [^];
			
	"$LS"		EQ	{ goto statusMsg; }
	"RS"  	    EQ  { goto modeMsg; }
	"VER"    	EQ	{ goto versionMsg; }
	"VD25"	    EQ	{ goto firmwareMsg; }
	"SN"		EQ	{ goto serialNbrMsg; }
	"PRW"		EQ	{ goto pulseWidthMsg; }
	"F"		    EQ	{ goto frequencyMsg; }
	"POIP"	    EQ	{ goto poipMsg; }
	"H1"		EQ	{ goto systemOnCounterMsg; }
	"H2"		EQ	{ goto tecCounterMsg; }
	"H3"		EQ	{ goto powerAmpCounterMsg; }
	"H4"		EQ	{ goto preAmpCounterMsg; }
	"T1"		EQ	{ goto tecResistanceMsg; }
	"T2"		EQ	{ goto externalResistanceMsg; }
	"T3"		EQ	{ goto boardResistanceMsg; }
	"COM_ERR"   EQ	{ goto errorMsg; }
	END { return 0; }
	ANY { return 1; }
*/

	statusMsg:
		t = p;
		/*!re2c
		  STATUS END
		  {
		  char* end;
		  long value = strtol((char*)t, &end, 16);
		  if (errno == ERANGE) return 1;
		  res = self->m_callbacks.status(self->m_callbacks.instance, value);
		  continue;
		  }
		  ANY			{ return 1; }
		*/
		
	modeMsg:
		t = p;
		/*!re2c
		  BOOL END	{ res = self->m_callbacks.mode(self->m_callbacks.instance, atoi(t)); continue; }
		  ANY			{ return 1; }
		*/
		
	versionMsg:
		t = p;
		/*!re2c
		  STRING END	{ res = self->m_callbacks.version(self->m_callbacks.instance, t); continue; }
		  ANY			{ return 1; }
		*/
		
	firmwareMsg:
		t = p;
		/*!re2c
		  STRING END	{ res = self->m_callbacks.firmware(self->m_callbacks.instance, t); continue; }
		  ANY			{ return 1; }
		*/
		
	serialNbrMsg:
		t = p;
		/*!re2c
		  STRING END	{ res = self->m_callbacks.serialNbr(self->m_callbacks.instance, atoi(t)); continue; }
		  ANY			{ return 1; }
		*/
		
	pulseWidthMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.pulseWidth(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	frequencyMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.frequency(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	poipMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.poip(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	systemOnCounterMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.systemOnCounter(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	tecCounterMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.tecCounter(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	powerAmpCounterMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.powerAmpCounter(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	preAmpCounterMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.preAmpCounter(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	tecResistanceMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.tecResistance(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	externalResistanceMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.externalResistance(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	boardResistanceMsg:
		t = p;
		/*!re2c
		  FLOAT END { if (!getFloat(t, &fVal)) return 1; res = self->m_callbacks.boardResistance(self->m_callbacks.instance, fVal); continue; } 
		  ANY		  { return 1; }
		*/
		
	errorMsg:
		t = p;
		/*!re2c
		  DIGIT END	{ res = self->m_callbacks.error(self->m_callbacks.instance, atoi(t)); continue; }
		  ANY			{ return 1; }
		*/
	}
	
	return res;
}

/******************************************************************************/
