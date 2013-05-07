
//include------------
#include "function.h"
#include "Dxlib.h"
#include <math.h>
#include <stdio.h>
//-------------------

int GameScene;

int Rank;

int StartTime;

int OldScore; 

int ScoreAddTime;//�X�R�A���Z����

int messagecounter;

int RankGraph[5];
int RankFontGraph;

#define PI 3.1415926535897932384626433832795

//�錾---------------------------------------------------------

//�v���C���[�p----------------------------------------------
#define PLAYER_SPEED 4 //�v���C���[�̈ړ����x
#define PUSH_GRAVITY 0.25 //�d��
#define FALL_RATE 4.0 //�������x�̌v�Z�l
#define JUMP_POWER 10.0 //�W�����v��

#define LIFE 4 //�v���C���[�̗̑�

//�v���C���[�̌���
#define RIGHT 0
#define LEFT  1
#define UP    2

//�O���t�B�b�N�n���h��
	
int PlayerGraph[4];//�v���C���[�O���t�B�b�N�n���h��(�������) 
int PlayerCGraph[3];//�v���C���[�O���t�B�b�N�n���h��(���Ⴊ�ݏ��)
int PlayerAtSideGraph[2];//�v���C���[�U���O���t�B�b�N�n���h��(��)
int PlayerJumpGraph;//�v���C���[�W�����v�O���t�B�b�N�n���h��
int PlayerGuardGraph;//�v���C���[�K�[�h�O���t�B�b�N(�������)
int PlayerCGuardGraph;//�v���C���[�K�[�h�O���t�B�b�N(���Ⴊ�ݏ��)
int BlendGraph;//�u�����h�O���t�B�b�N�n���h��

int PlayerX; //�v���C���[��X���W
int PlayerY; //�v���C���[��Y���W

int OldPlayerX;

int PlayerVx;//�v���C���[��X���x
int PlayerVy;//�v���C���[��Y���x

float Acc; //�W�����v�p�����x

float Gravity; //�d�͒l

int direction;//�v���C���[�̌���(�Eor��)

int PlayerLife; //�v���C���[�̗̑�

int PlayerInvicibleFlag; //�v���C���[�̖��G�t���O

int PlayerInvincibleTime;//�v���C���[�̖��G����

int PlayerJumpFlag; //�v���C���[�̃W�����v�t���O

int PlayerCoughtFlag; //�v���C���[���Ⴊ�݃t���O

int GuardGauge; //�h��p�Q�[�W

int GuardFlag; //�K�[�h�t���O

//�A�j���J�E���^�[--------------
unsigned int anim_counter;

unsigned int anim;

unsigned int playeranimpat;

unsigned int anim_counter_c;

unsigned int playeranimpat_c;

unsigned int anim_c;

unsigned int anim_at;

unsigned int anim_counter_at;

unsigned int playeranimpat_at;

unsigned int anim_a;

unsigned int anim_c_a;

//------------------------------
	
int PlayerSizeX; //�v���C���[�T�C�YX(�������)�𓾂邽�߂̕ϐ�
int PlayerSizeY; //�v���C���[�T�C�YY(�������)�𓾂邽�߂̕ϐ�

int PlayerCSizeX; //�v���C���[�T�C�YX(���Ⴊ�ݏ��)�𓾂邽�߂̕ϐ�
int PlayerCSizeY; //�v���C���[�T�C�YX(���Ⴊ�ݏ��)�𓾂邽�߂̕ϐ�

int Ground; //�n�ʂ̍��W(�v���C���[�p)

int drawtime; //�摜�`�掞��

//�����蔻��̈�-------
//�v���C���[���g
int playertop;
int playerbottom;
int playerleft;
int playerright;

//�h��p(��)
int GuardLefttop;
int GuardLeftbottom;
int GuardLeftleft;
int GuardLeftright;

//�h��p(�E)
int GuardRighttop;
int GuardRightbottom;
int GuardRightleft;
int GuardRightright;

//�U���p(��)
int AttackUptop;
int AttackUpbottom;
int AttackUpleft;
int AttackUpright;

//�U���p(��)
int AttackLefttop;
int AttackLeftbottom;
int AttackLeftleft;
int AttackLeftright;

//�U���p(�E)
int AttackRighttop;
int AttackRightbottom;
int AttackRightleft;
int AttackRightright;
//---------------------

//----------------------------------------------------------

//�o���A�p--------------------------------------------------
int BarrierGraph[3];

//�A�j���[�V�����J�E���^----------
unsigned int barrier_animpat;

unsigned int barrier_anim;

unsigned int barrier_animcounter;
//--------------------------------

//�����蔻��̈�------------------
int BarrierSizeX;
int BarrierSizeY;

int barriertop;
int barrierbottom;
int barrierleft;
int barrierright;

int BarrierInvincibleFlag;//�o���A���G�t���O
int BarrierInvincibleTime;//�o���A���G����
//--------------------------------

//�K�[�h�p
int ShieldGraph[4];
int ShieldCGraph[4];

//�A�j���[�V�����p�^�[��
int shield_animpat;
int shield_anim;
int shield_animcounter;
//----------------------------------------------------------

//�{�[���p--------------------------------------------------
#define MOVE_SPEED_EASY 3 //Easy�̃{�[���̈ړ����x
#define MOVE_SPEED_NORMAL 5 //Normal�̃{�[���̈ړ����x
#define MOVE_SPEED_HARD 7 //Hard�̃{�[���̈ړ����x

#define BALL_MAX 3 //�{�[���̍ő�l+1

int BallGraph;//�{�[���O���t�B�b�N�n���h��

int BallX[BALL_MAX];  //�{�[����X���W
int BallY[BALL_MAX];  //�{�[����Y���W

int BallVx[BALL_MAX]; //�{�[����X���x
int BallVy[BALL_MAX]; //�{�[����Y���x

int fBallVx[BALL_MAX]; //�{�[���̏������x
int fBallVy[BALL_MAX]; //�{�[���̏������x

int OldBallVx[BALL_MAX]; //�{�[���̌Â�X���x
int OldBallVy[BALL_MAX]; //�{�[���̌Â�Y���x	

int BallSizeX;//�{�[���T�C�YX�𓾂邽�߂̕ϐ�
int BallSizeY;//�{�[���T�C�YY�𓾂邽�߂̕ϐ�

int BallGround;//�n�ʂ̍��W(�{�[���p)

//�����蔻��̈�
int balltop[BALL_MAX];
int ballbottom[BALL_MAX];
int ballleft[BALL_MAX];
int ballright[BALL_MAX];

int distance[10]; //�{�[�����m�̋���
int check_distance;//�{�[�����m�̓����蔻��p

int BallInvincibleFlag;//�{�[���p���G

int BallInvincibleTime;//�{�[�����G����
//----------------------------------------------------------------

//�ז��L�����p----------------------------------------------------
int DistGraph;//�ז��L�����O���t�B�b�N�n���h��

int DistX; //X���W
int DistY; //Y���W

int DistSizeX;//�T�C�YX�𓾂邽�߂̕ϐ�
int DistSizeY;//�T�C�YY�𓾂邽�߂̕ϐ�

//�����蔻��̈�
int disttop;
int distbottom;
int distleft;
int distright;

int DistFlag; //�ז��L�������o�����Ă��邩(�t���O)
//----------------------------------------------------------------

