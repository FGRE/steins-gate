/* void CreateSound(Handle, Type, Source) */
chapter main
{
    #SYSTEM_sound_volume_bgm = 1000;
    CreateSound("sound", "BGM", "sound/bgm/bgm03");
    Request("sound", Play);
    WaitKey();
    /* Changes volume while playing */
    #SYSTEM_sound_volume_bgm = 500;
    WaitKey();
    SetVolume("sound", 0, 100, "null");
    WaitKey();
    /* After SetVolume, the variable has no effect on the object */
    #SYSTEM_sound_volume_bgm = 1000;
    WaitKey();
    Exit();
}
