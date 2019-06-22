/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
//初期化
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	//乱数の初期化 
	//C#で言うRandom rnd=new Random();と同じ
	srand(time(nullptr));


	for (int i = 0; i < 5; i++)
	{
		sprite3[i] = Sprite::create("sample09.png");
		this->addChild(sprite3[i]);
		sprite3[i]->setPosition(Vec2(150 * i, visibleSize.height / 2.0f));
		sprite3[i]->setTextureRect(Rect(0, 33, 32, 32));
		sprite3[i]->setScale(2.0f, 2.0f);

		float mx, my;

		mx = (float)rand()/RAND_MAX*600-300;
		my = (float)rand()/RAND_MAX*600-300;

		//アクション
		MoveBy* action1 = MoveBy::create(1.0f, Vec2(mx,my));
		sprite3[i]->runAction(action1);
	}


	//↓のと追加したスクリプトがぶつかっているためコメントアウト
	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//    problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//    // position the sprite on the center of the screen
	//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//    // add the sprite as a child to this layer
	//    this->addChild(sprite, 0);
	//}

	//テクスチャファイル名を指定して、スプライトを作成
	//Sprite* sprite = Sprite::create("image2.png");

	//sprite = Sprite::create("rion.png");

	//sprite2 = Sprite::create("sample09.png");
	//sprite2->setTextureRect(Rect(0, 33, 32, 32));
	//sprite2->setScale(2.0f,2.0f);

	////シーングラフにつなぐ
	//this->addChild(sprite);
	//this->addChild(sprite2);

	////アクション作成（1秒かけて）、右に200、上に100動く
	//MoveBy* action1 = MoveBy::create(1.0f, Vec2(400, 100));
	//MoveTo* action3 = MoveTo::create(1.0f, Vec2(300, 200));
	////ScaleBy*action1 = ScaleBy::create(1.0f,1.2f);
	////JumpTo*action1 = JumpTo::create(1.0f,Vec2(200,100),500.0f,3.0f);

	////曲線移動（ベジェ曲線）
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(500,500);
	//conf.controlPoint_2 = Vec2(500,100);
	//conf.endPosition = Vec2(200.0f,100.0f);
	//BezierTo*action1 = BezierTo::create(3.0f, conf);*/

	////EaseIn*action2 = EaseIn::create(action1,10.0f);
	////EaseBounceIn*action2 = EaseBounceIn::create(action1);
	////EaseBackInOut*action2 = EaseBackInOut::create(action1);
	////EaseSineIn*action2 = EaseSineIn::create(action1);

	////ノードに対してアクションを実行する
	//sprite->runAction(action1);
	////同じ名前のアクション名を使いたいときは->clone()をつけてあげる
	//sprite2->runAction(action1->clone());


	////画像の座標
	//sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//sprite2->setPosition(Vec2(visibleSize.width / 3.0f, visibleSize.height / 3.0f));


	////画像のサイズ
	//sprite->setScale(0.25f, 0.25f);

	//*sprite2->setScale(2.0f, 2.0f);
	//sprite2->getTexture()->setAliasTexParameters();*/
	////左右反転
	////sprite->setFlippedX(true);
	////上下反転
	////sprite->setFlippedY(true);
	////色合いの設定
	////sprite->setColor(Color3B(0xff, 0x00, 0x00));
	////非表示する
	////sprite->setVisible(false);
	////不透明度を設定
	////sprite->setOpacity(0x80);


	////完全不透明
	//sprite->setOpacity(255);

	////sprite2->setOpacity(255);

	////画像の左下が(0,0)
	////画像の右上が(1,0)の座標系
	////基準点を指定する
	//sprite->setAnchorPoint(Vec2(1.0f, 0.0f));


	//sprite->setRotation(45.0f);

	//                       R  G  B
	//sprite->setColor(Color3B(0, 0,255));

	//画像の一部を切り抜き
	//sprite->setTextureRect(Rect(0, 33, 32,32));
	//sprite2->setTextureRect(Rect(0, 33, 32, 32));



	/*counter = 0;

	state = 0;

	state2 = 0;

	_rotate = 0.0f;

	anim_counter = 0;

	_color = 0.0f;
*/


//updateを有効にする
//this->scheduleUpdate();
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//ここに更新処理を書く




	//Vec2 pos;


	////●回転
	///*_rotate += 1.0f;

	//sprite->setRotation(_rotate);*/


	////●色を徐々に変える
	///*_color++;
	//sprite -> setColor(Color3B(255 - (_color / 180.0f*255.0f), 0.0f, 0 +(_color / 180.0f*255.0f)));*/


	//anim_counter ++;

	//switch (anim_counter)
	//{
	//case 0:
	//	sprite2->setTextureRect(Rect(0, 33, 32, 32));
	//	break;
	//case 10:
	//	sprite2->setTextureRect(Rect(32, 33, 32, 32));
	//	break;
	//case 20:
	//	sprite2->setTextureRect(Rect(64, 33, 32, 32));
	//	break;
	//case 30:
	//	sprite2->setTextureRect(Rect(64, 33, 32, 32));
	//	anim_counter = 0;
	//	break;
	//default:
	//	break;
	//}

	//switch (state)
	//{

	//case 0:
	//	//左移動
	//	//スプライトの現在座標を取得
	//    pos = sprite2->getPosition();
	//	//座標を移動させる
	//	pos += Vec2(-5.0f, 0.0f);
	//	//移動後の座標を反映
	//	sprite2->setPosition(pos);

	//	
	//	if (pos.x<=150.0f)
	//	{
	//		state = 1;
	//	}
	//	break;
	//case 1:
	//	//右移動
	//	pos = sprite2->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite2->setPosition(pos);
	//	sprite2->setFlippedX(true);
	//	if (pos.x >= 1100.0f)
	//	{
	//		state = 0;
	//		sprite2->setFlippedX(false);
	//	}
	//	
	//	break;
	//
	//}


	//だんだん透明にする処理
	//5秒＝300frm
	/*counter++;
	float opacity =255-(counter / 300.0f*255.0f);
	if (opacity < 0)
	{
		opacity = 0.0f;
	}
	float opacity2 = 0 + (counter / 300.0f*255.0f);
	if (opacity2 >= 255) {
		opacity2 = 255;
	}
	sprite->setOpacity(opacity);
	sprite2->setOpacity(opacity2);
*/



/*float alfa = sprite->getOpacity();
alfa -=0.00003;
sprite->setOpacity(alfa);*/






}
