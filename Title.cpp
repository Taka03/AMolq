#include "Dxlib.h"
#include "function.h"

int EnterSound;  //���艹
int CancelSound;//��������
int SelectSound; //�I����

int LevelSelectMusic;//���x���Z���N�g�pBGM
int TitleMusic;

int Title()
{
	#define WORD_SIZE 20
    #define CMOVE 40
	#define TITLE_TIP 350
    #define TITLE_END TITLE_TIP + CMOVE * 2
    
    int TitleGraph; //�^�C�g���O���t�B�b�N�n���h��
    int CursorGraph; //�J�[�\���O���t�B�b�N�n���h��
    
    int TutorialGraph[9];
       
    int Color;
    
    //�L�[�֌W-------
    int Key;
    int BeforeInput;
    int UpInput;
    int DownInput;
    //--------------
    
    int CursorX; 
    int CursorY;
    
	TitleMusic = LoadSoundMem("sound/Title.ogg");//�^�C�g��BGM
	LevelSelectMusic = LoadSoundMem("sound/levelselect.ogg");
	
	EnterSound = LoadSoundMem("sound/decide.wav");
    SelectSound = LoadSoundMem("sound/select.wav");
    CancelSound = LoadSoundMem("sound/cancel.wav");
    
    TitleGraph = LoadGraph("graphic/Title.png");
    CursorGraph = LoadGraph("graphic/handicon.png");
    
    LoadDivGraph("graphic/chip.png", 10, 2, 5, 32, 32, TutorialGraph); 
    
    Color = GetColor(0, 0, 0);
    
    SetFontSize(WORD_SIZE);
    
    //�J�[�\���ʒu�̏�����
    CursorX = 165;
    CursorY = TITLE_TIP;
    
    SetDrawScreen(DX_SCREEN_BACK);
    
    	    PlayEffectLoop(TitleMusic);

    
    

    while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE) ==0)
    {
	    ClsDrawScreen();
	    
	     
	    BeforeInput = Key;
	    
	    Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	    
	    UpInput = ~Key & BeforeInput;
	    DownInput = Key & ~BeforeInput;
	    
	    if(DownInput & PAD_INPUT_UP)
	    {
	       CursorY -= CMOVE;
	       
	       PlayEffect(SelectSound);
	    }
	 
	    if(DownInput & PAD_INPUT_DOWN)
	    {
	       CursorY += CMOVE;
	       PlayEffect(SelectSound);
	    }
	 
	    if(CursorY<=TITLE_TIP) 
	    {
	       CursorY = TITLE_TIP;
	       
	         if(DownInput & PAD_INPUT_A)
	         {
	             StopEffect(TitleMusic);
	             
	             PlayEffect(EnterSound);
	             
	             PlayEffectLoop(LevelSelectMusic);
	                          
	             LevelSelect();
	             
	             return 0;
	             
	         } 
    
	    }
	    
	    if(CursorY == TITLE_TIP + CMOVE)
	    {
	        if(DownInput & PAD_INPUT_A)
	        {
	        	PlayEffect(EnterSound);
	        	
	        	return Tutorial();
	        }
	    }
	    
	 
	    if(CursorY>=TITLE_END)
	    {
	        CursorY = TITLE_END;
	    
	          if(DownInput & PAD_INPUT_A)
	          {
	             StopEffect(TitleMusic);
	             
	             exit(0);
	          }
	    }
	    
         DrawGraph(0, 0, TitleGraph, TRUE);
         
         DrawGraph(CursorX, CursorY, CursorGraph, TRUE);
             
         //��ʂ̕\��
         ScreenFlip();
         
    }
}    

