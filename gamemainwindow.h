#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <QMainWindow>
#include<QVector>
#include<QPushButton>
#include<choosedialog.h>
#include<QPair>

static const int O=0;
static const int X=1;
static const int EMPTY = 3;

namespace Ui {
class GameMainWindow;
}


class Chessman
{
public:
	friend class GameMainWindow;
	Chessman(){status = EMPTY;}
	bool operator==(const Chessman & c);

private:

	int status;
};


class GameMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit GameMainWindow(QWidget *parent = 0);
	~GameMainWindow();

private:

	Ui::GameMainWindow *ui;
	QVector<QVector<QPushButton *>> grids;//每一格的UI对象
	QVector<QVector<Chessman>> chessmen;//对应的棋子对象

	void win(int x,int y);//是否有胜利方，第一个为是否，第二个为谁

	int who;//当前谁下棋

	void setWhoText(const QString & str);//任意Text
	void setWhoText();//执子Text
	void setWhoText(int who);//胜利Text

	QString getBackground();

	void clear();//清空数据重来

	void showChooseDialog();

private slots:
	void ExitNow();
	void chooseO();
	void chooseX();
	void on_area1_1_clicked();
	void on_area1_2_clicked();
	void on_area1_3_clicked();
	void on_area2_1_clicked();
	void on_area2_2_clicked();
	void on_area2_3_clicked();
	void on_area3_1_clicked();
	void on_area3_2_clicked();
	void on_area3_3_clicked();
};
#endif // GAMEMAINWINDOW_H
