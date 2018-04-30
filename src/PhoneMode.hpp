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
#ifndef PHONE_MODE_HPP
#define PHONE_MODE_HPP

#include "Phone.hpp"

class PhoneMode
{
    friend class Phone;
protected:
    PhoneMode(Phone* pPhone) : pPhone(pPhone) { }
    virtual ~PhoneMode() { }

    virtual void OnOpen(uint8_t OldMode) = 0;
    virtual void Draw(uint32_t Diff) = 0;
    virtual void MouseMoved(int x, int y) = 0;
    virtual uint8_t LeftMouseClicked() { return Nsb::NSB_NULL; }
    virtual uint8_t RightMouseClicked() { return Nsb::NSB_NULL; }

    Phone* pPhone; // TODO: static?
};

#endif
