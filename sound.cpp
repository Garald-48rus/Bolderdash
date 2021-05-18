#include "sound.h"

sound::sound()
{
}
//------------------------------------
void sound::play_steps()
{
    sound_patch = "sound/steps.wav";
    QSound::play(sound_patch);
}
void sound::play_diamond()
{
    sound_patch = "sound/diamond.wav";
    QSound::play(sound_patch);
}
//-----------------------
void sound::play_win()
{
    sound_patch = "sound/win.wav";
  QSound::play(sound_patch);
}
//---------------------------
void sound::play_loose()
{
    sound_patch = "sound/loose.wav";
    QSound::play(sound_patch);
}
//-------------------------------------
void sound::stop()
{
     sound_patch = "";

}
//------------------------static---------------
QString sound::sound_patch = "";

