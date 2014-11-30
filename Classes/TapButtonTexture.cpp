//
//  TapButtonTexture.cpp
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#include "TapButtonTexture.h"

TapButtonTexture* TapButtonTexture::create(std::string fileName)
{
    auto texture = new TapButtonTexture(fileName);
    texture->init();
    texture->autorelease();
    
    return texture;
}

void TapButtonTexture::setMusicId(int musicId){
    mMusicId = musicId;
}

bool TapButtonTexture::isTarget(int musicId){
    return mMusicId == musicId;
}

bool TapButtonTexture::isTaped(cocos2d::Vec2 tapPosion){
    cocos2d::Vec2 position = this->getPosition();
    cocos2d::Size size = this->getContentSize();
    return tapPosion.x < (position.x + size.width) &&
           (position.x + size.width) < tapPosion.x &&
           tapPosion.y < (position.y + size.height) &&
           (position.y + size.height) < tapPosion.y;
}