chapter main
{
    /* Must be set before opening the phone */
    $SW_PHONE_MODE = "PhoneMode_PowerOff";
    WaitKey();
    /* Opens the phone */
    $SF_Phone_Open = 1;
    /* This is a blocking operation */
    $SF_Phone_Open = 0;
    $SF_Phone_Open = 1;
    WaitKey();

    /* MMDD */
    $LR_DATE = 0728;
    /* Opens SD */
    $SF_PhoneSD_Disp = 1;
    WaitKey();

    /* 0-3 */
    $SW_PHONE_MENUCUR = 0;
    $SW_PHONE_MODE = "PhoneMode_DefaultOperatable";
    while ($SW_PHONE_MENUCUR < 3)
    {
        WaitKey();
        $SW_PHONE_MENUCUR++;
    }
    WaitKey();

    /* Just changing $SW_PHONE_MAILMENUCUR won't work so switch modes */
    $SW_PHONE_MAILMENUCUR = 0;
    $SW_PHONE_MODE = "PhoneMode_MailMenu";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_DefaultOperatable";
    WaitKey();
    $SW_PHONE_MAILMENUCUR = 1;
    $SW_PHONE_MODE = "PhoneMode_MailMenu";

    /* Lets test bunch of modes */
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_Option";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_Ringing";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_ReceivingMail";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_ChangeWallPaper";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_ChangeRingingMelody";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_ChangeReceiveingMelody";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_SendBox";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_ReceiveBox";
    WaitKey();
    $SW_PHONE_MODE = "PhoneMode_AddressBook";
    WaitKey();

    /* Closes the phone */
    $SF_Phone_Open = 0;
    WaitKey();
    Exit();
}
