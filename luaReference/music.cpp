#include "music.h"

void Music::play() {
    std::cout << "play" << std::endl;
}
void Music::stop() {
    std::cout << "stop" << std::endl;
    if (callback) {
        std::cout << "callback onOver before" << std::endl;
        callback->onOver();
    }
}
void Music::setCallback(const std::shared_ptr<Music::Callback> &cb) {
    callback = cb;
}