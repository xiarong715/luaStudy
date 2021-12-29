#ifndef ___MUSIC_H___
#define ___MUSIC_H___
#include <iostream>
#include <memory>

class Music {
   public:
    class Callback {
       public:
        virtual void onOver() = 0;
    };
    Music():callback(nullptr) {}
    ~Music() {std::cout << "Music::~Music" << std::endl;}
    void play();
    void stop();
    void setCallback(const std::shared_ptr<Music::Callback> &cb);

   private:
    std::shared_ptr<Music::Callback> callback;
};
#endif