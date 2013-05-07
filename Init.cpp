//================================================
//include
//================================================
#include "Dxlib.h"

//================================================
//プロトタイプ宣言
//================================================
int Main(void);//メインループ用関数

	
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    //画面モードのセット
    SetGraphMode(640, 480, 16);
    
    //ウインドウモードに切り替える
    ChangeWindowMode(TRUE);
     
    /*DXライブラリ初期化処理*/
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    
    Main();
    
    /*DXライブラリ終了処理*/        
    DxLib_End();

    return 0;
}




    