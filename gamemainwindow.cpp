#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"

GameMainWindow::GameMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::GameMainWindow)
{
	ui->setupUi(this);
	setWindowOpacity(0.95);
	setWindowTitle("井字棋");
	setStyleSheet(
				"QMainWindow{background-color:rgb(76,74,72);}"
				"QGroupBox QPushButton{background-color:rgba(255,255,255,0.2);}"
				"QGroupBox{border:hidden;}"
				"#who{background-color:transparent;color:white;font-size:40px;}"
				);
	grids=
	{
		{ui->area1_1,ui->area1_2,ui->area1_3},
		{ui->area2_1,ui->area2_2,ui->area2_3},
		{ui->area3_1,ui->area3_2,ui->area3_3}
	};

	chessmen =
	{
		{Chessman(),Chessman(),Chessman()},
		{Chessman(),Chessman(),Chessman()},
		{Chessman(),Chessman(),Chessman()}
	};

	setWhoText("选择你的棋子");
	showChooseDialog();
}

GameMainWindow::~GameMainWindow()
{
	delete ui;
}

void GameMainWindow::win(int x, int y)
{
	bool isFull = true;
	for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
		{
			if(chessmen[x][y].status == EMPTY)
				isFull = false;
		}
	QPair<bool,int> ret;
	ret.first = false;
	if(x==y)//检查正斜角
	{
		if(chessmen[0][0].status != EMPTY && chessmen[0][0]==chessmen[1][1] && chessmen[1][1] == chessmen[2][2])
		{
			ret.first = true;
			ret.second = chessmen[0][0].status;
		}
	}
	if(x==2-y)//检查反斜角
	{
		if(chessmen[0][2].status != EMPTY && chessmen[0][2]==chessmen[1][1] && chessmen[1][1] == chessmen[2][0])
		{
			ret.first = true;
			ret.second = chessmen[0][2].status;
		}
	}
	if(chessmen[x][0].status != EMPTY && chessmen[x][0]==chessmen[x][1] && chessmen[x][1] == chessmen[x][2])
	{
		ret.first = true;
		ret.second = chessmen[x][0].status;
	}
	if(chessmen[0][y].status != EMPTY && chessmen[0][y]==chessmen[1][y] && chessmen[1][y] == chessmen[2][y])
	{
		ret.first = true;
		ret.second = chessmen[0][y].status;
	}

	if(ret.first == true)
	{
		setWhoText(ret.second);
		clear();
		showChooseDialog();
	}
	else if(isFull == true)
	{
		setWhoText("平局");
		clear();
		showChooseDialog();
	}
}

void GameMainWindow::setWhoText(const QString & str)
{
	ui->who->setText(str);
}

void GameMainWindow::setWhoText()
{
	if(who == O)
		setWhoText("现在由O执子");
	else
		setWhoText("现在由×执子");
}

void GameMainWindow::setWhoText(int who)
{
	if(who == O)
		setWhoText("O胜利！");
	else
		setWhoText("×胜利！");
}

QString GameMainWindow::getBackground()
{
	if(who == O)
		return "border-image:url(':/images/O.png');";
	else
		return "border-image:url(':/images/X.png');";
}

void GameMainWindow::clear()
{
	chessmen =
	{
		{Chessman(),Chessman(),Chessman()},
		{Chessman(),Chessman(),Chessman()},
		{Chessman(),Chessman(),Chessman()}
	};

	for(auto row: grids)
		for(QPushButton * grid : row)
		{
			grid->setStyleSheet("border-image:url('');");
			grid->setDisabled(false);
		}
}

void GameMainWindow::showChooseDialog()
{
	ChooseDialog * c = new ChooseDialog(this);
	connect(c,SIGNAL(Exit()),this,SLOT(ExitNow()));
	connect(c,SIGNAL(O()),this,SLOT(chooseO()));
	connect(c,SIGNAL(X()),this,SLOT(chooseX()));
	c->setWindowFlag(Qt::FramelessWindowHint);
	c->setModal(true);
	c->move(635,400);
	c->show();
}

void GameMainWindow::ExitNow()
{
	close();
}

void GameMainWindow::chooseO()
{
	who = O;
	setWhoText();
}

void GameMainWindow::chooseX()
{
	who = X;
	setWhoText();
}

void GameMainWindow::on_area1_1_clicked()
{
	grids[0][0]->setStyleSheet(getBackground());
	grids[0][0]->setDisabled(true);
	chessmen[0][0].status = who;
	who = (who+1)%2;
	setWhoText();
	win(0,0);
}

void GameMainWindow::on_area1_2_clicked()
{
	grids[0][1]->setStyleSheet(getBackground());
	grids[0][1]->setDisabled(true);
	chessmen[0][1].status = who;
	who = (who+1)%2;
	setWhoText();
	win(0,1);
}

void GameMainWindow::on_area1_3_clicked()
{
	grids[0][2]->setStyleSheet(getBackground());
	grids[0][2]->setDisabled(true);
	chessmen[0][2].status = who;
	who = (who+1)%2;
	setWhoText();
	win(0,2);
}

void GameMainWindow::on_area2_1_clicked()
{
	grids[1][0]->setStyleSheet(getBackground());
	grids[1][0]->setDisabled(true);
	chessmen[1][0].status = who;
	who = (who+1)%2;
	setWhoText();
	win(1,0);
}

void GameMainWindow::on_area2_2_clicked()
{
	grids[1][1]->setStyleSheet(getBackground());
	grids[1][1]->setDisabled(true);
	chessmen[1][1].status = who;
	who = (who+1)%2;
	setWhoText();
	win(1,1);
}

void GameMainWindow::on_area2_3_clicked()
{
	grids[1][2]->setStyleSheet(getBackground());
	grids[1][2]->setDisabled(true);
	chessmen[1][2].status = who;
	who = (who+1)%2;
	setWhoText();
	win(1,2);
}

void GameMainWindow::on_area3_1_clicked()
{
	grids[2][0]->setStyleSheet(getBackground());
	grids[2][0]->setDisabled(true);
	chessmen[2][0].status = who;
	who = (who+1)%2;
	setWhoText();
	win(2,0);
}

void GameMainWindow::on_area3_2_clicked()
{
	grids[2][1]->setStyleSheet(getBackground());
	grids[2][1]->setDisabled(true);
	chessmen[2][1].status = who;
	who = (who+1)%2;
	setWhoText();
	win(2,1);
}

void GameMainWindow::on_area3_3_clicked()
{
	grids[2][2]->setStyleSheet(getBackground());
	grids[2][2]->setDisabled(true);
	chessmen[2][2].status = who;
	who = (who+1)%2;
	setWhoText();
	win(2,2);
}

bool Chessman::operator==(const Chessman & c)
{
	return (status == c.status);
}
