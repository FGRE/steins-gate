chapter main
{
    $SW_PHONE_MODE = "PhoneMode_PowerOff";
    while (1)
    {
        $SF_Phone_Open = 1;
        WaitKey();
        $SF_Phone_Open = 0;
        WaitKey();
    }
    Exit();
}
