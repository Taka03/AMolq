#include "Dxlib.h"


#define GAME_TITLE 0
#define GAME_MAIN 1
#define LEVEL_SELECT 2
#define GAME_OVER 3

//関数-------------------------------
int Main(void); //メイン関数

int Init(void); //初期化用関数

int Title(void); //タイトル関数

int Tutorial(void);//チュートリアル関数

int LevelEasy(void); //レベルEasy関数

int LevelNormal(void);//レベルnormal関数

int LevelHard(void);//レベルHard関数
	
int LevelSelect(void);//レベルセレクト画面への移行関数

int DrawPlayerlife(void); //プレイヤーのライフ描画

int DrawPlayer(void);//プレイヤー描画関数
	
int MovePlayer(void);//プレイヤー動作関数

int Jump(void); //プレイヤーのジャンプ処理関数

int PlayerMoveRange(void); //プレイヤー動作範囲関数

int DrawBall(void);//ボール(分子)描画関数

int MoveBall(void);//ボール(分子)動作関数

int BallMoveRange(void); //ボール動作範囲関数

int BallSpeedUp(void);//ボールスピードの加算関数

int DrawScore(void); //スコア関数

int DrawNextBonus(void); //次のボーナススコアの描画

int DrawTime(void); //時間描画関数

int DrawTemp(void); //温度描画関数

int DrawLimitGauge(void);  //壁が迫ってくるゲージの描画

int DrawItem(void); //アイテム描画関数

int MoveItem(void); //アイテム動作関数

int ItemMoveRange(void); //アイテムの移動範囲関数

int EffItem(void); //アイテム効果関数

int DrawBack(void); //背景の描画関数

int Temp_Up(void); //温度の上昇関数

int PlayerHitCheck(void); //当たり判定用関数(プレイヤーとボール)

int PlayerGuardCheck(void); //プレイヤーの防御判定用関数

int DrawBarrier(void);//バリア描画用関数

int BarrierHitCheck(void); //当たり判定用関数(バリアとボール)

int BallHitCheck(void); //当たり判定用関数(ボール同士)

int ItemHitCheck(void); //当たり判定用関数(プレイヤーとアイテム)

int HitCheckArea(void); //当たり判定領域

int GameOver(void); //ゲームオーバー用関数

int GameOverMessage(int X, int Y); //Game Over表示関数

int Release(void); //メモリ開放処理関数 

int Debug(void); //デバッグ用関数

int Pause(void); //ポーズ関数

int TitleCallTime(void); //Game Overからタイトルへ戻る時間

float Radian(float degree); //度数からラジアン変換

int TimeChange(void); //時間で変わるもの

int DrawDisturb(void); //邪魔キャラ描画

int MoveDisturb(void); //邪魔キャラ動作

int DisturbHitCheck(void); //邪魔キャラ当たり判定

int DisturbMoveRange(void); //邪魔キャラ移動範囲

int DrawGuardGauge(void); //ガードゲージ描画

int PlayEffect(int Sound);//効果音再生

int PlayEffectLoop(int Sound);

int StopEffect(int Sound); 

int GroundUpRange(int GroundY);

int ScoreAdd(int AddScore);

int DrawShield(void);//防御シールド描画関数

int DrawEffWord(void);//アイテム効果表示用関数

int DrawRank(void);//ランク表示用関数

int WindowMode(void);

//--------------------------------------
int ActMain();

//効果音再生
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





