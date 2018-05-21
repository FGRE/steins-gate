/*
 * steins-gate: Open source implementation of Steins;Gate Visual Novel
 * Copyright (C) 2014-2016,2018 Mislav Blažević <krofnica996@gmail.com>
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
#ifndef SG_INTERPRETER_HPP
#define SG_INTERPRETER_HPP

#include "NSBInterpreter.hpp"
#include "SGExe.hpp"
#include "Phone.hpp"

class SGWindow;
class Phone;

struct SGConfig
{
    SGConfig();

    // プロダクト
    string bland, name, version;

    // スクリプト
    string start, close, menu;

    // ウィンドウ
    string title;
    int32_t debug;

    // フォント
    string font_face;
    uint32_t font_size, font_weight;
    string font_inline, font_outline;
    uint32_t font_margin_line, font_margin_low;

    // テキスト
    string bad_start, bad_end;
    uint32_t ruby_rate;

    // サウンド
    uint32_t bgm_volume, se_volume, voice_volume;

    // アイコン
    string icon_line, icon_page, icon_auto;

    // バックログ
    string script, icon_voice;
    uint32_t word_in_row;

    // セーブ
    string enable;

    // ボイス
    string all_name;

    // コンパイラ
    string compiler;
};

extern SGConfig* sCfg;

class SGInterpreter : public NSBInterpreter
{
    friend class Phone;
public:
    SGInterpreter(SGWindow* pWindow);
    ~SGInterpreter();

    void HandleEvent(const SDL_Event& Event);
    void MouseMoved(int x, int y);
    void MouseClicked(const SDL_Event& Event);

    virtual void OnVariableChanged(const string& Name);

private:
    void WriteHack(const char* ScriptName, uint32_t LineNumber, uint16_t NewMagic);

    void SendMailEdit();
    void AllowPhoneCall();
    void UNK101();
    void UNK143();
    void UNK128();

    void PhoneToggle();
    void PhoneAddressMenuHighlight();
    void SGPhoneOpen();
    void SGPhoneMode();
    void SGPhonePriority();

    Phone* pPhone;
};

#endif
