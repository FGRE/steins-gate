/*
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014 Mislav Blažević <krofnica996@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */
#ifndef PHONE_HPP
#define PHONE_HPP

#include "nsbconstants.hpp"
#include "Text.hpp"
#include "Image.hpp"
#include <SDL2/SDL_timer.h>
using namespace Nsb;

const int16_t PHONE_ANIM_SPEED = 40; // TODO: guess
const int8_t PHONE_ANIM_ROW_MAX = 1;
const int8_t PHONE_ANIM_COLUMN_MAX = 4;
const int8_t PHONE_ANIM_UNDERFLOW = -1;
const int16_t PHONE_WIDTH = 313;
const int16_t PHONE_HEIGHT = 576;
const int16_t PHONE_POS_X = 678;
const int16_t PHONE_POS_Y = 8;

// cg/sys/phone/phone_01.png
const int16_t PHONE_TEX_X = 95; // TODO: guess
const int16_t PHONE_TEX_Y = 0; // TODO: guess
const int16_t PHONE_HEADER_TEX_X = 670;
const int16_t PHONE_HEADER_TEX_Y = 384;
const int16_t PHONE_HEADER_WIDTH = 220;
const int16_t PHONE_HEADER_HEIGHT = 24;
const int16_t PHONE_NEW_MAIL_TEX_X = 302;
const int16_t PHONE_NEW_MAIL_TEX_Y = 576;
const int16_t PHONE_NEW_MAIL_WIDTH = 220;
const int16_t PHONE_NEW_MAIL_HEIGHT = 130;

const int16_t PHONE_HEADER_POS_X = PHONE_POS_X + 49; // 727
const int16_t PHONE_HEADER_POS_Y = PHONE_POS_Y + 89; // 97
const int16_t PHONE_WALLPAPER_X = PHONE_HEADER_POS_X;
const int16_t PHONE_WALLPAPER_Y = PHONE_HEADER_POS_Y + PHONE_HEADER_HEIGHT; // TODO: guess
const int16_t PHONE_OVERLAY_POS_X = PHONE_WALLPAPER_X;
const int16_t PHONE_OVERLAY_POS_Y = 180;

const int16_t MASK_TEX_X = 425;
const int16_t MASK_TEX_Y = 21;
const int16_t MASK_WIDTH = 220;
const int16_t MASK_HEIGHT = 253;

enum
{
    BLUE_HEADER_MAIL,
    BLUE_HEADER_CONTACTS,
    BLUE_HEADER_SETTINGS
};
const int16_t BLUE_HEADER_TEX_X = 670;
const int16_t BLUE_HEADER_TEX_Y[] =
{
    284, 318, 349
};
const int16_t BLUE_HEADER_POS_X = PHONE_HEADER_POS_X;
const int16_t BLUE_HEADER_POS_Y = PHONE_HEADER_POS_Y + PHONE_HEADER_HEIGHT;
const int16_t BLUE_HEADER_WIDTH = 220;
const int16_t BLUE_HEADER_HEIGHT = 23;

extern const char* HeaderString[];

class Clock
{
public:
    Clock()
    {
        Restart();
    }
    int GetElapsedTime()
    {
        return SDL_GetTicks() - Start;
    }
    void Restart()
    {
        Start = SDL_GetTicks();
    }
private:
    int Start;
};

class SGInterpreter;
class PhoneMode;
class PhoneSD;
class SGWindow;

class Phone : public Texture
{
    friend class PhoneModeMailMenu;
    friend class PhoneModeDefaultOperatable;
    friend class PhoneModeAddressBook;
    friend class PhoneModeSendMailEdit;
    friend class PhoneModeReceivingMail;
public:
    Phone(SGWindow* pWindow);
    virtual ~Phone();

    virtual void Draw(uint32_t Diff);
    void SetDate(int32_t Date);
    void SDDisplay(int32_t Show);
    void MailReceive(int32_t Show);
    void UpdateOpenMode(int32_t OpenMode);
    void UpdateMode(uint8_t NewMode);
    void MouseMoved(int x, int y);
    void LeftMouseClicked(int x, int y);
    void RightMouseClicked(SGInterpreter* pInterpreter);
    void SetPhoneCallAllowMask(uint16_t Mask);
    void AddressbookSet(uint8_t Index);
    void AddressbookReset(uint8_t Index);
    void AddressMenuHighlight(int32_t Index);
    void PhoneSendMailEdit(const string& Subject, const string& Sender, const string& Body);

private:
    void UpdateAnim();
    void UpdateOverlayAnim();

    SGWindow* pWindow;
    bool ShowSD;
    bool MailReceived;
    uint8_t Mode;
    uint8_t State;
    int8_t AnimRow;
    int8_t AnimColumn;
    int8_t OverlayAnimProgress;
    Clock AnimClock, OverlayClock;
    Image pWallpaper;
    Image pPhoneOpenTex; // Open/Close animation frames
    Image pPhoneTex;
    Texture Wallpaper;
    Texture Header;
    Texture Overlay, OverlayContent;
    Texture BlueHeader;
    PhoneMode* pMode;
    PhoneMode* PhoneModes[Nsb::NUM_MODES];
    PhoneSD* pSD;
};

#endif
