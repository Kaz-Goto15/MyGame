#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
//�{�^�����Ǘ�����N���X
class Button : public GameObject
{
private:
    enum STATE {
        IDLE,
        SELECT,
        PUSH,
        SELECTED,
        MAX
    };
    Text* buttonTextObj_;
    std::string buttonTextName_;
    int hImg_[MAX];
    Text::HORIZONAL_ALIGNMENT hAl;
    Text::VERTICAL_ALIGNMENT vAl;
    int actHandle_;
    XMINT4 clip = { 0,0,128,128 };
public:
    STATE state;

    Button(GameObject* parent);    //�R���X�g���N�^
    ~Button();                     //�f�X�g���N�^
    void Initialize() override; //������
    void Update() override;     //�X�V
    void Draw() override;       //�`��
    void Release() override;    //���

    //�摜�����N �{�^���摜��ς������ꍇ����p�����ăI�[�o�[���C�h����
    virtual std::string LinkImageFile(STATE state);

    //���g(�{�^��)�Ɛe�̑I���X�e�[�g��R�Â���
    void SetAction(int hAct);

    //�����I���Ɩ��ł��Ă��邪�A�����I��IDLE��Ԃɂ���֐�
    void EndAct() { state = IDLE; }

    //�e�L�X�g�ݒ�n
    void SetTextAlignment(Text::HORIZONAL_ALIGNMENT h, Text::VERTICAL_ALIGNMENT v);
    void SetFont(const char* fileName, const unsigned int charWidth, const unsigned int charHeight, const unsigned int rowLength);
    void SetText(std::string buttonName);

    //�{�^���A�j���[�V�����n
    virtual void DrawIdle() {}      //
    virtual void DrawSelect() {}
    virtual void DrawPush() {}
    virtual void DrawSelected() {}
private:
    //�eUpdate�֐�
    void UpdateIdle();
    void UpdateSelect();
    void UpdatePush();
    void UpdateSelected();

    //�{�^���̕`��͈͓��Ƀ}�E�X�J�[�\�������邩
    bool IsEntered();
    //�l���͈͓���
    bool Between(float value, float min, float max);
    //�}�E�X��1px�ł���������
    bool IsMovedMouse();
public:
    std::string GetDebugStr(int i);
};