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
#include "SGInterpreter.hpp"
#include "Phone.hpp"
#include "Window.hpp"
#include "PhoneModeSendMailEdit.hpp"
#include "PhoneModeDefaultOperatable.hpp"
#include "PhoneModeAddressBook.hpp"
#include "PhoneModeMailMenu.hpp"
#include "PhoneModeReceivingMail.hpp"
#include "PhoneSD.hpp"

enum PhoneState
{
    PHONE_CLOSING = 0,
    PHONE_OPENING = 1,
    PHONE_OPENING_DONE, // Switch from last opening animation frame to open phone frame
    PHONE_CLOSING_DONE, // Same as above, except that phone needs to be removed
    PHONE_OPEN,
    PHONE_CLOSED
};

// UNUSED
enum PhoneSDText
{
    PHONE_SD_TEXT_NEW_MAIL = 0,
    PHONE_SD_TEXT_UNK1 = 1,
    PHONE_SD_TEXT_UNK2 = 2,
    PHONE_SD_TEXT_MAX = 3
};
const int16_t PHONE_SD_TEXT_TEX_X[PHONE_SD_TEXT_MAX] =
{
    135, 168, 200
};

const char* HeaderString[] =
{
    "アドレス帳",
    "受信メールBOX",
    "送信メールBOX"
};

const int16_t WALLPAPER_WIDTH = 220;
const int16_t WALLPAPER_HEIGHT = 244;

static const int OverlayContentTexRect[] =
{
    717, 9, 49, 29,
    880, 576, 50, 38
};

Phone::Phone(SGWindow* pWindow) :
pWindow(pWindow),
State(PHONE_CLOSED),
ShowSD(false),
MailReceived(false),
Mode(PHONE_MODE_POWER_OFF),
pMode(nullptr),
OverlayAnimProgress(0)
{
    pWallpaper.LoadImage("cg/sys/phone/pwcg101.png");
    pPhoneTex.LoadImage("cg/sys/phone/phone_01.png");
    pPhoneOpenTex.LoadImage("cg/sys/phone/phone_open_anim.png");

    BlueHeader.SetPosition(BLUE_HEADER_POS_X, BLUE_HEADER_POS_Y);
    Overlay.CreateFromImageClip(&pPhoneTex, PHONE_NEW_MAIL_TEX_X, PHONE_NEW_MAIL_TEX_Y, PHONE_NEW_MAIL_WIDTH, PHONE_NEW_MAIL_HEIGHT);
    Overlay.SetPosition(PHONE_OVERLAY_POS_X, PHONE_OVERLAY_POS_Y);
    OverlayContent.CreateFromImage(&pPhoneTex);
    Header.CreateFromImageClip(&pPhoneTex, PHONE_HEADER_TEX_X, PHONE_HEADER_TEX_Y, PHONE_HEADER_WIDTH, PHONE_HEADER_HEIGHT);
    Header.SetPosition(PHONE_HEADER_POS_X, PHONE_HEADER_POS_Y);

    Wallpaper.SetPosition(PHONE_WALLPAPER_X, PHONE_WALLPAPER_Y);
    SetPosition(PHONE_POS_X, PHONE_POS_Y);

    for (int i = 0; i < NUM_MODES; ++i)
        PhoneModes[i] = nullptr;

    PhoneModes[PHONE_MODE_MAIL_MENU] = new PhoneModeMailMenu(this);
    PhoneModes[PHONE_MODE_DEFAULT_OPERATABLE] = new PhoneModeDefaultOperatable(this);
    PhoneModes[PHONE_MODE_ADDRESS_BOOK] = new PhoneModeAddressBook(this);
    PhoneModes[PHONE_MODE_SEND_MAIL_EDIT] = new PhoneModeSendMailEdit(this);
    PhoneModes[PHONE_MODE_RECEIVING_MAIL] = new PhoneModeReceivingMail(this);
    pSD = new PhoneSD();
}

