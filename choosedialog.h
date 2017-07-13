#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseDialog;
}

class ChooseDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ChooseDialog(QWidget *parent = 0);
	~ChooseDialog();

private slots:
	void on_exitButton_clicked();

	void on_O_clicked();

	void on_X_clicked();

private:
	Ui::ChooseDialog *ui;

signals:
	void Exit();
	void O();
	void X();
};

#endif // CHOOSEDIALOG_H