//�A�C�e���p------------------------------------------------------
#define ITEM_MAX 9 //�A�C�e���̍ő�l +1
	 
//�v���X�A�C�e��ID
#define DOWN_TEMP 0 //���x����
#define RESET_GAUGE 1 //LIMIT�Q�[�W���Z�b�g
#define STOP_BALL 2//�{�[���̓����̐Î~
#define RESET_GROUND 3//�n�ʂ̐���オ��̏�����
#define ADD_SCORE 4 //�X�R�A���Z
#define INVINCIBLE 5 //�v���C���[���G

//�}�C�i�X�A�C�e��ID
#define UP_GROUND 6 //�n�ʂ𐷂�グ��
#define UP_TEMP 7 //���x�㏸
#define DOWN_SCORE 8 //�X�R�A���Z

#define ITEM_SPEED 0.9 //�A�C�e���_�E�����x

int ItemGraph[ITEM_MAX]; //�A�C�e���O���t�B�b�N�n���h��

int ItemX[ITEM_MAX]; //�A�C�e����X���W
float ItemY[ITEM_MAX]; //�A�C�e����Y���W

int ItemSizeX;//�A�C�e���T�C�YX�𓾂邽�߂̕ϐ�
int ItemSizeY;//�A�C�e���T�C�YY�𓾂邽�߂̕ϐ�

int ItemID; //�A�C�e��ID
int ItemFlag;//�A�C�e���t���O(�A�C�e�����o�����Ă��邩)

int ItemGetFlag; //�A�C�e���擾�t���O(�A�C�e�����Ƃ�����)

//�����蔻��̈�
int itemtop[ITEM_MAX];
int itembottom[ITEM_MAX];
int itemleft[ITEM_MAX];
int itemright[ITEM_MAX];

float Item_down;//�A�C�e���̃_�E���X�s�[�h

int itemgetcounter;

//�A�j���J�E���^�[----
int up_animcounter;
int up_anim;
int up_animpat;

int down_animcounter;
int down_anim;
int down_animpat;
//------------------- 
int EffWordGraph[4];//�A�C�e�����ʕ\�����[�h�O���t�B�b�N

int wordtime;//���ʃ��[�h�\������

int WordFlag;//���[�h�\���t���O
//------------------------------------------------------------------

//���x�p------------------------------------------------------------
#define TEMP_EASY  100.0 //Easy�̏������x
#define TEMP_NORMAL 120.0//Normal�̏������x
#define TEMP_HARD 140.0 //Hard�̏������x

#define TEMP1_UP_SPEED 1 //���x(�����l)�̏㏸���x
#define TEMP2_UP_SPEED 1 //���x(�����l)�̏㏸���x

#define TEMP_BAR_BOTTOM 120 

int Temp1_Up;//���x(����)�̏㏸�l
int Temp2_Up;//���x(����)�̏㏸�l

int Temperature1;//�����l�̉��x
int Temperature2;//�����l�̉��x
int Temp_gauge;//���x�Q�[�W

int OldTemp1; //�����l�̉��x�̕ۑ��p
int OldTemp2; //�����l�̉��x�̕ۑ��p

int TempGraph;//���x�̃O���t�B�b�N�n���h��
//-------------------------------------------------------------------

//���ԗp-------------------------------------------------------------
#define SECOND_UP_SPEED 1 //���Ԃ̌o�ߑ��x?

int Hour;
int Minute;
int Second;

int Second_Add;//���Ԃ̌o�ߒl
//-------------------------------------------------------------------

//�X�R�A�p-----------------------------------------------------------
int Score; //�X�R�A
int DScore;
int AddScore;//���Z�X�R�A
int BonusScore; //�{�[�i�X�X�R�A
int ScoreAddFlag;
//-------------------------------------------------------------------

//Checkdata�p--------------------------------------------------------

//�n�ʂ̏オ���Ă��鎞��	
int check_limit_data[] =
{
	10, 10, 20, 20, 20, 20, 20, 20, 20, 30, 30, -1,
};

//�A�C�e���o���̎���	
int check_item_data[] =
{
	10, 20, 30, 40, 50, 0, -1,
};

//�{�[�i�X�X�R�A	
int check_bonus_data[] =
{
	500, 1000, 2000, 3000, 5000, 7000
};
	
//�{�[���X�s�[�h�A�b�v
int check_data_temp[] =
{
	40, 60, 80, 100, 110, 120, 140, 160, 180, 200, -1,
};
	
//�A�C�e�����~���Ă���ʒu
int check_item_x_data[] =
{
	100, 300, 200, 400, 200, -1,
};

int check_item_turn[] =
{
	4, 5, 6, 1, 3, 2, 7,  -1,
};

int check_rank[] =
{
   	600, 1100, 1700, 2200, 
};
	
//--------------------------------------------------------------------

//���̑����ʎ���------------------------------------------------------
#define SCREEN_WIDTH  640 //��ʂ̕�
#define SCREEN_HEIGHT 480 //��ʂ̍���

//#define STOP_TIME 100

#define GROUND_UP_SPEED 10 //�n�ʂ̐���オ�葬�x

//#define WALL_SPEED 10
	
#define INIT_GROUND 410 //�����n�ʍ��W
	
#define RIGHT_EDGE 450 //�E�[�̍��W

#define RIGHT_EDGE_BALL 420//�{�[���̉E�[�̍��W

#define RIGHT_EDGE_PLAYER 410 //�v���C���[�̉E�[�̍��W

#define MENU_STRING_LEFT 450 //�����̕\���ʒu
#define MENU_STRING_TOP 10

int GroundGraph;//�w�i�O���t�B�b�N�n���h��
int PauseGraph;
int BackGraph;
int Graph; //�ǔ���p�O���t�B�b�N�n���h��
int FrameGraph;

int GameOverGraph;//�Q�[���I�[�o�[��ʃO���t�B�b�N�n���h��

int TitleCallFlag;//�^�C�g���Ăяo���t���O

//[]�ɓ������---------------------
int item_counter;//�A�C�e���p

int Index;//�{�[���X�s�[�h�A�b�v�p

int limit;//�ǔ���p

int bonus; //�{�[�i�X�X�R�A�p

int item_position; //�A�C�e���ʒu

int item_data;//�A�C�e���o������

int dist_counter; //�ז��L�����o���J�E���^�[

int rank_counter; 
//---------------------------------

int Ground_Up;//�n�ʂ̏㏸�l

int Key;

int BeforeInput;

int DownInput;
int UpInput;

int stop_time;//�|�[�Y�^�C��

int pauseFlag;//�|�[�Y�t���O(�{�[�����̓������~�܂��Ă��邩)

int Left_Edge;//���[�̍��W

int limit_time; //�Q�[�W�̏㏸����?

int Red;
int Blue;
int Green;

int OldRed;
int OldGreen;
int OldBlue;
//--------------------------------------------------------------------
//--------------------------------------------------------------------

//���֌W--------------------------------------------------------------
int JumpSound; //�W�����v��
int GameMusic;
int GameOverMusic;//�Q�[���I�[�o�[BGM
int BallBoundSound; //�{�[�����ˉ�
int DamageSound; //�_���[�W��
int LifeUpSound; //���C�tup�� 
int WarnSound;//�x����(�v���C���[���C�t�����Ȃ��Ƃ�)
int MoveSound;//���s��
int GameOverSound;//GAME OVER��
int PauseSound; //�|�[�Y���̉�
int PItemGetSound;//�v���X�A�C�e���擾��
int MItemGetSound;//�}�C�i�X�A�C�e���擾��
int GuardSound;//�K�[�h��
int BarrierSound;//�o���A���ˉ�
int ScoreSound;
int RankSound;//�����N�\����
int FallSound;//������
//--------------------------------------------------------------------