Phone::~Phone()
{
    for (int i = 0; i < NUM_MODES; ++i)
        delete PhoneModes[i];
    delete pSD;
}

void Phone::UpdateOpenMode(int32_t OpenMode)
{
    if (!(State == PHONE_OPEN || State == PHONE_CLOSED))
        return;

    CreateFromImage(&pPhoneOpenTex);
    State = OpenMode;
    UpdateAnim();
    AnimClock.Restart();
}

void Phone::Draw(uint32_t Diff)
{
    // Update
    if (!(AnimClock.GetElapsedTime() < PHONE_ANIM_SPEED
        || State == PHONE_OPEN || State == PHONE_CLOSED))
    {
        UpdateAnim();
        AnimClock.Restart();
    }

    if (OverlayClock.GetElapsedTime() > 500)
        UpdateOverlayAnim();

    // Draw
    Texture::Draw(Diff);
    if (State == PHONE_OPEN)
    {
        if (Mode != PHONE_MODE_POWER_OFF && Mode != PHONE_MODE_RECEIVING_MAIL)
        {
            Wallpaper.Draw(Diff);
            Header.Draw(Diff);
            if (MailReceived)
            {
                Overlay.Draw(Diff);
                OverlayContent.Draw(Diff);
            }
        }
        if (Mode == PHONE_MODE_ADDRESS_CONFIRM_DIAL)
            PhoneModes[PHONE_MODE_ADDRESS_BOOK]->Draw(Diff);
        if (Mode == PHONE_MODE_ADDRESS_CONFIRM_MAIL)
            PhoneModes[PHONE_MODE_SEND_MAIL_EDIT]->Draw(Diff);
        if (pMode)
            pMode->Draw(Diff);
    }
    if (ShowSD)
        pSD->Draw(Diff);
}

void Phone::UpdateAnim()
{
    //
    // See: cg/sys/phone/phone_open_anim.png
    //

    // Animation finished in last call
    if (State == PHONE_OPENING_DONE)
    {
        CreateFromImageClip(&pPhoneTex, PHONE_TEX_X, PHONE_TEX_Y, PHONE_WIDTH, PHONE_HEIGHT);
        State = PHONE_OPEN;
        return;
    }
    else if (State == PHONE_CLOSING_DONE)
    {
        CreateEmpty(0, 0);
        SetPosition(PHONE_POS_X, PHONE_POS_Y);
        State = PHONE_CLOSED;
        return;
    }

    // Animation is not done: set next frame
    CreateFromImageClip(&pPhoneOpenTex, AnimColumn * PHONE_WIDTH, AnimRow * PHONE_HEIGHT, PHONE_WIDTH, PHONE_HEIGHT);

    // Check if animation is done
    switch (State)
    {
        case PHONE_OPENING:
            if (AnimColumn == 0 && AnimRow == 0)
                State = PHONE_OPENING_DONE;
            break;
        case PHONE_CLOSING:
            if (AnimColumn == PHONE_ANIM_COLUMN_MAX && AnimRow == PHONE_ANIM_ROW_MAX)
                State = PHONE_CLOSING_DONE;
            break;
    }

    // Advance animation progress
    switch (State)
    {
        case PHONE_OPENING: --AnimColumn; break;
        case PHONE_CLOSING: ++AnimColumn; break;
        case PHONE_OPENING_DONE: case PHONE_CLOSING_DONE: return;
    }

    // Go to previous row
    if (AnimColumn == PHONE_ANIM_UNDERFLOW)
    {
        AnimColumn = PHONE_ANIM_COLUMN_MAX;
        --AnimRow;
    }
    // Go to next row
    else if (AnimColumn > PHONE_ANIM_COLUMN_MAX)
    {
        AnimColumn = 0;
        ++AnimRow;
    }
}

