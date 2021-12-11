#include "library_page.h"
#include <QVideoWidget>
#include "player.h"
#include <QGridLayout>
#include "libraryPage/videolibrary.h"
#include <QSize>

LibraryPage::LibraryPage(std::vector<VideoFile> &videos) : QWidget() {


        QVideoWidget *videoWidget = new QVideoWidget();
        videoWidget->setStyleSheet("background: #FF00FF;");

        Player *player = new Player;
        player->setVideoOutput(videoWidget);

        VideoLibrary *library = new VideoLibrary(videos, *player);
        player->setContent(library->getButtons(), &videos);


        QGridLayout *libraryLayout = new QGridLayout();
        libraryLayout->addWidget(videoWidget, 0, 0);
        libraryLayout->addWidget(library, 1, 0);
        setLayout(libraryLayout);

}
