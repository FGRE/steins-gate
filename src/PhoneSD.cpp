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
#include "PhoneSD.hpp"
#include "NSBInterpreter.hpp"

const int16_t PHONE_SD_POS_X = 20;
const int16_t PHONE_SD_POS_Y = 20;
const int16_t PHONE_SD_TEX_X = 794;
const int16_t PHONE_SD_TEX_Y = 42;
const int16_t PHONE_SD_WIDTH = 200;
const int16_t PHONE_SD_HEIGHT = 50;

const int16_t PHONE_SD_BLUE_TEX_X = 782;
const int16_t PHONE_SD_BLUE_TEX_Y = 124;
const int16_t PHONE_SD_BLUE_WIDTH = PHONE_SD_WIDTH + (PHONE_SD_TEX_X - PHONE_SD_BLUE_TEX_X) * 2;
const int16_t PHONE_SD_BLUE_HEIGHT = PHONE_SD_HEIGHT + (136 - PHONE_SD_BLUE_TEX_Y) * 2;

// First digit in SD
const int16_t PHONE_SD_DIGIT_POS_X = 36;
const int16_t PHONE_SD_DIGIT_POS_Y = 36;
const int16_t PHONE_SD_DIGIT_OFFSET_X = 7;
const int16_t PHONE_SD_DAY_POS_Y = 47;

// 0-9
const int16_t PHONE_DIGIT_A_TEX_X[10] =
{
    334, 24, 59, 93, 127, 159, 192, 226, 260, 292
};
const int16_t PHONE_DIGIT_A_TEX_Y = 83;
const int16_t PHONE_DIGIT_A_WIDTH = 16;
const int16_t PHONE_DIGIT_A_HEIGHT = 22;

// SUN, MON-SAT
const int16_t PHONE_DAY_TEX_X[7] =
{
    23, 75, 126, 178, 229, 281, 332
};
const int16_t PHONE_DAY_TEX_Y = 128;
const int16_t PHONE_DAY_WIDTH = 39;
const int16_t PHONE_DAY_HEIGHT = 14;

// "/"
const int16_t PHONE_SLASH_TEX_X = 400;
const int16_t PHONE_SLASH_TEX_Y = 164;
const int16_t PHONE_SLASH_WIDTH = 16;
const int16_t PHONE_SLASH_HEIGHT = 24;

// ????
enum PhoneIcon
{
    PHONE_ICON_UNK = 0,
    PHONE_ICON_MAIL = 1,
    PHONE_ICON_SIGNAL = 2,
    PHONE_ICON_BATTERY = 3,
    PHONE_ICON_MAX = 4
};
const int16_t PHONE_ICON_TEX_X = 626;
const int16_t PHONE_ICON_TEX_Y[PHONE_ICON_MAX] =
{
    30, 56, 79, 106
};
const int16_t PHONE_ICON_POS_X[PHONE_ICON_MAX] =
{
    -1, 147, 187, 166
};
const int16_t PHONE_ICON_POS_Y = 30;
const int16_t PHONE_ICON_WIDTH[PHONE_ICON_MAX] =
{
    23, 16, 17, 19
};
const int16_t PHONE_ICON_HEIGHT = 11;

PhoneSD::PhoneSD()
{
    pSDTex.LoadImage("cg/sys/phone/phone_sd.png");
    SD.CreateFromImageClip(&pSDTex, PHONE_SD_TEX_X, PHONE_SD_TEX_Y, PHONE_SD_WIDTH, PHONE_SD_HEIGHT);
    SD.SetPosition(PHONE_SD_POS_X, PHONE_SD_POS_Y);

    for (int i = PHONE_ICON_SIGNAL; i < PHONE_ICON_MAX; ++i)
    {
        SDIcon[i].CreateFromImageClip(&pSDTex, PHONE_ICON_TEX_X, PHONE_ICON_TEX_Y[i], PHONE_ICON_WIDTH[i], PHONE_ICON_HEIGHT);
        SDIcon[i].SetPosition(PHONE_ICON_POS_X[i], PHONE_ICON_POS_Y);
    }
}

PhoneSD::~PhoneSD()
{
}

void PhoneSD::Draw(uint32_t Diff)
{
    SD.Draw(Diff);
    for (int i = 0; i < 6; ++i)
        SDDate[i].Draw(Diff);
    for (int i = PHONE_ICON_SIGNAL; i <= PHONE_ICON_BATTERY; ++i)
        SDIcon[i].Draw(Diff);
}

void PhoneSD::SetDate(string Date)
{
    int32_t PosX = PHONE_SD_DIGIT_POS_X;
    int i;

    // Month
    i = (Date[0] == '0' ? 1 : 0); // Alignment : skip preceeding zero
    for (; i < 2; ++i)
    {
        SDDate[i].CreateFromImageClip(&pSDTex, PHONE_DIGIT_A_TEX_X[Date[i] - '0'], PHONE_DIGIT_A_TEX_Y, PHONE_DIGIT_A_WIDTH, PHONE_DIGIT_A_HEIGHT);
        SDDate[i].SetPosition(PosX, PHONE_SD_DIGIT_POS_Y);
        PosX += PHONE_SD_DIGIT_OFFSET_X + PHONE_DIGIT_A_WIDTH;
    }

    // Slash
    SDDate[2].CreateFromImageClip(&pSDTex, PHONE_SLASH_TEX_X, PHONE_SLASH_TEX_Y, PHONE_SLASH_WIDTH, PHONE_SLASH_HEIGHT);
    SDDate[2].SetPosition(PosX, PHONE_SD_DIGIT_POS_Y);
    PosX += PHONE_SD_DIGIT_OFFSET_X + PHONE_DIGIT_A_WIDTH;

    // Day
    i = (Date[2] == '0' ? 3 : 2);
    for (; i < 4; ++i)
    {
        SDDate[i + 1].CreateFromImageClip(&pSDTex, PHONE_DIGIT_A_TEX_X[Date[i] - '0'], PHONE_DIGIT_A_TEX_Y, PHONE_DIGIT_A_WIDTH, PHONE_DIGIT_A_HEIGHT);
        SDDate[i + 1].SetPosition(PosX, PHONE_SD_DIGIT_POS_Y);
        PosX += PHONE_SD_DIGIT_OFFSET_X + PHONE_DIGIT_A_WIDTH;
    }

    // Week day
    SDDate[5].CreateFromImageClip(&pSDTex, PHONE_DAY_TEX_X[DateToWeekDay(Date)], PHONE_DAY_TEX_Y, PHONE_DAY_WIDTH, PHONE_DAY_HEIGHT);
    SDDate[5].SetPosition(PosX, PHONE_SD_DAY_POS_Y);
}

int PhoneSD::DateToWeekDay(string Date)
{
    string Month(Date, 0, 2);
    string Day(Date, 2, 2);
    std::tm time_in = { 0, 0, 0, stoi(Day), stoi(Month) - 1, 2010 - 1900 };
    std::time_t time = std::mktime(&time_in);
    return std::localtime(&time)->tm_wday;
}
