//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//  2811 cw3 : twak 11/11/2021
//

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlayer>
#include <string>
#include <vector>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>

#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "library_page.h"
#include "favourite_page.h"
#include "map_page.h"
#include "album_page.h"
#include "filter_page.h"
#include "player.h"
#include "thumbnail_button.h"
#include "mainPage/navigation_button.h"
#include "mainPage/title_label.h"

#include "main_window.h"


#include "Map/map.h"

// read in videos and thumbnails to this directory
std::vector<VideoFile> getInfoIn (std::string loc) {

    std::vector<VideoFile> out =  std::vector<VideoFile>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(VideoFile( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb;
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    /*std::vector<VideoFile> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::question(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! download, unzip, and add command line argument to \"quoted\" file location. Download videos from Tom's OneDrive?"),
                    QMessageBox::Yes |
                    QMessageBox::No );

        switch( result )
        {
        case QMessageBox::Yes:
          QDesktopServices::openUrl(QUrl("https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1qfuN"));
          break;
        default:
            break;
        }
        exit(-1);
    }


//    // the widget that will show the video
//    QVideoWidget *videoWidget = new QVideoWidget;

//    // the QMediaPlayer which controls the playback
//    Player *player = new Player;
//    player->setVideoOutput(videoWidget);

//    // a row of buttons
//    QWidget *buttonWidget = new QWidget();
//    // a list of the buttons
//    std::vector<ThumbnailButton*> buttons;
//    // the buttons are arranged horizontally
//    QHBoxLayout *layout = new QHBoxLayout();
//    buttonWidget->setLayout(layout);


//    // create the four buttons
//    for ( int i = 0; i < 4; i++ ) {
//        ThumbnailButton *button = new ThumbnailButton(buttonWidget, &videos.at(i));
//        button->connect(button, SIGNAL(jumpTo(VideoFile* )), player, SLOT (jumpTo(VideoFile*))); // when clicked, tell the player to play.
//        buttons.push_back(button);
//        layout->addWidget(button);
//    }

//    // tell the player what buttons and videos are available
//    player->setContent(&buttons, &videos);



    // create the main window and layout

    MainWindow mainWindow;

    // showtime!
    window.show();*/
    // No longer required should be moved to map_page
    //Map *m = new Map();
    //m->show();


    return app.exec();
}
