//
//  TextureBase.h
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/29.
//
//

#ifndef __MusicGameGenerator__TextureBase__
#define __MusicGameGenerator__TextureBase__

#include "cocos2d.h"

class TextureBase : public cocos2d::Sprite{
public:
    TextureBase(std::string fileName); //コンストラクタ
    virtual bool init(); //初期化処理
    void onEnter() override; // 表示前処理
    static TextureBase* create(std::string fileName);
protected:
    std::string mFilename;
};

#endif /* defined(__MusicGameGenerator__TextureBase__) */
