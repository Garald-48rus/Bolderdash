#ifndef SOUND_H
#define SOUND_H

#include <QString>
#include <QSound>


class sound

{
public:   
    sound();

    static QString sound_patch;

    void play_steps();
    void play_diamond();
    void play_win();
    void play_loose();

    void stop();
};

#endif // SOUND_H
