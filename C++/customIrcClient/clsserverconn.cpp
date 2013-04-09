#include "clsserverconn.h"
#include "../resources/jsoncommand.h"

namespace client{

    clsServerConn::clsServerConn(const QString hostName, const int port,
            QObject *parent)
        :QObject(parent)
         ,hostName(hostName)
         ,port(port)
         ,log(LOGTAGS_UI)
    {
        this->buffer = new QString();

        this->sock = new QTcpSocket(this);

        this->sock->connect(this->sock, SIGNAL(readyRead()), this,
                SLOT(readData()));
        this->sock->connect(this->sock, SIGNAL(connected()), this,
                SLOT(srvConnected()));
        this->sock->connect(this->sock, SIGNAL(disconnected()), this,
                SLOT(srvDisconnected()));
    }

    void clsServerConn::doConnect(){
        this->sock->connectToHost(this->hostName,this->port);
        this->log << "Connecting" << endl;
    }

    void clsServerConn::sendCommand(jsonCommand &toSend){
        //this->log << "Sending json object: " << docToSend->toJson() << endl;
        this->log << "Sending JSON: " << toSend << endl;
        QByteArray bAToSend;
        bAToSend.append(toSend.toJsonString() + "\r\n");
        this->sock->write(bAToSend);
    }

    void clsServerConn::srvConnected(){
        this->log << "Connected!" << endl;
        emit this->connected();
    }


    void clsServerConn::srvDisconnected(){
        this->log << "Disconnected" << endl;
        emit this->disconnected();
    }

	void clsServerConn::handleCompletedQuery(jsonCommand &comm){
        QVector<ircUser*> users;
		foreach(QVariant user, comm.getData("users").toList()){
            users.append(new ircUser(user));
        }
        emit this->userQueryCompleted(users);
    }

	void clsServerConn::handleUserInfo(jsonCommand &command){
		if(command.getData("change") == "STATUS"){
			emit this->userStatusChange(command.getData("user").toInt(),
					command.getData("new").toString());
		}else if(command.getData("change") == "LEAVE"){
            //emit this->userLeave(command->getData("user").toInt());
		}else if(command.getData("change") == "ENTER"){
            //		emit this->userEnter(new ircUser(command->getData("user")));
		}else if(command.getData("change") == "NICK"){
			emit this->userChangeNick(command.getData("user").toInt(),
					command.getData("new").toString());
        }
    }

	void clsServerConn::handleOwnUserChange(jsonCommand &comm){
        //This function might have the same body as handleUserInfo.
        //But for now this is the only thing changeable.
        //Maybe later there will be more stuff added here
		if(comm.getData("change") == "STATUS"){
            //Own user is always ID 1..
			emit this->userStatusChange(1, comm.getData("new").toString());
        }
    }

	void clsServerConn::handleEventRequest(jsonCommand &comm){
        //Let them flow, all the chats!
		QList<QVariant> events = comm.getData("events").toList();
        foreach(QVariant myEvent, events){
            this->handleEventReceived(myEvent.toMap());
        }
    }

    void clsServerConn::handleEventReceived(QVariantMap data){
        clsEvent myEvent(data);
        switch(myEvent.getType()){
            case EVENTTYPE_CHAT:
                emit this->chatReceived(new eventChat(data));
                break;
            case EVENTTYPE_USER_JOIN:
                emit this->userEnter(new eventUserJoin(data));
            case EVENTTYPE_USER_LEFT:
                emit this->userLeave(new eventUserLeave(data));
            default:
                break; //ERROR!
        }

    }


	bool clsServerConn::checkForJsonCommand(QByteArray toAdd, jsonCommand &comm){
		bool ret = false;
		foreach(char b, toAdd){
			if(b == '{' || b == '['){
				depth++;
			}else if(b == '}' || b == ']'){
				depth--;
			}
			this->buffer->append(b);

			if(depth == 0){
				//Clear the buffer.
				if(comm.getCommand() == JSONCOMMAND_NONE){
					ret = true;
					comm = new jsonCommand(*this->buffer);
					this->log << "Data received: \t" << this->buffer << endl;
					this->buffer->clear();
				}
			}
		}
		return ret;
	}

    void clsServerConn::readData(){
		jsonCommand comm(JSONCOMMAND_NONE);
		if(this->checkForJsonCommand(this->sock->readAll(), comm)){
			switch (comm.getCommand()) {
				case JSONCOMMAND_EVENT:
					this->handleEventReceived(comm.getData("event").toMap());
					break;
				case JSONCOMMAND_USERQUERY:
					this->handleCompletedQuery(comm);
					break;
				case JSONCOMMAND_CHANGEOWNUSER:
					this->handleOwnUserChange(comm);
					break;
				case JSONCOMMAND_GETEVENTS:
					this->handleEventRequest(comm);
				default:
					break;
			}
		}
    }

}
