//================================================
//include
//================================================
#include "Dxlib.h"

//================================================
//�v���g�^�C�v�錾
//================================================
int Main(void);//���C�����[�v�p�֐�

	
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    //��ʃ��[�h�̃Z�b�g
    SetGraphMode(640, 480, 16);
    
    //�E�C���h�E���[�h�ɐ؂�ւ���
    ChangeWindowMode(TRUE);
     
    /*DX���C�u��������������*/
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    
    Main();
    
    /*DX���C�u�����I������*/        
    DxLib_End();

    return 0;
}




    