//�֐�
//�v���C���[�p--------------------------------------------------------

//�v���C���[�̕`��
int DrawPlayer()
{
	if(!PlayerCoughtFlag)
	{
		if(!PlayerJumpFlag)
		{
				
				if(Key & PAD_INPUT_RIGHT)
				{
				    anim_counter++;
				    anim = anim_counter /4 % playeranimpat;
				    
					DrawGraph(PlayerX, PlayerY, PlayerGraph[anim], TRUE);
				   	 
			    }
			    
			    else if(Key & PAD_INPUT_LEFT)
			    {
			    	anim_counter++;
				    anim = anim_counter /4 % playeranimpat;
				    
	    			DrawTurnGraph(PlayerX, PlayerY, PlayerGraph[anim], TRUE);
			    }
			    
	
			    else if(direction == LEFT)
			    {
				   
				    DrawTurnGraph(PlayerX, PlayerY, PlayerGraph[2], TRUE);
			    }
			    
			    else if(direction == RIGHT)
			    {
					 DrawGraph(PlayerX, PlayerY, PlayerGraph[2], TRUE);
			    }
    	    
		}
		
		if(PlayerJumpFlag)
		{
	    
		    if(direction == LEFT)
		    {
				DrawTurnGraph(PlayerX,PlayerY, PlayerJumpGraph, TRUE);
		    }
		    
		    else if(direction == RIGHT)
		    {
				DrawGraph(PlayerX,PlayerY, PlayerJumpGraph, TRUE);
		    }
				
		}		
			    
	}
	
	if(PlayerCoughtFlag)
	{
		 if(!PlayerJumpFlag)
		 {
				anim_counter_c++;
				anim_c = anim_counter_c / 5 % 1;
				
				
				if(direction==RIGHT)
				{

					DrawGraph(PlayerX, PlayerY + PlayerCSizeY-7, PlayerCGraph[anim_c], TRUE);
				}
				
				else if(direction==LEFT)
				{
					DrawTurnGraph(PlayerX, PlayerY + PlayerCSizeY-7, PlayerCGraph[anim_c], TRUE);
				}
		}
			
	}
	
}

//�v���C���[�̓���
int MovePlayer()
{
		
		if(DownInput & PAD_INPUT_LEFT)
		{
		    direction = LEFT;
		}
		
		if(Key & PAD_INPUT_LEFT && !PlayerCoughtFlag)
		{
			PlayEffect(MoveSound);
			PlayerX += PlayerVx;
		    PlayerVx = -PLAYER_SPEED;
		}
		
		if(Key & PAD_INPUT_RIGHT && !PlayerCoughtFlag)
		{
			PlayEffect(MoveSound);
			PlayerX += PlayerVx;
			PlayerVx = PLAYER_SPEED;
			
		}
		
		if(DownInput & PAD_INPUT_RIGHT)
		{
			direction = RIGHT;
		}
	
		if(UpInput & PAD_INPUT_DOWN)
		{
			PlayerCoughtFlag = FALSE;
		}
		
		if(Key & PAD_INPUT_DOWN && !PlayerJumpFlag)
		{
			PlayerCoughtFlag = TRUE;
		}
}

//�W�����v����
int Jump()
{
	
	if(!PlayerJumpFlag)
	{
		if(DownInput & PAD_INPUT_A && !PlayerCoughtFlag)
		{
			Acc = -JUMP_POWER;
			PlayerJumpFlag = TRUE; 
			Gravity = PUSH_GRAVITY;
			
			PlayEffect(JumpSound);
		}
	}
	
	if(PlayerJumpFlag)
	{
		if(UpInput & PAD_INPUT_A)
		{
			PlayEffect(FallSound);
			
			if(Acc < 0)
			{
				Gravity = -Acc / FALL_RATE;
			}
		}
		
		Acc += Gravity;
		PlayerY += Acc;
		
		if(DownInput & PAD_INPUT_DOWN)
		{                        
			if(Acc > 0)
			{
				PlayerY += Acc;
			}
			
			if(Acc < 0)
			{
				PlayerY -= Acc;
			}
		}
	}
}

//�v���C���[�̈ړ��͈�
int PlayerMoveRange()
{
	    if(PlayerX < Left_Edge)
		{
			PlayerX = Left_Edge;
		}
		
		if(PlayerX > RIGHT_EDGE_PLAYER)
		{
			PlayerX = RIGHT_EDGE_PLAYER;
		}
		
		if(PlayerY > Ground)
		{
			PlayerY = Ground;
			PlayerJumpFlag = FALSE;
		}
		
}

//�v���C���[���C�t�̕`��
int DrawPlayerlife()
{
	int Color;
	int k;
	
	Color = GetColor(255,255,255);
	
	
	for(k = 0;k < PlayerLife;k++)
	{
		
		DrawFormatString(PlayerX + 30, PlayerY + 20, Color, "x %d", PlayerLife);
	}
	 
}

//�v���C���[�̓����蔻��`�F�b�N
int PlayerHitCheck()
{
	int i;

	for(i=0;i < BALL_MAX;i++)
    {
	    
	    if(playertop < ballbottom[i] &&
	       playerbottom > balltop[i] &&
	       playerleft < ballright[i] &&
	       playerright > ballleft[i] )
       	{
   	   	   	   	PlayEffect(DamageSound);
   	   	   	   	
   	   	   	   	PlayerLife--;
   	   	   	   	
   	   	   	   	PlayerInvicibleFlag = TRUE;
   	   	   	   	
   	   	   	   	BallX[i] += PlayerX;
   	   	   	   	BallY[i] += PlayerY;
	   	} 
	}
}

//�v���C���[�h�䔻��
int PlayerGuardCheck()
{
	int i;
	
	for(i=0;i < BALL_MAX;i++)
    {	
	   	
	   	if(GuardFlag)
	   	{
		   	if(direction == LEFT && Key & PAD_INPUT_B)
		   	{
		   		if(GuardLefttop < ballbottom[i] &&
			       GuardLeftbottom > balltop[i] &&
			       GuardLeftleft < ballright[i] &&
			       GuardLeftright > ballleft[i] )
		       	{
		       		PlayEffect(GuardSound);
		       		
		       		BallVy[i] = -BallVy[i];
		       		BallVx[i] = -BallVx[i];
		       		
		       		PlayerX += 20;
		       		
		       		GuardGauge = 0;
		       		
		       		GuardFlag = FALSE;
		       	    
		       	}
		   	}
		   	
		   	if(direction == RIGHT && Key & PAD_INPUT_B)
		   	{
		   		if(GuardRighttop < ballbottom[i] &&
			       GuardRightbottom > balltop[i] &&
			       GuardRightleft < ballright[i] &&
			       GuardRightright > ballleft[i] )
		       	{
		       		PlayEffect(GuardSound);

		       		
		       		BallVy[i] = -BallVy[i];
		       		BallVx[i] = -BallVx[i];
		       		
		       		PlayerX -= 20;
		       		
		       		GuardGauge = 0;
		       		
		       		GuardFlag = FALSE;
		       		
		       	}
		   	}
         }
    }
	   	 
}

