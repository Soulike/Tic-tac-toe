#include "choosedialog.h"
#include "ui_choosedialog.h"

ChooseDialog::ChooseDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ChooseDialog)
{
	ui->setupUi(this);
	setStyleSheet(
				"#O{border-image:url(':/images/O.png');}"
				"#O:hover{background-color: orange;}"
				"#X{border-image:url(':/images/X.png');}"
				"#X:hover{background-color: rgb(18,150,219);}"
				"#exitButton{font-size:18px;border-radius:5px;border:1px solid gray;background-color:gray;}"
				"#exitButton:hover{background-color:red;}"
				);
}

ChooseDialog::~ChooseDialog()
{
	delete ui;
}

void ChooseDialog::on_exitButton_clicked()
{
	close();
	emit Exit();
	delete this;
}

void ChooseDialog::on_O_clicked()
{
	emit O();
	close();
	delete this;
}

void ChooseDialog::on_X_clicked()
{
	emit X();
	close();
	delete this;
}
