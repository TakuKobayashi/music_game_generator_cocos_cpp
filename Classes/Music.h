//
//  Music.h
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#ifndef __MusicGameGenerator__Music__
#define __MusicGameGenerator__Music__

#include "cocos2d.h"

class Music{
public:
    Music(std::string fileName); //コンストラクタ
    virtual bool init(); //初期化処理
    static Music* create(std::string fileName);
protected:
    std::string mFilename;
};

#endif /* defined(__MusicGameGenerator__Music__) */