int LevelSelect()
{
	#define CMOVE 214
	#define LEVEL_TIP  3
	#define LEVEL_END  431
		
	#define MENU_X 2	
	#define MENU_Y 380
	
	int Color;
	
	int SelectGraph;
	
	int CursorGraph;
	
	int CursorX;
	int CursorY;
	
	Color = GetColor(0,0,0);
	
	CursorGraph = LoadGraph("graphic/LevelSelect_C.png");
	SelectGraph = LoadGraph("graphic/LevelSelect.png");
	
	CursorX = MENU_X;
	CursorY = 61;
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
    	int Key;
    	int BeforeInput;
    	int UpInput;
    	int DownInput;
    	
    	BeforeInput = Key;
    	
    	Key = GetJoypadInputState(DX_INPUT_KEY_PAD1); 
    	
    	UpInput = ~Key & BeforeInput;
    	DownInput = Key & ~BeforeInput;
    	
    	ClsDrawScreen();
    	
    	DrawGraph(0, 0, SelectGraph, TRUE);
    	
    	DrawGraph(CursorX, CursorY, CursorGraph, TRUE);	
    	
    	if(DownInput & PAD_INPUT_B)
    	{
    		PlayEffect(CancelSound);
    		StopEffect(LevelSelectMusic);
    		 Title();
    	}
    	
    	if(DownInput & PAD_INPUT_LEFT)
    	{
    		CursorX -= CMOVE;
    		PlayEffect(SelectSound);
    	}
    	
    	if(DownInput & PAD_INPUT_RIGHT)
    	{
    		CursorX += CMOVE;
    		PlayEffect(SelectSound);
    	} 
    	
    	if(CursorX == LEVEL_TIP)
    	{
    		if(DownInput & PAD_INPUT_A)
    		{	             
    			PlayEffect(EnterSound);
    			
    			StopEffect(LevelSelectMusic);
    			
    			LevelEasy();
    			
    			ActMain();
    			
    			return 0;
    		}
    	}
    	
    	if(CursorX == LEVEL_TIP + CMOVE)
    	{
	             
    		if(DownInput & PAD_INPUT_A)
    		{
    			PlayEffect(EnterSound);
    			
    			StopEffect(LevelSelectMusic);
    			
    			LevelNormal();
    			
    			ActMain();
    			
    			return 0;
    		}
    	}
    	
    	if(CursorX == LEVEL_TIP + CMOVE*2)
    	{
    		
    		if(DownInput & PAD_INPUT_A)
    		{
    		 	PlayEffect(EnterSound);

	    		StopEffect(LevelSelectMusic);

    			LevelHard();
    			
    			ActMain();
    			
    			return 0;
    		}
    	}
    	
    	if(CursorX < LEVEL_TIP)
    	{
    		CursorX = LEVEL_TIP;
    	}
    	
    	if(CursorX > LEVEL_END)
    	{
    		CursorX = LEVEL_END;
    	}

    	ScreenFlip();
    }
}