void Phone::UpdateOverlayAnim()
{
    const int* TexRect = OverlayContentTexRect + 4 * OverlayAnimProgress;
    OverlayContent.CreateFromImageClip(&pPhoneTex, TexRect[0], TexRect[1], TexRect[2], TexRect[3]);
    OverlayContent.SetPosition(834 - TexRect[2] / 2, 208 - TexRect[3] / 2);
    OverlayAnimProgress = !OverlayAnimProgress;
    OverlayClock.Restart();
}

void Phone::UpdateMode(uint8_t NewMode)
{
    if (NewMode == Mode || NewMode == NUM_MODES)
        return;

    pMode = PhoneModes[NewMode];
    switch (NewMode)
    {
        case PHONE_MODE_DEFAULT:
            Wallpaper.CreateFromImageClip(&pWallpaper, 0, 0, WALLPAPER_WIDTH, WALLPAPER_HEIGHT);
            break;
        default:
            if (pMode)
                pMode->OnOpen(Mode);
    }
    Mode = NewMode;
}

void Phone::MailReceive(int32_t Show)
{
    switch (Show)
    {
        case PHONE_CLOSING: MailReceived = false; break;
        case PHONE_OPENING: MailReceived = true; UpdateOverlayAnim(); break;
        default: assert(false); break;
    }
}

void Phone::SetDate(int32_t Date)
{
    string DateStr = to_string(Date);
    if (DateStr.size() == 3) DateStr = string("0") + DateStr;
    pSD->SetDate(DateStr);
}

void Phone::SDDisplay(int32_t Show)
{
    switch (Show)
    {
        case PHONE_CLOSING: ShowSD = false; break;
        case PHONE_OPENING: ShowSD = true; break;
        default: assert(false);
    }
}

void Phone::MouseMoved(int x, int y)
{
    if (pMode)
        pMode->MouseMoved(x, y);
}

void Phone::LeftMouseClicked(int x, int y)
{
    if (!(x > PHONE_WALLPAPER_X && x < PHONE_WALLPAPER_X + WALLPAPER_WIDTH &&
          y > PHONE_WALLPAPER_Y && y < PHONE_WALLPAPER_Y + WALLPAPER_HEIGHT))
        return;

    if (pMode)
        UpdateMode(pMode->LeftMouseClicked());
}

void Phone::RightMouseClicked(SGInterpreter* pInterpreter)
{
    switch (Mode)
    {
        case PHONE_MODE_DEFAULT:
            pInterpreter->PhoneToggle();
            break;
        default:
            if (pMode)
                UpdateMode(pMode->RightMouseClicked());
    }
}

void Phone::SetPhoneCallAllowMask(uint16_t Mask)
{
    PhoneModeAddressBook* pMode = (PhoneModeAddressBook*)PhoneModes[PHONE_MODE_ADDRESS_BOOK];
    pMode->CallAllowedMask = Mask;
}

void Phone::AddressMenuHighlight(int32_t Index)
{
    PhoneModeAddressBook* pMode = (PhoneModeAddressBook*)PhoneModes[PHONE_MODE_ADDRESS_BOOK];
    pMode->SetHighlight(Index);
}

void Phone::PhoneSendMailEdit(const string& Subject, const string& Sender, const string& Body)
{
    PhoneModeSendMailEdit* pMode = (PhoneModeSendMailEdit*)PhoneModes[PHONE_MODE_SEND_MAIL_EDIT];
    pMode->SetText(Subject, Sender, Body);
}

void Phone::AddressbookSet(uint8_t Index)
{
    PhoneModeAddressBook* pMode = (PhoneModeAddressBook*)PhoneModes[PHONE_MODE_ADDRESS_BOOK];
    pMode->AddContact(Index);
}

void Phone::AddressbookReset(uint8_t Index)
{
    PhoneModeAddressBook* pMode = (PhoneModeAddressBook*)PhoneModes[PHONE_MODE_ADDRESS_BOOK];
    pMode->DelContact(Index);
}
