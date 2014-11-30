#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "network/HttpClient.h"

using namespace cocos2d::network;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    mBallLayer = cocos2d::Vector<BallTexture*>();
    mMusicMap = cocos2d::Map<int, Music*>();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    auto backgroundTexture = StaticTexture::create("graphpaper.png");
    backgroundTexture->setPosition(backgroundTexture->getContentSize()/2);
    this->addChild(backgroundTexture, 0);

    auto micTexture = StaticTexture::create("mic.png");
    Size size = micTexture->getContentSize();
    Vec2 point = Vec2(size.width / 2, visibleSize.height - size.height / 2);
    micTexture->setPosition(point);
    this->addChild(micTexture, 1);
    
    int musicId = stackMusic("smua_pro_finish_vocal.mp3");
    auto tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto guitarTexture = StaticTexture::create("guitar.png");
    point.y -= guitarTexture->getContentSize().height;
    guitarTexture->setPosition(point);
    this->addChild(guitarTexture, 1);
    
    musicId = stackMusic("smua_pro_finish_guitar.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto bassTexture = StaticTexture::create("bass.png");
    point.y -= bassTexture->getContentSize().height;
    bassTexture->setPosition(point);
    this->addChild(bassTexture, 1);
    
    musicId = stackMusic("smua_pro_finish_synth_bass.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto drumTexture = StaticTexture::create("drum.png");
    point.y -= guitarTexture->getContentSize().height;
    drumTexture->setPosition(point);
    this->addChild(drumTexture, 1);

    musicId = stackMusic("smua_pro_finish_drums.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);

    /*
    auto fileUtils = CCFileUtils::sharedFileUtils();
    std::string path = fileUtils->fullPathForFilename("adventurers.mp3");
    
    std::string param_key = "audiofile=@";
    param_key += path;
    CCLOG("%s", param_key.c_str());
    

    HttpRequest* request = new HttpRequest();
    request->setUrl("http://devapi.gracenote.com/v1/timeline/");
    request->setRequestData(param_key.c_str(), strlen(param_key.c_str()));
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback([this](HttpClient* client, HttpResponse* response) {
        if (!response) {
            return;
        }
        CCLOG("%s", CCFileUtils::sharedFileUtils()->getWritablePath().c_str());
        
        if (0 != std::strlen(response->getHttpRequest()->getTag())) {
            CCLOG("%s completed", response->getHttpRequest()->getTag());
        }
        
        long statusCode = response->getResponseCode();
        auto statusString = StringUtils::format("HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
        CCLOG("response code: %ld", statusCode);
        
        if (!response->isSucceed()) {
            CCLOG("response failed");
            CCLOG("error buffer: %s", response->getErrorBuffer());
            return;
        }
        
        // dropbox/json11 dump data
        std::string responseString(response->getResponseData()->begin(), response->getResponseData()->end());
        CCLOG("response = %s", responseString.c_str());
    });
    
    request->setTag("GET test1");
    HttpClient::getInstance()->send(request);
    request->release();
    */
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->setEnabled(true);
    listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    
}

void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    
}

void HelloWorld::update(float dt){

}

int HelloWorld::stackMusic(std::string fileName){
    auto music = Music::create(fileName);
    music->play();
    mMusicMap.insert(music->getMusicId(), music);
    return music->getMusicId();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
