#include "nss/function_steinsgate.nss"
#include "nss/function.nss"

chapter main
{
    CreatePlainSP("絵板写", 10000);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08A";
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    Fade("BGBUF*", 0, 0, null, true);
    FadeDelete("絵板写", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08B";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08C";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08D";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08E";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08F";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    ColorOut(9000, #000000, 533, null, true);
    $SW_PHONE_ATCH_MODE = "TB_ATCH_SG01_08G";
    $SW_PHONE_ATCH_LINE = 0;
    UNK119();    
    StartAtch($SW_PHONE_ATCH_MODE);
    FadeDelete("OnColor*", 533, null, true);
    WaitAtch();
    Wait(266);
    CreatePlainSP("絵板写", 10000);
    DeleteAtch();
    Fade("BGBUF1", 0, 1000, null, true);
    FadeDelete("絵板写", 533, null, true);
    Exit();
}
