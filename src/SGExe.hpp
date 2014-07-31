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
#ifndef SG_EXE_HPP
#define SG_EXE_HPP

#include "exefile.hpp"
#include <string>
using std::string;

enum ExePublisher
{
    EXE_NITROPLUS,
    EXE_JAST,
    EXE_FUWANOVEL,
    EXE_INVALID
};

enum
{
    VA_PHONE_MAIL,
    VA_PHONE_ADDRMENU
};

class SGExe : private ExeFile
{
public:
    SGExe(const std::string& Name, ExePublisher Version, uint8_t CharWidth);

    string ReadStringIndirect(uint32_t Array, uint32_t ArrayIndex, uint32_t StructSize, uint32_t Offset);
    ExePublisher GetVersion();

private:
    ExePublisher Version;
};

extern SGExe* sExe;

#endif
