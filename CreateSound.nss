/* void CreateSound(Handle, Type, Source) */
chapter main
{
    CreateSound("sound", "BGM", "sound/bgm/bgm03");
    Request("sound", Play);
    WaitKey();
    Exit();
}
