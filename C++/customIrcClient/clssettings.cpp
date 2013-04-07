#include "clssettings.h"

clsSettings::clsSettings(const QString &filePath){
    QString fileName = filePath + "/settings.xml";
    QXmlStreamReader Rxml;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        std::cerr << "Error: Cannot read file " << fileName.toStdString()
         << ": " << qPrintable(file.errorString())
         << std::endl;
    }
    Rxml.setDevice(&file);
    Rxml.readNext();


    while(!Rxml.atEnd()){
        if(Rxml.isStartElement()){
            if(Rxml.name() == "settings"){
                Rxml.readNext(); //Start
            } else if(Rxml.name() == "server"){
                Rxml.readNext();
                this->readServer(Rxml);
            }
        }
        Rxml.readNext();
   }
    file.close();
}

QString clsSettings::getServer() const{
    return this->server;
}

int clsSettings::getPort() const{
    return this->port;
}


void clsSettings::readServer(QXmlStreamReader &reader){
    while(!reader.isEndElement()){
        QString name = reader.name().toString();
        if(name == "server"){
            this->server = reader.readElementText();
        }else if(name == "port"){
            this->port = reader.readElementText().toInt();
        }
        reader.readNext();
    }
}
