/* void CreateChoice(Handle) */

#include "nss/libtest.nss"

function CreateTex($handle, $sub, $pr, $x, $y, $img)
{
    $name = $handle + $sub;
    CreateTexture($name, $pr, $x, $y, $img);
}

function CreateBtn($nm, $bx, $by, $usu, $ove)
{
    $off = "cg/sys/title/" + $usu;
    $on = "cg/sys/title/" + $ove;
    CreateChoice($nm);
    CreateTex($nm, "/MouseUsual/img", 0, $bx, $by, $off);
    CreateTex($nm, "/MouseOver/img", 0, $bx, $by, $on);
    CreateTex($nm, "/MouseClick/img", 0, $bx, $by, $on);
}

chapter main
{
    CreateBtn("start", 888, 37, "05_STARTボタン.png", "05_STARTボタン_ON.png");
    CreateBtn("load", 888, 97, "06_LOAD.png", "06_LOAD_ON.png");
    CreateBtn("special", 888, 157, "07_EXTRA.png", "07_EXTRA_on.png");
    CreateBtn("config", 888, 217, "08_config.png", "08_config_on.png");
    CreateBtn("exit", 888, 277, "10_exit.png", "10_exit_on.png");
    select
    {
        case start:
        {
            Print("start");
        }
        case load:
        {
            Print("load");
        }
        case special:
        {
            Print("special");
        }
        case config:
        {
            Print("config");
        }
        case exit:
        {
            Print("exit");
        }
    }
    Exit();
}
