#ifndef CLSSETTINGS_H
#define CLSSETTINGS_H

#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QVector>
#include "ircuser.h"

namespace client{
	/*!
	 * \brief Settings class containing all the variables needed for the client
	 * \author Koen Beckers (K-4U)
	 * Gets the settings from the xml file called settings.xml
	 */
    class clsSettings
    {
        public:
			/*!
			 * \brief clsSettings Constructor
			 * \param filePath the path where the settings.xml file is located
			 */
            clsSettings(const QString &filePath);

			/*!
			 * \brief Gets the hostname of where the server is running
			 * \return The hostname of where the server is running
			 */
            QString getServer() const;

			/*!
			 * \brief Gets the port on which the server is listening
			 * \return The port on which the server is listening
			 */
            int getPort() const;
        private: //Functions
            void readServer(QXmlStreamReader &reader);


        private: //Values
            QString server;
            int port;
    };
}
#endif // CLSSETTINGS_H
