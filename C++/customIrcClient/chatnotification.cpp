#include "chatnotification.h"
#include "ui_chatnotification.h"
#include <math.h>
#include "../resources/clslog.h"


namespace client{
    chatNotification::chatNotification(QString message, QWidget *parent)
        :QWidget(parent)
         ,ui(new Ui::chatNotification)
         ,message(message)
         ,timeOfMessage(QTime::currentTime())
    {
        ui->setupUi(this);
        this->setMinimumWidth(parent->width());

        this->ui->lblTime->setText(this->timeOfMessage.toString());

        this->ui->lblNotification->setText(this->message);

		this->calculateMessageWidth();
	}

	chatNotification::chatNotification(QString message, QTime timeOfMessage, QColor myColor, QWidget *parent)
		:QWidget(parent)
		,ui(new Ui::chatNotification)
		,message(message)
		,timeOfMessage(timeOfMessage)
	{
		ui->setupUi(this);
		this->setMinimumWidth(parent->width());

		this->ui->lblTime->setText(this->timeOfMessage.toString());

		QPalette palette = ui->lblNotification->palette();
		palette.setColor(ui->lblNotification->foregroundRole(), myColor);
		ui->lblNotification->setPalette(palette);

		this->ui->lblNotification->setText(this->message);

		this->calculateMessageWidth();
	}

    chatNotification::~chatNotification()
    {
        delete ui;
    }

    void chatNotification::calculateMessageWidth(){
        this->ui->lblNotification->setGeometry(this->ui->lblTime->width() + 4,0,
                this->width() -
                (this->ui->lblTime->width() + 16),
                16);

        int lines = ceil((double)this->getWidth(this->ui->lblNotification) /
                (double)this->ui->lblNotification->width());

        this->setMinimumHeight(lines * this->getHeight(this->ui->lblNotification));
        this->ui->lblNotification->setMinimumHeight(this->minimumHeight() + 4);
    }

    int chatNotification::getWidth(QLabel *l) const{
        return l->fontMetrics().width(l->text());
    }

    int chatNotification::getHeight(QLabel *l) const{
        return l->fontMetrics().height();
    }



    void chatNotification::resizeEvent(QResizeEvent *event){
		Q_UNUSED(event);
        this->calculateMessageWidth();
    }

}
