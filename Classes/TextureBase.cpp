//
//  TextureBase.cpp
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/29.
//
//

#include "TextureBase.h"

USING_NS_CC;

TextureBase::TextureBase(std::string fileName) : mFilename(fileName)
{
}

TextureBase* TextureBase::create(std::string fileName)
{
    auto texture = new TextureBase(fileName);
    texture->init();
    texture->autorelease();
    
    return texture;
}

bool TextureBase::init()
{
    if (!Sprite::initWithFile(mFilename)){
        return false;
    }
    return true;
}

void TextureBase::onEnter(){
    Sprite::onEnter();
}