//�h��Q�[�W�̕`��
int DrawGuardGauge()
{
 	int Color;
 	
 	Color = GetColor(255,255,255);
 	
 	DrawBox(PlayerX, PlayerY - 20, PlayerX + GuardGauge,PlayerY-10, Color, TRUE);
 	
}

//--------------------------------------------------------------------

//�o���A�p------------------------------------------------------------
int DrawBarrier()
{
		barrier_animcounter++;
		barrier_anim = barrier_animcounter /3 % barrier_animpat;
		
		DrawGraph(PlayerX-18, PlayerY-15, BarrierGraph[barrier_anim], TRUE);
}

int BarrierHitCheck()
{
 	int i;
 	
 	for(i=0;i < BALL_MAX;i++)
 	{
	 	if(barriertop < ballbottom[i] &&
	       barrierbottom > balltop[i] &&
	       barrierleft < ballright[i] &&
	       barrierright > ballleft[i] )
       	{
       	   PlayEffect(BarrierSound);
       	   
       	   BallVx[i] *= -1;
	 	   BallVy[i] *= -1;
	 	   
	 	   BallX[i] += BallVx[i]*2;
    	   BallY[i] += BallVy[i]*2;
    	   
    	   BarrierInvincibleFlag = TRUE;
    	
       	}
	 	
	}
}


//--------------------------------------------------------------------

//�{�[���p------------------------------------------------------------

//�{�[���̕`��
int DrawBall()
{
	int i;
		
	for(i=0;i < BALL_MAX;i++)
	{
		DrawGraph(BallX[i], BallY[i], BallGraph, TRUE);
	}
}

//�{�[���̓���
int MoveBall()
{
	int i;
	
	for(i=0;i < BALL_MAX;i++)
	{
		BallX[i] += BallVx[i];
		BallY[i] += BallVy[i];
		
	}
	
}

//�{�[���̈ړ��͈�
int BallMoveRange()
{
	int i;
	
	for(i=0;i < BALL_MAX;i++)
	{
		if(BallX[i] < Left_Edge)
		{
			BallX[i] = Left_Edge;
			BallVx[i] = -BallVx[i];
			PlayEffect(BallBoundSound);
		}
		
		if(BallX[i]  > RIGHT_EDGE_BALL)
		{
			BallX[i] = RIGHT_EDGE_BALL;
			BallVx[i] = -BallVx[i];
		    PlayEffect(BallBoundSound);
		}
		
		if(BallY[i] > BallGround)
		{
			BallY[i] = BallGround;
			BallVy[i] = -BallVy[i];
			PlayEffect(BallBoundSound);
		}
		
		if(BallY[i] < 0)
		{
			BallY[i] = 0;
			BallVy[i] = -BallVy[i];
			PlayEffect(BallBoundSound);
		}
		
	}
}

//�{�[���̃X�s�[�h�A�b�v
int BallSpeedUp()
{
	int i;
	int j;
	
	for(i=0;i < BALL_MAX;i++)
    {
           	   fBallVx[i] += 1;
           	   fBallVy[i] += 1;           	           
               
               if(fBallVx[i]  > 10)
               {
               	  fBallVx[i] = 0;
               	  
               	  if(BallVx[i] < 0)
	           	  {
	           	   	 BallVx[i] -= 1;
	           	  }
	           	   
	           	  if(BallVx[i] > 0)
	           	  {
	           	   	 BallVx[i] += 1;
	           	  } 
	           }
	           
	           if(fBallVy[i] > 10)
	           {
	           	   fBallVy[i] = 0;
	           	   
	           	   if(BallVy[i] < 0)
	           	   {
	           	   	   BallVy[i] -= 1;
	           	   }
	           	   
	           	   if(BallVy[i] > 0)
	           	   {
	           	   	   BallVy[i] += 1;
	           	   }
	           }
        
	}
	
}


