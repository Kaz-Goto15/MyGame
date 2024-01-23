#include "DebugText.h"
#include "Engine/Text.h"

//コンストラクタ
DebugText::DebugText(GameObject* parent)
    :GameObject(parent, "DebugText"),
    pos({40,100}),
    count(0)
{
}

//デストラクタ
DebugText::~DebugText()
{
}

//初期化
void DebugText::Initialize()
{
    txt = new Text();
    txt->Initialize("char_gakusanmarugo_half.png", 16, 32, 16);
}

//更新
void DebugText::Update()
{
}

//描画
void DebugText::Draw()
{
    for (int i = 0; i < count; i++) {
        txt->Draw(pos.x, pos.y + 35 * i, pStrList_[i]->c_str());
    }
}

//開放
void DebugText::Release()
{
}

void DebugText::AddStrPtr(string* pStr)
{
    count++;
    pStrList_.push_back(pStr);
}
