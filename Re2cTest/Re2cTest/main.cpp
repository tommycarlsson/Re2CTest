//
//  main.cpp
//  Re2cTest
//
//  Created by Tommy Carlsson on 22/11/15.
//  Copyright (c) 2015 Tommy Karlsson. All rights reserved.
//

#include <iostream>
#include "LGLaserParser.h"

using namespace std;

int onStatus(void*, unsigned int v)
{
    cout << "onStatus: " << hex << v << endl;
    return 0;
}

int onMode(void*, unsigned int v)
{
    cout << "onMode: " << v;
    return 0;
}

int onVersion(void*, unsigned char* v)
{
    cout << "onVersion: " << v;
    return 0;
}

int onFirmware(void*, unsigned char* v)
{
    cout << "onFirmware: " << v;
    return 0;
}

int onSerialNbr(void*, unsigned int v)
{
    cout << "onSerialNbr: " << v;
    return 0;
}

int onPulseWidth(void*, float v)
{
    cout << "onPulseWidth: " << v;
    return 0;
}

int onFrequency(void*, float v)
{
    cout << "onFrequency: " << v;
    return 0;
}

int onPoip(void*, float v)
{
    cout << "onPoip: " << v;
    return 0;
}

int onSystemOnCounter(void*, float v)
{
    cout << "onSystemOnCounter: " << v;
    return 0;
}

int onTecCounter(void*, float v)
{
    cout << "onTecCounter: " << v;
    return 0;
}

int onPowerAmpCounter(void*, float v)
{
    cout << "onPowerAmpCounter: " << v;
    return 0;
}

int onPreAmpCounter(void*, float v)
{
    cout << "onPreAmpCounter: " << v;
    return 0;
}

int onTecResistance(void*, float v)
{
    cout << "onTecResistance: " << v;
    return 0;
}

int onExternalResistance(void*, float v)
{
    cout << "onExternalResistence: " << v;
    return 0;
}

int onBoardResistance(void*, float v)
{
    cout << "onBoardResistence: " << v;
    return 0;
}

int onError(void*, unsigned int v)
{
    cout << "onError: " << v;
    return 0;
}


int main(int argc, const char * argv[])
{
    LGLaserParser_Callbacks callbacks;
    
    callbacks.status = onStatus;
    callbacks.mode = onMode;
    callbacks.version = onVersion;
    callbacks.firmware = onFirmware;
    callbacks.serialNbr = onSerialNbr;
    callbacks.pulseWidth = onPulseWidth;
    callbacks.frequency = onFrequency;
    callbacks.poip = onPoip;
    callbacks.systemOnCounter = onSystemOnCounter;
    callbacks.tecCounter = onTecCounter;
    callbacks.powerAmpCounter = onPowerAmpCounter;
    callbacks.preAmpCounter = onPreAmpCounter;
    callbacks.tecResistance = onTecResistance;
    callbacks.externalResistance = onExternalResistance;
    callbacks.boardResistance = onBoardResistance;
    callbacks.error = onError;
    
    LGLaserParser parser;
    
    LGLaserParser_init(&parser, callbacks);
    
    string v("$LS=123abcde");
    LGLaserParser_scan(&parser, (char*)v.c_str(), v.length());
    
    return 0;
}
