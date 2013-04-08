#include "chatinput.h"
#include <QKeyEvent>


namespace client{

    chatInput::chatInput(QWidget *parent) :
        QPlainTextEdit(parent)
    {
    }


    void chatInput::keyPressEvent(QKeyEvent *e){
        QTextCursor c = textCursor();
        switch (e->key()) {
            case Qt::Key_Escape:
                // whatever
                break;

            case Qt::Key_Enter:
            case Qt::Key_Return:
                this->checkForCommand(this->toPlainText());
                break;
            default:
                QPlainTextEdit::keyPressEvent(e);
                break;
        }

    }

    void chatInput::checkForCommand(QString text){
        if(text.at(0) == '/'){
            //Yay, a command!
            //Split it
            QList<QString> splits = text.split(' ');
            splits[0] = splits[0].mid(1);//To remove the /
            QString command = splits[0];
            command = command.toLower();
            splits.pop_front(); //Remove command
            emit this->commandGiven(command,splits);
        }else{
            emit this->sendChat(text);
        }
        this->setPlainText("");
    }

}