int Tutorial(void)
{
    int Color;
    int MovingGraph;//������@�O���t�B�b�N
    int PItemExplainGraph;//�v���X�A�C�e�������O���t�B�b�N
    int MItemExplainGraph;//�}�C�i�X�A�C�e�������O���t�B�b�N
    int GameGraph;//�Q�[����ʐ����O���t�B�b�N
    int WordBeforeGameGraph;//�Q�[����ʑO�����O���t�B�b�N
    int GameRuleGraph;//�Q�[���O���t�B�b�N�����O���t�B�b�N
    int ScoreExGraph; //�X�R�A�v�Z���@�����O���t�B�b�N
    
    int PageUpSound; //�y�[�W�i�݉�
    int PageDownSound; //�y�[�W�߂艹
    
     //�L�[�֌W-------
    int Key;
    int BeforeInput;
    int UpInput;
    int DownInput;
    //--------------
    
    int tutorialcounter;//�Q�[����ʂ̏o����
    
    Color = GetColor(255,255,255);
    
    MovingGraph = LoadGraph("graphic/moving.png");
    PItemExplainGraph = LoadGraph("graphic/ItemExplain(Plus).png");
    MItemExplainGraph = LoadGraph("graphic/ItemExplain(Minus).png");
    GameGraph = LoadGraph("graphic/GameScreen.png");
    WordBeforeGameGraph = LoadGraph("graphic/GameExplain(Word).png");
    GameRuleGraph = LoadGraph("graphic/GameRule.png");
    ScoreExGraph = LoadGraph("graphic/Score.png");
    
    PageUpSound = LoadSoundMem("sound/pageup.wav");
    PageDownSound = LoadSoundMem("sound/pagedown.wav");
    
    tutorialcounter = 0;
    
    SetDrawScreen(DX_SCREEN_BACK);
    
    while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0)
    {
       BeforeInput = Key;
    	
       Key = GetJoypadInputState(DX_INPUT_KEY_PAD1); 
    	
       UpInput = ~Key & BeforeInput;
       DownInput = Key & ~BeforeInput;
       
       ClsDrawScreen();

       if(DownInput & PAD_INPUT_A)
       {
        	tutorialcounter++; 
        	PlayEffect(PageUpSound);
        	WaitTimer(50);
       }
       
       if(DownInput & PAD_INPUT_B)
       {
           tutorialcounter--;
           PlayEffect(PageDownSound);
           WaitTimer(50);
       }
       
       if(tutorialcounter < 0)
       {
          PlayEffect(CancelSound);
          
          StopEffect(TitleMusic);

           Title();
       }
       
       if(tutorialcounter > 6)
       {
       		StopEffect(TitleMusic);

       		Title();
       }
       
       switch(tutorialcounter)
       {
       		case 0:
       		{
       		   DrawGraph(0, 0, MovingGraph, TRUE);
       		   break;
       		}
       		
       		case 1:
       		{
       		   DrawGraph(0, 0, WordBeforeGameGraph, TRUE);
       		    break;
       		}
       		
       		case 2:
       		{
       		   DrawGraph(0, 0,GameGraph, TRUE);
       		    break;
       		}
       		
       		case 3:
       		{
       			DrawGraph(0, 0,ScoreExGraph, TRUE);
       			break;
       		}
       		
       		case 4:
       		{
       		    DrawGraph(0, 0,PItemExplainGraph, TRUE);   
       		     break;
       		}
       		
       		case 5:
       		{
       		    DrawGraph(0, 0,MItemExplainGraph, TRUE);
       		     break;

       		}
       		
       		case 6:
       		{
       		    DrawGraph(0, 0,GameRuleGraph, TRUE);
       		    break;

       		}
       		
       }
       
       ScreenFlip();
       
    }
}

int WindowMode()
{
	#define CMOVE 90
	#define TIP 200
	#define END 200 + CMOVE
	
	int CursorX;
	int CursorY;
	
	int Graph;
	int CursorGraph;
	
	
	 //�L�[�֌W-------
    int Key;
    int BeforeInput;
    int UpInput;
    int DownInput;
    //--------------
	
	CursorX = 100;
	CursorY = TIP;
	
	
	Graph = LoadGraph("graphic/WindowMode.png");
	CursorGraph = LoadGraph("graphic/handicon.png");
	
	SetDrawScreen(DX_SCREEN_BACK);
	
	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{
	   BeforeInput = Key;
    	
       Key = GetJoypadInputState(DX_INPUT_KEY_PAD1); 
    	
       UpInput = ~Key & BeforeInput;
       DownInput = Key & ~BeforeInput;
       
		ClsDrawScreen();
				
		DrawGraph(0, 0, Graph, TRUE);
		
		DrawGraph(CursorX, CursorY, CursorGraph, TRUE);
		
		if(DownInput & PAD_INPUT_DOWN)
		{
			PlayEffect(SelectSound);
			CursorY += CMOVE;
		}
		
		if(DownInput & PAD_INPUT_UP)
		{
			PlayEffect(SelectSound);
			CursorY -= CMOVE;
		}
		
		if(CursorY < TIP)
		{
			CursorY = TIP;
		}
		
		if(CursorY > END)
		{
			CursorY = END;
		}
		
		if(CursorY==TIP && DownInput & PAD_INPUT_A)
		{
			PlayEffect(EnterSound);
					
			ChangeWindowMode(FALSE);

			return Title();
		}
		
		if(CursorY==END && DownInput & PAD_INPUT_A)
		{
			PlayEffect(EnterSound);
    
			ChangeWindowMode(TRUE);

			return Title();
		}
		
		ScreenFlip();		
	}	
}
