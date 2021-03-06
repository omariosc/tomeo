#include "favourite_page.h"

#include <QGridLayout>
#include <QSize>
#include <QVideoWidget>

#include "libraryPage/videolibrary.h"
#include "main_window.h"

FavouritePage::FavouritePage(std::vector<VideoFile *> &videos, Player *player)
    : QWidget(), videos(videos) {
  library = new VideoLibrary(videos, player);
  QGridLayout *libraryLayout = new QGridLayout();
  libraryLayout->addWidget(library, 0, 0);
  setLayout(libraryLayout);
  filterForFavourites();  // Ensure only favourited videos are
  // Refresh on player quit to account for (un)favourited videos.
  connect(player, &Player::playerQuit, this,
          &FavouritePage::filterForFavourites);
}

// Update videoLibrary with only the videos that are favourited
void FavouritePage::filterForFavourites() {
  std::vector<VideoFile *> currentVideos;
  for (VideoFile *video : videos) {
    if (video->getFavourite()) {
      currentVideos.push_back(video);
    }
  }
  library->changeVideos(currentVideos);
}

void FavouritePage::refresh() { library->refresh(); }
