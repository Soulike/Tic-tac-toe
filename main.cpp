#include "gamemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GameMainWindow w;
	w.move(550,250);
	w.show();

	return a.exec();
}
