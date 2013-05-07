#include "Dxlib.h"
	
#define MOVE_SPEED_EASY 3
#define MOVE_SPEED_NORMAL 5
#define MOVE_SPEED_HARD 7
	
#define TEMP_EASY  -10.0
#define TEMP_NORMAL 30.0
#define TEMP_HARD 50.0
	
#define LEFT_EDGE  200
#define RIGHT_EDGE 500 
	
#define BOTTOM  420
	
int PlayerGraph;
int BallGraph;
int BackGraph;

int PlayerSizeX;
int PlayerSizeY;

int BallSizeX;
int BallSizeY;
		
int PlayerX; //プレイヤーのX座標
int PlayerY; //プレイヤーのY座標
	
int BallX;  //ボールのX座標
int BallY;  //ボールのY座標
	
int BallVx; //ボールのX速度
int BallVy; //ボールのY速度

int playertop;
int playerbottom;
int playerleft;
int playerright;
	
int balltop;
int ballbottom;
int ballleft;
int ballright;
	
int Title(); //タイトル関数

int Score(); //スコア関数

int Time(); //時間関数

int Temp(); //温度関数

int HitCheck(); //当たり判定用関数

int Hour;
int Minute;
int Second;

int Index;

float Temperature;

int Main()
{
	int Color;
	
	int check_data[] =
	{
		10.0, 15.0, 20, 25, 30, 40,
	};
		
	PlayerGraph = LoadGraph("human.png");
	BallGraph = LoadGraph("0055.png");
	BackGraph = LoadGraph("");
	
	Color = GetColor(255, 255, 255);
	
	GetGraphSize(PlayerGraph, &PlayerSizeX, &PlayerSizeY);
	GetGraphSize(BallGraph, &BallSizeX, &BallSizeY);
	
	PlayerX = 0;
	PlayerY = 325;
	
	BallX = 0;
	BallY = 50;
	
	Second = 0;
    Minute = 0;
    Hour = 0;
    
    Index = 0;
    
	SetDrawScreen(DX_SCREEN_BACK);
	
	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{
		int Key;
		
		Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		
		playertop = PlayerY ;
    	playerbottom = PlayerY + PlayerSizeY;
	    playerleft = PlayerX ;
	    playerright = PlayerX + PlayerSizeX;
	    
	    balltop    = BallY ;
	    ballbottom = BallY + BallSizeY;
	    ballleft   = BallX ;
	    ballright  = BallX + BallSizeX;
	    
	    
				
		ClsDrawScreen();
		
		if(Key & PAD_INPUT_LEFT)
		{
			PlayerX -= 4;
		}
		
		if(Key & PAD_INPUT_RIGHT)
		{
			PlayerX += 4;
		}
		
		if(PlayerX < LEFT_EDGE)
		{
			PlayerX = LEFT_EDGE;
		}
		
		if(PlayerX > RIGHT_EDGE)
		{
			PlayerX = RIGHT_EDGE;
		}
		
		BallX += BallVx;
		BallY += BallVy;
		
		if(BallX < LEFT_EDGE)
		{
			BallX = LEFT_EDGE;
			BallVx = -BallVx;
		}
		
		if(BallX  > RIGHT_EDGE)
		{
			BallX = RIGHT_EDGE;
			BallVx = -BallVx;
		}
		
		if(BallY > BOTTOM)
		{
			BallY = BOTTOM;
			BallVy = -BallVy;
		}
		
		if(BallY < 0)
		{
			BallY = 0;
			BallVy = -BallVy;
		}
		
			
		Time();
		
		if(Minute==check_data[Index])
		{
			if(BallVx < 0)
			{
				BallVx -= 1;
			}
			
			if(BallVx > 0)
			{
				BallVx += 1; 
			}
			
			if(BallVy < 0)
			{
				BallVy -= 1;
			}
			
			if(BallVy > 0)
			{
				BallVy += 1;
			}
			
			Index++;
		}
		
		Temp();
		
	   if(playertop < ballbottom &&
	      playerbottom > balltop &&
	      playerleft < ballright &&
	      playerright > ballleft )
	   {
		return 0;
	  }
	
		
		//DrawFormatString(50, 50, Color, "Temp; %2f", Temperature);
		
		DrawGraph(PlayerX, PlayerY, PlayerGraph, TRUE);
		
		DrawGraph(BallX, BallY, BallGraph, TRUE);
		
		DrawGraph(0, 0, BackGraph, TRUE);
		
		DrawBox(playerleft, playertop, playerright, playerbottom, Color, TRUE); 

        DrawBox(ballleft, balltop, ballright, ballbottom, Color, TRUE); 
		
		ScreenFlip();
	}
}

int Time()
{
	
	int Color;
	
	Color = GetColor(255,255,255);
    
    Second++;
    
    if(Second == 60)
    {
    	Second = 0;
    	Minute += 1;
    }
    
    if(Minute == 60)
    {
    	Minute = 0;
    	Hour += 1;
    }
    
    DrawFormatString(0, 0, Color, "Time: %2d:%2d:%2d", Hour, Minute, Second);
    
}

int Score()
{
	 int Color;
	 
	 Color = GetColor(255, 255, 255);
	 
	 //DrawString(); 
}

int Temp()
{
	int i;
	int j;
	
	//int gauge;
	
	//gauge = LoadGraph("");
	
	Temperature += 1;
	
	if(Temperature < 0)
	{
		
	}
	
	if(Temperature > 0 && Temperature < 20)
	{
		
	}
	
	if(Temperature > 20 && Temperature < 50)
	{
		i++;
		
		if(i > 255)
		{
			i=255;
		}
		
		j++;
		if(i > 255)
		{
			j = 255;
		}
		
	}
	
	DrawBox(620, 0, 639, 119, GetColor(i, j, 0), TRUE);
}

int LevelEasy()
{
	BallVx = MOVE_SPEED_EASY;
	BallVy = MOVE_SPEED_EASY;
	Temperature = TEMP_EASY;
}

int LevelNormal()
{
	BallVx = MOVE_SPEED_NORMAL;
	BallVy = MOVE_SPEED_NORMAL;
	Temperature = TEMP_NORMAL;
}

int LevelHard()
{
	BallVx = MOVE_SPEED_HARD;
	BallVy = MOVE_SPEED_HARD;
	Temperature = TEMP_HARD;
}

int HitCheck()
{
	int Color;
	
	Color = GetColor(255,255,255);
	
	DrawBox(ballleft, balltop, ballright-1, playerbottom - 1, Color, TRUE);  

}