//�{�[���̓����蔻��`�F�b�N
int BallHitCheck()
{
        
    if(distance[0] <= check_distance)//BallSizeX + BallSizeY)
    {
    	BallVx[0] *= -1;
    	BallVx[1] *= -1;
    	
    	BallVy[1] *= -1;
    	BallVy[0] *= -1;
    	
    	BallX[0] += BallVx[0]*2;
    	BallX[1] += BallVx[1]*2;
    	BallY[0] += BallVy[0]*2;
    	BallY[1] += BallVy[1]*2;
    	
    	BallInvincibleFlag = TRUE;
    	
    }
    
    if(distance[1] <= check_distance)
    {
    	BallVx[1] *= -1;
    	BallVx[2] *= -1;
    	
    	BallVy[2] *= -1;
    	BallVy[1] *= -1;
    	
    	BallX[1] += BallVx[0]*2;
    	BallX[2] += BallVx[2]*2;
    	BallY[1] += BallVy[0]*2;
    	BallY[2] += BallVy[2]*2;
    	
    	BallInvincibleFlag = TRUE;
        
    }
    
    if(distance[2] <= check_distance)
    {
        BallVx[0] *= -1;
    	BallVx[2] *= -1;
    	
    	BallVy[2] *= -1;
    	BallVy[0] *= -1;
    	
    	BallX[0] += BallVx[0]*2;
    	BallX[2] += BallVx[2]*2;
    	BallY[0] += BallVy[0]*2;
    	BallY[2] += BallVy[2]*2;
    	
    	BallInvincibleFlag = TRUE;
        
    }
    
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------

//�A�C�e���p----------------------------------------------------------

//�A�C�e���̕`��
int DrawItem()
{
	   
	      
	   switch(ItemID)
	   {
				case DOWN_TEMP:
				{
					DrawGraph(ItemX[0], ItemY[0], ItemGraph[0], TRUE);
					break;
				}
				
				case RESET_GAUGE:
				{
					DrawGraph(ItemX[1], ItemY[1], ItemGraph[1], TRUE);
				    break;
				}
				
				case STOP_BALL:
				{
					DrawGraph(ItemX[2], ItemY[2], ItemGraph[2], TRUE);
				    break;
				}
				
				case RESET_GROUND:
				{
					DrawGraph(ItemX[3], ItemY[3], ItemGraph[3], TRUE);
				    break;
				}
				
				case ADD_SCORE:
				{
					DrawGraph(ItemX[4], ItemY[4], ItemGraph[4], TRUE);
				    break;
				}
				
				case INVINCIBLE:
				{
					DrawGraph(ItemX[5], ItemY[5], ItemGraph[5], TRUE);
					break;
				}
				
				case UP_GROUND:
				{
					DrawGraph(ItemX[6], ItemY[6], ItemGraph[6], TRUE);
					break;
				}
				
				case UP_TEMP:
				{
					DrawGraph(ItemX[7], ItemY[7], ItemGraph[7], TRUE);
					break;
				}
				
				case DOWN_SCORE:
                {            	
                	DrawGraph(ItemX[8], ItemY[8], ItemGraph[8], TRUE);
                	break;
                }

	    }  
	    
}

//�A�C�e���̓���
int MoveItem()
{
	int j;
	
	for(j = 0;j < ITEM_MAX;j++)
	{
		ItemY[j] += Item_down;
	}
	
}

//�A�C�e���̓���͈�
int ItemMoveRange()
{
	int j;
	
	for(j = 0;j < ITEM_MAX;j++)
	{
		if(ItemX[j] < Left_Edge)
	    {
	     	 ItemX[j] = Left_Edge;
	    }
			    
		if(ItemY[j] > SCREEN_HEIGHT)
		{
		 	ItemFlag = FALSE;
		}
		
	}  
}

//�A�C�e���̌���	
int EffItem()
{
	#define B_SPEED 2
	
	//int up;
	//int down;                           
	
	switch(ItemID)
	{
			case DOWN_TEMP:
			{
				Temp1_Up = 10;
				Temperature1 -= Temp1_Up;
				
			    for(int down=0;down < BALL_MAX;down++)
				{
				   
				   if(BallVx[down] > 0)
				   {
				   	   BallVx[down] -= B_SPEED;
				   }
				   
				   if(BallVx[down] < 0)
				   {
				   	   BallVx[down] += B_SPEED;
				   }
				   
				   if(BallVy[down] > 0)
				   {
				   	   BallVy[down] -= B_SPEED;
				   }
				   
				   if(BallVy[down] < 0)
				   {
				   	   BallVy[down] += B_SPEED; 
				   }
				   
				   if(BallVx[down] == B_SPEED)
				   {
				   		BallVx[down] = 1;
				   		
				   }
				   
				   if(BallVx[down] == -B_SPEED)
				   {
				   		BallVx[down] = -1;
				   }
				   
				   if(BallVy[down] ==  B_SPEED)
				   {
				   		BallVy[down] = 1;
				   }
				   
				   if(BallVy[down] == -B_SPEED)
				   {
				   		BallVy[down] = -1;
				   }
				   
				   if(BallVx[down] == 1)
				   {
				   		BallVx[down] = 1;
				   		
				   }
				   
				   if(BallVx[down] == -1)
				   {
				   		BallVx[down] = -1;
				   }
				   
				   if(BallVy[down] ==  1)
				   {
				   		BallVy[down] = 1;
				   }
				   
				   if(BallVy[down] == -1)
				   {
				   		BallVy[down] = -1;
				   }
				   
				   
				} 
				PlayEffect(PItemGetSound);
				break;
			}
			
			case RESET_GAUGE:
			{
				limit_time = 0;
				
				PlayEffect(PItemGetSound);
			    break;
			}
			
			case STOP_BALL:
			{
				OldTemp1 = Temperature1;
				OldTemp2 = Temperature2;
				OldRed = Red;
				OldGreen = Green;
				OldBlue = Blue;
				PlayEffect(PItemGetSound);
				
				PlayEffect(PauseSound);
				
				pauseFlag = TRUE;
			
				break;
			}
			
			case RESET_GROUND:
			{
			    Ground += 10;
			    BallGround += 10; 
			   
			    if(!PlayerJumpFlag)
			    {
			    	PlayerY = Ground; 
			    }
			   
			    PlayEffect(PItemGetSound);
			    break;
			}
			
			case ADD_SCORE:
			{
				Score += AddScore;
				PlayEffect(PItemGetSound);
				AddScore = 300;
				break;
			}
			
			case INVINCIBLE:
			{
				PlayEffect(PItemGetSound);
				PlayerInvicibleFlag = TRUE;
								
				break;
			}
			
			case UP_GROUND:
			{
				Ground -= 10;
				BallGround -= 10;
				
				if(!PlayerJumpFlag)
				{
					PlayerY = Ground;
				} 
				
				PlayEffect(MItemGetSound);
				break;
			}
				
			case UP_TEMP:
			{
				Temp1_Up = 10;
				Temperature1 += Temp1_Up;
				PlayEffect(MItemGetSound);
				
				for(int up=0;up < BALL_MAX;up++)
				{
				   
				   if(BallVx[up] < 0)
				   {
				   	   BallVx[up] -= B_SPEED;
				   }
				   
				   if(BallVx[up] > 0)
				   {
				   	   BallVx[up] += B_SPEED;
				   }
				   
				   if(BallVy[up] < 0)
				   {
				   	   BallVy[up] -= B_SPEED;
				   }
				   
				   if(BallVy[up] > 0) 
				   {
				   	   BallVy[up] += B_SPEED; 
				   }
				   
				}
				  
				break;
			}
				
			case DOWN_SCORE:
            {
               	AddScore = 300;
               	Score -= AddScore;
               	PlayEffect(MItemGetSound);
               	break;
            }
			
	}   
}

//�A�C�e�������蔻��`�F�b�N
int ItemHitCheck()
{
	    int i;
	    int j;
	    
	    if(!ItemFlag)
	    {
	    		
	    		for(j=0;j < ITEM_MAX;j++)
				{					
					ItemX[j] = check_item_x_data[item_position];
					ItemY[j] = 0;
				}
				
				
				  ItemID = rand() % ITEM_MAX;
				  
				  if(check_item_turn[item_data]==-1)
				  {
				  		item_data = 0;
				  }
  		
	    		if(Minute==check_item_data[item_counter])
	    		{
	    		   ItemFlag = TRUE;
	    		   item_counter++;
	    		   
	    		   if(check_item_data[item_counter]==-1)
	    		   {
	    		   	   item_counter = 0;
	    		   }
	    		}	    	
	    }    
	   
	    if(ItemFlag)
	    {
		       for(j = 0; j < ITEM_MAX;j++)
		       {
			        MoveItem();
			        
			        DrawItem();
			       
			        if(playertop < itembottom[j] &&
				       playerbottom > itemtop[j] &&
				       playerleft < itemright[j] &&
				       playerright > itemleft[j]  )
				    {
						ItemGetFlag = TRUE;
						
						WordFlag = TRUE;
						
						ItemFlag = FALSE;
			        }
			        
			        item_position ++;
			        item_data++;
			       
					if(check_item_x_data[item_position] == -1)
					{
						item_position = 0;
					}
			   
			   }  
		}   	

}

int DrawEffWord()
{
 	
 	switch(ItemID)
 	{
 		case DOWN_TEMP:
		{
			DrawGraph(PlayerX, PlayerY-10, EffWordGraph[0], TRUE);
			break;
		}
		
		case RESET_GAUGE:
		{
		    DrawGraph(PlayerX, PlayerY-10, EffWordGraph[1], TRUE);
		    break;
		}
		
		case ADD_SCORE:
		{
			DrawGraph(PlayerX, PlayerY-10, EffWordGraph[2], TRUE);
		    break;
		}
				
		case UP_TEMP:
		{
			DrawGraph(PlayerX, PlayerY-10, EffWordGraph[0], TRUE);
			break;
		}
		
		case DOWN_SCORE:
        {            	
          	DrawGraph(PlayerX, PlayerY-10, EffWordGraph[0], TRUE);
          	break;
        }

 	}
 	
}

//���x���p------------------------------------------------------------

//Easy
int LevelEasy()
{
	int Easy;
	
	SRand(3);
	
	for(Easy=0;Easy < BALL_MAX;Easy++)
	{
		BallVx[Easy] = GetRand(4);
		BallVy[Easy] = GetRand(4);
		
		if(BallVx[Easy] == 0)
		{
			BallVx[Easy] += 1;
		}
		
		if(BallVy[Easy] == 0)
		{
			BallVy[Easy] += 1;
		}
		
		BallX[Easy] = GetRand(400);
		BallY[Easy] = GetRand(100);
	}
	
	Temperature1 = TEMP_EASY;
}

//Normal
int LevelNormal()
{
	int Normal;
	
	SRand(4);
	
	for(Normal=0;Normal < BALL_MAX;Normal++)
	{
		BallVx[Normal] = GetRand(7);
		BallVy[Normal] = GetRand(8);
		
		if(BallVx[Normal] == 0)
		{
			BallVx[Normal] += 1;
		}
		
		if(BallVy[Normal] == 0)
		{
			BallVy[Normal] += 1;
		}
		
    	BallX[Normal] = GetRand(400);
    	BallY[Normal] = GetRand(100);
    }
	
	Temperature1 = TEMP_NORMAL;
}

//Hard
int LevelHard()
{
	int Hard;
	
	SRand(10);
	
	for(Hard=0;Hard < BALL_MAX;Hard++)
	{
		BallVx[Hard] = GetRand(12);
		BallVy[Hard] = GetRand(14);
		
		if(BallVx[Hard] == 0)
		{
			BallVx[Hard] += 1;
		}
		
		if(BallVy[Hard] == 0)
		{
			BallVy[Hard] += 1;
		}
		
		BallX[Hard] = GetRand(400);
    	BallY[Hard] = GetRand(100);
	}
	
	Temperature1 = TEMP_HARD;
}
//--------------------------------------------------------------------

//�X�R�A�֌W----------------------------------------------------------

//�X�R�A�̕`��
int DrawScore()
{
	 int Color;
	 
	 Color = GetColor(255, 255, 255);
	 
	 DrawString(MENU_STRING_LEFT, MENU_STRING_TOP + 120, "SCORE", Color);
	 DrawFormatString(MENU_STRING_LEFT + 10, MENU_STRING_TOP + 150, Color, "%2d", Score); 
	 
	 if(Score < 0)
	 {
	 	 Score = 0;
	 }
}

int ScoreAdd(int AddScore)
{
 	 Score += AddScore; 
 	 
}


//���̃{�[�i�X�X�R�A�̕`��
int DrawNextBonus()
{
	int Color;

	Color = GetColor(255,255,255);
	
	BonusScore = check_bonus_data[bonus];
	
	if(Score >= check_bonus_data[bonus])
	{
		bonus++;
		
		PlayerLife++;
		
		PlayEffect(LifeUpSound);
	
	} 
	
	DrawString(MENU_STRING_LEFT, MENU_STRING_TOP + 180,"NEXT BONUS", Color);
	DrawFormatString(MENU_STRING_LEFT + 10, MENU_STRING_TOP + 210, Color, "%2d", BonusScore);
	
}
//--------------------------------------------------------------------

//���Ԋ֌W------------------------------------------------------------

//���Ԃ̕`��
int DrawTime()
{
	Temp1_Up = 1;
	
	int Color;
	int i;
	
	Color = GetColor(255,255,255);
    
    Second += Second_Add;
    
    if(Temperature1 < 0)
    {
    	Temperature1 = 0;
    }
    
    if(Temperature2 >= 10)
    {
        Temperature2 = 0;
        Temperature1 += Temp1_Up;
    }
        
    if(Second == 20)
    {
    	Temperature2 += Temp2_Up;
    	
    }
    
    if(Second == 40)
    {
    	Temperature2 += Temp2_Up;
                
    }
    
    if(Minute == 60)
    {
    	Minute = 0;
    	Hour += 1;
    }
    
    if(Hour == 60)
    {
    	
    }
    
    DrawString(MENU_STRING_LEFT, MENU_STRING_TOP + 60, "TIME", Color);
    DrawFormatString(MENU_STRING_LEFT + 10, MENU_STRING_TOP + 90, Color, "%2d:%2d:%2d", Hour, Minute, Second);
    
}
//--------------------------------------------------------------------

//--------------------------------------------------------------------

//���x�֌W------------------------------------------------------------

//���x�̕`��
int DrawTemp()
{
	int Color;
	
	Color = GetColor(255, 255, 255);
	
	DrawBox(598, 465, 607, 465 - Temperature1*2 , GetColor(255, 0, 0), TRUE);
	DrawString(MENU_STRING_LEFT, MENU_STRING_TOP, "TEMP", Color);
	DrawFormatString(MENU_STRING_LEFT, MENU_STRING_TOP + 30, Color, "%2d.%d��", Temperature1, Temperature2);
	
}
//--------------------------------------------------------------------


//�Q�[���I�[�o�[�֌W--------------------------------------------------

//�Q�[���I�[�o�[�̏���
int GameOver()
{
	int i;
	
	ClsDrawScreen();
			
   	ItemFlag = FALSE;
   	
   	GuardFlag = FALSE;
   	
   	PlayerVx = 0;
    PlayerVy = 0;
    
    Temperature2 = 0;
   	 			    
    for(i=0;i < BALL_MAX;i++)
    {
   	   BallVx[i] = 0;
   	   BallVy[i] = 0;
    }
    
    AddScore = 0;
    Item_down = 0;
    Second_Add = 0;
    
    return 0;       
}

//�Q�[���I�[�o�[���b�Z�[�W�̕\��
int GameOverMessage(int X, int Y)
{
	int Color;
	
	Color = GetColor(255,255,255);
	
	DrawGraph(0, 0, GameOverGraph, TRUE);
	
    
    	switch(messagecounter)
	{
		case 0:
		{
		  	DrawRank();
		 	
		
		}
		
		case 1:
		{
			DrawFormatString(X, Y + 80, Color, "TotalScore  %d", Score);
		}
		
		case 2:
		{
			DrawFormatString(X+ 200, Y + 60, Color, "+%d", itemgetcounter*30); 
		}
		
		case 3:
		{
			DrawFormatString(X, Y + 60, Color, "GetItem : %d", itemgetcounter); 
		}
		
		case 4:
		{
		   DrawFormatString(X+200, Y + 40, Color, "+%d",Temperature1);
		}
		
		case 5:
		{
		     DrawFormatString(X, Y + 40, Color, "Temperature:%d",Temperature1);
		}
		
		case 6:
		{
		   DrawFormatString(X+200, Y + 20, Color, "+%d", Hour*1000+Minute*10);  
		}
		
		case 7:
		{
		   	 DrawFormatString(X, Y + 20, Color, "Time %d:%d:%d",Hour, Minute, Second);
		}
		
		case 8:
		{
			DrawFormatString(X, Y, Color, "Score %d", OldScore);
		}
		
	
		
	}

	
	if(DownInput & PAD_INPUT_A)
	{
		messagecounter--;
		
		PlayEffect(ScoreSound);
		
		if(messagecounter==0)
		{
	    	PlayEffect(RankSound);
		}
		
	}

	if(messagecounter < 0)
	{
	    StopEffect(GameOverMusic);
	    rank_counter=0;
	    Release();
	    Title();	
	}
	return 0;
}

int Release()
{
	InitGraph();
	InitSoundMem();
	InitFontToHandle();
}


//--------------------------------------------------------------------

//���̑�--------------------------------------------------------------

//�|�[�Y
int Pause()
{
        int i;
                        
        if(pauseFlag)
	    {
	    	stop_time++;
	    	
	    	Temperature1 = 0;
	    	Temperature2 = 0;
	    	Temp1_Up = 0;
	    	Temp2_Up = 0;
	    	
	    	Red = 0;
	    	Blue = 255;
	    	Green = 0;
	    	
	    		    	 
	    	if(stop_time > 100)
	    	{
	    	   stop_time = 0;
	    	   Temperature1 = OldTemp1;
	    	   Temperature2 = OldTemp2;
	    	   Red = OldRed;
	    	   Green = OldGreen;
	    	   Blue = OldBlue;
	    	   
	    	   pauseFlag = FALSE;
	    	}
	    }
	    
	    if(!pauseFlag)
	    {
	       Temp1_Up = TEMP1_UP_SPEED;
           Temp2_Up = TEMP2_UP_SPEED;
	       MoveBall();
	       
	       StopEffect(PauseSound);
	    }
}

//�����蔻��̈�
int HitCheckArea()
{
		#define HIT_LEFT 16
		#define HIT_RIGHT 32
		#define HIT_BOTTOM 16
		
		int i;
		int j;
		
		float X1;
		float Y1;
		
		float X2;
		float Y2;
		
		float X3;
		float Y3;
		
		float X4;
		float Y4;
		
		float X5;
		float Y5;
		
		float X6;
		float Y6;
		
		if(Key & PAD_INPUT_DOWN && !PlayerJumpFlag)
		{
			playertop = PlayerY + PlayerCSizeY;
			playerbottom = PlayerY + PlayerCSizeY*2-7;
			playerleft = PlayerX + 8;
			playerright = PlayerX + PlayerCSizeY - 8;
			
			GuardLefttop = PlayerY + PlayerCSizeY-5;
			GuardLeftbottom = PlayerY + PlayerCSizeY + HIT_BOTTOM+10;
			GuardLeftleft = PlayerX - 5;
			GuardLeftright = PlayerX;
			
			GuardRighttop = PlayerY + PlayerCSizeY-5;                   //28
			GuardRightbottom = PlayerY + PlayerCSizeY + HIT_BOTTOM+10;  //58
			GuardRightleft = PlayerX + HIT_LEFT*2;                      //32
			GuardRightright = PlayerX + HIT_RIGHT + 5;                  //37
			
		}
		
		else
		{
			playertop = PlayerY + 10;
		    playerbottom = PlayerY + PlayerSizeY - 10;
		    playerleft = PlayerX + 10;
		    playerright = PlayerX + PlayerSizeX - 10;
		
			GuardLefttop = PlayerY+4;
			GuardLeftbottom = PlayerY + HIT_BOTTOM*3+3;
			GuardLeftleft = PlayerX - HIT_LEFT + 10;
			GuardLeftright = PlayerX;
			
			GuardRighttop = PlayerY+4;
			GuardRightbottom = PlayerY + HIT_BOTTOM*3+3;
			GuardRightleft = PlayerX + HIT_LEFT*2 ;
			GuardRightright = PlayerX + HIT_RIGHT+ 5;
		}
		
		barriertop = PlayerY-15;
		barrierbottom = PlayerY - 15 + BarrierSizeY;
		barrierleft = PlayerX - 18;
		barrierright = PlayerX - 18 + BarrierSizeX;
		    
	    X1 = BallX[0] - BallX[1];
	    Y1 = BallY[0] - BallY[1];
	    
	    X2 = BallX[1] - BallX[2];
	    Y2 = BallY[1] - BallY[2];
	    
	    X3 = BallX[2] - BallX[0];
	    Y3 = BallY[2] - BallY[0]; 
	    
	    for(i=0;i < BALL_MAX;i++)
	    {
		    balltop[i]    = BallY[i] + 2;
		    ballbottom[i] = BallY[i] + BallSizeY-2;
		    ballleft[i]   = BallX[i] + 2;
		    ballright[i]  = BallX[i] + BallSizeX - 2;
	    }
	    
	    disttop = DistY;
	    distbottom = DistY + DistSizeY;
	    distleft = DistX;
	    distright = DistX + DistSizeX;
	    
	   
	    for(j=0;j < ITEM_MAX;j++)
	    {
		   	itemtop[j] = ItemY[j];
		   	itembottom[j] = ItemY[j] + ItemSizeY;
		   	itemleft[j] = ItemX[j];
		   	itemright[j] = ItemX[j] + ItemSizeX;
	    }  
	    
	   
	    distance[0] = (X1 * X1 + Y1 * Y1) ;
	    distance[1] = (X2 * X2 + Y2 * Y2) ;
	    distance[2] = (X3 * X3 + Y3 * Y3) ;
	    	    
	    check_distance = ((BallSizeX * BallSizeX) + (BallSizeY * BallSizeY)) + 7;
	    
}

//LIMIT�Q�[�W�̕`��
int DrawLimitGauge()
{
	int Color;
	int Color2;
    int limit_gauge;
    
    Color = GetColor(0, 255, 0);
    Color2 = GetColor(255, 255, 255);
    
    DrawString(MENU_STRING_LEFT, MENU_STRING_TOP + 240, "LIMIT", Color2);
    
    if(limit_time == check_limit_data[limit])
    {
    	limit_time = 0;
       	Ground -= Ground_Up;
       	BallGround -= Ground_Up;
       	limit ++;
    }
    
    switch(check_limit_data[limit])
    {
        case -1:
        {
           limit = 0;
        }
        
        case 10:
        {
           DrawBox(MENU_STRING_LEFT, MENU_STRING_TOP + 270, MENU_STRING_LEFT  + limit_time*12 ,MENU_STRING_TOP + 290, Color, TRUE);
    
        }
        
        case 20:
        {
           DrawBox(MENU_STRING_LEFT, MENU_STRING_TOP + 270, MENU_STRING_LEFT  + limit_time*5 ,MENU_STRING_TOP + 290, Color, TRUE);
    
        }
        
        case 30:
        {
           DrawBox(MENU_STRING_LEFT, MENU_STRING_TOP + 270, MENU_STRING_LEFT  + limit_time*4 ,MENU_STRING_TOP + 290, Color, TRUE);
    
        }
   }
   
    
}

//�w�i�̕`��
int DrawBack()
{
		if(pauseFlag)
		{
			DrawGraph(0, 0, PauseGraph, TRUE);
	    }
		
		else 
		{
			DrawGraph(0, 0, BackGraph, TRUE);
		}
		
}

//������
int Init()
{
	GameScene = GAME_MAIN;
	
	GuardGauge = 100;
	
	messagecounter = 9;
	
	itemgetcounter = 0;
	
	int Color;
	int i;
	
	//--------------------
	//�O���t�B�b�N�̃��[�h|
	//--------------------	
	PlayerJumpGraph = LoadGraph("graphic/hum_jump.png");
	PlayerGuardGraph = LoadGraph("graphic/hum_guard.png");
	PlayerCGuardGraph = LoadGraph("graphic/hum_c_guard.png");
	BallGraph = LoadGraph("graphic/0055.png");
	GroundGraph = LoadGraph("graphic/ground.png");
	TempGraph = LoadGraph("graphic/temp.png");
	Graph = LoadGraph("graphic/menu.png");
	PauseGraph = LoadGraph("graphic/hyouga2.jpg");
	BackGraph = LoadGraph("graphic/thumb.jpg");
	FrameGraph = LoadGraph("graphic/limit_gaugeframa.png");
	RankFontGraph = LoadGraph("graphic/rank_font.png");
	
	GameOverGraph = LoadGraph("graphic/gameover.png");
	
	
	playeranimpat = 4;
	
	playeranimpat_c = 2;
	
	playeranimpat_at = 2;
	
	barrier_animpat = 3;
	
	shield_animpat = 3;
	
	
	LoadDivGraph("graphic/hum_move.png", 5, 5, 1, 32, 64, PlayerGraph); 
	LoadDivGraph("graphic/chip.png", 10, 2, 5, 32, 32, ItemGraph);
	LoadDivGraph("graphic/hum_c.png", 3, 3, 1, 32, 32, PlayerCGraph);
	LoadDivGraph("graphic/hum_at_side1.png", 2, 2, 1, 32, 64, PlayerAtSideGraph);
	LoadDivGraph("graphic/barrier.png", 3, 3, 1, 70, 70,BarrierGraph);
	LoadDivGraph("graphic/shield.png",3, 3, 1, 10, 60,ShieldGraph);
	LoadDivGraph("graphic/shield.png",3, 3, 1, 10, 30,ShieldCGraph);
	LoadDivGraph("graphic/Word.png",3, 1, 3, 168,32 ,EffWordGraph);
	LoadDivGraph("graphic/rank.png",5, 5, 1, 32,32 ,RankGraph);

	//---------------------
	//���t�@�C���̃��[�h
	//---------------------
	JumpSound = LoadSoundMem("sound/jump.wav"); //�W�����v��
	GameMusic = LoadSoundMem("sound/game.ogg");
	GameOverMusic = LoadSoundMem("sound/GameOver.ogg");//�Q�[���I�[�o�[BGM
    BallBoundSound = LoadSoundMem("sound/don.wav"); //�{�[�����ˉ�
    DamageSound = LoadSoundMem("sound/damage.wav"); //�_���[�W��
	LifeUpSound = LoadSoundMem("sound/lifeup.wav"); //���C�tup�� 
	WarnSound = LoadSoundMem("sound/");   //�x����
	MoveSound = LoadSoundMem("sound/move.wav");//���s��
	GameOverSound = LoadSoundMem("sound/SHUTDOWN.wav"); //�Q�[���I�[�o�[��
	PauseSound = LoadSoundMem("sound/ALARM_CL.wav");
	PItemGetSound = LoadSoundMem("sound/PITEM.wav");
	MItemGetSound = LoadSoundMem("sound/MITEM.wav");
	GuardSound = LoadSoundMem("sound/guard.wav");//�K�[�h��
	BarrierSound = LoadSoundMem("sound/barrier.wav");//�o���A���ˉ�
	ScoreSound = LoadSoundMem("sound/score.wav");
	RankSound = LoadSoundMem("sound/rank.wav");
	
	Ground = INIT_GROUND;
    BallGround = Ground + 40;
	
	PlayerX = Left_Edge;
	PlayerY = Ground;
	
	//------------------------
	//�O���t�B�b�N�T�C�Y�𓾂�|
	//------------------------
	GetGraphSize(PlayerGraph[0], &PlayerSizeX, &PlayerSizeY);
	GetGraphSize(BallGraph, &BallSizeX, &BallSizeY);
	
	DistX = -20;
	DistY = Ground - 40;
	
	dist_counter = 0;
	
	ItemSizeX = 32;
    ItemSizeY = 32;
    
    DistSizeX = 16;
    DistSizeY = 64;
    
    PlayerCSizeX = 32;
    PlayerCSizeY = 32;
    
    BarrierSizeX = 70;
    BarrierSizeY = 70; 
    
    item_counter = 0;
    Index = 0;
    limit = 0;
    bonus = 0;
    
    PlayerLife = LIFE;
    
    direction = RIGHT;
    
    PlayerVx = 0;
    PlayerVy = 0;
    
    Temp1_Up = TEMP1_UP_SPEED;
    Temp2_Up = TEMP2_UP_SPEED;
    Ground_Up = GROUND_UP_SPEED;
    Second_Add = SECOND_UP_SPEED; 
    Item_down = ITEM_SPEED;
        
	Color = GetColor(255, 255, 255);
	
	Second = 0;
    Minute = 0;
    Hour = 0;
    
    PlayerInvincibleTime = 0;
    
    stop_time = 0;
    
    //�t���O----------------------
    ItemFlag = FALSE;
    
    ItemGetFlag = FALSE;
    
    PlayerInvicibleFlag = FALSE;
    
    PlayerJumpFlag = FALSE; 
    
    pauseFlag = FALSE;
  	
  	TitleCallFlag = FALSE;
  	
  	//----------------------------
    Score = 0;
    AddScore = 0;
    BonusScore = check_bonus_data[bonus];
    
    limit_time = 0;
    
    Red = Temperature1 - 50;
    Green = 0;
    Blue = 0;
   
    Temp_gauge = TEMP_BAR_BOTTOM - 10;
    
    item_position = 0;
    
}

int TimeChange()
{
    AddScore = 10;
    Second = 0;
    Minute += 1;
    Score += AddScore;
    limit_time+= 1;
        
    Red += 1;
    
    Blue += 0;
    
    Green += 0;
    
    GuardGauge += 20;
    
    if(GuardGauge >= 100)
    {
     	GuardGauge = 100;
     	GuardFlag = TRUE;
    }
    
    if(Red > 255)
    {
    	Red = 255;
    }
    
    if(Green > 255)
    {
    	Green = 0;
    }
    
    if(Blue > 255)
    {
    	Blue = 0;
    }
    	
    Temperature2 += Temp2_Up;
        
    BallSpeedUp();
        
}

int GroundUpRange(int GroundY)
{
 	if(Ground < GroundY)
 	{
 		Ground = GroundY;
 	}
 	 	
}

int DrawShield(void)
{
 	if(!PlayerCoughtFlag)
	{
		
				if(direction == RIGHT && Key & PAD_INPUT_B)
				{
			        shield_animcounter++;
				    shield_anim = shield_animcounter /4 % shield_animpat;
			        DrawGraph(PlayerX+30, PlayerY, ShieldGraph[shield_anim], TRUE);
				}															
				
				else if(direction == LEFT && Key & PAD_INPUT_B)
				{
					shield_animcounter++;
				    shield_anim = shield_animcounter /4 % shield_animpat;
					DrawGraph(PlayerX-10, PlayerY, ShieldGraph[shield_anim], TRUE);
				}
		
	}
	
	if(PlayerCoughtFlag)
	{
		
				if(direction == RIGHT && Key & PAD_INPUT_B)
				{
			        shield_animcounter++;
				    shield_anim = shield_animcounter /4 % shield_animpat;
			        DrawGraph(PlayerX+30, PlayerY+PlayerCSizeY, ShieldCGraph[shield_anim], TRUE);
				}															
				
				else if(direction == LEFT && Key & PAD_INPUT_B)
				{
					shield_animcounter++;
				    shield_anim = shield_animcounter /4 % shield_animpat;
					DrawGraph(PlayerX-10, PlayerY+PlayerCSizeY, ShieldCGraph[shield_anim], TRUE);
				}
		
	}
 	 
}

int DrawRank()
{
		
	DrawGraph(100, 400, RankFontGraph, TRUE);
	DrawGraph(190, 390, RankGraph[rank_counter], TRUE);
	
	if(Score >= check_rank[rank_counter])
	{
	 	rank_counter++;
	 	
	}
	
	
	
}
