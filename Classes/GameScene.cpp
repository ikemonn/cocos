//
//  GameScene.cpp
//  nyancatch
//
//  Created by 池本 大騎 on 2014/10/06.
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "AppMacros.h"

using namespace std;
using namespace CocosDenshion;

Scene* GameScene::scene()
{
    Scene* scene = Scene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    // 背景の追加
    createBackground();
    
    // 猫の表示
    createCat();
    
    // スコアと残り時間を表示
    createLabel();
    
    return true;
}

void GameScene::createBackground()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    // 背景の表示
    Sprite* pBgUnder = Sprite::create("game_bg.png");
    pBgUnder->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(pBgUnder, kZOrder_Background, kTag_Background);
}

void GameScene::createCat()
{
    Size winSize = Director::getInstance()->getWinSize();
    Size bgSize = this->getChildByTag(kTag_Background)->getContentSize();
    
    // 猫の表示
    Sprite* pCat = Sprite::create("cat1.png");
    pCat->setPosition(Point(bgSize.width * 0.5, bgSize.height * 0.35 - (bgSize.height - winSize.height)/2));
    this->addChild(pCat, kZOrder_Cat, kTag_Cat);
    
    // カゴの表示
    Sprite* pBasket = Sprite::create("basket1.png");
    pBasket->setPosition(Point(pCat->getPositionX() + bgSize.width * 0.05, pCat->getPositionY() + bgSize.height * 0.03));
    this->addChild(pBasket, kZOrder_Basket, kTag_Basket);
    
    // カゴ前面の表示
    Sprite* pBasketFront = Sprite::create("basket0.png");
    pBasketFront->setPosition(pBasket->getPosition());
    this->addChild(pBasketFront, kZOrder_Basket_Front, kTag_Basket_Front);
    
    
    
}

void GameScene::createLabel()
{
    Size winSize = Director::getInstance()->getWinSize();
    Size viewSize = Director::getInstance()->getOpenGLView()->getFrameSize();
    float scale = Director::getInstance()->getOpenGLView()->getScaleY();
    float offset = (winSize.height * scale - viewSize.height) / 2 / scale;
    
    // 残り時間の表示
    Sprite* pTimeLeft = Sprite::create("timeleft.png");
    pTimeLeft->setPosition(Point(pTimeLeft->getContentSize().width / 2, winSize.height - pTimeLeft->getContentSize().height / 2 - offset));
    this->addChild(pTimeLeft, kZOrder_TimeLeft, kTag_TimeLeft);
    Size timeLeftSize = pTimeLeft->getContentSize();
    
    // 残り時間10の位
    m_pTimeLeft_Tenths = Label::createWithSystemFont("6", "Arial", 24.0);
    m_pTimeLeft_Tenths->setPosition(Point(timeLeftSize.width * 0.45, timeLeftSize.height * 0.4));
    m_pTimeLeft_Tenths->setColor(Color3B::BLACK);
    pTimeLeft->addChild(m_pTimeLeft_Tenths);
    
    // 残り時間1の位
    m_pTimeLeft_Ones = Label::createWithSystemFont("0", "Arial", 24.0);
    m_pTimeLeft_Ones->setPosition(Point(timeLeftSize.width * 0.675, timeLeftSize.height * 0.4));
    m_pTimeLeft_Ones->setColor(Color3B::BLACK);
    pTimeLeft->addChild(m_pTimeLeft_Ones);
    
    // スコアの表示
    Sprite* pScore = Sprite::create("game_counter.png");
    pScore->setPosition(Point(winSize.width - pScore->getContentSize().width / 2, pScore->getContentSize().height/2 + offset));
    this->addChild(pScore, kZOrder_Score, kTag_Score);
    
    Size scoreSize = pScore->getContentSize();
    
    // スコア100の位
    m_pScore_Hundreds = Label::createWithSystemFont("", "Arial", 24.0);
    m_pScore_Hundreds->setPosition(Point(scoreSize.width * 0.4, scoreSize.height * 0.3));
    m_pScore_Hundreds->setColor(Color3B::BLACK);
    pScore->addChild(m_pScore_Hundreds);
    
    // スコア10の位
    m_pScore_Tenths = Label::createWithSystemFont("", "Arial", 24.0);
    m_pScore_Tenths->setPosition(Point(scoreSize.width * 0.625, scoreSize.height * 0.3));
    m_pScore_Tenths->setColor(Color3B::BLACK);
    pScore->addChild(m_pScore_Tenths);
    
    // スコア1の位
    m_pScore_Ones = Label::createWithSystemFont("0", "Arial", 24.0);
    m_pScore_Ones->setPosition(Point(scoreSize.width * 0.85, scoreSize.height * 0.3));
    m_pScore_Ones->setColor(Color3B::BLACK);
    pScore->addChild(m_pScore_Ones);
    
}

