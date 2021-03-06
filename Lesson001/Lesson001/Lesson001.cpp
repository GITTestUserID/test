// バージョン管理　Lesson001.cpp : 
//
// 

#include "stdafx.h"
#include "Player1.h"
#include "Player2.h"
#include "Lesson001.h"
#include <iomanip>

#define DAMAGE 1

Player1 player1;
Player2 player2;

void Init();
void Display();

int main()
{
	// 初期化
	cout << "ゲームを初期化します" << endl;
	Init();
	

	cout << "初期化終了ゲームを開始します" << endl;
	Sleep(1000);
	cout << "Fight" << endl;
	Sleep(1000);
	system("cls");

	// メイン
	while (GameFlag) {

		int janken = JResult[player1.Attack()][player2.Attack()];
		// 試合結果の格納
		GResult.push_back(janken);

		// 手の決及び判定		
		switch (janken) {
		case 0:
			//cout << "引き分け " << endl;
			break;
		case 1:
			//cout << "□Player1の勝ち" << endl;
			player2.SetDamage(DAMAGE);
			p1r++;
			break;
		case 2:
			//cout << "■Player2の勝ち" << endl;
			p2r++;
			player1.SetDamage(DAMAGE);
		}
		GameFlag = player1.isAlive()*player2.isAlive();

		// ステージ表示
		Display();
	}
	// 結果判定
	cout << endl << endl << "   競技回数:" << dec << GResult.size() << endl;
	cout << "   Player1勝利回数:" << setw(3) << p1r << "     勝率："
		 << fixed << setprecision(2) << (float)p1r/GResult.size() *100 << "%" << endl;
	cout << "   Player2勝利回数:" << setw(3) << p2r << "     勝率："
		<< fixed << setprecision(2) << (float)p2r / GResult.size() * 100 << "%" << endl;

	if (player1.isAlive() == false) {
		cout << endl << "  結果：Player2の勝ち" << endl;
	}
	
	if (player2.isAlive() == false) {
		cout << endl << "  結果：Player1の勝ち" << endl;
	}
		
	// 終了処理
	std::getchar();

	return 0;
}

void Init() {
	GameFlag = true;
	player1.Init();
	player2.Init();
	p1r = 0;
	p2r = 0;
}

void Display() {
	system("cls");
	setColor(COL_YELLOW);setCursorPos(1,1);cout << "<<試合結果>>";
	setCursorPos(2, 2);
	setColor(COL_WHITE);	cout << "Player1の勝ち";
	setColor(COL_RED);		cout << "■  ";
	setColor(COL_WHITE);	cout << "Player2の勝ち";
	setColor(COL_BLUE);		cout << "■ ";
	setColor(COL_WHITE);	cout << "引き分け";
	setColor(COL_GRAY);		cout << "■";

	setCursorPos(2, 3);
	std::for_each(GResult.cbegin(), GResult.cend(), [](int x) {
		int count=0;
		switch (x) {
		case 0:
			setColor(COL_GRAY);
			cout << "■";
			break;
		case 1:
			setColor(COL_RED);
			cout << "■";
			break;
		case 2:
			setColor(COL_BLUE);
			cout << "■";
		}
		setColor(COL_WHITE);
	});
	Sleep(100);
}