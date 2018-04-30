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
#include "PhoneModeAddressBook.hpp"
#include "SGExe.hpp"
#include "SGWindow.hpp"
#include <cstring>

PhoneModeAddressBook::PhoneModeAddressBook(Phone* pPhone) :
PhoneMode(pPhone),
ContactHighlight(0),
CallAllowedMask(0),
AddressMask(0)
{
    pWhite.LoadColor(MASK_WIDTH, MASK_HEIGHT, Nsb::Color::WHITE);
    pHighlight.LoadColor(220, 20, 0xffc896);
    Highlight.CreateFromImage(&pHighlight);
    Mask.CreateFromImage(&pPhone->pPhoneTex);
    Mask.SetPosition(PHONE_WALLPAPER_X, PHONE_WALLPAPER_Y);
    HeaderText.SetPosition(BLUE_HEADER_POS_X + 24, BLUE_HEADER_POS_Y);
    //HeaderText.SetCharacterSize(20);
}

PhoneModeAddressBook::~PhoneModeAddressBook()
{
}

void PhoneModeAddressBook::OnOpen(uint8_t OldMode)
{
    pPhone->pWindow->MoveCursor(BLUE_HEADER_POS_X + BLUE_HEADER_WIDTH / 2, BLUE_HEADER_POS_Y + BLUE_HEADER_HEIGHT + 10);
    pPhone->BlueHeader.CreateFromImageClip(&pPhone->pPhoneTex, BLUE_HEADER_TEX_X, BLUE_HEADER_TEX_Y[BLUE_HEADER_CONTACTS], BLUE_HEADER_WIDTH, BLUE_HEADER_HEIGHT);
    pPhone->Wallpaper.CreateFromImage(&pWhite);
    Mask.CreateFromImageClip(&pPhone->pPhoneTex, MASK_TEX_X, MASK_TEX_Y, MASK_WIDTH, MASK_HEIGHT);
    HeaderText.CreateFromString(string(HeaderString[0], strlen(HeaderString[0]) - 3));
}

void PhoneModeAddressBook::Draw(uint32_t Diff)
{
    Mask.Draw(Diff);
    pPhone->BlueHeader.Draw(Diff);
    HeaderText.Draw(Diff);
    Highlight.Draw(Diff);
    for (auto& i : Contacts)
        i.CText.Draw(Diff);
}

void PhoneModeAddressBook::MouseMoved(int x, int y)
{
    if (x > BLUE_HEADER_POS_X && x < BLUE_HEADER_POS_X + MASK_WIDTH &&
        y > BLUE_HEADER_POS_Y + BLUE_HEADER_HEIGHT)
        SetHighlight((y - (BLUE_HEADER_POS_Y + BLUE_HEADER_HEIGHT)) / 20);
}

uint8_t PhoneModeAddressBook::LeftMouseClicked()
{
    if (CallAllowedMask & (1 << ContactHighlight))
        return PHONE_MODE_ADDRESS_CONFIRM_DIAL;
    return Nsb::NSB_NULL;
}

uint8_t PhoneModeAddressBook::RightMouseClicked()
{
    return PHONE_MODE_DEFAULT_OPERATABLE;
}

void PhoneModeAddressBook::SetHighlight(int16_t Index)
{
    if (Index < 0 || Index >= Contacts.size())
        return;

    Highlight.SetPosition(BLUE_HEADER_POS_X, BLUE_HEADER_POS_Y + BLUE_HEADER_HEIGHT + Index * 20);
    ContactHighlight = Index;
}

void PhoneModeAddressBook::AddContact(uint8_t Index)
{
    uint16_t AddressMask = 1 << Index;
    if (this->AddressMask & AddressMask)
        return;

    string Name = sExe->ReadStringIndirect(VA_PHONE_ADDRMENU, Index, 0xC, 0x4);
    Text ContactText;
    ContactText.SetPosition(PHONE_WALLPAPER_X, BLUE_HEADER_POS_Y + BLUE_HEADER_HEIGHT + Contacts.size() * 20);
    ContactText.SetColor(Nsb::Color::BLACK);
    ContactText.CreateFromString(Name); /* TODO: size 20 */
    Contacts.push_back({ ContactText, Index });
    this->AddressMask |= AddressMask;
}

void PhoneModeAddressBook::DelContact(uint8_t Index)
{
    uint16_t AddressMask = 1 << Index;
    if (!(this->AddressMask & AddressMask))
        return;

    for (auto i = Contacts.begin(); i != Contacts.end(); ++i)
    {
        if (i->Index == Index)
        {
            Contacts.erase(i);
            break;
        }
    }
    this->AddressMask &= ~AddressMask;
}
