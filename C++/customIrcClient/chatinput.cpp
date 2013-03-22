#include "chatinput.h"
#include <QKeyEvent>

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
            emit this->sendChat(this->toPlainText());
            this->setPlainText("");
        break;
        default:
            QPlainTextEdit::keyPressEvent(e);
            break;
    }

}
