//
//  GameScene.h
//  nyancatch
//
//  Created by 池本 大騎 on 2014/10/06.
//
//

#ifndef __nyancatch__GameScene__
#define __nyancatch__GameScene__

#include "cocos2d.h"

USING_NS_CC;


class GameScene : public Layer
{
protected:
    enum kTag
    {
        kTag_Background = 1,
        kTag_Basket,
        kTag_Basket_Front,
        kTag_Score,
        kTag_TimeLeft,
        kTag_Cat,
    };
    
    enum kZOrder
    {
        kZOrder_Background = 1,
        kZOrder_Basket,
        kZOrder_Basket_Front,
        kZOrder_Cat,
        kZOrder_Score,
        kZOrder_TimeLeft,

    };
    
    Label* m_pScore_Ones;
    Label* m_pScore_Tenths;
    Label* m_pScore_Hundreds;
    Label* m_pTimeLeft_Ones;
    Label* m_pTimeLeft_Tenths;
    void createBackground();
    void createCat();
    void createLabel();
    
public:
    virtual bool init();
    static Scene* scene();
    CREATE_FUNC(GameScene);
    
};



#endif /* defined(__nyancatch__GameScene__) */
