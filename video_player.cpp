//
// Created by twak on 11/11/2019.
//

#include "video_player.h"

#include "QUrl"

VideoPlayer::VideoPlayer() : QMediaPlayer(NULL) {
  setVolume(50);  // Be slightly less annoying
}

// Change Media being played
void VideoPlayer::setContent(VideoFile* i) {
  if (i != NULL) {
    setMedia(*i->url);
    play();
  }
}
