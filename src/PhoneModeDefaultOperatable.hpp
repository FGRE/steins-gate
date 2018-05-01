/*
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014,2018 Mislav Blažević <krofnica996@gmail.com>
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
#ifndef PHONE_MODE_DEFAULT_OPERATABLE_HPP
#define PHONE_MODE_DEFAULT_OPERATABLE_HPP

#include "PhoneMode.hpp"

class Phone;

class PhoneModeDefaultOperatable : PhoneMode
{
    friend class Phone;
protected:
    PhoneModeDefaultOperatable(Phone* pPhone);

    virtual void OnOpen(uint8_t OldMode);
    virtual void Draw(uint32_t Diff);
    virtual void MouseMoved(int x, int y);
    virtual uint8_t LeftMouseClicked();
    virtual uint8_t RightMouseClicked();

private:
    void HighlightButton(int8_t x, int8_t y);

    int8_t ButtonHighlightX, ButtonHighlightY; // Currently highlighed button
    Texture Button[2][2];
    Texture MenuOverlay;
};

#endif
