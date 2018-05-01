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
#include "PhoneModeReceivingMail.hpp"
#include <cstring>

static const char* RecMailStr = "受信中";

PhoneModeReceivingMail::PhoneModeReceivingMail(Phone* pPhone) : PhoneMode(pPhone), AnimStep(0)
{
    for (int i = 0; i < 4; ++i)
        HDots[i].SetPosition(780 + (i % 2) * 48 + (i % 2) * 2 + (i / 2) * 10, 150 + (i / 2) * 48 + (i / 2) * 2);

    for (int i = 0; i < 2; ++i)
        VDots[i].SetPosition(780 + i * 48 * 2 + i * 4, 150 + (!i) * 10);

    // TODO: position and size are a guess
    RecMailText.SetPosition(780 + 28, 150 + 18);
    RecMailText.SetCharacterSize(20);
    RecMailText.CreateFromString(RecMailStr);
    UpdateAnim();
}

PhoneModeReceivingMail::~PhoneModeReceivingMail()
{
}

void PhoneModeReceivingMail::OnOpen(uint8_t OldMode)
{
}

void PhoneModeReceivingMail::Draw(uint32_t Diff)
{
    if (AnimClock.GetElapsedTime() > 100)
        UpdateAnim();

    pPhone->Header.Draw(Diff);
    for (int i = 0; i < 4; ++i)
        HDots[i].Draw(Diff);
    for (int i = 0; i < 2; ++i)
        VDots[i].Draw(Diff);
    RecMailText.Draw(Diff);
}

void PhoneModeReceivingMail::MouseMoved(int x, int y)
{
}

void PhoneModeReceivingMail::UpdateAnim()
{
    AnimClock.Restart();

    for (int i = 0; i < 4; ++i)
        HDots[i].CreateFromImageClip(&pPhone->pPhoneTex, 1000, 720 + AnimStep * 10, 48, 8);
    for (int i = 0; i < 2; ++i)
        VDots[i].CreateFromImageClip(&pPhone->pPhoneTex, 1000 + AnimStep * 10, 720, 8, 48);

    if (++AnimStep == 5)
        AnimStep = 0;
}
