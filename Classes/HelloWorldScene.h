#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <vector>
#include "cocos2d.h"

#include "BallTexture.h"
#include "TapButtonTexture.h"
#include "StaticTexture.h"
#include "RailTexture.h"
#include "PopupTexture.h"
#include "Music.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void update(float dt) override;
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
    cocos2d::Vector<BallTexture*> mBallLayer;
    cocos2d::Map<int, Music*> mMusicMap;
    
    void stackMusic(std::string fileName);
};

#endif // __HELLOWORLD_SCENE_H__
