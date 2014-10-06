//
//  AppMacros.h
//  nyancatch
//
//  Created by 池本 大騎 on 2014/10/06.
//
//

#ifndef __nyancatch__AppMacros__
#define __nyancatch__AppMacros__

#include "cocos2d.h"

typedef struct tagResource
{
    cocos2d::Size size;
    char directory[100];
} Resource;

static Resource smallResource = {cocos2d::Size(512, 384), "S"};
static Resource mediumResource = {cocos2d::Size(1024, 768), "M"};
static Resource largeResource = {cocos2d::Size(2048, 1536), "L"};

static cocos2d::Size designResolutionSize = cocos2d::Size(1024, 768);


#endif /* defined(__nyancatch__AppMacros__) */
