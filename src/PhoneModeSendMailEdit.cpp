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
#include "PhoneModeSendMailEdit.hpp"
#include "SGExe.hpp"

PhoneModeSendMailEdit::PhoneModeSendMailEdit(Phone* pPhone) : PhoneMode(pPhone)
{
    pWhite.LoadColor(MASK_WIDTH, MASK_HEIGHT, Nsb::Color::WHITE);
    Mask.SetPosition(PHONE_WALLPAPER_X, PHONE_WALLPAPER_Y);

    for (int i = 0; i < 3; ++i)
    {
        MailText[i].SetPosition(729.0f, 144.0f + i * 17);
        MailText[i].SetCharacterSize(17);
        MailText[i].SetColor(Nsb::Color::BLACK);
    }
}

PhoneModeSendMailEdit::~PhoneModeSendMailEdit()
{
}

void PhoneModeSendMailEdit::OnOpen(uint8_t OldMode)
{
    pPhone->Wallpaper.CreateFromImage(&pWhite);
    Mask.CreateFromImageClip(&pPhone->pPhoneTex, MASK_TEX_X, MASK_TEX_Y, MASK_WIDTH, MASK_HEIGHT);
}

void PhoneModeSendMailEdit::Draw(uint32_t Diff)
{
    Mask.Draw(Diff);;
    pPhone->BlueHeader.Draw(Diff);
    for (int i = 0; i < 3; ++i)
        MailText[i].Draw(Diff);
}

void PhoneModeSendMailEdit::MouseMoved(int x, int y)
{
}

void PhoneModeSendMailEdit::SetText(const string& Subject, const string& Sender, string Body)
{
    // Fuwanovel has '\n' characters in exe
    if (sExe->GetVersion() != EXE_FUWANOVEL)
        MailText[2].SetWrap(220);

    MailText[0].CreateFromString(Sender);
    MailText[1].CreateFromString(Subject);
    MailText[2].CreateFromString(Body);
}
