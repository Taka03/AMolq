#include "Dxlib.h"


#define GAME_TITLE 0
#define GAME_MAIN 1
#define LEVEL_SELECT 2
#define GAME_OVER 3

//�֐�-------------------------------
int Main(void); //���C���֐�

int Init(void); //�������p�֐�

int Title(void); //�^�C�g���֐�

int Tutorial(void);//�`���[�g���A���֐�

int LevelEasy(void); //���x��Easy�֐�

int LevelNormal(void);//���x��normal�֐�

int LevelHard(void);//���x��Hard�֐�
	
int LevelSelect(void);//���x���Z���N�g��ʂւ̈ڍs�֐�

int DrawPlayerlife(void); //�v���C���[�̃��C�t�`��

int DrawPlayer(void);//�v���C���[�`��֐�
	
int MovePlayer(void);//�v���C���[����֐�

int Jump(void); //�v���C���[�̃W�����v�����֐�

int PlayerMoveRange(void); //�v���C���[����͈͊֐�

int DrawBall(void);//�{�[��(���q)�`��֐�

int MoveBall(void);//�{�[��(���q)����֐�

int BallMoveRange(void); //�{�[������͈͊֐�

int BallSpeedUp(void);//�{�[���X�s�[�h�̉��Z�֐�

int DrawScore(void); //�X�R�A�֐�

int DrawNextBonus(void); //���̃{�[�i�X�X�R�A�̕`��

int DrawTime(void); //���ԕ`��֐�

int DrawTemp(void); //���x�`��֐�

int DrawLimitGauge(void);  //�ǂ������Ă���Q�[�W�̕`��

int DrawItem(void); //�A�C�e���`��֐�

int MoveItem(void); //�A�C�e������֐�

int ItemMoveRange(void); //�A�C�e���̈ړ��͈͊֐�

int EffItem(void); //�A�C�e�����ʊ֐�

int DrawBack(void); //�w�i�̕`��֐�

int Temp_Up(void); //���x�̏㏸�֐�

int PlayerHitCheck(void); //�����蔻��p�֐�(�v���C���[�ƃ{�[��)

int PlayerGuardCheck(void); //�v���C���[�̖h�䔻��p�֐�

int DrawBarrier(void);//�o���A�`��p�֐�

int BarrierHitCheck(void); //�����蔻��p�֐�(�o���A�ƃ{�[��)

int BallHitCheck(void); //�����蔻��p�֐�(�{�[�����m)

int ItemHitCheck(void); //�����蔻��p�֐�(�v���C���[�ƃA�C�e��)

int HitCheckArea(void); //�����蔻��̈�

int GameOver(void); //�Q�[���I�[�o�[�p�֐�

int GameOverMessage(int X, int Y); //Game Over�\���֐�

int Release(void); //�������J�������֐� 

int Debug(void); //�f�o�b�O�p�֐�

int Pause(void); //�|�[�Y�֐�

int TitleCallTime(void); //Game Over����^�C�g���֖߂鎞��

float Radian(float degree); //�x�����烉�W�A���ϊ�

int TimeChange(void); //���Ԃŕς�����

int DrawDisturb(void); //�ז��L�����`��

int MoveDisturb(void); //�ז��L��������

int DisturbHitCheck(void); //�ז��L���������蔻��

int DisturbMoveRange(void); //�ז��L�����ړ��͈�

int DrawGuardGauge(void); //�K�[�h�Q�[�W�`��

int PlayEffect(int Sound);//���ʉ��Đ�

int PlayEffectLoop(int Sound);

int StopEffect(int Sound); 

int GroundUpRange(int GroundY);

int ScoreAdd(int AddScore);

int DrawShield(void);//�h��V�[���h�`��֐�

int DrawEffWord(void);//�A�C�e�����ʕ\���p�֐�

int DrawRank(void);//�����N�\���p�֐�

int WindowMode(void);

//--------------------------------------
int ActMain();

//���ʉ��Đ�
int PlayEffect(int Sound)
{

	PlaySoundMem(Sound, DX_PLAYTYPE_BACK); 
}

int PlayEffectLoop(int Sound)
{
	PlaySoundMem(Sound, DX_PLAYTYPE_LOOP);
}

int StopEffect(int Sound)
{
	 StopSoundMem(Sound);
}





