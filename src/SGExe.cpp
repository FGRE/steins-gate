/* 
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014-2016 Mislav Blažević <krofnica996@gmail.com>
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
#include "SGExe.hpp"

SGExe* sExe;

static const uint32_t AddressTable[][3] =
{
    { 0x643d68, 0x63d338, 0x643d68 },
    { 0x64dd18, 0x61b2f0, 0x64dd18 }
};

SGExe::SGExe(const string& Name, ExePublisher Version, uint8_t CharWidth) :
ExeFile(Name, CharWidth),
Version(Version)
{
}

string SGExe::ReadStringIndirect(uint32_t Array, uint32_t ArrayIndex, uint32_t StructSize, uint32_t Offset)
{
    uint32_t Address = ArrayIndex * StructSize + AddressTable[Array][Version];
    return Read<string>(Read<uint32_t>(Address + Offset));
}

ExePublisher SGExe::GetVersion()
{
    return Version;
}
