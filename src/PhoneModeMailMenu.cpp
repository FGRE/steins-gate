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
#include "PhoneModeMailMenu.hpp"
#include <cstring>
#include <SDL2/SDL_mouse.h>

const int16_t OVERLAY_RED_TEX_X = 302;
const int16_t OVERLAY_RED_TEX_Y = 722;
const int16_t OVERLAY_RED_WIDTH = 220;
const int16_t OVERLAY_RED_HEIGHT = 119;
const int16_t OVERLAY_RED_POS_X = 728;
const int16_t OVERLAY_RED_POS_Y = 159;

const int16_t MAIL_MENU_TEXT_POS_X = 750;

PhoneModeMailMenu::PhoneModeMailMenu(Phone* pPhone) :
PhoneMode(pPhone),
MailMenuHighlight(0)
{
    OverlayRed.SetPosition(OVERLAY_RED_POS_X, OVERLAY_RED_POS_Y);
    OverlayRed.CreateFromImageClip(&pPhone->pPhoneTex, OVERLAY_RED_TEX_X, OVERLAY_RED_TEX_Y, OVERLAY_RED_WIDTH, OVERLAY_RED_HEIGHT);

    for (int i = 0; i < 2; ++i)
    {
        MailMenuText[i].SetPosition(MAIL_MENU_TEXT_POS_X, 170 + i * 20);
        MailMenuText[i].SetCharacterSize(20);
        MailMenuText[i].SetColor(Nsb::Color::BLACK);
        MailMenuText[i].CreateFromString(HeaderString[i + 1]);
    }
    MailMenuText[MailMenuHighlight].SetColor(Nsb::Color::RED);
}

void PhoneModeMailMenu::OnOpen(uint8_t OldMode)
{
    if (MailMenuHighlight != 0)
    {
        MailMenuText[MailMenuHighlight].SetColor(Nsb::Color::BLACK);
        MailMenuText[0].SetColor(Nsb::Color::RED);
        MailMenuHighlight = 0;
    }
    int x, y;
    SDL_GetMouseState(&x, &y);
    MouseMoved(x, y);
}

void PhoneModeMailMenu::Draw(uint32_t Diff)
{
    OverlayRed.Draw(Diff);
    for (int i = 0; i < 2; ++i)
        MailMenuText[i].Draw(Diff);
}

void PhoneModeMailMenu::MouseMoved(int x, int y)
{
    if (x > MAIL_MENU_TEXT_POS_X && x < MAIL_MENU_TEXT_POS_X + MailMenuText[0].GetWidth())
    {
        int i = (y - 170) / 20;
        if (i >= 0 && i < 2 && i != MailMenuHighlight)
        {
            MailMenuText[MailMenuHighlight].SetColor(Nsb::Color::BLACK);
            MailMenuText[i].SetColor(Nsb::Color::RED);
            MailMenuHighlight = i;
        }
    }
}

uint8_t PhoneModeMailMenu::RightMouseClicked()
{
    return PHONE_MODE_DEFAULT_OPERATABLE;
}
