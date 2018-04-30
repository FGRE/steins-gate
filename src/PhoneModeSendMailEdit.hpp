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
#ifndef PHONE_MODE_SEND_MAIL_EDIT_HPP
#define PHONE_MODE_SEND_MAIL_EDIT_HPP

#include "PhoneMode.hpp"
using std::string;

class Phone;

class PhoneModeSendMailEdit : PhoneMode
{
    friend class Phone;
protected:
    PhoneModeSendMailEdit(Phone* pPhone);
    ~PhoneModeSendMailEdit();

    virtual void OnOpen(uint8_t OldMode);
    virtual void Draw(uint32_t Diff);
    virtual void MouseMoved(int x, int y);

    void SetText(const string& Subject, const string& Sender, string Body);
private:
    Image pWhite;
    Texture Mask;
    Text MailText[3];
};

#endif
